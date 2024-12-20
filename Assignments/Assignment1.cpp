/*Inputs and Functions:

Inputs:

Add Item:
Item ID (integer)
Item Name (string)
Quantity (integer)
Reorder Level (integer)

Update Stock:
Item ID (integer)
Quantity to add (integer)

View Inventory:
No inputs required.

Exit:
No inputs required.

Functions:
addItem(int id, string name, int quantity, int reorderLevel): Adds a new item to the inventory.
updateStock(int id, int quantity): Updates the stock of an existing item based on its ID.
viewInventory(): Displays
*/



CODE:

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

// Class representing an item in the inventory
class Item {
public:
    int id;                // Unique identifier for the item
    string name;          // Name of the item
    int quantity;         // Current quantity of the item in stock
    int reorderLevel;     // Minimum quantity before reorder is needed

    // Constructor to initialize an item with its attributes
    Item(int id, string name, int quantity, int reorderLevel)
        : id(id), name(name), quantity(quantity), reorderLevel(reorderLevel) {}
};

// Class representing the inventory system
class Inventory {
private:
    vector<Item> items;   // Vector to store items in the inventory

public:
    // Function to add a new item to the inventory
    void addItem(int id, string name, int quantity, int reorderLevel) {
        items.emplace_back(id, name, quantity, reorderLevel); // Add item to the vector
        cout << "Item added.\n"; // Confirmation message for item addition
    }

    // Function to update the stock of an existing item
    void updateStock(int id, int quantity) {
        for (auto& item : items) { // Iterate through the items in the inventory
            if (item.id == id) { // Check if the item ID matches
                item.quantity += quantity; // Update the quantity of the item
                cout << "Stock updated.\n"; // Confirmation message for stock update
                return; // Exit the function after updating
            }
        }
        cout << "Item not found.\n"; // Message if the item ID does not exist
    }

    // Function to view all items in the inventory
    void viewInventory() {
        cout << "Inventory:\n"; // Header for inventory display
        for (const auto& item : items) { // Iterate through the items
            // Display item details: ID, Name, Quantity, and Reorder Level
            cout << "ID: " << item.id << ", Name: " << item.name 
                 << ", Quantity: " << item.quantity 
                 << ", Reorder Level: " << item.reorderLevel << endl;
            // Check if the item quantity is below the reorder level
            if (item.quantity < item.reorderLevel) {
                cout << "ALERT: Low stock for " << item.name << "!\n"; // Low stock alert
            }
        }
    }
};

// Main function to run the inventory management system
int main() {
    Inventory inventory; // Create an Inventory object to manage items
    int choice; // Variable to store user choice for menu options

    do {
        // Display menu options for the user
        cout << "\n1. Add Item\n2. Update Stock\n3. View Inventory\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice; // Get user choice

        switch (choice) {
            case 1: { // Case for adding a new item
                int id, quantity, reorderLevel; // Variables for item details
                string name; // Variable for item name
                cout << "Enter Item ID, Name, Quantity, Reorder Level: ";
                cin >> id >> name >> quantity >> reorderLevel; // Get item details from user
                inventory.addItem(id, name, quantity, reorderLevel); // Add item to inventory
                break; // Exit the case
            }
            case 2: { // Case for updating stock of an existing item
                int id, quantity; // Variables for item ID and quantity to add
                cout << "Enter Item ID and quantity to add: ";
                cin >> id >> quantity; // Get item ID and quantity from user
                inventory.updateStock(id, quantity); // Update stock for the specified item
                break; // Exit the case
            }
            case 3: // Case for viewing the inventory
                inventory.viewInventory(); // Display the current inventory
                break; // Exit the case
            case 4: // Case for exiting the program
                cout << "Exiting.\n"; // Exit message
                break; // Exit the case
            default: // Case for handling invalid choices
                cout << "Invalid choice.\n"; // Error message for invalid input
        }
    } while (choice != 4); // Continue looping until the user chooses to exit

    return 0; // Exit the program
}



/*
OUTPUT:

1. Add Item
2. Update Stock
3. View Inventory
4. Exit

Enter your choice: 1
Enter Item ID, Name, Quantity, Reorder Level:
12345
BAT
60
2
Item added.

1. Add Item
2. Update Stock
3. View Inventory
4. Exit

Enter your choice: 3
Inventory:
ID: 12345, Name: BAT, Quantity: 60, Reorder Level: 2

1. Add Item
2. Update Stock
3. View Inventory
4. Exit

Enter your choice: 4
Exiting.
*/
