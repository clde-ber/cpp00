#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>
#include <cstring>
#include <iostream>
#include <cstdlib>

class   profile
{
    private :
        int index;
        int _contactNb;
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkestSecret;
        void printContact(std::string str);
    public :
        profile(void); // constructor
        ~profile(void); // destructor
        int do_print(profile *tmp) const;
        int do_add(profile *ind);
        int promptForIndex(void);
};

#endif
