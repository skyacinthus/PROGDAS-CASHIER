#include <iostream>
#include <string>
using namespace std;

#define MENU_COUNT 5

int view();
void order();
void removeItem();
double calculateTotal();

struct MenuItem{
    string name;
    double price;
    int quantity;
};

MenuItem menu[MENU_COUNT] = {
    {"Burger", 15000, 0},
    {"Fries", 10000, 0},
    {"Soda", 5000, 0},
    {"Salad", 12000, 0},
    {"Ice Cream", 8000, 0}
};

int main(){
    string customer;
    int choice;

    cout << "WELCOME TO xxx CAFE!" << endl;
    cout << "ENTER NAME (Nickname): ";
    cin >> customer;
    cin.ignore();

    cout << "\n==========================\n";
    cout << "       WELCOME, " << customer << "!" << endl;
    cout << "WHAT WOULD YOU LIKE TO ORDER?" << endl;

    order();

    while (1){
        choice = view();

        if (choice == 1){
            order();
        }
        else if (choice == 2){
            removeItem();
        }
        else if (choice == 3){
            int tax = calculateTotal() * 0.1;
            cout << "\n\n\n=========================\n";
            cout << "ITEMS" << endl;

            for (int i = 0; i < MENU_COUNT; i++){
                if (menu[i].quantity > 0) {
                    cout << menu[i].name << " x" << menu[i].quantity << " - Rp." << menu[i].price * menu[i].quantity << endl;
                }
            }

            cout << "=========================\n";
            cout << "SUBTOTAL: Rp." << calculateTotal() << endl;
            cout << "TAX (10%): Rp." << tax << endl;
            cout << "=========================\n";
            cout << "TOTAL AMOUNT DUE: Rp." << calculateTotal() + tax << endl;
            cout << "THANK YOU FOR YOUR ORDER, " << customer << "!" << endl;
            break;
        }
        else if (choice == 4){
            cout << "THANK YOU, " << customer << "! SEE YOU NEXT TIME!" << endl;
            break;
        }
        else{
            cout << "INVALID OPTION!\n";
        }
    }

    return 0;
}

void order(){
    int choice;

    cout << "\n========== MENU ==========\n";
    for (int i = 0; i < MENU_COUNT; i++){
        cout << i + 1 << ". " << menu[i].name << " - Rp." << menu[i].price << endl;
    }
    cout << "==========================\n";
    cout << "SELECT: ";
    cin >> choice;
    cin.ignore();

    if (choice < 1 || choice > MENU_COUNT){
        cout << "INVALID ORDER!\n";
        return;
    }

    menu[choice - 1].quantity++;
    cout << "YOUR ORDER IS ADDED!\n";
}

void removeItem(){
    int choice;
    int count;

    cout << "\n========== REMOVE ==========\n";
    for (int i = 0; i < MENU_COUNT; i++){
        if (menu[i].quantity > 0) {
            cout << count << ". " << menu[i].name << " (x" << menu[i].quantity << ")\n";
            count++;
        }
    }
    cout << "============================\n";

    cout << "SELECT ITEM TO REMOVE: ";
    cin >> choice;
    cin.ignore();

    if (choice < 1 || choice > MENU_COUNT || menu[choice - 1].quantity == 0){
        cout << "INVALID\n";
        return;
    }

    menu[choice - 1].quantity--;
    cout << "ITEM REMOVED!\n";
}

int view() {
    int choice;
    int count = 1;

    cout << "\n========== CART ==========\n";
    for (int i = 0; i < MENU_COUNT; i++){
        if (menu[i].quantity > 0) {
            cout << count << ". " << menu[i].name << " x" << menu[i].quantity << " - Rp." << menu[i].price * menu[i].quantity << endl;
            count++;
        }
    }
    cout << "==========================\n";
    cout << "TOTAL: Rp." << calculateTotal() << endl;
    cout << "==========================\n";
    cout << "1. ORDER MORE\n";
    cout << "2. REMOVE ITEM\n";
    cout << "3. CHECKOUT\n";
    cout << "4. EXIT\n";
    cout << "SELECT: ";
    cin >> choice;
    cin.ignore();

    return choice;
}

double calculateTotal(){
    double total = 0;

    for (int i = 0; i < MENU_COUNT; i++){
        total += menu[i].price * menu[i].quantity;
    }

    return total;
}
