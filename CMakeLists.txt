cmake_minimum_required(VERSION 3.0.0)
project(ditorender VERSION 0.1.0)

include(CTest)
enable_testing()

set (CMAKE_CXX_STANDARD 17)

add_executable(ditorender main.cpp src/util/tuple.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(
  hello_test
  hello_test.cpp
)
target_link_libraries(
  hello_test
  gtest_main
)

add_executable(
  util_tuple_test
  src/util/tuple_Test.cpp
  src/util/tuple.cpp
)
target_link_libraries(
  util_tuple_test
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)