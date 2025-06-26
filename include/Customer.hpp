#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <string>
#include <vector>

class Order;

class Customer{
public:
    Customer() = delete;
    Customer(std::string customerName, std::string contact);
    Customer(const Customer& other);
    Customer& operator=(const Customer& rhs);

    Customer(Customer&& other) noexcept;
    Customer& operator=(Customer&& rhs) noexcept;

    ~Customer() = default;
    
    void placeOrder(Order order);
    void viewOrderHistory() const;
    std::string getName() const;
    std::string getContactInfo() const;


private:
    std::string name;
    std::string contactInfo;
    std::vector<Order> orderHistory;
};

#endif