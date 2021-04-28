#include <string.h>

#include <iostream>
using namespace std;

class Vehicle {
   private:
    int price;
    char *manufacturer;

   public:
    Vehicle() : price(0), manufacturer(NULL) {}
    Vehicle(int pr, char *manu) {
        price = pr;
        manufacturer = new char[strlen(manu) + 1];
        strcpy(manufacturer, manu);
    }
    Vehicle(Vehicle &rhs) : price(rhs.price) {
        manufacturer = new char[strlen(rhs.manufacturer) + 1];
        strcpy(manufacturer, rhs.manufacturer);
    }

    Vehicle &operator=(const Vehicle &rhs);
    void display();
    void read();
};

Vehicle &Vehicle::operator=(const Vehicle &rhs) {
    if (this == &rhs) {
        return *this;
    }
    delete[] manufacturer;
    price = rhs.price;
    manufacturer = new char[strlen(rhs.manufacturer) + 1];
    strcpy(manufacturer, rhs.manufacturer);
    return *this;
}

void Vehicle::display() {
    cout << "\n [ DISPLAYING VEHICLE DATA ] \n";
    cout << "PRICE: " << price << "\n";
    if (manufacturer == NULL) {
        cout << "MANUFACTURER: N/A"
             << "\n";
    } else {
        cout << "MANUFACTURER: " << manufacturer << "\n";
    }
}

void Vehicle::read() {
    char text[100];
    cout << "\n [ READING VEHICLE DATA ] \n";
    cout << "ENTER PRICE: ";
    cin >> price;
    cout << "ENTER MANUFACTURER: ";
    cin >> text;
    manufacturer = new char[strlen(text) + 1];
    strcpy(manufacturer, text);
}

class Car : public Vehicle {
   private:
    char *color;
    int seats;
    int model;

   public:
    Car() {
        color = NULL;
        seats = 0;
        model = 0;
    }
    Car(char *color, int seats, int model, int price, char *manufacturer)
        : Vehicle(price, manufacturer), seats(seats), model(model) {
        this->color = new char[strlen(color) + 1];
        strcpy(this->color, color);
    }
    Car(Car &rhs) : Vehicle(rhs), seats(rhs.seats), model(rhs.model) {
        this->color = new char[strlen(rhs.color) + 1];
        strcpy(this->color, rhs.color);
    }

    void display();
    void read();
};

void Car::display() {
    Vehicle::display();
    cout << "\n [ DISPLAYING CAR INFO ] \n";
    if (color == NULL) {
        cout << "COLOR: N/A"
             << "\n";
    } else {
        cout << "COLOR: " << color << "\n";
    }
    cout << "MODEL: " << model << "\n";
    cout << "SEATS: " << seats << "\n";
}

void Car::read() {
    char colorText[100];
    Vehicle::read();
    cout << "\n [ READING CAR DATA ] \n";
    cout << "ENTER COLOR: ";
    cin >> colorText;
    color = new char[strlen(colorText) + 1];
    strcpy(color, colorText);
    cout << "ENTER NUMBER OF SEATS: ";
    cin >> seats;
    cout << "ENTER MODEL NUMBER: ";
    cin >> model;
}
int main() {
    Car ob1;
    ob1.read();
    ob1.display();
    return 0;
}
