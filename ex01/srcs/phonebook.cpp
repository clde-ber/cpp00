#include "phonebook.hpp"

int idx = 0;

profile::profile(void) : index(0), contact_nb(0), first_name(""), last_name(""), nickname(""), phone_number(""), darkest_secret("")
{
    std::cout << "constructor called" << std::endl;
    return ;
}

profile::~profile(void)
{
    std::cout << "destructor called" << std::endl;
    return ;
}

profile_list::profile_list(int ll, char sp, char el, profile *pl) : line_length(ll), separator(sp), eol(el)
{
    profile tmp;
    for (int i = 0; i < 8; i++)
        pl[i] = tmp;
    std::cout << "constructor called" << std::endl;
    return ;
}

profile_list::~profile_list(void)
{
    std::cout << "destructor called" << std::endl;
    return ;
}

int profile::do_print(char **profiles, profile *tmp) const
{
    int len;
    
    len = 0;
    std::cout << "     index|" << "first name|" << " last name|" \
        << "  nickname" << std::endl;
    for (int i = 0; i < tmp->contact_nb; i++)
    {
        std::cout << "         " << i << "|";
        len = 10 - \
        tmp[i].first_name.std::string::substr(0, 10).std::string::length();
        for (int x = 0; x < std::abs(len); x++)
            std::cout << " ";
        if (len)
            std::cout << tmp[i].first_name.std::string::substr(0, 10);
        else
            std::cout << tmp[i].first_name.std::string::substr(0, 9) << ".";
        std::cout << "|";
        len = 10 - \
        tmp[i].last_name.std::string::substr(0, 10).std::string::length();
        for (int x = 0; x < abs(len); x++)
            std::cout << " ";
        if (len)
            std::cout << tmp[i].last_name.std::string::substr(0, 10);
        else
            std::cout << tmp[i].last_name.std::string::substr(0, 9) << ".";
        std::cout << "|";
        len = 10 - \
        tmp[i].nickname.std::string::substr(0, 10).std::string::length();
        for (int x = 0; x < abs(len); x++)
            std::cout << " ";
        if (len)
            std::cout << tmp[i].nickname.std::string::substr(0, 10);
        else
            std::cout << tmp[i].nickname.std::string::substr(0, 9) << ".";
        std::cout << std::endl;
    }
    return 0;
}

int profile::do_add(profile *ind)
{
    std::string input("");

    if (ind->index == 8)
        ind->index = 0;
    else
        ind->contact_nb = 8;
    if (ind->contact_nb != 8)
        ind->contact_nb = ind->index + 1;
    std::cout << "Please enter first name" << std::endl;
    getline(std::cin, input);
    ind[ind->index].first_name = input;
    std::cout << "Please enter last name" << std::endl;
    getline(std::cin, input);
    ind[ind->index].last_name = input;
    std::cout << "Please enter nickname" << std::endl;
    getline(std::cin, input);
    ind[ind->index].nickname = input;
    std::cout << "Please enter phone number" << std::endl;
    getline(std::cin, input);
    ind[ind->index].phone_number = input;
    std::cout << "Please enter darkest secret" << std::endl;
    getline(std::cin, input);
    ind[ind->index].darkest_secret = input;
    ind[ind->index].index = ind->index;
    ind->index++;
    return 0;
}

int main(void)
{
    std::string  line;
    profile ind[8];
    profile_list prof(10, '|', '\n', ind);

    while (std::cout << "Please type a command" << std::endl)
    {
        getline(std::cin, line);
        try
        {
            if (line == "ADD")
                ind->do_add(ind);
            else if (line == "EXIT")
                break ;
            else if (line == "SEARCH")
                ind->do_print(NULL, ind);
            else
                throw "Wrong entry\n";
        }
        catch (const char *error)
        {
            std::cout << error << std::endl;
        }
    }
    return 0;
}