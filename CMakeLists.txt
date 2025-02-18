# CMake project setups for the project and its dependencies
# Using the https://cliutils.gitlab.io/modern-cmake/chapters/basics.html as a reference
cmake_minimum_required(VERSION 3.15)

project(controller-logic VERSION 1.0
                  DESCRIPTION "Controller logic for the tractor 🚜🧑‍🌾"
                  LANGUAGES C CXX)

# Only do these if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    # Let's nicely support folders in IDEs
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
endif()

include(FetchContent)

add_subdirectory(src)

# Testing only available if this is the main app
# Emergency override MODERN_CMAKE_BUILD_TESTING provided as well
if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING)
   AND BUILD_TESTING)
  add_subdirectory(tests)
endif()

