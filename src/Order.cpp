#include <iostream>
#include "Order.hpp"
#include "Dish.hpp"

Order::Order(Customer *customer)
    : m_customer{customer}
{}

Order::Order(const Order &other)
    : m_customer{other.m_customer}
    , totalPrice{other.totalPrice}
{
    for(size_t i = 0; i < other.orderedDishes.size(); ++i){
        orderedDishes.push_back(other.orderedDishes[i]);
    }
}

Order &Order::operator=(const Order &other)
{
    if(this == &other){
        return *this;
    }
    m_customer = other.m_customer;
    totalPrice = other.totalPrice;

    orderedDishes.clear();

    for(size_t i = 0; i < other.orderedDishes.size(); ++i){
        orderedDishes.push_back(other.orderedDishes[i]);
    }

    return *this;
}

Order::Order(Order &&other) noexcept
    : m_customer{std::move(other.m_customer)}
    , totalPrice{other.totalPrice}
    , orderedDishes{std::move(other.orderedDishes)}
{
    other.orderedDishes.clear();
}

Order &Order::operator=(Order &&other) noexcept
{
    if(this == &other){
        return *this;
    }

    m_customer = std::move(other.m_customer);
    totalPrice = other.totalPrice;
    orderedDishes = std::move(other.orderedDishes);

    other.orderedDishes.clear();

    return *this;
}

void Order::addDish(Dish* dish) 
{
    orderedDishes.push_back(dish);
}

void Order::calculateTotal()
{
    double total = 0.0;

    for(size_t i = 0; i < orderedDishes.size(); ++i)
    {
        total += (orderedDishes[i])->getPrice();
    }

    totalPrice = total;
}

void Order::displayOrder() const
{
    if(orderedDishes.empty()){
        std::cout<< "No order history available.\n";
        return;
    }

    for(size_t i = 0; i < orderedDishes.size(); ++i){
        orderedDishes[i]->display();
    }

    std::cout<<"Total bill: "<< totalPrice <<std::endl;
}

double Order::getTotolPrice() const
{
    return totalPrice;
}
