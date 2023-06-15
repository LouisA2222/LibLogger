#pragma once
#include <iostream>
#include <map>

class Logger
{
    private:
        std::map<std::string, std::string> _config = {
            {"info", "true"},
            {"warning", "true"},
            {"error", "true"},
            {"debug", "true"},
            {"writeInFile", "false"},
            {"fileName", "log.txt"},
            {"writeInConsole", "true"},
            {"defaultColor", "white"},
            {"defaultStyle", "reset"}
        };
        std::map<std::string, std::string> _colors = {
            {"red", "\033[31m"},
            {"green", "\033[32m"},
            {"yellow", "\033[33m"},
            {"blue", "\033[34m"},
            {"magenta", "\033[35m"},
            {"cyan", "\033[36m"},
            {"white", "\033[37m"},
            {"reset", "\033[0m"}
        };
        std::map<std::string, std::string> _style = {
            {"bold", "\033[1m"},
            {"dim", "\033[2m"},
            {"italic", "\033[3m"},
            {"underline", "\033[4m"},
            {"blink", "\033[5m"},
            {"reverse", "\033[7m"},
            {"hidden", "\033[8m"},
            {"reset", "\033[0m"}
        };
    public:
        Logger();
        ~Logger();
        void info(const char *msg, const char *file = "", const char *function = "", int line = 0);
        void warning(const char *msg, const char *file = "", const char *function = "", int line = 0);
        void error(const char *msg, const char *file = "", const char *function = "", int line = 0);
        void debug(const char *msg, const char *file = "", const char *function = "", int line = 0);

        // Getters
        std::map<std::string, std::string> getConfig() const;
        std::map<std::string, std::string> getColors() const;
        std::map<std::string, std::string> getStyle() const;

        // Setters
        void setConfig(std::map<std::string, std::string> config);
        void setConfig(const char *key, const char *value);
        void setColors(std::map<std::string, std::string> colors);
        void setStyle(std::map<std::string, std::string> style);
};

