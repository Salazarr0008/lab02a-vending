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

    inventory(items);

    string choice;

    cout << "\nEnter the item ID you want: ";
    cin >> choice;

    for (item& product : items)
    {
        if (product.id == choice)
        {
            if (product.quantity > 0)
            {
                cout << "You selected " << product.itemName << endl;
                cout << "Price: $" << fixed << setprecision(2)
                     << product.price << endl;

                product.quantity--;

                cout << "Purchase complete!" << endl;
            }
            else
            {
                cout << "Sorry, this item is sold out." << endl;
            }
        }
    }

    return 0;
}

void inventory(const vector<item>& items)
{
    cout << "\n===== INVENTORY =====" << endl;

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
