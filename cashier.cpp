#include <iostream>
#include <string>
using namespace std;

#define MAX_ITEMS 100
#define MENU_COUNT 5

int view(int  count);
void order(int menucount);
void remove(int count);
double calculateTotal(int count);

struct MenuItem {
    string name;
    double price;
    int quantity;
};

MenuItem menu[MENU_COUNT] = {
    {"Burger", 15000, 0},
    {"Fries", 10000, 0},
    {"Soda", 5000, 0},
    {"Salad", 1200, 0},
    {"Ice Cream", 8000, 0}
};
MenuItem orders[MAX_ITEMS];
int ordercount = 0;
int menucount = MENU_COUNT;

int main() {
    string user;
    int choice;
    
    cout << "WELCOME TO xxx CAFE!" << endl;
    cout << "ENTER NAME (Nickname): ";
    cin >> user; 
    cin.ignore();
    
    cout << "\n==========================\n";
    cout << "       WELCOME, " << user << "!" << endl;
    cout << "WHAT WOULD YOU LIKE TO ORDER?" << endl;
    
    order(menucount);
    
    while(1) {
        choice = view(ordercount);
        
        if(choice == 1) {
            order(menucount);
        }
        else if(choice == 2) {
            remove(ordercount);
        }
        else if(choice == 3) {
            cout << "\n\n\n\n=========================\n";
            cout << "ITEMS" << endl;
            for(int i = 0; i < ordercount; i++) {
                cout << i + 1 << ". " << orders[i].name 
                     << " x" << orders[i].quantity 
                     << " - Rp." << orders[i].price * orders[i].quantity << endl;
            }
            cout << "=========================\n";
            cout << "TOTAL AMOUNT DUE: Rp." << calculateTotal(ordercount) << endl;
            cout << "THANK YOU FOR YOUR ORDER, " << user << "!" << endl;
            break;
        }
    }
    
    return 0;
}

void order(int menucount) {
    int choice;
    
    cout << "\n========== MENU ==========\n";
    for(int i = 0; i < menucount; i++) {
        cout << i + 1 << ". " << menu[i].name << " - Rp." << menu[i].price << endl;
    }
    cout << "==========================\n";
    cout << "SELECT: ";
    cin >> choice;
    cin.ignore();
    
    if(choice < 1 || choice > menucount) {
        cout << "INVALID ORDER!\n";
        return;
    }

    string selectedName = menu[choice - 1].name;
    double selectedPrice = menu[choice - 1].price;

    for (int i = 0; i < ordercount; i++) {
        if (orders[i].name == selectedName) {
            orders[i].quantity++;
            cout << "ADDED ANOTHER " << selectedName << "!\n";
            return;
        }
    }

    orders[ordercount].name = selectedName;
    orders[ordercount].price = selectedPrice;
    orders[ordercount].quantity = 1;
    ordercount++;

    cout << "NEW ITEM ADDED!\n";
}

void remove(int count) {
    int del;

    cout << "SELECT ITEM NUMBER TO REMOVE: ";
    cin >> del;
    cin.ignore();

    if(del > count || del < 1) {
        cout << "INVALID\n";
        return;
    }

    if (orders[del - 1].quantity > 1) {
        orders[del - 1].quantity--;
        cout << "QUANTITY DECREASED!\n";
        return;
    }

    cout << "ITEM REMOVED!\n";
    for(int i = del - 1; i < count - 1; i++) {
        orders[i] = orders[i+1];
    }
    ordercount--;
}

int view(int count) {
    int choice;
    double totalPrice = calculateTotal(ordercount);
    
    cout << "\n========== CART ==========\n";
    for(int i = 0; i < count; i++) {
        cout << i + 1 << ". " << orders[i].name 
             << " x" << orders[i].quantity 
             << " - Rp." << orders[i].price * orders[i].quantity << endl;
    }
    cout << "==========================\n";
    cout << "TOTAL: Rp." << totalPrice << endl;
    cout << "==========================\n";
    cout << "1. ORDER MORE\n";
    cout << "2. REMOVE ITEM\n";
    cout << "3. CHECKOUT\n";
    cout << "SELECT: ";
    cin >> choice;
    cin.ignore();
    
    return choice;
}

double calculateTotal(int count) {
    double total = 0;
    for(int i = 0; i < count; i++) {
        total += orders[i].price * orders[i].quantity;
    }
    return total;
}
