gtest_proj = subproject('gtest')

gtest_dep = gtest_proj.get_variable('gtest_main_dep')
gmock_dep = gtest_proj.get_variable('gmock_dep')

test_exe = executable(
    'magic_test',
    'test_easing_strategy.cpp',
    dependencies: [gtest_dep, gmock_dep, all_dep],
)
test('magic_test', test_exe)