#include <bits/stdc++.h>
using namespace std;

// Declare a Class for SportsCar that encapsulates its properties and behaviors

// getter and setter methods are the way to interact with private members and allow us to have a full control over the data... jaise ki hmko validation karni ho ya ki ye data valid hai ya nahi.... but we can't do that if we make them public

class SportsCar{
private:
    // characters aur attributes of SportsCar
    string model;
    string brand;
    bool isEngineOn;
    int currSpeed;
    int currGear;
    string tyre="MRF";

public:
    // Constructor to initialize the SportsCar object
    SportsCar(string m, string b){
        this->model = m;
        this->brand = b;
        this->isEngineOn = false;
        this->currSpeed = 0;
        this->currGear = 0;
    }


    // Getter and setter methods are used to interact with private members.... this is the only way to access private members
    int getCurrentSpeed(){
        return this->currSpeed;
    }

    string getTyre(){
        return this->tyre;
    }

    void setTyre(string t){
        // here we can use validation that this type of tyre is allowed or not but we can't do that if we make them public
        this->tyre = t;
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
    
   SportsCar* myCar = new SportsCar("Mustang", "Ford");
    
    myCar->start();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->accelerate();
    myCar->brake();
    myCar->shiftGear(2);
    myCar->accelerate();
    myCar->stop();

// to stop this we use encapsulation so we use private keyword to restrict access to the members of the class
    // // setting arbitary value to the speed
    // myCar->currSpeed = 500;

    cout << "Current speed is: " << myCar->getCurrentSpeed() << " km/h." << endl;

    delete myCar;

    return 0;
}