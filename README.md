# 🍽️ Restaurant Ordering System

This project is a console-based Restaurant Ordering System built in C++ using Object-Oriented Programming (OOP) principles. It allows customers to browse menus, place orders, and view order history. The system is designed to be modular, extensible, and testable.

---

## 📦 Features

- 🧾 **Menu Management**: Add dishes categorized as Appetizer, Entree, or Dessert.
- 🍽️ **Order Processing**: Customers can place orders and view bills.
- 👥 **Customer Management**: Stores customer names and contact info.
- 🗂️ **Order History**: Track previous orders for each customer.
- ✅ **Unit Tests**: Built with [Google Test](https://github.com/google/googletest).

---

## 📁 Project Structure

.
├── build/ # Makefile is here

├── include/ # Header files

├── src/ # Source (.cpp) files

├── tests/ # Google Test unit tests

└── README.md # This file


---

## 🔧 Requirements

- C++17 or later
- `g++` (or any compatible C++ compiler)
- [Google Test](https://github.com/google/googletest) installed globally (or locally with modification)

To install Google Test globally:


🚀 Build Instructions
Clone the repository and build the project:
```bash
sudo apt update
sudo apt install libgtest-dev
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
sudo cp *.a /usr/lib

git clone <your-repo-url>
cd your-repo-name/build

# Build main program
make

# Run the application
./Restaurant

🧪 Running Tests
To run the unit tests:
make test
This compiles tests/test.cpp along with the main source files (except main.cpp) and links against Google Test.

To clean all build files:
make clean
