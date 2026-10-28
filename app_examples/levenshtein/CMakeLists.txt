add_eff_app(levenshtein
    TYPE exe
    ARCHS e1x e1
    TARGETS fabric
    SOURCE main.c levenshtein.c
)

eff_subtarget_compile_options(levenshtein_fabric PRIVATE -DUSE_PRAGMAS)

if(EFF_BLD_HAND_OPTIMIZED)
    eff_subtarget_compile_options(levenshtein_fabric PRIVATE --pnr-rounds=8)
endif()
