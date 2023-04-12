#pragma once
#include<fstream>
#include<string>
#include<iostream>
#include<chrono>
#include<ctime>
#include<sstream>
#include<iomanip>
#include<Windows.h>

namespace ch
{
    enum class LogLevel
    {
        DEBUG,
        RELEASE
    };

    enum class LogStatus
    {
        info,
        warning,
        error
    };

    enum class Color
    {
        RED = 4,
        YELLOW = 14,
        WHITE = 7
    };

    class Logger
    {
    private:
        static std::ofstream m_out;
        static LogLevel m_logLevel;
        static LogStatus m_logStatus;

    public:
        static void SetLogPath(const std::string& path)
        {
            m_out.open(path);
        }

        static void SetLogLevel(LogLevel logLevel)
        {
            m_logLevel = logLevel;
        }

        static std::string status(const LogStatus st)
        {
            m_logStatus = st;
            switch(m_logStatus)
            {
                case LogStatus::info:
                    return "INFO";
                case LogStatus::warning:
                    return "WARNING";
                case LogStatus::error:
                    return "ERROR";
                default:
                    return "NO STATUS";
            }
        }

        static std::string timestamp()
        {
            auto now = std::chrono::system_clock::now();
            time_t tt = std::chrono::system_clock::to_time_t(now);
            std::stringstream ss;
            ss << std::put_time(std::localtime(&tt), "%F %T");
            return ss.str();
        }

        static std::string WrapBlock(const std::string& val)
        {
            return "[" + val + "] ";
        }

        static void Write(const std::string& msg, const LogStatus st = LogStatus::info)
        {
            std::string result = WrapBlock(timestamp()) + WrapBlock(status(st)) + WrapBlock(msg);
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            if (m_logLevel == LogLevel::DEBUG)
            {
                m_out << result << "\n";
                switch(m_logStatus)
                {
                    case LogStatus::error:
                    {
                        SetConsoleTextAttribute(hConsole, static_cast<int>(Color::RED));
                        std::cout << result << "\n";
                        break;
                    }
                    case LogStatus::warning:
                    {
                        SetConsoleTextAttribute(hConsole, static_cast<int>(Color::YELLOW));
                        std::cout << result << "\n";
                        break;
                    }
                    case LogStatus::info:
                    {
                        SetConsoleTextAttribute(hConsole, static_cast<int>(Color::WHITE));
                        std::cout << result << "\n";
                        break;
                    }
                    default:
                        break;
                }
            }
            if (m_logLevel == LogLevel::RELEASE)
            {
                m_out << result << "\n";
            }
        }
    };
}