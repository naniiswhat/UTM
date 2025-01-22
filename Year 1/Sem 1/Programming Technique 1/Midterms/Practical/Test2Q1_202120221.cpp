// PT1/2122/1-TEST2-QUESTION 1 (Debugging)
// Name: ???
// Matric No.: ???
// Section: ???

#include <iostream>
#include <string>
#include <cctype>

// standard car wash service charge for
// "sedan" type car
#define WASH 10.0
#define VACUUM 7.0
#define POLISH 15.0

using namespace std;

// function prototypes
void setType(string &);
void setPackage(int);

float wash(string);
float vacuum(string);
float polish(string);

// start main function
int main() {
    // car type
    string carType;

    // car wash service package
    int wsPkg;

    // total service charge based on car type and
    // wash service package
    float totalCharge;

    setType(carType);
    setPackage(wspkg);

    switch(wsPkg) {
        case 3: totalCharge += polish(carType);
        case 2: totalCharge += vacuum(carType); break;
        case 1: totalCharge = wash(carType);
    }

    cout << endl;

    cout << "Total service charge is " << totalCharge;
    return 0;
}

// implement new user-defined functions

// function to set car type
int setType(string &type) {
   // only exit the loop after user enter valid
   // car type that are "sedan" or "mpv"
   do {
        cout << "\nEnter car type (sedan/mpv): ";
        cin << type;

   } while (type.compare("sedan") && type.compare("mpv"));

   cout << endl;
}

// function to set wash service package
void setPackage(int pkg) {
   // only exit the loop after user enter valid
   // integer number 1, 2 or 3
   while (pkg >= 1 && pkg <= 3) {
        cout << "1. Basic\n";
        cout << "2. Deluxe\n";
        cout << "3. Premium\n";
        cout << "Choose wash service package (1/2/3): ";
        cin >> pkg;
   }

   cout << endl;
}

// Function to determine exterior wash service charge based
// on car type. The "mpv" type car will be charged 20% higher.
float wash(string type) {
   float charge;

   if (!type.compare("mpv"))
      charge = WASH + WASH * 20 / 100;
   else
      charge = WASH;

   cout << "Wash service charge is " << charge << endl;

   return charge;
}

// Function to determine interrior vacuum service charge based
// on car type. The "mpv" type car will be charged 5% higher.
float vacuum(string type) {
   float charge;

   if (type.compare("mpv")) {
       charge = VACUUM + VACUUM * 5 / 100;

   } else {
       charge = WASH;
   }


   cout << "Vacuum service charge is " << charge << endl;

   return charge;
}

// Function to determine exterior polish service charge based
// on car type. The "mpv" type car will be charged 20% higher.
float polish(string type) {
   float charge;

   if (!type.compare("mpv"))
      charge = POLISH + POLISH * 20 / 100;
   else
      charge = POLISH;

   cout << "Polish service charge is " << charge << endl;

   return charge;
}

/*
Please open/view your C++ source code and the running program side by side.
Test the running program by using the following test cases:

TEST CASE 1:
--------------------------------------------------------------------------
Enter car type (sedan/mpv): suv

Enter car type (sedan/mpv): sedan

1. Basic
2. Deluxe
3. Premium
Choose wash service package (1/2/3): 0
1. Basic
2. Deluxe
3. Premium
Choose wash service package (1/2/3): 4
1. Basic
2. Deluxe
3. Premium
Choose wash service package(1/2/3): 1

Wash service charge is 10

Total service charge is 10


TEST CASE 2:
--------------------------------------------------------------------------
Enter car type (sedan/mpv): sedan

1. Basic
2. Deluxe
3. Premium
Choose wash service package (1/2/3): 2

Vacuum service charge is 7
Wash service charge is 10

Total service charge is 17


TEST CASE 3:
--------------------------------------------------------------------------
Enter car type (sedan/mpv): mpv

1. Basic
2. Deluxe
3. Premium
Choose wash service package (1/2/3): 2

Vacuum service charge is 7.35
Wash service charge is 12

Total service charge is 19.35


TEST CASE 4:
--------------------------------------------------------------------------
Enter car type (sedan/mpv): sedan

1. Basic
2. Deluxe
3. Premium
Choose wash service package (1/2/3): 3

Polish service charge is 15
Vacuum service charge is 7
Wash service charge is 10

Total service charge is 32


TEST CASE 5:
--------------------------------------------------------------------------
Enter car type (sedan/mpv): mpv

1. Basic
2. Deluxe
3. Premium
Choose wash service package (1/2/3): 3

Polish service charge is 18
Vacuum service charge is 7.35
Wash service charge is 12

Total service charge is 37.35
*/
