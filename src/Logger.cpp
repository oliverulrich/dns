#include "Logger.h"

#include <chrono>
#include <format>

Logger::Logger(std::ostream &out, const Level min_level) : out(out), min_level(min_level) {
}

void Logger::log(const Level level, std::string_view msg) const {
    if (level < min_level)
        return;

    const auto now = std::chrono::system_clock::now();
    auto local = std::chrono::zoned_time{std::chrono::current_zone(), now};
    auto level_str = level_to_str(level);

    out << std::format("[{:%F %T}] [{}] {}\n", local, level_str, msg);
}

void Logger::debug(const std::string_view msg) const {
    log(Level::Debug, msg);
}

void Logger::info(const std::string_view msg) const {
    log(Level::Info, msg);
}

void Logger::warning(const std::string_view msg) const {
    log(Level::Warning, msg);
}

void Logger::error(const std::string_view msg) const {
    log(Level::Error, msg);
}

std::string_view Logger::level_to_str(const Level level) noexcept {
    switch (level) {
        case Level::Debug: return "DEBUG";
        case Level::Info: return "INFO";
        case Level::Warning: return "WARNING";
        case Level::Error: return "ERROR";
        default: return "UNKNOWN";
    }
}
