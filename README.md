
# UltimateLog
The ultimate Logger Lib, for C++

---

## Functions :
```CPP
void Logger::info(const char *msg, const char *file, const char *function, int line);

void Logger::info(std::string *msg, const char *file, const char *function, int line);

void Logger::info(std::string msg, const char *file, const char *function, int line);

/// Same functions exists for warning, werror, debug and success.
```

## Options :

the options list is :
```C
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
```
if you need to change one option, for exemple, to dont display info on production :
```CPP
void Logger::setConfig(const char *key, const char *value)
//FOR example : log.setConfig("info", "false");
```

## Installation :

<b>Only works with Makefile for the moment</b>

for a global install :
```bash
git clone https://github.com/LouisA2222/LibLogger.git
cd LibLogger
make install
```

for a local install on your repo :
```bash
git clone https://github.com/LouisA2222/LibLogger.git
cd LibLogger
make
```
(this will build the lib, its up to you to move it to your directory)

Credits : Me.