#include <iostream>
using namespace std;

// -----------------------------
// Base Class: FoodItem (Encapsulation + Polymorphism)
class FoodItem {
protected:
    string name;
    float price;

public:
    FoodItem(string n, float p) {
        name = n;
        price = p;
    }

    virtual void show() const {
        cout << name << " - Rs." << price << endl;
    }

    float getPrice() const {
        return price;
    }

    virtual ~FoodItem() {}
};

// -----------------------------
// Derived Class 1: Burger
class Burger : public FoodItem {
public:
    Burger() : FoodItem("Burger", 250) {}

    void show() const override {
        cout << "?? Burger - Rs." << price << endl;
    }
};

// -----------------------------
// Derived Class 2: Pizza
class Pizza : public FoodItem {
public:
    Pizza() : FoodItem("Pizza", 500) {}

    void show() const override {
        cout << "?? Pizza - Rs." << price << endl;
    }
};

// -----------------------------
// Derived Class 3: Drink
class Drink : public FoodItem {
public:
    Drink() : FoodItem("Drink", 100) {}

    void show() const override {
        cout << "?? Drink - Rs." << price << endl;
    }
};

// -----------------------------
// Class 4: Customer (Encapsulation)
class Customer {
private:
    string name;
    string phone;

public:
    void inputDetails() {
        cout << "Enter your name: ";
        getline(cin, name);
        cout << "Enter your phone number: ";
        getline(cin, phone);
    }

    void showDetails() const {
        cout << "\nCustomer: " << name << "\nPhone: " << phone << endl;
    }
};

// -----------------------------
// Class 5: Order (Composition, no vectors)
class Order {
private:
    FoodItem* items[10];  // fixed-size array
    int count;

public:
    Order() {
        count = 0;
    }

    void addItem(FoodItem* item) {
        if (count < 10) {
            items[count] = item;
            count++;
        } else {
            cout << "Order limit reached (10 items max)!\n";
        }
    }

    void showBill() const {
        float total = 0;
        cout << "\n---- Your Order ----\n";
        for (int i = 0; i < count; i++) {
            items[i]->show();  // Polymorphism
            total += items[i]->getPrice();
        }
        cout << "--------------------\n";
        cout << "Total Bill: Rs." << total << endl;
    }

    ~Order() {
        for (int i = 0; i < count; i++) {
            delete items[i];  // Cleaning up memory
        }
    }
};

// -----------------------------
// Main Program
int main() {
    Customer customer;
    Order order;

    customer.inputDetails();

    int choice;
    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Burger (Rs.250)\n";
        cout << "2. Pizza  (Rs.500)\n";
        cout << "3. Drink  (Rs.100)\n";
        cout << "4. Show Bill & Exit\n";
        cout << "Choose item (1-4): ";
        cin >> choice;
        cin.ignore(); // to clear newline from buffer

        switch (choice) {
            case 1:
                order.addItem(new Burger());
                break;
            case 2:
                order.addItem(new Pizza());
                break;
            case 3:
                order.addItem(new Drink());
                break;
            case 4:
                order.showBill();
                customer.showDetails();
                cout << "\nThank you for ordering! ??\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}

