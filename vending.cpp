   #include <iomanip>
   #include <iostream>
   #include <vector>
   #include <string>
using namespace std;




struct item{
string itemName;
double price;
long int quantity;
string id;
};









int main () { 
cout << "Wlcome to our vending machine";


 vector <item> inventory;
 18 inventory.push_back ({"Doritos", .75, 10, "B5"})
 19 inventory.push_back ({"M&M", 1, 10, "B8"})
 20 inventory.push_back ({"Lays", .75, 10, "C5"})
 21 inventory.push_back ({"Skittles", .50, 10, "C8"})
 22 inventory.push_back ({"Coke", 1.25, 10, "A5"})
 23 inventory.push_back ({"Water", 1, 10, "A8"})
return 0; 
}

