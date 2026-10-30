add_eff_app(dmv
    TYPE exe
    ARCHS e1x e1
    TARGETS fabric
    SOURCE main.c dmv.c
)

eff_subtarget_compile_options(dmv_fabric PRIVATE -I ${CMAKE_SOURCE_DIR}/shared -DUSE_PRAGMAS)
