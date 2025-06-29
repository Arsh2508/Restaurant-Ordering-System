#ifndef DISH_HPP
#define DISH_HPP

#include <string>

class Dish{
public:
    Dish() = delete;
    Dish(const std::string& dishName, double dishPrice);

    Dish(const Dish& other);
    Dish& operator=(const Dish& rhs);
    Dish(Dish&& other) noexcept;
    Dish& operator=(Dish&& rhs) noexcept;
    
    virtual void display() const;
    double getPrice() const;
    std::string getName() const;

    virtual ~Dish() = default;
    
protected:
    std::string name;
    double price;

};

class Appetizer : public Dish{
public:
    Appetizer(const std::string& dishName, double dishPrice, bool spicy);
    void display() const;
private:
    bool isSpicy;
};

class Entree : public Dish{
public:
    Entree(const std::string& dishName, double dishPrice, int cal);
    void display() const;
private:
    int calories; 
};

class Dessert : public Dish{
public:
    Dessert(const std::string& dishName, double dishPrice, bool nuts);
    void display() const;
private:
    bool containNuts;
};

#endif