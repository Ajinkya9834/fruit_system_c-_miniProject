#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Fruit {
    string name;
    string color;
    float price;

public:
    Fruit(string name, string color, float price) : name(name), color(color), price(price) {}
    string getName() { return name; }
    string getColor() { return color; }
    float getPrice() { return price; }
    void setPrice(float newPrice) { price = newPrice; }
    void display() {
        cout << "Name: " << name << ", Color: " << color << ", Price: Rs." << price << endl;
        cout<<"=========================="<<endl;
    }
};

class Customer {
    int id;
    string name;

public:
    Customer(int id, string name) : id(id), name(name) {}
    int getId() { return id; }
    string getName() { return name; }
    void display() {
        cout << "Customer ID: " << id << ", Name: " << name << endl;
        cout<<"=========================="<<endl;
    }
};

class Order {
    int customerId;
    vector<Fruit> items;
    float total;

public:
    Order(int customerId) : customerId(customerId), total(0) {}
    int getCustomerId() { return customerId; }
    void addItem( Fruit& fruit)  {
        items.push_back(fruit);
        total += fruit.getPrice();
    }
    void display() {
        cout << "Customer ID: " << customerId << endl;
        for ( auto& item : items) {
            item.display();
        }
        cout << "Total: Rs." << total << endl;
        cout<<"=========================="<<endl;
    }
};
void addFruit(vector<Fruit>& fruits) {
    string name, color;
    float price;
    cout << "Enter fruit name: ";
    cin >> name;
    cout << "Enter fruit color: ";
    cin >> color;
    cout << "Enter fruit price: ";
    cin >> price;
    fruits.push_back(Fruit(name, color, price));
}

void updateFruit(vector<Fruit>& fruits) {
    string name;
    cout << "Enter the name of the fruit to update: ";
    cin >> name;
    for (auto& fruit : fruits) {
        if (fruit.getName() == name) {
            float newPrice;
            cout << "Enter new price: ";
            cin >> newPrice;
            fruit.setPrice(newPrice);
            cout << "Price updated successfully." << endl;
            return;
        }
    }
    cout << "Fruit not found!" << endl;
}

void deleteFruit(vector<Fruit>& fruits) {
    string name;
    cout << "Enter the name of the fruit to delete: ";
    cin >> name;
    for (auto it = fruits.begin(); it != fruits.end(); ++it) {
        if (it->getName() == name) {
            fruits.erase(it);
            cout << "Fruit deleted successfully." << endl;
            return;
        }
    }
    cout << "Fruit not found!" << endl;
}

void displayFruits( vector<Fruit>& fruits) {
    for ( auto& fruit : fruits) {
        fruit.display();
    }
    cout<<"=========================="<<endl;
}

void addOrder(vector<Order>& orders,  vector<Fruit>& fruits) {
    int customerId;
    cout << "Enter customer ID: ";
    cin >> customerId;
    Order order(customerId);
    char choice;
    do {
        string fruitName;
        cout << "Enter fruit name to add to order: ";
        cin >> fruitName;
        bool found = false;
        for ( auto& fruit : fruits) {
            if (fruit.getName() == fruitName) {
                order.addItem(fruit);
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Fruit not found!" << endl;
        }
        cout << "Add more fruits to order? (y/n): ";
        cin >> choice;
    } while (choice == 'y');
    orders.push_back(order);
}

void displayOrders( vector<Order>& orders) {
    for ( auto& order : orders) {
        order.display();
    }
    cout<<"=========================="<<endl;
}

void searchOrderByCustomerId( vector<Order>& orders) {
    int customerId;
    cout << "Enter customer ID to search orders: ";
    cin >> customerId;
    for ( auto& order : orders) {
        if (order.getCustomerId() == customerId) {
            order.display();
            return;
        }
    }
    cout << "Order not found for customer ID: " << customerId << endl;
    cout<<"=========================="<<endl;
}

int main() {
    vector<Fruit> fruits;
    vector<Order> orders;
    int choice;

    do {
        cout << "1. Add Fruit" << endl;
        cout << "2. Update Fruit" << endl;
        cout << "3. Delete Fruit" << endl;
        cout << "4. Display All Fruits" << endl;
        cout << "5. Add Order" << endl;
        cout << "6. Display All Orders" << endl;
        cout << "7. Search Order by Customer ID" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addFruit(fruits);
                break;
            case 2:
                updateFruit(fruits);
                break;
            case 3:
                deleteFruit(fruits);
                break;
            case 4:
                displayFruits(fruits);
                break;
            case 5:
                addOrder(orders, fruits);
                break;
            case 6:
                displayOrders(orders);
                break;
            case 7:
                searchOrderByCustomerId(orders);
                break;
            case 8:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 8);

    return 0;
}