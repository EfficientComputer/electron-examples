add_eff_app(conv5x5
    TYPE exe
    ARCHS e1x e1
    TARGETS fabric
    SOURCE main.c conv5x5.c
)

eff_subtarget_compile_options(conv5x5_fabric PRIVATE -DUSE_PRAGMAS)
