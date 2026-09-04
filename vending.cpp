#include <iomanip>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// product info
struct item
{
    string itemName;
    double price;
    long int quantity;
    string id;
};

// inventory
void inventory(const vector<item>& items);

// money
double money();

int main()
{
    cout << "Welcome to our vending machine" << endl;

    // items
    vector<item> items;

    // add items
    items.push_back({"Doritos", .75, 10, "B5"});
    items.push_back({"M&M", 1, 10, "B8"});
    items.push_back({"Lays", .75, 10, "C5"});
    items.push_back({"Skittles", .50, 10, "C8"});
    items.push_back({"Coke", 1.25, 10, "A5"});
    items.push_back({"Water", 1, 10, "A8"});


    // main loop
    while (true)
    {
        // show inventory
        inventory(items);
        string choice;

        cout << "\nEnter the item ID you want: (0 to exit)";
        cin >> choice;

        // exit
        if (choice == "0")
        {
            cout << "Goodbye Have A Nice Day!";
            break;
        }


        //starts validChoise as false
        bool validChoice = false;

        // check ID
        for (const item& product : items)
        {
            if (choice == product.id)
            {
                validChoice = true;
                break;
            }
        }

        // invalid ID
        if (!validChoice)
        {
            cout << "Invalid item ID. Please try again." << endl;
            continue;
        }

        // get money
        double credit = money();

        // find item
        for (item& product : items)
        {
            if (product.id == choice)
            {
                // check stock
                if (product.quantity > 0)
                {
                    cout << "You selected " << product.itemName << endl;
                    cout << "Price: $" << fixed << setprecision(2)
                         << product.price << endl;

                    // check money
                    if (credit >= product.price)
                    {
                        // remove item
                        product.quantity--;

                        // calculate change
                        double change = credit - product.price;

                        cout << "Purchase complete!" << endl;
                        cout << "Your change is: $"
                             << fixed << setprecision(2)
                             << change << endl;

                        // receipt
                        cout << "\n========== RECEIPT ==========" << endl;
                        cout << "Item:          " << product.itemName << endl;
                        cout << "Price:         $" << fixed << setprecision(2) << product.price << endl;
                        cout << "Amount Paid:   $" << fixed << setprecision(2) << credit << endl;
                        cout << "Change:        $" << fixed << setprecision(2) << change << endl;
                        cout << "=============================" << endl;
                        cout << "Thank you for your purchase!" << endl;
                    }
                    else
                    {
                        // not enough money
                        cout << "Not enough money!" << endl;
                        cout << "You need $"
                             << fixed << setprecision(2)
                             << (product.price - credit)
                             << " more." << endl;
                    }
                }
                else
                {
                    // sold out
                    cout << "Sorry, this item is sold out." << endl;
                }
            }
        }
    }

    return 0;
}

// show inventory
void inventory(const vector<item>& items)
{
    cout << "\n=========== INVENTORY ===========" << endl;

    // show items
    for (const item& product : items)
    {
        cout << product.id << " - "
             << product.itemName
             << " $" << fixed << setprecision(2)
             << product.price
             << " (" << product.quantity << " available)"
             << endl;
    }
}

// insert money
double money()
{
    double credit = 0;
    int coin;

    // coin loop
    while (true)
    {
        cout << "\nCurrent Credit $"
             << fixed << setprecision(2) << credit << endl;

        cout << "Enter Coin" << endl;
        cout << "5 = Nickel" << endl;
        cout << "10 = Dime" << endl;
        cout << "25 = Quarter" << endl;
        cout << "100 = Dollar" << endl;
        cout << "0 = Done" << endl;

        cout << "Coin: ";
        cin >> coin;

        // nickel
        if (coin == 5)
        {
            credit = credit + 0.05;
        }
        // dime
        else if (coin == 10)
        {
            credit = credit + 0.10;
        }
        // quarter
        else if (coin == 25)
        {
            credit = credit + 0.25;
        }
        // dollar
        else if (coin == 100)
        {
            credit = credit + 1;
        }
        // done
        else if (coin == 0)
        {
            break;
        }
        // invalid coin
        else
        {
            cout << "Coin Invalid" << endl;
        }
    }

    return credit;
}
