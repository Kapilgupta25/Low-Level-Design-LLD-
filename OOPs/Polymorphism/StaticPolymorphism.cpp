#include <bits/stdc++.h>
using namespace std;


// static polymorphism in C++ is achieved through function overloading
// where multiple functions can have the same name, same return type but different parameters.

class Car{
protected:
    // characters aur attributes of car
    string model;
    string brand;
    bool isEngineOn;
    int currSpeed;
    int curGear;

public:
    // Constructor to initialize the car
    Car(string m, string b){
        this->model = m;
        this->brand = b;
        this->isEngineOn = false;
        this->currSpeed = 0;
        this->curGear = 0;
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

    void shiftgear(int gear){
        if(isEngineOn){
            curGear = gear;
            cout<< brand << " " << model << " shifted to gear " << curGear << "." << endl;
        } else {
            cout<< "Start the engine first!" << endl;
        }
    }

    void brake(){
        if(isEngineOn && currSpeed > 0){
            currSpeed -= 10; // decrease speed by 10
            if(currSpeed < 0) currSpeed = 0; // prevent negative speed
            cout<< brand << " " << model << " slowed down to " << currSpeed << " km/h." << endl;
        } else {
            cout<< "Car is already stopped or engine is off!" << endl;
        }
    }

// accelerate methods demonstrating static polymorphism - overloading
    void accelerate(){
        if(isEngineOn){
            currSpeed += 10; // increase speed by 10
            cout<< brand << " " << model << " accelerated to " << currSpeed << " km/h." << endl;
        } else {
            cout<< "Start the engine first!" << endl;
        }
    }

    void accelerate(int speed){
        if(isEngineOn){
            currSpeed += speed; // increase speed by specified amount
            cout<< brand << " " << model << " accelerated to " << currSpeed << " km/h." << endl;
        } else {
            cout<< "Start the engine first!" << endl;
        }
    }

    virtual ~Car(){}

};


int main() {
    
    Car* myCar = new Car("Mustang", "Ford");
    
    myCar->start();
    myCar->shiftgear(1);
    myCar->accelerate();
    myCar->accelerate(40); // using overloaded method
    myCar->brake();
    myCar->shiftgear(2);
    myCar->accelerate(50); // using overloaded method
    myCar->stop();
    delete myCar;


    return 0;
}