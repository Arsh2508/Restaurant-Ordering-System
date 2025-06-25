#ifndef ORDER_HPP
#define ORDER_HPP

#include <vector>

class Customer;
class Dish;

class Order{
public:
    Order(Customer* customer);
    Order(const Order& other);
    Order& operator=(const Order& other);
    Order(Order&& other) noexcept;
    Order& operator=(Order&& other) noexcept;
    ~Order() = default;

    void addDish(Dish* dish);
    void calculateTotal();
    void displayOrder() const;
    
private:
    Customer* customer;
    std::vector<Dish*> orderedDishes;
    double totalPrice;
};

#endif