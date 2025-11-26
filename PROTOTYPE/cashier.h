#ifndef CASHIER_H
#define CASHIER_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

struct MenuItem {
    string name;
    double price;
    int quantity;
};

class Cashier {
private:
    vector<MenuItem> menu; 
    string customerName;

public:
    Cashier() : customerName("") {}

    // Load menu from file (menu.txt)
    bool loadMenuFromFile(const string& filename) {
        menu.clear();

        ifstream file(filename);
        if (!file.is_open()) return false;

        string line;
        while (getline(file, line)) {
            if (line.empty()) continue;

            size_t pos = line.find(';');
            if (pos == string::npos) continue;

            string name = line.substr(0, pos);
            double price = stod(line.substr(pos + 1));

            menu.push_back({ name, price, 0 });
        }

        file.close();
        return true;
    }

    // Customer
    void setCustomerName(const string& name) { customerName = name; }
    string getCustomerName() const { return customerName; }

    // Menu operations
    int getMenuCount() const { return menu.size(); }

    MenuItem getMenuItem(int index) const {
        if (index >= 0 && index < menu.size()) return menu[index];
        return { "", 0, 0 };
    }

    string getMenuItemName(int index) const {
        if (index >= 0 && index < menu.size()) return menu[index].name;
        return "";
    }

    double getMenuItemPrice(int index) const {
        if (index >= 0 && index < menu.size()) return menu[index].price;
        return 0.0;
    }

    bool addToOrder(int menuIndex, int quantity) {
        if (menuIndex < 0 || menuIndex >= menu.size() || quantity < 1)
            return false;
        menu[menuIndex].quantity += quantity;
        return true;
    }

    bool removeFromOrder(int menuIndex, int quantity) {
        if (menuIndex < 0 || menuIndex >= menu.size() || quantity < 1)
            return false;
        if (menu[menuIndex].quantity < quantity)
            return false;

        menu[menuIndex].quantity -= quantity;
        return true;
    }

    void clearCart() {
        for (auto& item : menu)
            item.quantity = 0;
    }

    vector<MenuItem> getCartItems() const {
        vector<MenuItem> items;
        for (const auto& it : menu)
            if (it.quantity > 0) items.push_back(it);
        return items;
    }

    bool isCartEmpty() const {
        for (const auto& it : menu)
            if (it.quantity > 0) return false;
        return true;
    }

    double calculateSubtotal() const {
        double total = 0;
        for (const auto& it : menu)
            total += it.price * it.quantity;
        return total;
    }

    double calculateTax() const {
        return calculateSubtotal() * 0.1;
    }

    double calculateDiscount(const string& code) const {
        if (code == "SALMAIMOET" || code == "REFAIMOET" || code == "AYESHAIMOET")
            return calculateSubtotal() * 0.1;
        return 0;
    }

    double calculateTotal(double discount = 0) const {
        return calculateSubtotal() + calculateTax() - discount;
    }

    bool validatePayment(const string& method, double amount, double totalDue) const {
        if (method == "CASH" || method == "cash") {
            return amount >= totalDue;
        }
        else if (method == "CARD" || method == "card" ||
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
