#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <stdio.h>

using namespace std;

int ArrayAbsurdity(char* buf)
{
    char* numberOfElements = nullptr;
    char* numberString = nullptr;

    numberOfElements = strtok(buf, ";");
    if (!numberOfElements)
    {
        return -1;
    }

    int number = atoi(numberOfElements);
    int sumExpected = 
}

int ArrayAbsurdity(string line)
{
    char buf[4096];
    if (line.length() > 4096)
    {
        return -1;
    }

    memset(buf, 0, sizeof(buf));
    strcpy(buf, line.c_str());
    return ArrayAbsurdity(buf);
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        return -1;
    }
    ifstream inputFile(argv[1]);
    string line;

    if (inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            if (line.length() == 0)
            {
                continue;
            }
            cout << ArrayAbsurdity(line) << endl;
        }
        inputFile.close();
    }

}

