# Electron Examples

Welcome to the Electron Examples repository. This collection of example applications helps you get up and running with the Electron E1 and Electron E1x processors and their Evaluation Kits (EVKs). Whether you are exploring the processors for the first time or building production applications, these examples provide a solid starting point and reference implementations that demonstrate best practices for developing on Efficient hardware. Use them as templates for your own projects, or as building blocks to accelerate your development.

If you haven't already, please make sure you've set up your board and development environment using our [Evaluation Kit Setup Instructions](https://docs.efficient.computer/evaluation-kit).

---


## Choose your target

Every example builds for both processors. Pick the target when you configure, and keep one build
directory per target:

```bash
# Electron E1 EVK
cmake -S . -B bld-e1 -G Ninja -DEFF_ARCH=e1 && cmake --build bld-e1 --target quickstart/fabric/quickstart

# Electron E1x EVK (legacy)
cmake -S . -B bld-e1x -G Ninja -DEFF_ARCH=e1x && cmake --build bld-e1x --target quickstart/fabric/quickstart
```

The `fft` and `ldpc` examples generate their test data with a Python script that needs `numpy`.
Install it into the same environment as the compiler: `pip install numpy`.

Board-specific details, such as the console UART and the user LED pins, are handled by the build and
by `quickstart/board.h`, so the application sources are the same for both. See the
[Targets](https://docs.efficient.computer/sdk/targets) page for what differs between the processors.

## App Examples

Optimized algorithm implementations demonstrating how to leverage the Fabric architecture for real-world DSP, image processing, communications, and compute workloads. Each app includes complete source code with Fabric-optimized kernels and correctness validation. This project supports both our physical EVK and our Cloud EVK.

- **bfs**: Breadth-First Search (Graph)
- **biquad_filter**: Optimized Biquad IIR Filter (DSP)
- **cholesky_decomp**: Cholesky Decomposition (Linear Algebra)
- **conv3x3**: 3×3 Convolution Kernel (ML/Vision)
- **conv3x3_dw**: 3×3 Depthwise Convolution (ML/Vision)
- **conv3x3xn**: Multi-Channel 3×3 Convolution (ML/Vision)
- **conv5x5**: Optimized 5×5 Convolution Kernel (ML/Vision)
- **crc32**: CRC-32 Checksum (Data Integrity)
- **dijkstras**: Dijkstra's Shortest Path (Graph)
- **dmm**: Dense Matrix Multiply (Linear Algebra)
- **dmm_i8**: Int8 Dense Matrix Multiply (Linear Algebra)
- **dmv**: Dense Matrix-Vector Multiply (Linear Algebra)
- **dmv_fp**: Floating-Point Dense Matrix-Vector Multiply (Linear Algebra)
- **fft**: Fast Fourier Transform (DSP)
- **fir**: FIR Filter (DSP)
- **hello**: Minimal "Hello World" example
- **isqrt**: Integer Square Root (Math)
- **jpeg**: JPEG Image Encoder (Multimedia)
- **knapsack**: 0/1 Knapsack Solver (Dynamic Programming)
- **ldpc**: LDPC Encoder/Decoder (Communications)
- **levenshtein**: Levenshtein Edit Distance (Dynamic Programming)
- **qr_decomp**: QR Decomposition (Linear Algebra)
- **quickstart**: Simple "Hello World" example
- **recursive_factorial**: Recursive Factorial (Math)
- **smv**: Sparse Matrix-Vector Multiply (Sparse Linear Algebra)
- **sort**: Merge Sort (Sorting)
- **spadd**: Sparse Matrix Addition (Sparse Linear Algebra)
- **sparse**: Sparse Vector Operations (Sparse Linear Algebra)
- **sqrt_newton**: Newton's Method Square Root (Math)
