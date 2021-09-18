#include <iostream>
#include <string>

using namespace std;

string  to_upper(string str)
{
    unsigned long i;
    string res("");

    for (i = 0; i < str.length(); i++) 
        res += toupper(str[i]);
    return (res);
}

int main(int ac, char **av)
{
    int i;
    string arg("");

    if (ac == 1)
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
    else
    {
        for (i = 1; i < ac; i++)
        {
            arg = to_upper(av[i]);
            cout << arg;
        }
        cout << "" << endl;
    }
    return (0);
}