add_eff_app(dijkstras
    TYPE exe
    ARCHS e1x e1
    TARGETS fabric
    SOURCE main.c dijkstras.c graph.c
)

eff_subtarget_compile_options(dijkstras_fabric PRIVATE -DUSE_PRAGMAS)
