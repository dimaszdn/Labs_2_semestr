#include<Logger.h>

int main()
{

    ch::Logger::SetLogPath("log.txt");
    ch::Logger::SetLogLevel(ch::LogLevel::DEBUG);
    ch::Logger::Write("Crash", ch::LogStatus::error);
    ch::Logger::Write("Problem", ch::LogStatus::warning);
    return 0;
}
