#include <bits/stdc++.h>
using namespace std;

// Dymamic polymorphism in C++ is achieved through function overriding
// where a derived class provides a specific implementation of a method that is already defined in its base class.

class Car{
protected:
    // characters aur attributes of car
    string model;
    string brand;
    bool isEngineOn;
    int currSpeed;

public:
    // Constructor to initialize the car
    Car(string m, string b){
        this->model = m;
        this->brand = b;
        this->isEngineOn = false;
        this->currSpeed = 0;
    }


    // common methods of all car
    void start(){
        isEngineOn = true;
        cout<< brand << " " << model << " Engine started." << endl;
    }

    void stop(){
        if(isEngineOn){
            isEngineOn = false;
            currSpeed = 0;
            cout<< brand << " " << model << " stopped." << endl;
        } else {
            cout<< "Engine is already off!" << endl;
        }
    }

    virtual void accelerate(){}    // abstract methods for Dynamic Polymorphism
    virtual void brake(){}        // abstract methods for Dynamic Polymorphism

    virtual ~Car(){}

};

// manualCar class inherits Car class and has its own specific methods & It overrides the accelerate and brake methods to provide specific functionality
class ManualCar : public Car {
private:
    // specific to manual Car
    int currGear;

public:
    // Constructor to initialize the ManualCar object
    ManualCar(string m, string b) : Car(m, b) {
        currGear = 0; // Initial gear
    }

    // specilized method for manual car
    void shiftgear(int gear){
        currGear=gear;
        cout<< brand << " " << model << " Shifted to gear "<< currGear << endl;
    }

    // Overriding the accelerate method - Dynamic Polymorphism
    void accelerate(){
        if(isEngineOn){
            currSpeed += 20;
            cout<< brand << " " << model << " accelerated to " << currSpeed << " km/h." << endl;
        } else {
            cout<< "Start the engine first!" << endl;
        }
    }
    

    // Overriding the brake method - Dynamic Polymorphism
    void brake(){
        if(isEngineOn && currSpeed > 0){
            currSpeed -= 20;
            cout<< brand << " " << model << " slowed down to " << currSpeed << " km/h." << endl;
        } else {
            cout<< "Car is not moving or engine is off!" << endl;
        }
    }
};


// ElectricCar class inherits Car class and has its own specific methods & It overrides the accelerate and brake methods to provide specific functionality
class ElectricCar : public Car{
private:
    // characters aur attributes of ElectricCar
    int batteryLevel;

public:
    // Constructor to initialize the ElectricCar object
    ElectricCar(string m, string b) : Car(m, b) {
        this->batteryLevel = 100; // Assuming full battery at start
    }

    void charge(){
        batteryLevel = 100;
        cout << brand << " " << model << " is fully charged." << endl;
    }   

    // Overriding the accelerate method - Dynamic Polymorphism
    void accelerate(){
        if(isEngineOn){
            currSpeed += 15; // Electric cars might accelerate slower
            batteryLevel -= 10;
            cout<< brand << " " << model << " accelerated to " << currSpeed << " km/h." << endl;
        } else {
            cout<< "Start the engine first!" << endl;
        }
    }

    // Overriding the brake method - Dynamic Polymorphism
    void brake(){
        if(isEngineOn && currSpeed > 0){
            currSpeed -= 15; // Electric cars might have different braking characteristics
            batteryLevel -= 10;
            cout<< brand << " " << model << " slowed down to " << currSpeed << " km/h."<< batteryLevel << " % battery left"<< endl;
        } else {
            cout<< "Car is not moving or engine is off!" << endl;
        }
    }

};

int main() {
    
    ManualCar* myManualCar = new ManualCar("Mustang", "Ford");
    
    myManualCar->start();
    myManualCar->shiftgear(1);
    myManualCar->accelerate();
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->shiftgear(2);
    myManualCar->accelerate();
    myManualCar->stop();
    delete myManualCar;

    cout<<"-------------------------------------------"<<endl;

    ElectricCar* myElectricCar = new ElectricCar("Model S",  "Tesla");

    myElectricCar->start();
    myElectricCar->charge();
    myElectricCar->accelerate();
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->stop();
    delete myElectricCar;

    return 0;
}