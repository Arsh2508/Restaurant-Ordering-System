#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include <string>
class Dish;

class Menu{
public:
    Menu();
    Menu(const Menu& other);
    Menu& operator=(const Menu& rhs);
    Menu(Menu&& other) noexcept;
    Menu& operator=(Menu&& rhs) noexcept;
    ~Menu();

    void addDish(Dish* dish);
    void displayMenu() const;
    Dish* getDishByName(const std::string& dishName) const;

private:
    std::vector<Dish*> dishes;
};

#endif