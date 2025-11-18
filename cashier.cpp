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
};

MenuItem menu[MENU_COUNT] = {
    {"Burger", 15000},
    {"Fries", 10000},
    {"Soda", 5000},
    {"Salad", 1200},
    {"Ice Cream", 8000}
};
MenuItem orders[MAX_ITEMS];
int ordercount = 0;
int menucount = MENU_COUNT;

int main() {
    string user;
    int choice;
    
    cout << "=========================" << endl;
    cout << "ENTER NAME (Nickname): ";
    cin >> user; 
    cin.ignore();
    
    cout << "\n=========================\n";
    cout << "WELCOME, " << user << "!" << endl;
    cout << "WHAT WOULD YOU LIKE TO ORDER TODAY?" << endl;
    
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
                cout << i + 1 << ". " << orders[i].name << " - Rp." << orders[i].price << endl;
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
    
    cout << "========= MENU =========\n";
    for(int i = 0; i < menucount; i++) {
        cout << i + 1 << ". " << menu[i].name << " - Rp." << menu[i].price << endl;
    }
    cout << "=========================\n";
    cout << "SELECT: ";
    cin >> choice;
    cin.ignore();
    
    if(choice < 1 || choice > menucount) {
        cout << "INVALID ORDER!\n";
        return;
    }
    
    orders[ordercount].name = menu[choice - 1].name;
    orders[ordercount].price = menu[choice - 1].price;
    ordercount++;
    cout << "YOUR ORDER IS ADDED!\n";
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
    
    cout << "ITEM REMOVED!\n";
    for(int i = del - 1; i < count - 1; i++) {
        orders[i] = orders[i+1];
    }
    ordercount--;
}

int view(int count) {
    int choice;
    double totalPrice = calculateTotal(ordercount);
    
    cout << "========= CART =========\n";
    for(int i = 0; i < count; i++) {
        cout << i + 1 << ". " << orders[i].name << " - Rp." << orders[i].price << endl;
    }
    cout << "========================\n";
    cout << "TOTAL: Rp." << totalPrice << endl;
    cout << "========================\n";
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
        total += orders[i].price;
    }
    return total;
}