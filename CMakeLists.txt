cmake_minimum_required(VERSION 3.0.0)
#set(VCPKG_DEFAULT_TRIPLET "x64-mingw-dynamic")
set(VCPKG_TARGET_TRIPLET "x64-mingw-dynamic")
#set(VCPKG_DEFAULT_HOST_TRIPLET "x64-mingw-dynamic")
#set(VCPKG_TARGET_ARCHITECTURE "x64-mingw-dynamic")
project(raytrace VERSION 0.0.1)


find_package(OpenGL REQUIRED)
find_path(STB_INCLUDE_DIRS "stb_c_lexer.h")
find_package(glfw3 CONFIG REQUIRED)
include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src
        ${OPENGL_INCLUDE_DIRS}  
        ${GLFW_INCLUDE_DIRS}
        ${STB_INCLUDE_DIRS}
)


file(GLOB_RECURSE sources ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_executable(raytrace ${sources})
#include(CTest)
#enable_testing()


target_link_libraries(raytrace PRIVATE 
        ${OPENGL_LIBRARIES} 
        ${GLFW_LIBRARIES}
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)