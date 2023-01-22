#include "Func.h"

std::string currentDateTime() {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    char buffer[128];
    strftime(buffer, sizeof(buffer), "%m-%d-%Y %X", now);
    return buffer;
}

string GetPosition(int position)
{
    switch (Position(position))
    {
    case Position::Guest:
        return "Geust";
    case Position::Admin:
        return "Admin";
    case Position::Manager:
        return "Manager";
    case Position::Director:
        return "Director";
    default:
        throw exception("Wrong position!\n");
        break;
    }
}
int verificateNum(int leftRange, int rightRange)
{
    int num;
    while (!(cin >> num) || (num < leftRange) || (rightRange < num))
    {
        cin.clear();
        while (cin.get() != '\n')
            continue;
    }
    return num;
}