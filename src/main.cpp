#include <iostream>
#include "PasswordEntryManager.h"
using namespace std;

void showMenu()
{
    cout << "===============================\n";
    cout << "  ShieldPass Password Manager  \n";
    cout << "===============================\n";
    cout << "1. Add New Password\n";
    cout << "2. View All Passwords\n";
    cout << "3. Search Password By Name/Website\n";
    cout << "4. Delete A Password Entry\n";
    cout << "5. Update/Edit Existing Password\n";
    cout << "\n---------------------------------\n\n";
    cout << "6. Change Master Password\t(Future Phase)\n";
    cout << "7. Export/Backup Vault\t(Future Phase)\n";
    cout << "8. Exit\n";
}

int main()
{
    cout << "In the name of Allah\n\n";

    PasswordEntryManager manager;
    int choice = 0;

    while (true)
    {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number.\n\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            manager.addNewEntry();
            break;
        case 2:
            manager.viewAllEntries();
            break;
        case 3:
            manager.searchPassword();
            break;
        case 4:
            manager.deletePassword();
            break;
        case 5:
            manager.updatePassword();
            break;
        case 8:
            cout << "Program exited successfully.\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }

        cout << "\n";
    }

    return 0;
}
