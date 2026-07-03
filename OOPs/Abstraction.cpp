#include <bits/stdc++.h>
using namespace std;

// Abstract class for Car i.e, blueprint for all car types
class Car{
    public:
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void shiftGear(int gear) = 0;
    virtual ~Car() {}
};


// Declare a class for SportsCar that inherits from Car
// Implements all the abstract methods defined in Car class
class SportsCar : public Car{
    public:
    // characters aur attributes of SportsCar
    string model;
    string brand;
    bool isEngineOn;
    int currSpeed;
    int currGear;

    // Constructor to initialize the SportsCar object
    SportsCar(string m, string b){
        this->model = m;
        this->brand = b;
        this->isEngineOn = false;
        this->currSpeed = 0;
        this->currGear = 0;
    }

    // behaviours aur methods of SportsCar
    void start(){
        isEngineOn = true;
        cout<< brand << " " << model << " Engine started." << endl;
    }

    void shiftGear(int gear){
        if(isEngineOn){
            currGear = gear;
            cout<< brand << " " << model << " shifted to gear " << currGear << "." << endl;
        } else {
            cout<< "Start the engine first!" << endl;
        }
    }

    void accelerate(){
        if(isEngineOn){
            currSpeed += 20;
            cout<< brand << " " << model << " accelerated to " << currSpeed << " km/h." << endl;
        } else {
            cout<< "Start the engine first!" << endl;
        }
    }

    void brake(){
        if(isEngineOn && currSpeed > 0){
            currSpeed -= 20;
            cout<< brand << " " << model << " slowed down to " << currSpeed << " km/h." << endl;
        } else {
            cout<< "Car is not moving or engine is off!" << endl;
        }
    }

    void stop(){
        if(isEngineOn){
            isEngineOn = false;
            currSpeed = 0;
            currGear = 0;
            cout<< brand << " " << model << " stopped." << endl;
        } else {
            cout<< "Engine is already off!" << endl;
        }
    }

};

int main() {
    // hm c++ mein parent class ke pointer se kisi bhi child class ko point ke sakte hai ye uske instance ko point kr skate hai 
    Car* myCar = new SportsCar("Model S", "Tesla");
    
    myCar->start();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->accelerate();
    myCar->brake();
    myCar->shiftGear(2);
    myCar->accelerate();
    myCar->stop();

    return 0;
    
}