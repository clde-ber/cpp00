#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>
#include <cstring>
#include <iostream>

class   profile
{
    private :
        int index;
        int contact_nb;
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

    public :
        profile(void); // constructor
        ~profile(void); // destructor
        int do_print(char **profiles, profile *tmp) const;
        int do_add(profile *ind);
};

class   profile_list
{
    public :
        profile_list(int ll, char sp, char el, profile *pl);
        ~profile_list(void);

    private :
        int     line_length;
        char    separator;
        char    eol;
        profile     profiles[8];
};

#endif
