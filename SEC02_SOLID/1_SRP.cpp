#include <iostream>
#include <vector>
#include <fstream>
#include <string>

struct Journal
{
    std::string _title;
    std::vector<std::string> _entries;

    Journal(std::string title) : _title{title}
    {
    }

    void addEntry(const std::string &message)
    {
        static int count = 1;
        _entries.push_back(std::to_string(count++) + ":" + message);
    }

    // Here the class is performing two tasks
    // void saveEntry(const std::string &fileName)
    // {
    //     std::ofstream ofs(fileName);
    //     if (ofs.is_open())
    //     {
    //         for (const auto &entry : _entries)
    //         {
    //             ofs << entry;
    //         }
    //     }
    //     else
    //     {
    //         std::cerr << "File Not Opened for write operation" << std::endl;
    //     }
    // }
};

// Here SaveJournal has a onky single responsibility of saving entries
struct SaveJournal
{
    void saveEntry(const Journal &j, const std::string &fileName)
    {
        std::ofstream ofs(fileName, std::ios::out);
        if (ofs.is_open())
        {
            ofs << j._title << std::endl;
            for (const auto &entry : j._entries)
            {
                ofs << entry << std::endl;
            }
        }
        else
        {
            std::cerr << "File Not Opened for write operation" << std::endl;
        }
    }
};

int main()
{
    Journal j("Vamsi Journal");
    j.addEntry("Today i Learned Solid Principle");
    j.addEntry("Slept for few hours unnecessarily");
    // j.saveEntry("VamsiJournal.txt");

    SaveJournal sj;
    sj.saveEntry(j, "VamsiVlog");

    return 0;
}