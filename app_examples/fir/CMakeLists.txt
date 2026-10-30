add_eff_app(fir
    TYPE exe
    ARCHS e1x e1
    TARGETS fabric
    SOURCE main.c fir.c
)

eff_subtarget_compile_options(fir_fabric PRIVATE -DUSE_PRAGMAS)
