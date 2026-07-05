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


class DBPersistence {
public:
    virtual void save(ShoppingCart* cart) = 0;
};

class SQLPersistence : public DBPersistence {
public:
    void save(ShoppingCart* c) override {
        cout << "Saving shopping cart to SQL database..." << endl;
    }
};

class MongoDBPersistence : public DBPersistence {
public:
    void save(ShoppingCart* c) override {
        cout << "Saving shopping cart to MongoDB..." << endl;
    }
};

class FilePersistence : public DBPersistence {
public:
    void save(ShoppingCart* c) override {
        cout << "Saving shopping cart to file..." << endl;
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
    
    DBPersistence* sqlDb = new SQLPersistence();
    sqlDb->save(myCart);
    DBPersistence* mongoDb = new MongoDBPersistence();
    mongoDb->save(myCart);
    DBPersistence* fileDb = new FilePersistence();
    fileDb->save(myCart);

    return 0;
}