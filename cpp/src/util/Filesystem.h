#pragma once

#include <string>

namespace util {
    void displayDirectory(const std::string& directory);
    bool readFileIfExists(const std::string& path, std::string& outContent);
}