# ShieldPass Manager

A simple C++ command-line Password Vault to securely store, view, update, search, and delete website credentials.

---

## 📁 Project Overview

This application manages saved credentials (Name, Website, Password) using a plain text vault file. The system supports password confirmation on add/update, keeps old values when input is blank during update, and clears the screen before each menu for a clean user interface. Future plans include encryption and a master-password system.

---

## 🗂 Project Structure

```
shieldPass/
├── src/
│   ├── main.cpp
│   └── PasswordEntryManager.cpp
├── include/
│   └── PasswordEntryManager.h
├── data/
│   └── vault.txt
├── docs/
│   └── DESIGN.md
├── build/
├── README.md
└── shieldPass (executable)
```

---

## 🚀 Build & Run

```bash
g++ -c src/main.cpp -Iinclude -o build/main.o
 g++ -c src/PasswordEntryManager.cpp -Iinclude -o build/PasswordEntryManager.o
 g++ build/main.o build/PasswordEntryManager.o -o shieldPass
 ./shieldPass
```

---

## ✅ Current Features

- Add new entry (with password confirmation)
- View all entries (auto-load latest data)
- Search entry by name or website
- Update existing entry (blank input = keep old value)
- Delete entry
- Clear screen before each menu for clean UI

---

## 🔮 Future Enhancements

- Master Password Prompt
- Encrypt vault using AES-GCM / XChaCha20
- Export / Import backup

---

## 🎯 Purpose

This project is for learning, practicing secure software design using C++, and building a resume-ready project.

---

## 🤝 Contribution (Future)

More features like encryption will be added step by step. This project is developed from scratch without external libraries to strengthen core logic.
