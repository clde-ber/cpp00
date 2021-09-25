#include "phonebook.hpp"

using namespace std;

int idx = 0;

profile::profile(void) : index(0), first_name(""), last_name(""), nickname(""), phone_number(""), darkest_secret("")
{
    cout << "constructor called" << endl;
    return ;
}

profile::~profile(void)
{
    cout << "destructor called" << endl;
    return ;
}

profile_list::profile_list(int ll, char sp, char el, profile *pl) : line_length(ll), separator(sp), eol(el)
{
    profile tmp;
    for (int i = 0; i < 8; i++)
        pl[i] = tmp;
    cout << "constructor called" << endl;
    return ;
}

profile_list::~profile_list(void)
{
    cout << "destructor called" << endl;
    return ;
}

bool profile_list::set_profile(unsigned long index, char **profiles, profile_list **ind, profile_list **tmp)
{
    
    return 0;
}

bool profile::get_profile(unsigned long index, char **profiles, profile *tmp) const
{
    cout << tmp->first_name << endl;
    cout << tmp->last_name << endl;
    cout << tmp->nickname << endl;
    cout << tmp->phone_number << endl;
    cout << tmp->darkest_secret << endl;
    return 0;
}

int profile::do_print(unsigned long index, char **profiles, profile *tmp) const
{
    for (int i = 0; i < tmp[0].index; i++)
    {
        cout << tmp[i].first_name << endl;
        cout << tmp[i].last_name << endl;
        cout << tmp[i].nickname << endl;
        cout << tmp[i].phone_number << endl;
        cout << tmp[i].darkest_secret << endl;
        i++;
    }
    return 0;
}

int profile::do_add(profile *ind)
{
    string input("");

    if (ind[0].index == 8)
        ind[0].index = 0;
    cout << "Please enter first name" << endl;
    getline(cin, input);
    ind[ind[0].index].first_name = input;
    cout << "Please enter last name" << endl;
    getline(cin, input);
    ind[ind[0].index].last_name = input;
    cout << "Please enter nickname" << endl;
    getline(cin, input);
    ind[ind[0].index].nickname = input;
    cout << "Please enter phone number" << endl;
    getline(cin, input);
    ind[ind[0].index].phone_number = input;
    cout << "Please enter darkest secret" << endl;
    getline(cin, input);
    ind[ind[0].index].darkest_secret = input;
    ind[0].index++;
    return 0;
}

int main(void)
{
    string  line;
    profile ind[8];
    profile_list prof(10, '|', '\n', ind);

    while (cout << "Please type a command" << endl)
    {
        getline(cin, line);
        try
        {
            if (line == "ADD")
                ind->do_add(ind);
            else if (line == "EXIT")
                break ;
            else if (line == "SEARCH")
                ind->do_print(0, NULL, ind);
            else
                throw "Wrong entry\n";
        }
        catch (const char *error)
        {
            cout << error << endl;
        }
    }
    return 0;
}