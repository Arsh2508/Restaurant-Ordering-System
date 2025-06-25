#ifndef CUSTORMER_HPP
#define CUSTORMER_HPP

#include <string>
#include <vector>

class Order;

class Customer{
public:
    Customer(std::string customerName, std::string contact);
    Customer(const Customer& other);
    Customer& operator=(const Customer& rhs);

    Customer(Customer&& other) noexcept;
    Customer& operator=(Customer&& rhs) noexcept;

    ~Customer() = default;
    
    void placeOrder(Order order);
    void viewOrderHistory() const;
    std::string getName() const;


private:
    std::string name;
    std::string contactInfo;
    std::vector<Order> orderHistory;
};

#endif