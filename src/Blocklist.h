#ifndef DNS_DOMAIN_BLOCKLIST_H
#define DNS_DOMAIN_BLOCKLIST_H

#include <string_view>
#include <unordered_set>
#include <string>

class Blocklist {
public:
    void block(std::string_view domain);

    bool is_blocked(std::string_view domain) const;

private:
    static std::string reverse_domain(std::string_view domain);

    std::unordered_set<std::string> blocked;
};

#endif //DNS_DOMAIN_BLOCKLIST_H
