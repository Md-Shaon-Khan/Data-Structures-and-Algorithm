#include<bits/stdc++.h>
using namespace std;

struct Talk {
    char id;
    int start;
    int finish;
    int value;
};


bool isCompatible(Talk a, Talk b) {
    return (a.finish <= b.start || b.finish <= a.start);
}


bool compareByValue(Talk a, Talk b) {
    return a.value > b.value;
}

int main() {
 
    vector<Talk> talks = {
        {'A', 1, 4, 10},
        {'B', 3, 5, 5},
        {'C', 0, 6, 11},
        {'D', 5, 7, 12},
        {'E', 3, 8, 8},
        {'F', 5, 6, 20},
        {'G', 8, 11, 7}
    };

   
    sort(talks.begin(), talks.end(), compareByValue);

    vector<Talk> selected; 
    

    for (auto &talk : talks) {

        bool canSelect = true;

        for (auto &sel : selected) {

            if (!isCompatible(talk, sel)) {
                canSelect = false;
                break;
            }

        }

        if (canSelect) {

            selected.push_back(talk);

        }
    }

    
    cout << "(ID, Start, Finish, Value):\n";
    int totalValue = 0;

    for (auto &talk : selected) {

        cout << talk.id << "  " << talk.start << "  " << talk.finish << "  " << talk.value << endl;
        totalValue += talk.value;

    }
    cout << "Total Priority: " << totalValue << endl;

    return 0;
}
