#include "Logger.hpp"

Logger::Logger()
{
}

Logger::~Logger()
{
}

/// @brief Logger info function (print in green)
/// @param msg 
/// @param file can be empty (nullptr or "")
/// @param function can be empty (nullptr or "")
/// @param line can be empty (0)
void Logger::info(const char *msg, const char *file, const char *function, int line)
{
    if (this->_config["info"] == "true" && this->_config["writeInConsole"] == "true")
    {
        std::cout << this->_colors["green"] << this->_style["bold"] << "[INFO] " << this->_style["reset"] << msg
                  << (file && file[0] != '\0' ? " (in " + std::string(file) : "")
                  << (function && function[0] != '\0' ? " in " + std::string(function) : "")
                  << (line != 0 ? " at line " + std::to_string(line) + ")" : "")
                  << std::endl;
    }
}

/// @brief Logger warning function (print in yellow)
/// @param msg
/// @param file can be empty (nullptr or "")
/// @param function can be empty (nullptr or "")
/// @param line can be empty (0)
void Logger::warning(const char *msg, const char *file, const char *function, int line)
{
    if (this->_config["warning"] == "true" && this->_config["writeInConsole"] == "true")
    {
        std::cout << this->_colors["yellow"] << this->_style["bold"] << "[WARNING] " << this->_style["reset"] << msg
                  << (file && file[0] != '\0' ? " (in " + std::string(file) : "")
                  << (function && function[0] != '\0' ? " in " + std::string(function) : "")
                  << (line != 0 ? " at line " + std::to_string(line) + ")" : "")
                  << std::endl;
    }
}

/// @brief Logger error function (print in red)
/// @param msg
/// @param file can be empty (nullptr or "")
/// @param function can be empty (nullptr or "")
/// @param line can be empty (0)
void Logger::error(const char *msg, const char *file, const char *function, int line)
{
    if (this->_config["error"] == "true" && this->_config["writeInConsole"] == "true")
    {
        std::cout << this->_colors["red"] << this->_style["bold"] << "[ERROR] " << this->_style["reset"] << msg
                  << (file && file[0] != '\0' ? " (in " + std::string(file) : "")
                  << (function && function[0] != '\0' ? " in " + std::string(function) : "")
                  << (line != 0 ? " at line " + std::to_string(line) + ")" : "")
                  << std::endl;
    }
}

/// @brief Logger debug function (print in blue)
/// @param msg
/// @param file can be empty (nullptr or "")
/// @param function can be empty (nullptr or "")
/// @param line can be empty (0)
void Logger::debug(const char *msg, const char *file, const char *function, int line)
{
    if (this->_config["debug"] == "true" && this->_config["writeInConsole"] == "true")
    {
        std::cout << this->_colors["blue"] << this->_style["bold"] << "[DEBUG] " << this->_style["reset"] << msg
                  << (file && file[0] != '\0' ? " (in " + std::string(file) : "")
                  << (function && function[0] != '\0' ? " in " + std::string(function) : "")
                  << (line != 0 ? " at line " + std::to_string(line) + ")" : "")
                  << std::endl;
    }
}

///@section: getters

/// @brief Get the config map
/// @return std::map<std::string, std::string>
std::map<std::string, std::string> Logger::getConfig() const
{
    return this->_config;
}

/// @brief Get the colors map
/// @return std::map<std::string, std::string>
std::map<std::string, std::string> Logger::getColors() const
{
    return this->_colors;
}

/// @brief Get the style map
/// @return std::map<std::string, std::string>
std::map<std::string, std::string> Logger::getStyle() const
{
    return this->_style;
}

///@section: setters
/// @brief Set the config map
/// @param config
void Logger::setConfig(std::map<std::string, std::string> config)
{
    this->_config = config;
}

/// @brief Set the config option
/// @param key
/// @param value
void Logger::setConfig(const char *key, const char *value)
{
    std::string keyStr = key;
    std::string valueStr = value;
    this->_config[keyStr] = valueStr;
}

/// @brief Set the colors map
/// @param colors
void Logger::setColors(std::map<std::string, std::string> colors)
{
    this->_colors = colors;
}

/// @brief Set the style map
/// @param style
void Logger::setStyle(std::map<std::string, std::string> style)
{
    this->_style = style;
}

