#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

vector<pair<int,int>>sequentialSearch(vector<pair<int,int>>& orders,int number){
    vector<pair<int,int>> result;
    for(auto &order:orders){
        if(order.second>number){
            result.push_back(order);
        }
    }
    return result;
}

void printArray(vector<pair<int,int>>arr){
    for(auto &i :arr){
        cout<<i.first<<"  :"<<i.second<<endl;
    }
    cout<<endl;
}

int main(){
        vector<pair<int, int>> orders = {
        {1002, 6},{1004, 7},{1006, 9},{1008, 1},{1009, 1},
        {1010, 3},{1011, 2},{1012, 2},{1015, 4},{1018, 3},
        {1021, 8},{1023, 4},{1025, 4},{1027, 2},{1029, 2},
        {1031, 6},{1033, 5},{1035, 9},{1038, 1},{1040, 5},
        {1042, 7},{1049, 5},{1050, 8},{1052, 3},{1055, 2}
    };

    auto start = high_resolution_clock::now();
    vector<pair<int, int>> result = sequentialSearch(orders,3);
    auto stop = high_resolution_clock::now();

    printArray(result);
    auto duration = duration_cast<nanoseconds>(stop-start);
    cout<<duration.count();


    return 0;
}