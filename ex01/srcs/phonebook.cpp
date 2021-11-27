#include "phonebook.hpp"

int idx = 0;

profile::profile(void) : index(0), _contactNb(0), _firstName(""), _lastName(""), _nickname(""), _phoneNumber(""), _darkestSecret("")
{
    std::cout << "constructor called - profile created" << std::endl;
    return ;
}

profile::~profile(void)
{
    std::cout << "destructor called" << std::endl;
    return ;
}

void    profile::printContact(std::string str)
{
    int spaces(0);

    spaces = 10 - str.length();
    for (int x = 0; x < spaces; x++)
        std::cout << " ";
    if (str.length() <= 10)
        std::cout << str;
    else
        std::cout << str.substr(0, 9) << ".";
}

int profile::promptForIndex(void)
{
    std::string input("");

    std::cout << "Please enter index for contact details" << std::endl;
    getline(std::cin, input);
    if (input.at(0) >= 48 and input.at(0) <= 55 and input.length() == 1)
    {
        std::cout << "     index|     " << input.at(0) << std::endl;
        std::cout << "first name|     " << this[input.at(0) - 48]._firstName << std::endl;
        std::cout << " last name|     " << this[input.at(0) - 48]._lastName << std::endl;
        std::cout << " nickname |     " << this[input.at(0) - 48]._nickname << std::endl;
        std::cout << "phone num.|     " << this[input.at(0) - 48]._phoneNumber << std::endl;
        std::cout << "darkest s.|     " << this[input.at(0) - 48]._darkestSecret << std::endl;
        return 1;
    }
    if (input.compare("EXIT"))
    {
        std::cout << "Index must range from 0 to 7" << std::endl;
        return 1;
    }
    return 0;
}

int profile::do_print(profile *tmp) const
{
    int i = 0;

    std::cout << "     index|" << "first name|" << " last name|" \
        << "  nickname" << std::endl;
    for (i = 0; i < tmp->_contactNb; i++)
    {
        std::cout << "         " << i << "|";
        tmp[i].printContact(tmp[i]._firstName);
        std::cout << "|";
        tmp[i].printContact(tmp[i]._lastName);
        std::cout << "|";
        tmp[i].printContact(tmp[i]._nickname);
        std::cout << std::endl;
    }
    return 0;
}

int profile::do_add(profile *ind)
{
    std::string input("");

    std::cout << "Please enter first name" << std::endl;
    getline(std::cin, input);
    ind[ind->index]._firstName = input;
    std::cout << "Please enter last name" << std::endl;
    getline(std::cin, input);
    ind[ind->index]._lastName = input;
    std::cout << "Please enter _nickname" << std::endl;
    getline(std::cin, input);
    ind[ind->index]._nickname = input;
    std::cout << "Please enter phone number" << std::endl;
    getline(std::cin, input);
    ind[ind->index]._phoneNumber = input;
    std::cout << "Please enter darkest secret" << std::endl;
    getline(std::cin, input);
    ind[ind->index]._darkestSecret = input;
    ind[ind->index].index = ind->index;
    ind->index++;
    if (ind->index == 8)
        ind->index = 0;
    else
        ind->_contactNb = 8;
    if (ind->_contactNb != 8)
        ind->_contactNb = ind->index + 1;
    return 0;
}

int main(void)
{
    std::string  line;
    profile ind[8];

    while (std::cout << "Please type a command" << std::endl)
    {
        getline(std::cin, line);
        if (line == "ADD")
            ind->do_add(ind);
        else if (line == "EXIT")
            return 0 ;
        else if (line == "SEARCH")
        {
            ind->do_print(ind);
            if (!ind->promptForIndex())
                return 0;       
        }
        else
            std::cout << "Wrong entry" << std::endl;
    }
    return 0;
}