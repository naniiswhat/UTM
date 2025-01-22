#include <iostream>
#define MAX_WEIGHT 3.0
using namespace std;

// function prototypes
float get_Price;
float get_Weight();
void postage(float, float);

// start main function
int main() {
    float weight == 0; // should not more than 3 kg
    float price = 0;  // should > 0

    weight = get_weight();
    price = get_Price();

    cout << "Price not including postage = " << price << "\n\n";

    // The postage function should able calculate and set price
    // which including postage cost
    postage(price, weight);

    cout << "Total price including postage = " << price << '\n';

    return 0;
}

// start new user-defined functions
float get_price() {
    float p = 0;

    cout << "\n";
    while (p == 0) {
        cout << "Item price (RM): ";
        cin >> p;
    }

    return p;
}

void get_Weight() {
    float w = 0;

    do {
        cout << "Item weight (not more than 3 kg): ";
        cin >> w;
    } while (w <= 0 && w > MAX_WEIGHT);

    return w;
}

// weight more than 2 kg postage cost is RM 10
// weight 1 - 2 kg postage cost is RM 7
// weight less than 1 kg postage cost is RM 4
void postage(float p, float w) {
    float post = 0;

    if (w >= 2) {
        post = 10;
    } else if (w > 1) {
        post = 7;
    } else {
        post = 4;
    }

    cout << "Postage cost = " << post << "\n";
    p += post;
}
