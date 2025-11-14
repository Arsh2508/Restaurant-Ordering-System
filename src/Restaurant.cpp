#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>
#include "Restaurant.hpp"
#include "Customer.hpp"
#include "Order.hpp"
#include "FoodItem.hpp"


void Restaurant::showMenu() const
{
    menu.displayMenu();
}

Customer* Restaurant::getCustomerByName(const std::string &name) const
{
    for(size_t i = 0; i < customers.size(); ++i)
    {
        if(customers[i]->getName() == name){
            return customers[i].get();
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

    acceptOrder(customers.back().get());
  

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
    int isSpicy = 0;
    int calories = 0;
    int nuts = 0;
    int alcoholic = 0;
    
    std::cout<<"Enter type\n"
            <<"1) Appetizer: \n"
            <<"2) Entree: \n"
            <<"3) Dessert: \n"
            <<"4) Drink: \n";
    std::cin>>choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear buffer

    std::string dishName;
    double dishPrice;

    std::cout<<"Enter name: ";
    std::getline(std::cin, dishName);

    std::cout<<"Enter price: ";
    std::cin>>dishPrice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear buffer

    std::shared_ptr<FoodItem> item = nullptr;

    switch(choice){
        case 1:{
            std::cout<<"Is this Appetizer spicy\n"
                    <<"Enter 1 for spicy or 0 for not spicy: ";
            std::cin>>isSpicy;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (std::cin.fail()) {  
                std::cin.clear();
                isSpicy = 0;
            }
            item = std::make_shared<Appetizer>(dishName, dishPrice, isSpicy);
            break;
        }
        case 2:{
            std::cout<<"Enter calories: ";
            std::cin>>calories;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (std::cin.fail()) {  
                std::cin.clear();
                calories = 0;
            }
            item = std::make_shared<Entree>(dishName, dishPrice, calories);
            break;
        }
        case 3:{
            std::cout<<"Does this Dessert contain nuts\n"
                    <<"Enter 1 for yes or 0 for no : ";
            std::cin>>nuts;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (std::cin.fail()) {  
                std::cin.clear();
                nuts = 0;
            }
            item = std::make_shared<Dessert>(dishName, dishPrice, nuts);
            break;
        }
        case 4:{
            std::cout<<"Is this Drink alcoholic\n"
                    <<"Enter 1 for yes or 0 for no : ";
            std::cin>>alcoholic;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (std::cin.fail()) {  
                std::cin.clear();
                alcoholic = 0;
            }
            item = std::make_shared<Drink>(dishName, dishPrice, alcoholic);
            break;
        }
        default:
            std::cout<<"Invalid input!";
            return;
    }

    if(item){
        menu.addItem(item);
        std::cout << "Added " << item->getName() << " to menu.\n";
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
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cout << "Invalid input! Please enter a number.\n";
            continue; 
        }        

        switch(choice){
            case 1:{
                std::string dishName;
                std::cout<<"Enter dish name: ";
                std::getline(std::cin, dishName);

                FoodItem* itemPtr = menu.getItemByName(dishName);

                if(itemPtr){
                    const auto& menuItems = menu.getItems();
                    for(const auto& item : menuItems) {
                        if(item->getName() == dishName) {
                            order.addItem(item);
                            std::cout << "Added " << item->getName() << " (" << item->getPrice() << "$)\n";
                            break;
                        }
                    }
                }
                else{
                    std::cout<<"No such dish found with name "<<dishName<<std::endl;
                }
                break;
            }
            case 2:{
                std::cout<<"Order is accepted:\n";
                order.calculateTotal();
                orders.push_back(std::make_shared<Order>(order));
                customer->placeOrder(order);
                std::cout << "Order finalized. Total = " << order.getTotalPrice()<< "$\n";
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
        orders[i]->displayOrder();
    }
}

Restaurant::Restaurant()
{
    loadMenuFromJSON("data/menu.json");
}

void Restaurant::loadMenuFromJSON(const std::string& filePath)
{
    std::ifstream file(filePath);
    
    if (!file.is_open()) {
        file.open("../data/menu.json");
    }
    if (!file.is_open()) {
        file.open("../../data/menu.json");
    }
    if (!file.is_open()) {
        file.open("data/menu.json");
    }
    
    if (!file.is_open()) {
        std::cerr << "Warning: Could not open menu file. Tried multiple paths.\n";
        return;
    }

    std::string line;
    std::string jsonContent;
    
    while (std::getline(file, line)) {
        jsonContent += line + "\n";
    }
    file.close();

    size_t pos = 0;
    int itemCount = 0;
    
    while ((pos = jsonContent.find("\"name\"", pos)) != std::string::npos) {
        size_t nameStart = jsonContent.find("\"", pos + 7);
        if (nameStart == std::string::npos) break;
        
        size_t nameEnd = jsonContent.find("\"", nameStart + 1);
        if (nameEnd == std::string::npos) break;
        
        std::string name = jsonContent.substr(nameStart + 1, nameEnd - nameStart - 1);

        size_t catPos = jsonContent.find("\"category\"", nameEnd);
        if (catPos == std::string::npos) break;
        
        size_t catStart = jsonContent.find("\"", catPos + 11);
        if (catStart == std::string::npos) break;
        
        size_t catEnd = jsonContent.find("\"", catStart + 1);
        if (catEnd == std::string::npos) break;
        
        std::string category = jsonContent.substr(catStart + 1, catEnd - catStart - 1);

        size_t pricePos = jsonContent.find("\"price\"", catEnd);
        if (pricePos == std::string::npos) break;
        
        size_t colonPos = jsonContent.find(":", pricePos);
        if (colonPos == std::string::npos) break;
        
        size_t priceStart = jsonContent.find_first_not_of(" \t\n\r", colonPos + 1);
        size_t priceEnd = jsonContent.find_first_of(",}", priceStart);
        if (priceEnd == std::string::npos) break;
        
        std::string priceStr = jsonContent.substr(priceStart, priceEnd - priceStart);
        double price = std::stod(priceStr);

        std::shared_ptr<FoodItem> item = nullptr;

        if (category == "Appetizer") {
            item = std::make_shared<Appetizer>(name, price, false);
        } else if (category == "Main" || category == "Entree") {
            item = std::make_shared<Entree>(name, price, 0);
        } else if (category == "Dessert") {
            item = std::make_shared<Dessert>(name, price, false);
        } else if (category == "Drink" || category == "Side") {
            item = std::make_shared<Drink>(name, price, false);
        }
        if (item) {
            menu.addItem(item);
            itemCount++;
        }

        pos = priceEnd;
    }

    if (itemCount > 0) {
        std::cout << "Menu loaded: " << itemCount << " items loaded from JSON.\n" << std::endl;
    } else {
        std::cout << "Warning: No menu items found in JSON file.\n" << std::endl;
    }
}


