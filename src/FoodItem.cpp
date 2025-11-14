#include <iostream>
#include "FoodItem.hpp"

int FoodItem::id_counter = 0;

FoodItem::FoodItem(const std::string& itemName, double itemPrice, const std::string& itemCategory)
    : m_id{++id_counter}
    , m_name{itemName}
    , m_price{itemPrice}
    , m_category{itemCategory}
{}

FoodItem::FoodItem(const FoodItem &other)
    : m_id{other.m_id}
    , m_name{other.m_name}
    , m_price{other.m_price}
    , m_category{other.m_category}
{}

FoodItem &FoodItem::operator=(const FoodItem &rhs)
{
    if(this == &rhs){
        return *this;
    }

    m_id = rhs.m_id;
    m_name = rhs.m_name;
    m_price = rhs.m_price;
    m_category = rhs.m_category;

    return *this;
}

FoodItem::FoodItem(FoodItem &&other) noexcept
    : m_id {other.m_id}
    , m_name{std::move(other.m_name)}
    , m_price{other.m_price}
    , m_category{std::move(other.m_category)}
{}

FoodItem &FoodItem::operator=(FoodItem &&rhs) noexcept
{
    if (this == &rhs){
        return *this;
    }

    m_id = rhs.m_id;
    m_name = std::move(rhs.m_name);
    m_price = rhs.m_price;
    m_category = std::move(rhs.m_category);

    return *this;
}

void FoodItem::display() const
{
 std::cout << "-----------------------------------\n"
              <<"FoodItem: "<< m_name
              <<"\nPrice: " << m_price << "$\n"
              <<"\n-----------------------------------\n";
}

double FoodItem::getPrice() const
{
    return m_price;
}

std::string FoodItem::getName() const
{
    return m_name;
}

std::string FoodItem::getCategory() const
{
    return m_category;
}

Appetizer::Appetizer(const std::string& itemName, double itemPrice, bool spicy)
    : FoodItem(itemName, itemPrice, "Appetizer")
    , isSpicy{spicy}
{}

void Appetizer::display() const
{
    std::cout << "-----------------------------------\n"
              <<"Appetizer: "<< m_name
              <<"\nPrice: " << m_price << "$\n"
              <<(isSpicy ? "Spicy!" : "Not Spicy.")
              <<"\n-----------------------------------\n";
}

Entree::Entree(const std::string& itemName, double itemPrice, int cal)
    : FoodItem(itemName, itemPrice, "Entree")
    , calories{cal}
{}

void Entree::display() const 
{
    std::cout << "-----------------------------------\n"
              <<"Entree: "<< m_name
              <<"\nPrice: " << m_price << "$\n"
              <<"Calories: " <<calories
              << "\n-----------------------------------\n";
}

Dessert::Dessert(const std::string& itemName, double itemPrice, bool nuts)
    : FoodItem(itemName, itemPrice, "Dessert")
    , containNuts{nuts}
{}

void Dessert::display() const
{
    std::cout << "-----------------------------------\n"
              <<"Dessert: "<< m_name
              <<"\nPrice: " << m_price << "$\n"
              << (containNuts ? "Contains nuts!" : "Does not contain nuts.")
              <<"\n-----------------------------------\n";
}

Drink::Drink(const std::string& itemName, double itemPrice, bool alcoholic) 
    : FoodItem(itemName, itemPrice, "Drink")
    , isAlcoholic{alcoholic}
{}

void Drink::display() const
{
    std::cout << "-----------------------------------\n"
            <<"Drink: "<< m_name
            <<"\nPrice: " << m_price << "$\n"
            << (isAlcoholic ? "Is alcoholic!" : "Is not alcoholic.")
            <<"\n-----------------------------------\n";
}