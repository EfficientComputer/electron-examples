add_eff_app(dmm
    TYPE exe
    ARCHS e1x e1
    TARGETS fabric
    SOURCE main.c dmm.c
)

eff_subtarget_compile_options(dmm_fabric PRIVATE -I ${CMAKE_SOURCE_DIR}/shared -DUSE_PRAGMAS --disable-memory-ordering)
