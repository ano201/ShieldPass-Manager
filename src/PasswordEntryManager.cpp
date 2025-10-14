#include "PasswordEntryManager.h"
#include <fstream>
#include <filesystem>
#include <sstream>
#include <limits>

void PasswordEntryManager::saveToFile()
{
    ofstream vault(vaultFile, ios::binary);
    for (const auto &e : entries)
    {
        vault << e.name << "\n"
              << e.website << "\n"
              << e.password << "\n\n";
    }
    vault.close();
}

void PasswordEntryManager::loadFromFile()
{
    entries.clear();

    if (!filesystem::exists("data"))
        filesystem::create_directory("data");
    if (!filesystem::exists(vaultFile))
    {
        ofstream createFile(vaultFile);
        createFile.close();
    }

    ifstream vault(vaultFile);
    if (!vault)
        return;

    string n, w, p;
    while (true)
    {
        if (!getline(vault, n))
            break;
        if (!getline(vault, w))
            break;
        if (!getline(vault, p))
            break;

        string sep;
        getline(vault, sep);

        PasswordEntry e;
        e.name = n;
        e.website = w;
        e.password = p;

        entries.push_back(e);
    }
    vault.close();
}

void PasswordEntryManager::addNewEntry()
{
    loadFromFile();
    PasswordEntry e;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Enter name: ";
    getline(cin, e.name);
    cout << "Enter website: ";
    getline(cin, e.website);
    string pass1, pass2;
    while (true)
    {
        cout << "Enter password: ";
        getline(cin, pass1);
        cout << "Confirm password: ";
        getline(cin, pass2);

        if (pass1 == pass2)
        {
            e.password = pass1;
            break;
        }
        cout << "Password didn't match! Try again.\n";
    }

    entries.push_back(e);
    saveToFile();
    cout << "Entry added successfully!\n";
}

void PasswordEntryManager::viewAllEntries()
{
    loadFromFile();
    if (entries.empty())
    {
        cout << "\nNo saved password found!\n";
        return;
    }

    cout << "\n---All saved entries---\n";
    for (const auto &e : entries)
    {
        cout << "Name: " << e.name
             << "\nWebsite: " << e.website
             << "\nPassword: " << e.password
             << "\n--------------------------------\n";
    }
}

void PasswordEntryManager::searchPassword()
{
    loadFromFile();
    if (entries.empty())
    {
        cout << "\nNo saved password found!\n";
        return;
    }

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    string keyword;
    cout << "Enter name or website: ";
    getline(cin, keyword);
    cout << "\n---Search Result---\n";
    bool found = false;
    for (const auto &e : entries)
    {
        if (keyword == e.name || keyword == e.website)
        {
            found = true;
            cout << "Name: " << e.name
                 << "\nWebsite: " << e.website
                 << "\nPassword: " << e.password
                 << "\n--------------------------------\n";
        }
    }
    if (!found)
        cout << "No matching entries found\n";
}

void PasswordEntryManager::deletePassword()
{
    cout << "You selected: Delete A Password Entry.\n";
}

void PasswordEntryManager::updatePassword()
{
    cout << "You selected: Update/Edit Existing Password.\n";
}