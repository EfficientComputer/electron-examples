add_eff_app(isqrt
    TYPE exe
    ARCHS e1x e1
    TARGETS fabric
    SOURCE main.c isqrt.c
)

eff_subtarget_compile_options(isqrt_fabric PRIVATE -DUSE_PRAGMAS)
