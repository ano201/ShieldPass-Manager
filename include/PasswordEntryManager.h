#ifndef PASSWORD_ENTRY_MANAGER_H
#define PASSWORD_ENTRY_MANAGER_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct PasswordEntry
{
    string name;
    string website;
    string password;
};

class PasswordEntryManager
{
private:
    vector<PasswordEntry> entries;
    string vaultFile = "data/vault.txt";

public:
    void addNewEntry();
    void viewAllEntries();
    void searchPassword();
    void deletePassword();
    void updatePassword();
    void saveToFile();
    void loadFromFile();
};

#endif