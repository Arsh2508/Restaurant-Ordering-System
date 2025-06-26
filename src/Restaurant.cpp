#include <iostream>
#include <limits>
#include "Restaurant.hpp"
#include "Customer.hpp"
#include "Order.hpp"
#include "Dish.hpp"

Restaurant::Restaurant(const Restaurant &other)
    : menu{other.menu}
{
    for(size_t i = 0; i < other.customers.size(); ++i)
    {
        customers.push_back(new Customer(*other.customers[i]));
    }

    for(size_t i = 0; i < other.orders.size(); ++i)
    {
        orders.push_back(other.orders[i]);
    }
}

Restaurant &Restaurant::operator=(const Restaurant &other)
{
    if(this == &other){
        return *this;
    }

    menu = other.menu;

    customers.clear();
    for(size_t i = 0; i < other.customers.size(); ++i){
        customers.push_back(new Customer(*other.customers[i]));
    }

    orders.clear();
    for(size_t i = 0; i < other.orders.size(); ++i)
    {
        orders.push_back(other.orders[i]);
    }

    return *this;

}

Restaurant::Restaurant(Restaurant &&other) noexcept
    : menu{std::move(other.menu)}
    , customers{std::move(other.customers)}
    , orders{std::move(other.orders)}
{
    other.customers.clear();
    other.orders.clear();
}

Restaurant &Restaurant::operator=(Restaurant &&other) noexcept
{
    if(this == &other){
        return *this;
    }

    menu = std::move(other.menu);

    customers = std::move(other.customers);
    orders = std::move(other.orders);

    other.customers.clear();
    other.orders.clear();

    return *this;
}

Restaurant::~Restaurant()
{
    for(size_t i = 0; i < customers.size(); ++i)
    {
        delete customers[i];
    }
}

void Restaurant::showMenu() const
{
    menu.displayMenu();
}

Customer* Restaurant::getCustomerByName(const std::string &name) const
{
    for(size_t i = 0; i < customers.size(); ++i)
    {
        if(customers[i]->getName() == name){
            return customers[i];
        }
    }

    return nullptr;
}

void Restaurant::placeNewOrder(std::string &customerName)
{
    int count = 0;
    while(getCustomerByName(customerName)){
        ++count;
        std::cout<<"The custormer with the name"<<customerName<<" already exists:\n"
                <<"Renaminig to "<<customerName<<count<<std::endl;
        customerName += std::to_string(count);
    }
    std::cout<<"Enter custormers contact info: ";
    std::string contact;
    std::getline(std::cin, contact);
    customers.emplace_back(new Customer(customerName, contact));

    acceptOrder(customers.back());
  

}

void Restaurant::viewCustomerOrderHistory(const std::string &customerName) const
{
    for(size_t i = 0; i < customers.size(); ++i)
    {
        if(customers[i]->getName() == customerName){
            customers[i]->viewOrderHistory();
            return;
        }
    }
    std::cout << "No customer found with name "<< customerName <<std::endl;
}

void Restaurant::setMenu()
{
    int choice;
    std::cout<<"Enter type\n"
            <<"1) Appetizer: \n"
            <<"2) Entree: \n"
            <<"3) Dessert: \n";
    std::cin>>choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear buffer


    std::string dishName;
    double dishPrice;

    std::cout<<"Enter name: ";
    std::getline(std::cin, dishName);

    std::cout<<"Enter price: ";
    std::cin>>dishPrice;

    Dish* dish = nullptr;


    switch(choice){
        case 1:
            int isSpicy;
            std::cout<<"Is this Appetizer spicy\n"
                    <<"Enter 1 for spicy or 0 for not spicy: ";
            std::cin>>isSpicy;
            if (std::cin.fail()) {  
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                isSpicy = 1;
            }
            dish = new Appetizer(dishName, dishPrice, isSpicy);
            break;
        case 2:
            int calories;
            std::cout<<"Enter calories: ";
            std::cin>>calories;
            dish = new Entree(dishName, dishPrice, calories);
            break;
        case 3:
            int nuts;
            std::cout<<"Does this Dessert contain nuts\n"
                    <<"Enter 1 for yes or 0 for no : ";
            std::cin>>nuts;
            if (std::cin.fail()) {  
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                nuts = 1;
            }
            dish = new Dessert(dishName, dishPrice, nuts);
            break;
        default:
            std::cout<<"Invalid input!";
            return;
    }

    if(dish){
        menu.addDish(dish);
    }
}

void Restaurant::acceptOrder(Customer* customer)
{
    Order order(customer);

    int choice = 0;

    do{
        std::cout<<"----------------------\n"
                <<"1) Order dish\n"
                <<"2) Accept order\n";
        std::cin>>choice;

        switch(choice){
            case 1:{
                std::string dishName;
                std::cout<<"Enter dish name: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, dishName);

                Dish* dish = menu.getDishByName(dishName);

                if(dish){
                    order.addDish(dish);
                    std::cout << "Added " << dish->getName() << " (" << dish->getPrice() << "$)\n";
                }
                else{
                    std::cout<<"No such dish found with name "<<dishName<<std::endl;
                }
                break;
            }
            case 2:{
                std::cout<<"Order is accepted:\n";
                order.calculateTotal();
                orders.push_back(order);
                customer->placeOrder(order);
                std::cout << "Order finalized. Total = " << order.getTotolPrice()<< "$\n";
                break;
            }
            default:
                std::cout<<"Invalid input! Try again:\n";
                break;
        }
    }
    while(choice != 2);


}

void Restaurant::displayCustomers() const
{

    if(customers.empty()){
        std::cout<<"There is no customers yet: \n";
    }

    for(size_t i = 0; i < customers.size(); ++i)
    {
        std::cout<<"----------------------------------\n"
                <<"Name: "<<customers[i]->getName()
                <<"\nContact info: "<<customers[i]->getContactInfo()
                <<"\n----------------------------------\n";
    }
}

void Restaurant::displayOrders() const
{
    if(orders.empty()){
        std::cout<<"No orders yet!\n";
        return;
    }
    
    for(size_t i = 0; i < orders.size(); ++i){
        orders[i].displayOrder();
    }
}
