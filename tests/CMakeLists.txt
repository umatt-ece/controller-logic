FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/6910c9d9165801d8827d628cb72eb7ea9dd538c5.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(testlib hello_test.cc)  # Ensure this matches your test source

target_link_libraries(testlib GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(testlib)  # Match the executable name here