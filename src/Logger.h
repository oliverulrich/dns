#ifndef DNS_LOGGER_H
#define DNS_LOGGER_H

#include <iostream>

class Logger {
public:
    enum class Level {
        Debug,
        Info,
        Warning,
        Error,
    };

    explicit Logger(std::ostream &out = std::cout, Level min_level = Level::Info);

    void log(Level level, std::string_view msg) const;

    void debug(std::string_view msg) const;

    void info(std::string_view msg) const;

    void warning(std::string_view msg) const;

    void error(std::string_view msg) const;

private:
    static std::string_view level_to_str(Level level) noexcept;

    std::ostream &out;
    Level min_level;
};

#endif // DNS_LOGGER_H
