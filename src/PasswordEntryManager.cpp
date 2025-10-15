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
    cout << "====================\n";
    cout << "  Add new Password  \n";
    cout << "====================\n";
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
    cout << "======================\n";
    cout << "  View All Passwords  \n";
    cout << "======================\n";
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
    cout << "===================================\n";
    cout << "  Search Password By Name/Website  \n";
    cout << "===================================\n";
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
    cout << "===========================\n";
    cout << "  Delete A Password Entry  \n";
    cout << "===========================\n";
    loadFromFile();
    if (entries.empty())
    {
        cout << "\nNo saved password found!\n";
        return;
    }

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    string keyword;
    cout << "Enter name or website to delete: ";
    getline(cin, keyword);

    bool found = false;
    vector<PasswordEntry> updatedEntries;

    for (const auto &e : entries)
    {
        if (keyword == e.name || keyword == e.website)
        {
            found = true;
            cout << "\nFound entry:\n";
            cout << "Name: " << e.name
                 << "\nWebsite: " << e.website
                 << "\nPassword: " << e.password << "\n";

            cout << "\nAre you sure you want to delete this entry? (y/n): ";
            char confirm;
            cin >> confirm;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (confirm == 'y' || confirm == 'Y')
            {
                cout << "Entry deleted successfully!\n";
                continue;
            }
            else
            {
                cout << "Deletion canceled. Entry kept.\n";
            }
        }

        updatedEntries.push_back(e);
    }

    if (!found)
    {
        cout << "No matching entry found!\n";
        return;
    }

    entries = updatedEntries;

    saveToFile();
}

void PasswordEntryManager::updatePassword()
{
    cout << "=================================\n";
    cout << "  Update/Edit Existing Password  \n";
    cout << "=================================\n";
    loadFromFile();
    if (entries.empty())
    {
        cout << "\nNo saved password found!\n";
        return;
    }

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    string keyword;
    cout << "Enter name or website to update: ";
    getline(cin, keyword);
    bool found = false;
    for (auto &e : entries)
    {
        if (keyword == e.name || keyword == e.website)
        {
            found = true;
            cout << "Found entry:\n"
                 << "Name: " << e.name
                 << "\nWebsite: " << e.website << "\n\n";
            cout << "Press enter to skip updating a field.\n";

            string newName, newWebsite, pass1, pass2;

            cout << "Enter new name (Leave empty to keep same): ";
            getline(cin, newName);
            if (!newName.empty())
                e.name = newName;

            cout << "Enter new website (Leave empty to keep same): ";
            getline(cin, newWebsite);
            if (!newWebsite.empty())
                e.website = newWebsite;

            cout << "Enter new password (leave empty to keep same): ";
            getline(cin, pass1);

            if (!pass1.empty()) // only if user typed something
            {
                cout << "Confirm new password: ";
                getline(cin, pass2);

                if (pass1 == pass2)
                {
                    e.password = pass1;
                    cout << "Password updated successfully!\n";
                }
                else
                {
                    cout << "Passwords didn't match! Keeping old password.\n";
                }
            }

            cout << "\nEntry updated successfully!\n";
            break;
        }
    }
    if (!found)
    {
        cout << "No matching entry found!\n";
        return;
    }

    saveToFile();
}
