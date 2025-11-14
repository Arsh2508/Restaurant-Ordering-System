#ifndef RESTAURANT_HPP
#define RESTAURANT_HPP

#include <vector>
#include <memory>
#include <string>

#include "Menu.hpp"
#include "Customer.hpp"
#include "Order.hpp"

class Restaurant{
public:
    Restaurant();
    
    static Restaurant& getInstance() {
        static Restaurant instance;
        return instance;
    }   

    Restaurant(const Restaurant&) = delete;
    Restaurant& operator=(const Restaurant&) = delete;
    Restaurant(Restaurant&&) noexcept = delete;
    Restaurant& operator=(Restaurant&&) noexcept = delete;
    ~Restaurant() = default;

    void showMenu() const;
    Customer* getCustomerByName(const std::string& name) const;
    void placeNewOrder(std::string& customerName);
    void viewCustomerOrderHistory(const std::string& customerName) const;
    void setMenu();
    void acceptOrder(Customer * customer);
    void displayCustomers() const;
    void displayOrders() const;
    void loadMenuFromJSON(const std::string& filePath);

private:
    Menu menu;
    std::vector<std::shared_ptr<Customer>> customers;
    std::vector<std::shared_ptr<Order>> orders;

};

#endif