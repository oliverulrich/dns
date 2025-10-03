#include "BlocklistLoader.h"

#include <fstream>

Blocklist BlocklistLoader::from_file(std::filesystem::path &path) {
    std::ifstream file(path);
    if (!file)
        throw std::runtime_error("Failed to open blocklist file: " + path.string());

    Blocklist blocklist;

    std::string line;
    while (std::getline(file, line)) {
        if (line.starts_with('#'))
            continue;

        blocklist.block(line);
    }

    return blocklist;
}
