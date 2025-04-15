cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 23)

option(USE_GLFW "Enable GLFW support" ON)
option(USE_FMT "Enable FMT support" ON)
project(ParticleSandboxV2)

add_library(ParticleSandboxV2Lib)
target_sources(ParticleSandboxV2Lib
    PRIVATE
    src/app/Application.cpp
    src/core/Context.cpp
    src/core/Particle.cpp
    src/core/Simulation.cpp
    src/core/Solver.cpp
    src/graphics/Layout.cpp
    src/graphics/RenderEngine.cpp
    src/graphics/Renderer.cpp
    src/graphics/Scene.cpp
    src/graphics/View.cpp
    src/graphics/Window.cpp
    src/graphics/rhi/Shader.cpp
    src/graphics/rhi/VertexArray.cpp
    src/graphics/rhi/VertexBuffer.cpp
)

target_include_directories(ParticleSandboxV2Lib PUBLIC src)

if(USE_GLFW)
    target_compile_definitions(ParticleSandboxV2Lib PRIVATE USE_GLFW)
    find_package(glfw3 REQUIRED)
    target_link_libraries(ParticleSandboxV2Lib glfw)
endif()

if(USE_FMT)
    target_compile_definitions(ParticleSandboxV2Lib PRIVATE USE_FMT)
    find_package(fmt REQUIRED)
    target_link_libraries(ParticleSandboxV2Lib fmt::fmt)
endif()

find_package(glm REQUIRED)
target_link_libraries(ParticleSandboxV2Lib glm::glm)

if(1)
    target_compile_definitions(ParticleSandboxV2Lib PRIVATE USE_OPENGL)
    find_package(OpenGL REQUIRED)
    target_link_libraries(ParticleSandboxV2Lib OpenGL::GL)
        
    find_package(glad)
    target_link_libraries(ParticleSandboxV2Lib glad::glad)
endif()

# ParticleSandboxV2 executable
add_executable(ParticleSandboxV2 src/main/main.cpp)
target_link_libraries(ParticleSandboxV2 PRIVATE ParticleSandboxV2Lib)
install(TARGETS ParticleSandboxV2 DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_BUILD_TYPE})