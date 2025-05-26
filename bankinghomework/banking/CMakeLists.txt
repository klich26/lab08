cmake_minimum_required(VERSION 3.10)

project(banking LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


option(CODE_COVERAGE "Enable coverage" ON)
if(CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(--coverage)
    link_libraries(--coverage)
endif()

include_directories(include)


add_library(banking STATIC
   sources/Account.cpp
    sources/Transaction.cpp
)


add_subdirectory(third-party/gtest)

enable_testing()
add_subdirectory(tests)
