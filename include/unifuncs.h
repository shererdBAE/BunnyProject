#pragma once
#include <iostream>
#include <string>

namespace uni
{
    int checknum();

    int checkrange (int, int);

    int checkpositive ();

    void cont();

    std::string firstwordin();

    void buffclear();

    std::string getline();

    std::string reverse_string (std::string);

    std::string reverse_string();

    void newlines(int numberoflines);

    char waitforcharinput(int seconds);
}