#ifndef CASHIER_H
#define CASHIER_H

#include <string>
#include <vector>
using namespace std;

struct MenuItem {
    string name;
    double price;
    int quantity;
};

class Cashier {
private:
    static const int MENU_COUNT = 5;
    MenuItem menu[MENU_COUNT] = {
        {"Burger", 15000, 0},
        {"Fries", 10000, 0},
        {"Soda", 5000, 0},
        {"Salad", 12000, 0},
        {"Ice Cream", 8000, 0}
    };
    string customerName;

public:
    Cashier() : customerName("") {}
    
    // Customer management
    void setCustomerName(const string& name) {
        customerName = name;
    }
    
    string getCustomerName() const {
        return customerName;
    }
    
    // Menu operations
    int getMenuCount() const {
        return MENU_COUNT;
    }
    
    MenuItem getMenuItem(int index) const {
        if (index >= 0 && index < MENU_COUNT) {
            return menu[index];
        }
        return {"", 0, 0};
    }
    
    string getMenuItemName(int index) const {
        if (index >= 0 && index < MENU_COUNT) {
            return menu[index].name;
        }
        return "";
    }
    
    double getMenuItemPrice(int index) const {
        if (index >= 0 && index < MENU_COUNT) {
            return menu[index].price;
        }
        return 0;
    }

    bool addToOrder(int menuIndex, int quantity) {
        if (menuIndex < 0 || menuIndex >= MENU_COUNT || quantity < 1) {
            return false;
        }
        menu[menuIndex].quantity += quantity;
        return true;
    }
    
    bool removeFromOrder(int menuIndex, int quantity) {
        if (menuIndex < 0 || menuIndex >= MENU_COUNT || quantity < 1) {
            return false;
        }
        if (menu[menuIndex].quantity < quantity) {
            return false;
        }
        menu[menuIndex].quantity -= quantity;
        return true;
    }
    
    void clearCart() {
        for (int i = 0; i < MENU_COUNT; i++) {
            menu[i].quantity = 0;
        }
    }
    
    vector<MenuItem> getCartItems() const {
        vector<MenuItem> items;
        for (int i = 0; i < MENU_COUNT; i++) {
            if (menu[i].quantity > 0) {
                items.push_back(menu[i]);
            }
        }
        return items;
    }
    
    bool isCartEmpty() const {
        for (int i = 0; i < MENU_COUNT; i++) {
            if (menu[i].quantity > 0) {
                return false;
            }
        }
        return true;
    }
    
    double calculateSubtotal() const {
        double total = 0;
        for (int i = 0; i < MENU_COUNT; i++) {
            total += menu[i].price * menu[i].quantity;
        }
        return total;
    }
    
    double calculateTax() const {
        return calculateSubtotal() * 0.1;
    }
    
    double calculateDiscount(const string& code) const {
        if (code == "SALMAIMOET") {
            return calculateSubtotal() * 0.1;
        }
        return 0;
    }
    
    double calculateTotal(double discount = 0) const {
        return calculateSubtotal() + calculateTax() - discount;
    }
    
    // Payment
    bool validatePayment(const string& method, double amount, double totalDue) const {
        if (method == "CASH" || method == "cash") {
            return amount >= totalDue;
        } else if (method == "CARD" || method == "card" || 
                   method == "QRIS" || method == "qris") {
            return true;
        }
        return false;
    }
    
    double calculateChange(double paid, double totalDue) const {
        return paid - totalDue;
    }
};

#endif