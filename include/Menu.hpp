#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include <memory>
#include <string>

class FoodItem;

class Menu{
public:
    Menu();
    Menu(const Menu& other);
    Menu& operator=(const Menu& rhs);
    Menu(Menu&& other) noexcept;
    Menu& operator=(Menu&& rhs) noexcept;
    ~Menu();

    void addItem(std::shared_ptr<FoodItem> FoodItem);
    void displayMenu() const;
    FoodItem* getItemByName(const std::string& itemName) const;
    const std::vector<std::shared_ptr<FoodItem>>& getItems() const;

private:
    std::vector<std::shared_ptr<FoodItem>> FoodItemes;
};

#endif