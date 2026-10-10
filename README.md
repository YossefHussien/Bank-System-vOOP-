Bank System (OOP Version)

A C++ console-based banking application, redesigned from my earlier procedural Bank System using Object-Oriented Programming and extended with new features. Developed as a hands-on application of the OOP concepts learned in the Programming Advices roadmap.

Features

* Authentication: Login/logout with per-user permissions, and system lock after 3 failed login attempts.
* Client Management: Add, update, delete, find, and list clients.
* Transactions: Deposit, withdraw, transfer between clients, and total balances, with a transfer log.
* User Management: Full CRUD for system users, with permissions managed through bitwise operations.
* Login Register: Logs every login with date and time, viewable from a permission-protected screen.
* Password Encryption: User passwords are encrypted before being saved to file.
* Currency Exchange: List currencies, find a currency, update rates, and convert between currencies.
* Data Persistence: Data is stored in text files using `<fstream>`.

OOP Concepts Applied

* Encapsulation: Private data members accessed through properties (get/set).
* Abstraction: Simple interfaces like `Find()`, `Save()`, and `Delete()` hide file handling details.
* Inheritance: `clsBankClient` and `clsUser` inherit from `clsPerson`, and all screens inherit from `clsScreen`.
* Static Methods and Object Modes: Used for lookups, and a single `Save()` handles both adding and updating.

Technologies

* Language: C++
* Concepts: OOP, `std::vector`, `enum`, File I/O, Bitwise Operations

Requirements

* Windows OS and Visual Studio (the project uses `system("cls")` and `__declspec(property)`)

Default Admin Login

* Username: Admin
* Password: Admin123

How to Run the Project

1. Clone this repository:

git clone https://github.com/YossefHussien/Bank-System-vOOP-.git

2. Open the project in Visual Studio, then build and run.
