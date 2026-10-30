add_eff_app(dmv_fp
    TYPE exe
    ARCHS e1x e1
    TARGETS fabric
    SOURCE main.c dmv_fp.c
)

eff_subtarget_compile_options(dmv_fp_fabric PRIVATE -DUSE_PRAGMAS)
