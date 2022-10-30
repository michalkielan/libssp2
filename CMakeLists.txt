project(ssp2)
cmake_minimum_required(VERSION 3.5)

set(CMAKE_BUILD_TYPE Debug)
set(TARGET_NAME ssp2)

add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories(include)

add_library(${TARGET_NAME} SHARED src/ssp.cpp)

set(LINKER_FLAGS -Wl,--gc-sections)

set(DEPS pthread rt dl)

if(UNIX AND NOT APPLE)
    set(PLATFORM linux_x64)
endif()

target_compile_options(${TARGET_NAME} PRIVATE -fpie)

target_link_libraries(
    ${TARGET_NAME}
    PUBLIC -Wl,--whole-archive
    ${DEPS}
    ${CMAKE_SOURCE_DIR}/lib/${PLATFORM}/libssp.so
    -Wl,--no-whole-archive
    ${LINKER_FLAGS}
)
