#include <iostream>
#include <fstream>

class Logger
{
private:
    std::ofstream logFile;
    Logger()
    {
        logFile.open("app.log", std::ios::trunc);
    }

    ~Logger()
    {
        logFile.close();
    }

public:
    // Don't allow copy operations
    Logger(const Logger &) = delete;
    Logger &operator=(const Logger &) = delete;

    static Logger &getInstance()
    {
        static Logger instance;
        return instance;
    }

    void log(const std::string &msg)
    {
        logFile << msg << std::endl;
    }
};

class Another
{

public:
    Another()
    {
        Logger::getInstance().log("Another class Constructor");
    }
};

int main()
{
    Logger::getInstance().log("Program Started");
    Another a;
    return 0;
}