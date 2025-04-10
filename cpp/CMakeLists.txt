cmake_minimum_required(VERSION 3.28)

find_package(fmt REQUIRED)

project(ParticleSandboxV2)

set(SOURCES
    src/main/main.cpp
    src/app/Application.cpp
)
add_executable(ParticleSandboxV2 ${SOURCES})

set_property(TARGET ParticleSandboxV2 PROPERTY CXX_STANDARD 23)

target_include_directories(ParticleSandboxV2 PUBLIC ${fmt_INCLUDE_DIRS})
target_link_libraries(ParticleSandboxV2 fmt::fmt)

install(TARGETS ParticleSandboxV2 DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_BUILD_TYPE})