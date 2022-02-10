miok_dlist_lib = static_library('miok',
    'package.c',
    include_directories: inc_dir,
    gnu_symbol_visibility: 'hidden',
    install: true)

miok_dlist_dep = declare_dependency(
    link_with: miok_dlist_lib,
    include_directories: inc_dir)
