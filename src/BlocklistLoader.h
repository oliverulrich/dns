#ifndef DNS_BLOCKLIST_LOADER_H
#define DNS_BLOCKLIST_LOADER_H

#include <filesystem>

#include "Blocklist.h"

class BlocklistLoader {
public:
    static Blocklist from_file(std::filesystem::path &path);
};

#endif //DNS_BLOCKLIST_LOADER_H
