# DESIGN.md

## Data Format

Current storage format: 3 lines per entry

```
name
website
password
(blank line separator)
```

File: `data/vault.txt`

---

## Components

### 1️⃣ PasswordEntry (struct)

- `name`
- `website`
- `password`

### 2️⃣ PasswordEntryManager (class)

Responsibilities:

- `loadFromFile()` – Load entries from file
- `saveToFile()` – Save all entries to file
- `addEntry()` – Add new password with confirmation
- `viewAll()` – Display all entries
- `searchEntry()` – Search by name or website
- `updateEntry()` – Update entry (blank input keeps old value)
- `deleteEntry()` – Delete selected entry

### 3️⃣ main.cpp

- Handles CLI menu
- Clears screen before each menu
- Collects user input
- Calls PasswordEntryManager functions

---

## Flow

1. Start program → `loadFromFile()`
2. Show menu
3. User selects option
   - Add → confirm password → save
   - View → display entries
   - Search → display matching entries
   - Update → blank input keeps old value → save
   - Delete → remove entry → save
4. Exit

---

## Menu Options (Current Phase)

- Add Entry
- View All Entries
- Search Entry
- Update Entry
- Delete Entry
- Exit

---

## Future Enhancements

- Master Password System
- Encryption (AES-GCM / XChaCha20)
- Backup / Import vault

---

## Notes

- Program clears the console at the start of each operation for clean UI.
- Add/Update require password confirmation to prevent mistakes.
- Update allows fields to remain unchanged if input is left blank.
