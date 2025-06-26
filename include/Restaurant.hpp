#ifndef RESTAURANT_HPP
#define RESTAURANT_HPP

#include <vector>

#include "Menu.hpp"
#include "Customer.hpp"
#include "Order.hpp"

class Restaurant{
public:
    Restaurant() = default;
    Restaurant(const Restaurant& other);
    Restaurant& operator=(const Restaurant& other);
    Restaurant(Restaurant&& other) noexcept;
    Restaurant& operator=(Restaurant&& other) noexcept;
    ~Restaurant();

    void showMenu() const;
    Customer* getCustomerByName(const std::string& name) const;
    void placeNewOrder(std::string& customerName);
    void viewCustomerOrderHistory(const std::string& customerName) const;
    void setMenu();
    void acceptOrder(Customer * customer);
    void displayCustomers() const;
    void displayOrders() const;
private:
    Menu menu;
    std::vector<Customer*> customers;
    std::vector<Order> orders;

};

#endif