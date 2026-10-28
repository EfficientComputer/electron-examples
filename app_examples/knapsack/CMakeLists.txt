add_eff_app(knapsack
    TYPE exe
    ARCHS e1x e1
    TARGETS fabric
    SOURCE main.c knapsack.c
)

eff_subtarget_compile_options(knapsack_fabric PRIVATE -DUSE_PRAGMAS --disable-memory-ordering --mof-passes=convert-parallel-for,lift-scf-parallel --disable-mof-option-exploration)
