#include <bits/stdc++.h>
using namespace std;

// Product class represents a product with a name and price of any Ecommerce application.
class Product{
public:
    string name;
    double price;

    Product(string n, double p){
        this->name = n;
        this->price = p;
    }
};

// Voilated SRP : ShoppingCart class is handling multiple responsibilities
class ShoppingCart {
private:
    vector<Product*> products;

public:
// setter method to add a product to the shopping cart
    void addProduct(Product* p) {
        products.push_back(p);
    }

    // getter method to get the products
    const vector<Product*>& getProducts() const {
        return products;
    }

    // calculate total price of all products in the cart
    double calculateTotal() {
        double total = 0.0;
        for(auto p:products){
            total += p->price;
        }
        return total;
    }

    // method to print Invoice: voilated SRP (it must be in a separate class)
    void printInvoice() {
        cout << "Receipt:" << endl;
        for (auto p : products) {
            cout << p->name << ": $" << p->price << endl;
        }
        cout << "Total: $" << calculateTotal() << endl;
    }

    // method to save to DB: voilated SRP (it must be in a separate class)
    void saveToDatabase() {
        // Simulating saving to a database
        cout << "Saving shopping cart to database..." << endl;
        // Database logic would go here
    }
};

int main() {

    ShoppingCart* myCart = new ShoppingCart();

    myCart->addProduct(new Product("Laptop", 999.99));
    myCart->addProduct(new Product("Smartphone", 499.99));
    myCart->addProduct(new Product("Headphones", 199.99));
    myCart->addProduct(new Product("Smartwatch", 299.99));

    myCart->printInvoice();
    myCart->saveToDatabase();

    
    return 0;
}