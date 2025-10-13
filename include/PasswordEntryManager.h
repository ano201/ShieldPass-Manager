#ifndef PASSWORD_ENTRY_MANAGER_H
#define PASSWORD_ENTRY_MANAGER_H

#include <iostream>
using namespace std;

class PasswordEntryManager
{
public:
    void addNewEntry();
    void viewAllEntries();
    void searchPassword();
    void deletePassword();
    void updatePassword();
};

#endif