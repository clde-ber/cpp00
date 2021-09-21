#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>
#include <cstring>
#include <iostream>

class   profile
{
    std::string index;
    std::string fist_name;
    std::string last_name;
    std::string nickname;
};

class   profile_list
{
    int     line_length;
    char    separator;
    char    eol;
};

#endif
