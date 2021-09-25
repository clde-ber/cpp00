#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>
#include <cstring>
#include <iostream>

class   profile
{
    private :
        unsigned long index;
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

    public :
        profile(void); // constructor
        ~profile(void); // destructor
        int do_print(unsigned long index, char **profiles, profile *tmp) const;
        bool get_profile(unsigned long index, char **profiles, profile *tmp) const;
        int do_add(profile *ind);
};

class   profile_list
{
    public :
        profile_list(int ll, char sp, char el, profile *pl);
        ~profile_list(void);
        unsigned long get_index(profile_list *ind);
        bool set_profile(unsigned long index, char **profiles, profile_list **ind, profile_list **tmp);

    private :
        int     line_length;
        char    separator;
        char    eol;
        profile     profiles[8];
};

#endif
