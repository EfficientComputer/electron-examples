add_eff_app(hello
    TYPE exe
    ARCHS e1x e1
    TARGETS fabric
    SOURCE hello.c
)

eff_subtarget_compile_options(hello_fabric PRIVATE -DUSE_PRAGMAS)
