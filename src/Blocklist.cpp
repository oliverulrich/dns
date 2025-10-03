#include "Blocklist.h"

#include <iostream>
#include <ranges>

void Blocklist::block(const std::string_view domain) {
    blocked.emplace(reverse_domain(domain));
}

bool Blocklist::is_blocked(const std::string_view domain) const {
    const auto reversed = reverse_domain(domain);

    for (auto end = reversed.size(); end != std::string::npos; end = reversed.rfind('.', end - 1)) {
        if (blocked.contains(reversed.substr(0, end)))
            return true;
    }

    return false;
};

std::string Blocklist::reverse_domain(std::string_view domain) {
    return domain
           | std::views::reverse
           | std::views::split('.')
           | std::views::transform(std::views::reverse)
           | std::views::join_with('.')
           | std::ranges::to<std::string>();
}
