cmake_minimum_required(VERSION 3.15)
project(SymCiSo)

set(CMAKE_CXX_STANDARD 20)

# SymCiSo executable
add_executable(${PROJECT_NAME} 
    SymCiSo/src/main.cpp
    SymCiSo/src/core/log.h
    SymCiSo/src/core/log.cpp
    SymCiSo/src/components/impedance.h
    SymCiSo/src/components/impedance.cpp
    SymCiSo/src/node.h 
    SymCiSo/src/node.cpp
    SymCiSo/src/components/component.h
    SymCiSo/src/components/component.cpp
    SymCiSo/src/circuit.h
    SymCiSo/src/circuit.cpp 
    SymCiSo/src/core/core.h
    SymCiSo/src/connection.h
    SymCiSo/include/symciso.h "SymCiSo/src/voltage_diff.h")
 
target_include_directories(${PROJECT_NAME} PRIVATE SymCiSo/src)
target_include_directories(${PROJECT_NAME} PRIVATE SymCiSo/include)
# Set SymCiSo executable as the default project
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

# Used to include GMP (MPIR) library required by SymEngine
set(CMAKE_INCLUDE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/SymCiSo/vendor/mpir/include")
set(CMAKE_LIBRARY_PATH "${CMAKE_CURRENT_SOURCE_DIR}/SymCiSo/vendor/mpir/lib")
# MPIR DLL requirrd by the final executable
set(DLL_SOURCE_PATH "${CMAKE_SOURCE_DIR}/SymCiSo/vendor/mpir/bin/mpir.dll")
set(DLL_DESTINATION_PATH "${CMAKE_BINARY_DIR}")
configure_file(${DLL_SOURCE_PATH} ${DLL_DESTINATION_PATH} COPYONLY)

# SymEngine dependency
add_subdirectory(SymCiSo/vendor/symengine EXCLUDE_FROM_ALL)
target_link_libraries(${PROJECT_NAME} symengine)
target_include_directories(${PROJECT_NAME} PRIVATE SymCiSo/vendor/symengine)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_BINARY_DIR}/SymCiSo/vendor/symengine)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_BINARY_DIR}/SymCiSo/vendor/symengine/symengine/utilities/teuchos)
target_include_directories(${PROJECT_NAME} PRIVATE SymCiSo/vendor/mpir/include)
set(MSVC_USE_MT yes CACHE BOOL "Use MT flags when compiling in MSVC")
set(MSVC_WARNING_LEVEL 1 CACHE STRING "MSVC warning level")

# spdlog dependency
target_include_directories(${PROJECT_NAME} PRIVATE SymCiSo/vendor/spdlog/include)
