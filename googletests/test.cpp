#include <gtest/gtest.h>
#include "Restaurant.hpp"
#include "Customer.hpp"
#include <string>


TEST(RestaurantTest, AddCustomer) {
    Restaurant r;
    std::string name = "Alice";
    r.placeNewOrder(name);
    Customer* c = r.getCustomerByName(name);
    EXPECT_NE(c, nullptr); 
}

TEST(CustomerTest, CustomerName) {
    Customer c{"Bob","123456"};
    EXPECT_EQ(c.getName(),"Bob");
}

