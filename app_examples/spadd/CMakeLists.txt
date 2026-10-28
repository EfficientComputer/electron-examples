add_eff_app(spadd
    TYPE exe
    ARCHS e1x e1
    TARGETS fabric
    SOURCE main.c spadd.c
)

eff_subtarget_compile_options(spadd_fabric PRIVATE -I ${CMAKE_SOURCE_DIR}/shared -DUSE_PRAGMAS --disable-memory-ordering --mof-passes=convert-parallel-for,lift-scf-parallel --disable-mof-option-exploration)
