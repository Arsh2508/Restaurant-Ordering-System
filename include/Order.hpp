#ifndef ORDER_HPP
#define ORDER_HPP

#include <vector>
#include <memory>

class Customer;
class FoodItem;

class Order{
public:
    Order() = delete;;
    Order(Customer* customer);
    Order(const Order& other);
    Order& operator=(const Order& other);
    Order(Order&& other) noexcept;
    Order& operator=(Order&& other) noexcept;
    ~Order() = default;

    void addItem(std::shared_ptr<FoodItem> item);
    void calculateTotal();
    void displayOrder() const;
    double getTotalPrice() const;

private:
    Customer* m_customer;
    double totalPrice;
    std::vector<std::shared_ptr<FoodItem>> orderedItems;
};

#endif