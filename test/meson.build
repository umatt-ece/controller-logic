gtest_proj = subproject('gtest')

gtest_dep = gtest_proj.get_variable('gtest_main_dep')
gmock_dep = gtest_proj.get_variable('gmock_dep')

test_project_sources = [
    'test_easing_strategy.cpp',
]

test_exe = executable(
    meson.project_name() + '_test',
    test_project_sources,
    dependencies: [gtest_dep, gmock_dep, all_dep],
)
test(meson.project_name() + '_test', test_exe)