#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    string id;
    string name;
    int cost;
    int impact;
};


bool compareImpact(Item a, Item b) {
    return a.impact > b.impact;
}

int main() {
    int budget = 500000;

    vector<Item> items = {
        {"P1", "Food Rations", 300000, 40},
        {"P2", "Water Kits", 100000, 25},
        {"P3", "Shelters", 350000, 50},
        {"P4", "Medical", 100000, 18},
        {"P5", "Communication", 50000, 12}
    };


    sort(items.begin(), items.end(), compareImpact);

    int totalCost = 0;
    int totalImpact = 0;
    vector<string> selected;


    for (int i = 0; i < items.size(); i++) {
        if (totalCost + items[i].cost <= budget) {
            totalCost += items[i].cost;
            totalImpact += items[i].impact;
            selected.push_back(items[i].id);
        }
    }


    cout << "Selected Items: ";
    for (string id : selected) cout << id << " ";
    cout << endl;

    cout << "Total Cost: " << totalCost << " BDT" << endl;
    cout << "Total Impact: " << totalImpact << endl;

    return 0;
}