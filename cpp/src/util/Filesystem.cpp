#include "Filesystem.h"

#include <filesystem>
#include <fmt/core.h>

using namespace util;
namespace fs = std::filesystem;

void util::displayDirectory(const std::string& directory)
{
    try {
        fs::path dirPath(directory);

        if (!fs::exists(dirPath)) {
            fmt::print(stderr, "❌ Le répertoire n'existe pas : {}\n", directory);
            return;
        }

        if (!fs::is_directory(dirPath)) {
            fmt::print(stderr, "⚠️  Ce n'est pas un répertoire : {}\n", directory);
            return;
        }

        for (const auto& entry : fs::directory_iterator(dirPath)) {
            const auto& path = entry.path();
            const bool isDir = fs::is_directory(path);
            fmt::print("{} {}\n", isDir ? "📁" : "📄", path.filename().string());
        }
    }
    catch (const fs::filesystem_error& e) {
        fmt::print(stderr, "💥 Erreur filesystem : {}\n", e.what());
    }
}