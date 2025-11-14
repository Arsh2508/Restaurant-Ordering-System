#include <iostream>
#include <memory>
#include "Menu.hpp"
#include "FoodItem.hpp"

Menu::Menu() = default;

Menu::Menu(const Menu &other)
{
    for(size_t i = 0; i < other.FoodItemes.size(); ++i){
        FoodItemes.push_back(std::make_shared<FoodItem>(*other.FoodItemes[i]));
    }
}

Menu &Menu::operator=(const Menu &rhs)
{
    if(&rhs == this){
        return *this;
    }

    FoodItemes.clear();

    for(size_t i = 0; i < rhs.FoodItemes.size(); ++i){
        FoodItemes.push_back(std::make_shared<FoodItem>(*rhs.FoodItemes[i]));
    }

    return *this;
}

Menu::Menu(Menu &&other) noexcept 
    : FoodItemes{std::move(other.FoodItemes)}
{
    other.FoodItemes.clear();
}

Menu &Menu::operator=(Menu &&rhs) noexcept
{
    if(this == &rhs){
        return *this;
    }

    FoodItemes = std::move(rhs.FoodItemes);
    rhs.FoodItemes.clear();

    return *this;
}

Menu::~Menu()
{
    FoodItemes.clear();
}


void Menu::addItem(std::shared_ptr<FoodItem> foodItem)
{
    if(foodItem){
        FoodItemes.push_back(foodItem);
    }
}

void Menu::displayMenu() const
{
    if(FoodItemes.size()){
        for(size_t i = 0; i < FoodItemes.size(); ++i){
            FoodItemes[i]->display();
        }
    }
    else{
        std::cout<<"No dishes to pisplay!\n";
    }
}

FoodItem *Menu::getItemByName(const std::string &itemName) const
{
    for(size_t i = 0; i < FoodItemes.size(); ++i){
        if(FoodItemes[i]->getName() == itemName){
            return FoodItemes[i].get();
        }
    }

    return nullptr;
}

const std::vector<std::shared_ptr<FoodItem>>& Menu::getItems() const
{
    return FoodItemes;
}
