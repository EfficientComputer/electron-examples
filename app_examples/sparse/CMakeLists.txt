add_eff_app(sparse
    TYPE exe
    ARCHS e1x e1
    TARGETS fabric
    SOURCE main.c svec.c
)

eff_subtarget_compile_options(sparse_fabric PRIVATE -DUSE_PRAGMAS)
