#include "Customer.hpp"
#include "Order.hpp"

Customer::Customer(std::string customerName, std::string contact)
    : name{customerName}
    , contactInfo{contact}
{}

Customer::Customer(const Customer &other)
    : name{other.name}
    , contactInfo{other.contactInfo}
{
    for(size_t i = 0; i < other.orderHistory.size(); ++i)
    {
        orderHistory.push_back(other.orderHistory[i]);
    }
}

Customer &Customer::operator=(const Customer &rhs)
{
    if(this == &rhs){
        return *this;
    }

    name = rhs.name;
    contactInfo = rhs.contactInfo;

    orderHistory.clear();

    for(size_t i = 0; i < rhs.orderHistory.size(); ++i){
        orderHistory.push_back(rhs.orderHistory[i]);
    }

    return *this;
}

Customer::Customer(Customer &&other) noexcept
    : name{std::move(other.name)}
    , contactInfo{std::move(other.contactInfo)}
    , orderHistory{std::move(other.orderHistory)}
{
    other.orderHistory.clear();
}

Customer &Customer::operator=(Customer &&rhs) noexcept
{
    if(this == &rhs){
        return *this;
    }

    name = std::move(rhs.name);
    contactInfo = std::move(rhs.contactInfo);
    orderHistory = std::move(rhs.orderHistory);

    rhs.orderHistory.clear();

    return *this;
}

void Customer::placeOrder(Order order)
{
    
}

