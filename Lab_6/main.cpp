#include <iostream>
#include<Logger.h>
#include<Windows.h>

HANDLE hConsole;

enum class ColorConsole
{
    RED = 4,
    YELLOW = 14
};

int main()
{
    Logger::SetLogPath("log.txt");
    Logger::SetLogLevel(LogLevel::DEBUG);
    //hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //SetConsoleTextAttribute(hConsole, static_cast<int>(ColorConsole::YELLOW));
    Logger::Write("Hi!");
    //SetConsoleTextAttribute(hConsole, static_cast<int>(ColorConsole::RED));
    Logger::Write("Hi!", LogStatus::warning);
    Logger::Write("GFDHG!", LogStatus::error);
    return 0;
}
