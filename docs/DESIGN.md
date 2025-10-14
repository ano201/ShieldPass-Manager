# DESIGN

## Data Format

Current storage format: **3-line per entry**

```
name
website
password
(blank line separator)
```

File used: `data/vault.txt`

## Components

### 1️⃣ PasswordEntry (struct)

Fields:

- `name`
- `website`
- `password`

### 2️⃣ PasswordEntryManager (class)

Responsibilities:

- `loadFromFile()` – Read entries from text file
- `saveToFile()` – Write all entries back to file
- `addEntry()` – Add new password to list
- `viewAll()` – Display all entries
- `searchEntry()` – Find entry by name or website

### 3️⃣ main.cpp

- Handles CLI menu
- Collects user input
- Calls manager functions

## Flow

1. Program starts → `loadFromFile()`
2. User selects menu option
3. For Add → Save and write again using `saveToFile()`
4. For View/Search → Always load latest data

## Menu Options (Current Phase)

- Add Entry
- View All Entries
- Search Entry
- Exit

## Future Enhancements (Planned)

### 🔒 Encryption Plan

- Introduce **Master Password Prompt**
- Use **KDF (Argon2)** for hashing master password
- Encrypt vault using **AES-GCM / XChaCha20**

### 🧱 Encrypted Data Format

```
MAGIC || salt || nonce || ciphertext
```

### 📌 Additional Planned Features

- Delete entry
- Update entry
- Export / Import backup
