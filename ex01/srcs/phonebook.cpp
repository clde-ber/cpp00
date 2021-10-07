#include "phonebook.hpp"

using namespace std;

int idx = 0;

profile::profile(void) : index(0), contact_nb(0), first_name(""), last_name(""), nickname(""), phone_number(""), darkest_secret("")
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

int profile::do_print(char **profiles, profile *tmp) const
{
    for (int i = 0; i < tmp->contact_nb; i++)
    {
        cout << tmp[i].first_name << endl;
        cout << tmp[i].last_name << endl;
        cout << tmp[i].nickname << endl;
        cout << tmp[i].phone_number << endl;
        cout << tmp[i].darkest_secret << endl;
    }
    return 0;
}

int profile::do_add(profile *ind)
{
    string input("");

    if (ind->index == 8)
        ind->index = 0;
    else
        ind->contact_nb = 8;
    if (ind->contact_nb != 8)
        ind->contact_nb = ind->index + 1;
    cout << "Please enter first name" << endl;
    getline(cin, input);
    ind[ind->index].first_name = input;
    cout << "Please enter last name" << endl;
    getline(cin, input);
    ind[ind->index].last_name = input;
    cout << "Please enter nickname" << endl;
    getline(cin, input);
    ind[ind->index].nickname = input;
    cout << "Please enter phone number" << endl;
    getline(cin, input);
    ind[ind->index].phone_number = input;
    cout << "Please enter darkest secret" << endl;
    getline(cin, input);
    ind[ind->index].darkest_secret = input;
    ind->index++;
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
                ind->do_print(NULL, ind);
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