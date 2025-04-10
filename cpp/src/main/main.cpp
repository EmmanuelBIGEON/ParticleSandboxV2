#include <iostream>
#include <fmt/core.h>
#include <stdexcept>

#include "app/Application.h"

int main() {
    try {
        app::ParticleSandboxApplication app;    

        if(!app.Run())
            throw std::runtime_error("ParticleSandboxApplication failed to run");

    } catch(const std::exception& e) {
        fmt::print("Error: {}\n", e.what());
    }
}