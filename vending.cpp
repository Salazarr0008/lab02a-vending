#include <iomanip>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct item
{
    string itemName;
    double price;
    long int quantity;
    string id;
};

void inventory(const vector<item>& items);
double money();

int main()
{
    cout << "Welcome to our vending machine" << endl;

    vector<item> items;

    items.push_back({"Doritos", .75, 10, "B5"});
    items.push_back({"M&M", 1, 10, "B8"});
    items.push_back({"Lays", .75, 10, "C5"});
    items.push_back({"Skittles", .50, 10, "C8"});
    items.push_back({"Coke", 1.25, 10, "A5"});
    items.push_back({"Water", 1, 10, "A8"});


    while (true)
    {
         inventory(items);
        string choice;

        cout << "\nEnter the item ID you want: (0 to exit)";
        cin >> choice;

        if (choice == "0")
        {
            cout << "Goodbye Have A Nice Day!";
            break;
        }

        bool validChoice = false;

        for (const item& product : items)
        {
            if (choice == product.id)
            {
                validChoice = true;
                break;
            }
        }

        if (!validChoice)
        {
            cout << "Invalid item ID. Please try again." << endl;
            continue;
        }

        double credit = money();

        for (item& product : items)
        {
            if (product.id == choice)
            {
                if (product.quantity > 0)
                {
                    cout << "You selected " << product.itemName << endl;
                    cout << "Price: $" << fixed << setprecision(2)
                         << product.price << endl;

                    if (credit >= product.price)
                    {
                        product.quantity--;

                        double change = credit - product.price;

                        cout << "Purchase complete!" << endl;
                        cout << "Your change is: $"
                             << fixed << setprecision(2)
                             << change << endl;
                    }
                    else
                    {
                        cout << "Not enough money!" << endl;
                        cout << "You need $"
                             << fixed << setprecision(2)
                             << (product.price - credit)
                             << " more." << endl;
                    }
                }
                else
                {
                    cout << "Sorry, this item is sold out." << endl;
                }
            }
        }
    }

    return 0;
}

void inventory(const vector<item>& items)
{
    cout << "\n=========== INVENTORY ===========" << endl;

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

double money()
{
    double credit = 0;
    int coin;

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

        if (coin == 5)
        {
            credit = credit + 0.05;
        }
        else if (coin == 10)
        {
            credit = credit + 0.10;
        }
        else if (coin == 25)
        {
            credit = credit + 0.25;
        }
        else if (coin == 100)
        {
            credit = credit + 1;
        }
        else if (coin == 0)
        {
            break;
        }
        else
        {
            cout << "Coin Invalid" << endl;
        }
    }

    return credit;
}

