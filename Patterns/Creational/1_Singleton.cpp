/*

More about Singleton Pattern: https://chatgpt.com/share/6996a7af-4bd4-800d-ba39-2a2ea25f8051

*/
#include <iostream>

class Singleton
{
private:
    Singleton();

public:
    static Singleton &getInstance()
    {
        static Singleton instance;
        return instance;
    }

    // Don't allow copying
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;
};

int main()
{

    return 0;
}