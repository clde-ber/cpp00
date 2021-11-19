#include <iostream>
#include <string>

std::string  to_upper(std::string str)
{
    unsigned long i;

    std::string res("");

    for (i = 0; i < str.length(); i++) 
        res += toupper(str[i]);
    return (res);
}

int main(int ac, char **av)
{
    int i;
    std::string arg("");

    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (i = 1; i < ac; i++)
        {
            arg = to_upper(av[i]);
            std::cout << arg;
        }
        std::cout << "" << std::endl;
    }
    return (0);
}