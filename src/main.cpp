#include <iostream>
#include <limits>
#include "Restaurant.hpp"

int main()
{
    Restaurant restaurant;

    int choice = 0;

    do {
        std::cout<<"----------------------------\n"
                <<"1) Add dish\n"
                <<"2) Display menu\n"
                <<"3) Place new order\n"
                <<"4) Display customers\n"
                <<"5) Display orders\n"
                <<"6) View customer's order History\n"
                <<"0) Exit\n"
                <<"----------------------------\n: ";
        
        std::cin>>choice;

        switch (choice){
            case 1:
                restaurant.setMenu();
                break;
            case 2:
                restaurant.showMenu();
                break;
            case 3:
            {
                std::string name;
                std::cout<<"Input custormer's name: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, name);
                restaurant.placeNewOrder(name);
                break;
            }
            case 4:
                restaurant.displayCustomers();
                break;
            case 5:
                restaurant.displayOrders();
                break;
            case 6:
            {
                std::string name;
                std::cout<<"Enter custormer's name to view orders: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, name);
                restaurant.viewCustomerOrderHistory(name);
                break;
            }
            case 0:
                std::cout<<"Exiting...\n";
                break;
            default:
                std::cout<<"Invalid input! Try again: \n";
                break;
        }
    }
    while (choice != 0);
        
  

    return 0;
}
