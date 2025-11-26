#include <iostream>
#include "cashier.h"  // Include your backend
using namespace std;

// Keep your UI functions but use cashierSystem
Cashier cashier;  // Global backend instance
void order();
int view();

int main() {
    string customer;
    int choice;
    
    cout << "WELCOME TO xxx!" << endl;
    cout << "ENTER NAME (Nickname): ";
    getline(cin, customer);
    cashier.setCustomerName(customer);
    
    cout << "\n==========================\n";
    cout << "     WELCOME, " << customer << "!" << endl;
    cout << "WHAT WOULD YOU LIKE TO ORDER?" << endl;
    
    order();
    
    while (true) {
        choice = view();
        
        if (choice == 1) {
            order();
        } 
        else if (choice == 2){
            int choice, qty;
            
            vector<MenuItem> cartItems = cashier.getCartItems();
            
            if (cartItems.empty()) {
                cout << "CART IS EMPTY!\n";
                cout << "============================\n";
                continue;
            }
            
            cout << "============================\n";
            for (size_t i = 0; i < cartItems.size(); i++) {
                cout << i + 1 << ". " << cartItems[i].name 
                    << " (x" << cartItems[i].quantity << ")\n";
            }
            cout << "============================\n";
            cout << "SELECT ITEM TO REMOVE: ";
            cin >> choice;
            cin.ignore();
            
            if (choice < 1 || choice > (int)cartItems.size()) {
                cout << "INVALID SELECTION!\n";
                continue;
            }
            
            int menuIndex = -1;
            int count = 0;
            for (int i = 0; i < cashier.getMenuCount(); i++) {
                if (cashier.getMenuItem(i).quantity > 0) {
                    count++;
                    if (count == choice) {
                        menuIndex = i;
                        break;
                    }
                }
            }
            
            cout << "HOW MANY " << cartItems[choice - 1].name 
                << "'s WOULD YOU LIKE TO REMOVE? ";
            cin >> qty;
            cin.ignore();
            
            if (cashier.removeFromOrder(menuIndex, qty)) {
                cout << "ITEM REMOVED!\n";
            } else {
                cout << "INVALID QUANTITY!\n";
            }
        }
        else if (choice == 3) { 
            char discountChoice;
            string discountCode;
            double discount = 0;
            
            cout << "DO YOU HAVE A DISCOUNT CODE? (Y/N): ";
            cin >> discountChoice;
            cin.ignore();
            
            if (discountChoice == 'Y' || discountChoice == 'y') {
                cout << "ENTER DISCOUNT CODE: ";
                getline(cin, discountCode);
                
                discount = cashier.calculateDiscount(discountCode);
                if (discount > 0) {
                    cout << "\nDISCOUNT CODE APPLIED! YOU GET 10% OFF!\n";
                } else {
                    cout << "\nINVALID DISCOUNT CODE!\n";
                }
            }
            
            cout << "\nCHECKING OUT..." << endl;
            double subtotal = cashier.calculateSubtotal();
            double tax = cashier.calculateTax();
            double total = cashier.calculateTotal(discount);
            
            cout << "\n=========================\n";
            cout << "ITEMS\n";
            vector<MenuItem> items = cashier.getCartItems();
            for (const auto& item : items) {
                cout << item.name << " x" << item.quantity 
                     << " - Rp." << item.price * item.quantity << endl;
            }
            cout << "=========================\n";
            cout << "SUBTOTAL: Rp." << subtotal << endl;
            cout << "TAX (10%): Rp." << tax << endl;
            if (discount > 0) {
                cout << "DISCOUNT: -Rp." << discount << endl;
            }
            cout << "=========================\n";
            cout << "TOTAL AMOUNT: Rp." << total << endl;
            
            string paymentMethod;
            cout << "HOW WOULD YOU LIKE TO PAY? (CASH/CARD/QRIS): ";
            getline(cin, paymentMethod);
            
            if (paymentMethod == "CASH" || paymentMethod == "cash") {
                double cash;
                cout << "ENTER CASH AMOUNT: Rp.";
                cin >> cash;
                cin.ignore();
                
                if (cashier.validatePayment(paymentMethod, cash, total)) {
                    cout << "CHANGE: Rp." << cashier.calculateChange(cash, total) << endl;
                } else {
                    cout << "INSUFFICIENT CASH!" << endl;
                    continue;
                }
            } else if (cashier.validatePayment(paymentMethod, 0, total)) {
                cout << "PROCESSING PAYMENT..." << endl;
                cout << "PAYMENT SUCCESSFUL!" << endl;
            } else {
                cout << "INVALID PAYMENT METHOD!" << endl;
                continue;
            }
            
            cout << "\nTHANK YOU FOR YOUR ORDER, " << customer << "!" << endl;
            break;
        }
        else if (choice == 4) {
            cashier.clearCart();
            cout << "CART CLEARED!\n";
        }
        else if (choice == 5) {
            cout << "THANK YOU, " << customer << "! SEE YOU NEXT TIME!" << endl;
            break;
        }
    }
    
    return 0;
}

void order() {
    int choice, qty;
    
    cout << "\n========== MENU ==========\n";
    for (int i = 0; i < cashier.getMenuCount(); i++) {
        cout << i + 1 << ". " << cashier.getMenuItemName(i) 
             << " - Rp." << cashier.getMenuItemPrice(i) << endl;
    }
    cout << "==========================\n";
    cout << "SELECT: ";
    cin >> choice;
    cin.ignore();
    
    if (choice < 1 || choice > cashier.getMenuCount()) {
        cout << "INVALID ORDER!\n";
        return;
    }
    
    cout << "HOW MANY " << cashier.getMenuItemName(choice - 1) 
         << "'s WOULD YOU LIKE TO ORDER? ";
    cin >> qty;
    cin.ignore();
    
    if (cashier.addToOrder(choice - 1, qty)) {
        cout << "YOUR ORDER IS ADDED!\n";
    } else {
        cout << "INVALID QUANTITY!\n";
    }
}

int view() {
    int choice;
    cout << "\n========== CART ==========\n";
    
    vector<MenuItem> cartItems = cashier.getCartItems();
    for (size_t i = 0; i < cartItems.size(); i++) {
        cout << i + 1 << ". " << cartItems[i].name 
             << " x" << cartItems[i].quantity 
             << " - Rp." << cartItems[i].price * cartItems[i].quantity << endl;
    }
    
    cout << "==========================\n";
    cout << "TOTAL: Rp." << cashier.calculateSubtotal() << endl;
    cout << "==========================\n";
    cout << "1. ORDER MORE\n";
    cout << "2. REMOVE ITEM\n";
    cout << "3. CHECKOUT\n";
    cout << "4. CLEAR CART\n";
    cout << "5. EXIT\n";
    cout << "SELECT: ";
    cin >> choice;
    cin.ignore();
    return choice;
}