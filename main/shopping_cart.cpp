#include<iostream>
using namespace std;

// Constants for tax rate, discount rate, and maximum items in the cart
const double tax_rate = 0.07;
const double disc_rate = 0.10;
const int max_item = 10;

// Function declarations or prototypes
void addItem(string cart[], double prices[], int &itemcount);
void removeItem(string cart[], double prices[], int &itemcount);
void displayCart(string cart[], double prices[], int itemcount);
double calculateTotal(double prices[], int itemcount);
double applyDiscount(double total);
double applyTax(double total);
void displayMenu();

int main() {   
    string cart[max_item]; // Array to store item names
    double prices[max_item]; // Array to store item prices
    int itemcount = 0; // Current count of items in the cart
    int choice = 0; // User's menu choice - INITIALIZED

    // Display the application header
    cout << "******************************************************" << endl;
    cout << "                  SHOPPING CART SYSTEM                " << endl;

    while (choice != 5) {
        displayMenu(); // Display menu each iteration
        cout << "\t\tEnter your choice: ";
        cin >> choice;

        // Handle user choices with a switch statement
        switch (choice) {
            case 1:
                addItem(cart, prices, itemcount);
                break;
            case 2:
                removeItem(cart, prices, itemcount);
                break;	 
            case 3:
                displayCart(cart, prices, itemcount);
                break;
            case 4: {
                double total = calculateTotal(prices, itemcount);
                total = applyDiscount(total);
                total = applyTax(total);
                cout << "Total price after discount and tax: $" << total << endl;
                break;
            }
            case 5:
                cout << "Thank you for shopping! Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";   		            
        }
    }
    return 0;
}

// Function to display menu
void displayMenu() {
    cout << "******************************************************" << endl;
    cout << "                     <<<< MENU >>>>                   " << endl;
    cout << "\n";
    cout << "                 1) Add Item                          " << endl;
    cout << "                 2) Remove Item                       " << endl;
    cout << "                 3) Display Cart                      " << endl;
    cout << "                 4) Calculate Total and Checkout      " << endl;
    cout << "                 5) Exit                              " << endl;
    cout << "******************************************************" << endl;
}

// Function to add an item to the cart
void addItem(string cart[], double prices[], int &itemcount) {
    if (itemcount < max_item) {
        string item;
        double price;

        // Get item details from the user
        cout << "Enter the item name: ";
        cin.ignore();
        getline(cin, item);  
        cout << "Enter the item price: $";
        cin >> price; 

        // Add item to the cart and update count
        cart[itemcount] = item;
        prices[itemcount] = price;
        itemcount++;  

        cout << item << " has been added to your cart.\n";
    } else {
        cout << "Your cart is full! Cannot add more items.\n";
    }
}
 
// Function to remove an item from the cart
void removeItem(string cart[], double prices[], int &itemcount) {
    if (itemcount == 0) {
        cout << "Your cart is empty. Nothing to remove.\n";
        return;
    }

    string itemToRemove;
    bool itemFound = false;

    // Get the name of the item to remove
    cout << "Enter the name of the item to remove: ";
    cin.ignore();
    getline(cin, itemToRemove);

    // Search and remove the item from the cart
    for (int i = 0; i < itemcount; i++) {
        if (cart[i] == itemToRemove) {
            for (int j = i; j < itemcount - 1; j++) {
                cart[j] = cart[j + 1];
                prices[j] = prices[j + 1];
            }
            itemcount--;
            itemFound = true;
            cout << itemToRemove << " has been removed from your cart.\n";
            break;
        }
    }

    if (!itemFound) {
        cout << "Item not found in the cart.\n";
    }
}
 
// Function to display the cart contents
void displayCart(string cart[], double prices[], int itemcount) {
    if (itemcount == 0) {
        cout << "Your cart is empty.\n";
    } else {
        cout << "\n--- YOUR SHOPPING CART ---\n";
        for (int i = 0; i < itemcount; i++) {
            cout << (i + 1) << ". " << cart[i] << " - $" << prices[i] << endl;
        }
    }
}

// Function to calculate the total price of items in the cart
double calculateTotal(double prices[], int itemcount) {
    double total = 0.0;
    for (int i = 0; i < itemcount; i++) {
        total += prices[i];
    }
    return total;
}

// Function to apply a discount to the total price
double applyDiscount(double total) {
    double discount = total * disc_rate;
    double discountedTotal = total - discount;
    cout << "Discount applied: -$" << discount << endl;
    return discountedTotal;
}

// Function to apply tax to the total price
double applyTax(double total) {
    double tax = total * tax_rate;
    double finalTotal = total + tax;
    cout << "Tax applied: +$" << tax << endl;
    return finalTotal;
}