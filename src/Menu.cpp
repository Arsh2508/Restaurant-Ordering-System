#include <iostream>
#include "Menu.hpp"
#include "Dish.hpp"

Menu::Menu() = default;

Menu::Menu(const Menu &other)
{
    for(size_t i = 0; i < other.dishes.size(); ++i){
        dishes.push_back(new Dish(*other.dishes[i]));
    }
}

Menu &Menu::operator=(const Menu &rhs)
{
    if(&rhs == this){
        return *this;
    }

    for(size_t i = 0; i < dishes.size(); ++i){
        delete dishes[i];
    }

    dishes.clear();

    for(size_t i = 0; i < rhs.dishes.size(); ++i){
        dishes.push_back(new Dish(*rhs.dishes[i]));
    }

    return *this;
}

Menu::Menu(Menu &&other) noexcept 
    : dishes{std::move(other.dishes)}
{
    other.dishes.clear();
}

Menu &Menu::operator=(Menu &&rhs) noexcept
{
    if(this == &rhs){
        return *this;
    }

    dishes = std::move(rhs.dishes);
    rhs.dishes.clear();

    return *this;
}

Menu::~Menu()
{
    for(size_t i = 0; i < dishes.size(); ++i){
        delete dishes[i];
    }
}

void Menu::addDish(Dish *dish)
{
    if(dish){
        dishes.push_back(dish);
    }
}

void Menu::displayMenu() const
{
    if(dishes.size()){
        for(size_t i = 0; i < dishes.size(); ++i){
            dishes[i]->display();
        }
    }
    else{
        std::cout<<"No dishes to pisplay!\n";
    }
}

Dish *Menu::getDishByName(const std::string &dishName) const
{
    for(size_t i = 0; i < dishes.size(); ++i){
        if(dishes[i]->getName() == dishName){
            return dishes[i];
        }
    }
    return nullptr;
}
