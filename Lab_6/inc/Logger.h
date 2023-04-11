#pragma once
#include<fstream>
#include<string>
#include<iostream>
#include<chrono>
#include<ctime>
#include<sstream>
#include<iomanip>

/*Если ERROR, то использовать cerr*/

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
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
        std::stringstream ss;
        ss << std::put_time(std::localtime(&tt), "%F %T");
        return ss.str();
    }

    static std::string WrapBlock(const std::string& val, const std::string& prefix = "[", const std::string& sufix = "]")
    {
        return prefix + val + sufix;
    }

    static void Write(const std::string& msg, const LogStatus st = LogStatus::info)
    {
        std::string result = WrapBlock(timestamp()) + WrapBlock(status(st)) + WrapBlock(msg);
        if (m_logLevel == LogLevel::DEBUG)
        {
            std::cout << result << "\n";
            m_out << result << "\n";
        }
        if (m_logLevel == LogLevel::RELEASE)
        {
            m_out << result << "\n";
        }
    }
};