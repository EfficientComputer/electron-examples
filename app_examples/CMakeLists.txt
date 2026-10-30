cmake_minimum_required(VERSION 3.15)

# The SDK (setup_sdk.cmake) configures effcc as the compiler. Declare no languages here
# so CMake doesn't probe for a host compiler first: on Windows that probe picks up MSVC or
# MinGW and injects host link flags (-luuid, --out-implib, ...) that the effcc linker
# rejects. CMAKE_SYSTEM_NAME must be set before project() for the same reason.
set(CMAKE_SYSTEM_NAME Generic)
project(app_examples LANGUAGES NONE)

# The data generators below are Python scripts. Ask CMake for the interpreter instead of
# hardcoding "python3": on Windows that name resolves to the Microsoft Store stub and the
# build fails with exit code 9009. With a virtual environment active, its Python is chosen.
find_package(Python3 REQUIRED COMPONENTS Interpreter)
execute_process(COMMAND ${Python3_EXECUTABLE} -c "import numpy" RESULT_VARIABLE _numpy_rc OUTPUT_QUIET ERROR_QUIET)
if(NOT _numpy_rc EQUAL 0)
    message(FATAL_ERROR "The fft and ldpc examples generate their test data with numpy, which "
                        "${Python3_EXECUTABLE} cannot import. Install it into the active environment: "
                        "pip install numpy")
endif()

# Uncomment to enable hand-optimized app versions:
#
# set(EFF_BLD_HAND_OPTIMIZED ON)

# The Electron E1x EVK routes the console through UART 3. The Electron E1 EVK uses the
# SDK default (UART 0 on pins 22 and 23), so leave it alone there.
if(EFF_ARCH STREQUAL "e1x")
  set(EFF_STDIO_PORT 3)
elseif(EFF_ARCH STREQUAL "e1")
  # The Electron E1 EVK's USB console is on pins 22 and 23. Release 26.3.1 makes that the SDK
  # default; release 26.3.0 defaulted to pins 12 and 13, so set it explicitly for both.
  add_compile_definitions(STDIO_UART=UART_0 STDIO_PINMUX=PINMUX_22 STDIO_PINMUX_2=PINMUX_23
                          STDIO_PINMUX_RX=PINMUX_22 STDIO_PINMUX_TX=PINMUX_23)
endif()

# The EFF SDK is the sdk folder of the installed effcc package. Pass it with
# -DEFF_SDK_ROOT_DIR=<path> (or the EFF_SDK_ROOT_DIR environment variable); otherwise ask
# the active Python environment where the package is, which is what a wheel install gives.
if(NOT DEFINED EFF_SDK_ROOT_DIR AND DEFINED ENV{EFF_SDK_ROOT_DIR})
  set(EFF_SDK_ROOT_DIR "$ENV{EFF_SDK_ROOT_DIR}")
endif()
if(NOT DEFINED EFF_SDK_ROOT_DIR)
  execute_process(
    COMMAND ${Python3_EXECUTABLE} -c "import effcc; print(effcc.__path__[0])"
    OUTPUT_VARIABLE _effcc_pkg
    OUTPUT_STRIP_TRAILING_WHITESPACE
    RESULT_VARIABLE _effcc_rc)
  if(NOT _effcc_rc EQUAL 0)
    message(
      FATAL_ERROR
        "effcc not found. Activate the Python environment it is installed in, or pass -DEFF_SDK_ROOT_DIR=<effcc package>/sdk"
    )
  endif()
  set(EFF_SDK_ROOT_DIR "${_effcc_pkg}/sdk")
  # Tell the SDK where the compiler binaries are as well. On Windows the environment's
  # effcc launcher lives in Scripts\, which the SDK's PATH lookup does not understand.
  if(NOT DEFINED EFFCC_DIR)
    set(EFFCC_DIR "${_effcc_pkg}")
  endif()
endif()
file(REAL_PATH "${EFF_SDK_ROOT_DIR}" EFF_SDK_ROOT_DIR)
include(${EFF_SDK_ROOT_DIR}/setup_sdk.cmake)
add_subdirectory(${EFF_SDK_ROOT_DIR} sdk)

if(EFF_BLD_HAND_OPTIMIZED)
  add_compile_definitions(EFF_BLD_HAND_OPTIMIZED)
endif()

add_subdirectory(bfs)
add_subdirectory(biquad_filter)
add_subdirectory(cholesky_decomp)
add_subdirectory(conv3x3)
add_subdirectory(conv3x3_dw)
add_subdirectory(conv3x3xn)
add_subdirectory(conv5x5)
add_subdirectory(crc32)
add_subdirectory(dijkstras)
add_subdirectory(dmm)
add_subdirectory(dmm_i8)
add_subdirectory(dmv)
add_subdirectory(dmv_fp)
add_subdirectory(fft)
add_subdirectory(fir)
add_subdirectory(hello)
add_subdirectory(isqrt)
add_subdirectory(jpeg)
add_subdirectory(knapsack)
add_subdirectory(ldpc)
add_subdirectory(quickstart)
add_subdirectory(levenshtein)
add_subdirectory(qr_decomp)
add_subdirectory(recursive_factorial)
add_subdirectory(smv)
add_subdirectory(sort)
add_subdirectory(spadd)
add_subdirectory(sparse)
add_subdirectory(sqrt_newton)
