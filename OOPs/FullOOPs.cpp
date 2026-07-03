#include <bits/stdc++.h>
using namespace std;

// this example demonstrate all the concepts of OOPs in c++

class Car{
protected:
    string model;
    string brand;
    bool isEngineOn;
    int currSpeed;

public:
    Car(string m, string b){
        this->model = m;
        this->brand = b;
        this->isEngineOn = false;
        this->currSpeed = 0;
    }


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

    virtual void accelerate(){}    // abstract methods for Dynamic Polymorphism - Overriding
    virtual void accelerate(int speed) = 0;         // abstract methods for Static Polymorphism - Overloading
    virtual void brake(){}        // abstract methods for Dynamic Polymorphism - Overriding

    virtual ~Car(){}

};


class ManualCar : public Car {
private:
    int currGear;

public:
    ManualCar(string m, string b) : Car(m, b) {
        currGear = 0;
    }

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

    // Overloading & overriding the accelerate method - Static & dynamic Polymorphism
    void accelerate(int speed){
        if(isEngineOn){
            currSpeed += speed; // increase speed by the given value
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


class ElectricCar : public Car{
private:
    int batteryLevel;

public:
    ElectricCar(string m, string b) : Car(m, b) {
        this->batteryLevel = 100; 
    }

    void charge(){
        batteryLevel = 100;
        cout << brand << " " << model << " is fully charged." << endl;
    }   

    // Overriding the accelerate method - Dynamic Polymorphism
    void accelerate(){
        if(isEngineOn){
            currSpeed += 15;
            batteryLevel -= 10;
            cout<< brand << " " << model << " accelerated to " << currSpeed << " km/h." << endl;
        } else {
            cout<< "Start the engine first!" << endl;
        }
    }

    // Overloading & overriding the accelerate method - Static & dynamic Polymorphism
    void accelerate(int speed){
        if(isEngineOn){
            currSpeed += speed; 
            batteryLevel -= (speed / 2); 
            if(batteryLevel < 0) batteryLevel = 0;
            cout<< brand << " " << model << " accelerated to " << currSpeed << " km/h." << batteryLevel << " % battery left" << endl;
        } else {
            cout<< "Start the engine first!" << endl;
        }  
    }

    // Overriding the brake method - Dynamic Polymorphism
    void brake(){
        if(isEngineOn && currSpeed > 0){
            currSpeed -= 15; 
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
    myManualCar->accelerate(30);
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
    myElectricCar->accelerate(50);
    myElectricCar->brake();
    myElectricCar->stop();
    delete myElectricCar;

    return 0;
}