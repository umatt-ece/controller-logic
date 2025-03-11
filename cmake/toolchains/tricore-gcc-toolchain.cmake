# https://medium.com/@mimayuresh/organise-your-embedded-codebase-a-structured-approach-with-cmake-890fa038ef41
set(CMAKE_SYSTEM_NAME TriCore)

set(CMAKE_CROSSCOMPILING TRUE)

find_program(TRICORE_GCC_COMPILER NAMES tricore-gcc)
find_program(TRICORE_GPP_COMPILER NAMES tricore-g++)

if(NOT TRICORE_GCC_COMPILER)
    message(FATAL_ERROR "tricore-gcc not found!")
endif()

if(NOT TRICORE_GPP_COMPILER)
    message(FATAL_ERROR "tricore-g++ not found!")
endif()

set(CMAKE_C_COMPILER "${TRICORE_GCC_COMPILER}")
set(CMAKE_CXX_COMPILER "${TRICORE_GPP_COMPILER}")


# This will forcefully append the flags to the compiler
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mcpu=tc1798 -x c -DCONTROLLER_3CS" CACHE STRING "C compiler flags" FORCE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mcpu=tc1798 -x c++ -DCONTROLLER_3CS" CACHE STRING "C++ compiler flags" FORCE)

message(STATUS "Using C compiler: ${CMAKE_C_COMPILER}")
message(STATUS "Using CXX compiler: ${CMAKE_CXX_COMPILER}")
