//
// Created by o.le on 19.02.25.
//

#include "core/debug/Debug.h"

#include <cassert>
#include <iomanip>
#include <sstream>
#include <filesystem>

namespace deb
{
    static Logger *LOGGER = nullptr;

    namespace
    {
        const auto BASE_PATH = std::string(LOG_FILE_PATH);

        std::string getStatusString(LogLevel status)
        {
            switch (status)
            {
            case DEBUG: return "DEBUG";
            case INFO: return "INFO";
            case WARNING: return "WARNING";
            case ERROR: return "ERROR";
            default: return "UNKNOWN";
            }
        }

        std::string getCurrentTimestamp(const std::string &format)
        {
            auto time_now = std::time(nullptr);
            auto tm = *std::localtime(&time_now);

            std::ostringstream oss;
            oss << std::put_time(&tm, format.c_str());
            return oss.str();
        }
    }

    void Logger::init()
    {
        assert(!LOGGER);
        LOGGER = new Logger();
    }

    Logger &Logger::getInstance()
    {
        assert(LOGGER);
        return *LOGGER;
    }

    void Logger::shutdown()
    {
        delete LOGGER;
        LOGGER = nullptr;
    }

    void Logger::log(const std::string &msg)
    {
        log(msg, DEBUG);
    }

    void Logger::log(const std::string &message, LogLevel status)
    {
        std::string timestamp = getCurrentTimestamp("%Y-%m-%d %H:%M:%S");
        std::string formatted_message = "[" + timestamp + "] " +
            deb::getStatusString(status) + ": " + message;
        _log_file << formatted_message << std::endl;
    }

    Logger::Logger()
    {
        setup();
        std::string date = getCurrentTimestamp("%Y-%m-%d");
        _log_file.open(BASE_PATH + date + ".log", std::ios::app);
        if (!_log_file.is_open()) throw std::runtime_error("Couldn't open log file");
    }

    void Logger::setup()
    {
        if (!std::filesystem::exists(BASE_PATH))
        {
            std::filesystem::create_directory(BASE_PATH);
        }
    }

    Logger::~Logger()
    {
        if (_log_file.is_open())
        {
            _log_file.close();
        }
    }
}
