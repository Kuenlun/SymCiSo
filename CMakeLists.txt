cmake_minimum_required(VERSION 3.0)
project(SymCiSo)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(SymCiSo/vendor/symengine EXCLUDE_FROM_ALL)

add_executable(SymCiSo_Test 
    SymCiSo/src/main.cpp
)

target_link_libraries(SymCiSo_Test symengine)

target_include_directories(SymCiSo_Test PRIVATE SymCiSo/vendor/symengine)
target_include_directories(SymCiSo_Test PRIVATE ${CMAKE_BINARY_DIR}/SymCiSo/vendor/symengine)
target_include_directories(SymCiSo_Test PRIVATE ${CMAKE_BINARY_DIR}/SymCiSo/vendor/symengine/symengine/utilities/teuchos)
