cmake_minimum_required(VERSION 3.15)
project(SymCiSo)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_INCLUDE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/SymCiSo/vendor/mpir/include")
set(CMAKE_LIBRARY_PATH "${CMAKE_CURRENT_SOURCE_DIR}/SymCiSo/vendor/mpir/lib")

add_subdirectory(SymCiSo/vendor/symengine EXCLUDE_FROM_ALL)

add_executable(SymCiSo_Test 
    SymCiSo/src/main.cpp
)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT SymCiSo_Test)

target_link_libraries(SymCiSo_Test symengine)

target_include_directories(SymCiSo_Test PRIVATE SymCiSo/vendor/symengine)
target_include_directories(SymCiSo_Test PRIVATE ${CMAKE_BINARY_DIR}/SymCiSo/vendor/symengine)
target_include_directories(SymCiSo_Test PRIVATE ${CMAKE_BINARY_DIR}/SymCiSo/vendor/symengine/symengine/utilities/teuchos)
target_include_directories(SymCiSo_Test PRIVATE SymCiSo/vendor/mpir/include)


set(MSVC_USE_MT yes CACHE BOOL "Use MT flags when compiling in MSVC")
set(MSVC_WARNING_LEVEL 1 CACHE STRING "MSVC warning level")

set(DLL_SOURCE_PATH "${CMAKE_SOURCE_DIR}/SymCiSo/vendor/mpir/bin/mpir.dll")
set(DLL_DESTINATION_PATH "${CMAKE_BINARY_DIR}")
configure_file(${DLL_SOURCE_PATH} ${DLL_DESTINATION_PATH} COPYONLY)
