add_eff_app(quickstart
    TYPE exe
    ARCHS e1x e1
    TARGETS fabric
    SOURCE main.c
)

eff_subtarget_compile_options(quickstart_fabric PRIVATE -DUSE_PRAGMAS)
