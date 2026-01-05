#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    string id;
    string name;
    double cost;
    double impact;
    double ratio;
};


bool compareRatio(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    double budget = 500000;

    vector<Item> items = {
        {"P1", "Food Rations", 300000, 40, 0},
        {"P2", "Water Kits", 100000, 25, 0},
        {"P3", "Shelters", 350000, 50, 0},
        {"P4", "Medical", 100000, 18, 0},
        {"P5", "Communication", 50000, 12, 0}
    };


    for (auto &it : items)
        it.ratio = it.impact / it.cost;


    sort(items.begin(), items.end(), compareRatio);

    double totalCost = 0;
    double totalImpact = 0;
    vector<pair<string, double>> selected; 


    for (auto &it : items) {
        if (totalCost + it.cost <= budget) {

            totalCost += it.cost;
            totalImpact += it.impact;
            selected.push_back({it.id, 1.0});
        } else {

            double remain = budget - totalCost;
            if (remain > 0) {
                double fraction = remain / it.cost;
                totalCost += remain; 
                totalImpact += it.impact * fraction;
                selected.push_back({it.id, fraction});
            }
            break;
        }
    }


    cout << "Selected Items: ";
    for (auto &p : selected) {
        cout << p.first;
        if (p.second < 1.0)
            cout << " (" << p.second * 100 << "%)";
        cout << " ";
    }
    cout << endl;

    cout << "Total Cost: " << totalCost << " BDT" << endl;
    cout << "Total Impact: " << totalImpact << endl;

    return 0;
}
