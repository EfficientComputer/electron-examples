add_eff_app(conv3x3_dw
    TYPE exe
    ARCHS e1x e1
    TARGETS fabric
    SOURCE main.c conv3x3_dw.c
)

eff_subtarget_compile_options(conv3x3_dw_fabric PRIVATE -DUSE_PRAGMAS --disable-memory-ordering)
