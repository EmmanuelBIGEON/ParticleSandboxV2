cmake_minimum_required(VERSION 3.28)

# Even if it can't be optional for now.
option(USE_GLFW "Enable GLFW support" ON)
option(USE_FMT "Enable FMT support" ON)

project(ParticleSandboxV2)

set(SOURCES
    src/main/main.cpp
    src/app/Application.cpp
    src/graphics/Window.cpp
)
add_executable(ParticleSandboxV2 ${SOURCES})

set_property(TARGET ParticleSandboxV2 PROPERTY CXX_STANDARD 23)

# GLFW
if(USE_GLFW)
    target_compile_definitions(ParticleSandboxV2 PRIVATE USE_GLFW)
    find_package(glfw3 REQUIRED)
    target_include_directories(ParticleSandboxV2 PUBLIC ${glfw3_INCLUDE_DIRS})
    target_link_libraries(ParticleSandboxV2 glfw)
endif()

# FMT
if(USE_FMT)
    target_compile_definitions(ParticleSandboxV2 PRIVATE USE_FMT)
    find_package(fmt REQUIRED)
    target_include_directories(ParticleSandboxV2 PUBLIC ${fmt_INCLUDE_DIRS})
    target_link_libraries(ParticleSandboxV2 fmt::fmt)
endif()

install(TARGETS ParticleSandboxV2 DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_BUILD_TYPE})