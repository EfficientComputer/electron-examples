add_eff_app(dmm_i8
    TYPE exe
    ARCHS e1x e1
    TARGETS fabric
    SOURCE main.c dmm.c
)

eff_subtarget_compile_options(dmm_i8_fabric PRIVATE -I ${CMAKE_SOURCE_DIR}/shared -DUSE_PRAGMAS --disable-memory-ordering)
