gtest_proj = subproject('gtest')

gtest_dep = gtest_proj.get_variable('gtest_main_dep')
gmock_dep = gtest_proj.get_variable('gmock_dep')

test_exe = executable(
    'magic_test',
    'test.cpp',
    dependencies: [gtest_dep, gmock_dep],
)
test('magic_test', test_exe)