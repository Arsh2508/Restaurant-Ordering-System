#include <iostream>
#include "Dish.hpp"

Dish::Dish() = delete;

Dish::Dish(std::string dishName, double dishPrice)
    : name{dishName}
    , price{dishPrice}
{}

Dish::Dish(const Dish &other)
    : name{other.name}
    , price{other.price}
{}

Dish &Dish::operator=(const Dish &rhs)
{
    if(this == &rhs){
        return *this;
    }

    name = rhs.name;
    price = rhs.price;

    return *this;
}

Dish::Dish(Dish &&other) noexcept
    : name{std::move(other.name)}
    , price{other.price}
{}

Dish &Dish::operator=(Dish &&rhs) noexcept
{
    if (this == &rhs){
        return *this;
    }

    name = std::move(rhs.name);
    price = rhs.price;

    return *this;
}

void Dish::display() const
{
    std::cout << name << " - " << price <<"$\n";
}

double Dish::getPrice() const
{
    return price;
}

std::string Dish::getName() const
{
    return name;
}

Appetizer::Appetizer(std::string dishName, double dishPrice, bool spicy)
    : Dish(dishName, dishPrice)
    , isSpicy{spicy}
{}

void Appetizer::display() const
{
    std::cout << "-----------------------------------\n"
              <<"Appetizer: "<< name
              <<"\nPrice: " << price << "$\n"
              <<(isSpicy ? "Spicy!" : "Not Spicy.")
              <<"\n-----------------------------------\n";
}

Entree::Entree(std::string dishName, double dishPrice, int cal)
    : Dish(dishName, dishPrice)
    , calories{cal}
{}

void Entree::display() const 
{
    std::cout << "-----------------------------------\n"
              <<"Entree: "<< name
              <<"\nPrice: " << price << "$\n"
              <<"Calories: " <<calories
              << "\n-----------------------------------\n";
}

Dessert::Dessert(std::string dishName, double dishPrice, bool nuts)
    : Dish(dishName, dishPrice)
    , containNuts{nuts}
{}

void Dessert::display() const
{
    std::cout << "-----------------------------------\n"
              <<"Appetizer: "<< name
              <<"\nPrice: " << price << "$\n"
              << (containNuts ? "Contains nuts!" : "Does not contain nuts.")
              <<"\n-----------------------------------\n";
}
