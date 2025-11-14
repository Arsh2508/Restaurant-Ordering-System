#ifndef FOODITEM_HPP
#define FOODITEM_HPP

#include <string>

class FoodItem{
public:
    FoodItem() = delete;
    FoodItem(const std::string& ItemName, double ItemPrice, const std::string& ItemCategory);

    FoodItem(const FoodItem& other);
    FoodItem& operator=(const FoodItem& rhs);
    FoodItem(FoodItem&& other) noexcept;
    FoodItem& operator=(FoodItem&& rhs) noexcept;
    
    virtual void display() const;
    double getPrice() const;
    std::string getName() const;
    std::string getCategory() const;

    virtual ~FoodItem() = default;
    
protected:
    static int id_counter;

    int m_id;
    std::string m_name;
    double m_price;
    std::string m_category;

};

class Appetizer : public FoodItem{
public:
    Appetizer(const std::string& ItemName, double ItemPrice, bool spicy);
    void display() const override;
private:
    bool isSpicy;
};

class Entree : public FoodItem{
public:
    Entree(const std::string& ItemName, double ItemPrice, int cal);
    void display() const override;
private:
    int calories; 
};

class Dessert : public FoodItem{
public:
    Dessert(const std::string& ItemName, double ItemPrice, bool nuts);
    void display() const override;
private:
    bool containNuts;
};

class Drink : public FoodItem {
public:
    Drink(const std::string& itemName, double itemPrice, bool alcoholic);
    void display() const override;
private:
    bool isAlcoholic;
};

#endif