add_eff_app(bfs
    TYPE exe
    ARCHS e1x e1
    TARGETS fabric
    SOURCE main.c bfs.c bfs_graph.c
)

eff_subtarget_compile_options(bfs_fabric PRIVATE -DUSE_PRAGMAS)

if(EFF_BLD_HAND_OPTIMIZED)
    eff_subtarget_compile_options(bfs_fabric PRIVATE --disable-memory-ordering)
endif()
