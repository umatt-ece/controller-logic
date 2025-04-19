project(
  'controller-logic',
  'c',
  version: '0.1',
  default_options: ['warning_level=3'],
)

project_sources = files(
  'src/easing/easing_out_cubic.c',
  'src/easing/easing_out_sin.c',
  'src/easing/easing_strategy.c',
)

include = include_directories('src/easing')

liball = static_library(meson.project_name(), project_sources, include_directories: include)

all_dep = declare_dependency(
  link_with: liball,
  include_directories: include,
)

subdir('test')