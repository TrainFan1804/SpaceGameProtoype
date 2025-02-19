//
// Created by o.le on 19.02.25.
//

#ifndef DEBUG_H
#define DEBUG_H

#include <fstream>
#include <string>

namespace deb
{
    enum LogLevel
    {
        DEBUG, INFO, WARNING, ERROR
    };

    class Logger
    {
    public:
        static void init();
        static Logger &getInstance();
        static void shutdown();

        void log(const std::string &message);
        void log(const std::string &message, LogLevel status);
    private:
        Logger();
        ~Logger();
        std::ofstream _log_file;

        void setup();
        std::string getCurrentTimestamp(const std::string &format);
        std::string getStatusString();
    };

    std::string getStatusString(LogLevel level);
}

#endif //DEBUG_H
