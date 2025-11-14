#include <iostream>
#include "Order.hpp"
#include "FoodItem.hpp"

Order::Order(Customer *customer)
    : m_customer{customer}
    , totalPrice{0.0}
{}

Order::Order(const Order &other)
    : m_customer{other.m_customer}
    , totalPrice{other.totalPrice}
{
    for(size_t i = 0; i < other.orderedItems.size(); ++i){
        orderedItems.push_back(other.orderedItems[i]);
    }
}

Order &Order::operator=(const Order &other)
{
    if(this == &other){
        return *this;
    }
    m_customer = other.m_customer;
    totalPrice = other.totalPrice;

    orderedItems.clear();

    for(size_t i = 0; i < other.orderedItems.size(); ++i){
        orderedItems.push_back(other.orderedItems[i]);
    }

    return *this;
}

Order::Order(Order &&other) noexcept
    : m_customer{std::move(other.m_customer)}
    , totalPrice{other.totalPrice}
    , orderedItems{std::move(other.orderedItems)}
{
    other.orderedItems.clear();
}

Order &Order::operator=(Order &&other) noexcept
{
    if(this == &other){
        return *this;
    }

    m_customer = std::move(other.m_customer);
    totalPrice = other.totalPrice;
    orderedItems = std::move(other.orderedItems);

    other.orderedItems.clear();

    return *this;
}

void Order::addItem(std::shared_ptr<FoodItem> item) 
{
    orderedItems.push_back(item);
}

void Order::calculateTotal()
{
    double total = 0.0;

    for(size_t i = 0; i < orderedItems.size(); ++i)
    {
        total += (orderedItems[i])->getPrice();
    }

    totalPrice = total;
}

void Order::displayOrder() const
{
    if(orderedItems.empty()){
        std::cout<< "No order history available.\n";
        return;
    }

    for(size_t i = 0; i < orderedItems.size(); ++i){
        orderedItems[i]->display();
    }

    std::cout<<"Total bill: "<< totalPrice <<std::endl;
}

double Order::getTotalPrice() const
{
    return totalPrice;
}
