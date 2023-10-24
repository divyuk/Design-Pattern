#include <iostream>
#include <fstream>

class Logger
{
public:
    static Logger &getInstance()
    {
        static Logger instance; // Static instance created only once
        return instance;
    }

    void log(const std::string &message)
    {
        logFile << message << std::endl;
        std::cout << "Messages:" << message << std::endl;
        logFile.flush();
    }

private:
    // Private constructor to prevent external instantiation
    Logger()
    {
        logFile.open("log.txt", std::ios::out | std::ios::app);
        if (!logFile.is_open())
        {
            std::cerr << "Failed to open log file" << std::endl;
        }
        else
        {
            logFile << "Somethign" << std::endl;
            std::cout << "Writing Done\n";
        }
    }

    // Private copy constructor and copy assignment operator to prevent cloning
    Logger(const Logger &) = delete;
    Logger &operator=(const Logger &) = delete;

    std::ofstream logFile;
};

int main()
{
    Logger &logger = Logger::getInstance();

    logger.log("This is a log message.");
    logger.log("Another log message.");

    return 0;
}
