cmake_minimum_required(VERSION 3.14)
set(Name DivideAndCoquer)
project(${Name})
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

enable_testing()

set(INCLUDE_DIR 
    "${CMAKE_CURRENT_SOURCE_DIR}/"
)

set(HEADERS
    Account.hpp
    Bank.hpp
)

# Source files
set(SOURCE_FILES
    Account.cpp
    Bank.cpp
)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_include_directories(${Name} PUBLIC ${INCLUDE_DIR})

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)

FetchContent_MakeAvailable(googletest)

enable_testing()
find_package(GTest REQUIRED)
include(GoogleTest)

set(AccountSrc Tests/AccountTests.cpp)
set(BankSrc Tests/BankTests.cpp)

add_executable(
	AccountTest
	${AccountSrc}
)

add_executable(
	BankTest
	${BankSrc}
)

target_link_libraries(
	AccountTest
	${Name}
    GTest::gtest_main
)


target_link_libraries(
	BankTest
	${Name}
    GTest::gtest_main
)

gtest_discover_tests(AccountTest)
gtest_discover_tests(BankTest)