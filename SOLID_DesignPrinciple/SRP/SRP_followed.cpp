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

// Shopping class has a single responsibilities of calculating the total price of products in the cart.
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
        for (auto p:products) {
            total += p->price;
        }
        return total;
    }
};

// ShoppingCartprinter class is responsible for printing the invoice of the shopping cart.
class ShoppingCartprinter {
private:
    ShoppingCart* cart;
public:

    ShoppingCartprinter(ShoppingCart* c){
        this->cart = c;
    }

    void printInvoice() {
        cout << "Receipt:" << endl;
        for (auto p : cart->getProducts()) {
            cout << p->name << ": $" << p->price << endl;
        }
        cout << "Total: $" << cart->calculateTotal() << endl;
    }

};


// ShoppingCartDatabase class is responsible for saving the shopping cart to a database.
class ShoppingCartDatabase {
private:
    ShoppingCart* cart;
public:

    ShoppingCartDatabase(ShoppingCart* c){
        this->cart = c;
    }

    void saveToDatabase() {
        cout << "Saving shopping cart to database..." << endl;
    }
};

int main() {

    ShoppingCart* myCart = new ShoppingCart();

    myCart->addProduct(new Product("Laptop", 999.99));
    myCart->addProduct(new Product("Smartphone", 499.99));
    myCart->addProduct(new Product("Headphones", 199.99));
    myCart->addProduct(new Product("Smartwatch", 299.99));

    ShoppingCartprinter* printer = new ShoppingCartprinter(myCart);
    
    printer->printInvoice();
    
    ShoppingCartDatabase* db = new ShoppingCartDatabase(myCart);
    db->saveToDatabase();

    return 0;
}