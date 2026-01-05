#include <bits/stdc++.h>
using namespace std;

struct Item {
    string id;
    string name;
    int cost;
    int impact;
    double ratio;
};

bool cmp(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    int budget = 500000;
    vector<Item> items = {
        {"P1", "Food Rations", 300000, 40, 0},
        {"P2", "Water Purification Kits", 100000, 25, 0},
        {"P3", "Temporary Shelters", 350000, 50, 0},
        {"P4", "Medical Supplies", 100000, 18, 0},
        {"P5", "Communication Equipment", 50000, 12, 0}
    };

    for (auto &item : items) {
        item.ratio = (double)item.impact / item.cost;
    }

    sort(items.begin(), items.end(), cmp);

    vector<Item> selectedItems;
    int totalCost = 0;
    int totalImpact = 0;

    for (auto item : items) {
        if (totalCost + item.cost <= budget) {
            selectedItems.push_back(item);
            totalCost += item.cost;
            totalImpact += item.impact;
        }
    }

    cout << "Selected Items:\n";
    for (auto item : selectedItems) {
        cout << item.id << " - " << item.name << "\n";
    }
    cout << "\nTotal Cost: " << totalCost << " BDT\n";
    cout << "Total Impact Score: " << totalImpact << "\n";

    return 0;
}
