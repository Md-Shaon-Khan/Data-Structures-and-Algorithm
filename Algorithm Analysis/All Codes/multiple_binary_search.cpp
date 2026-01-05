#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

pair<int, int>* binarySearch(vector<pair<int,int>>& orders,int order_id){
    int low = 0, high = orders.size() - 1;

    while(low<high){
        int mid = (low+high)/2;

        if(orders[mid].first==order_id){
            return &orders[mid];
        }
        else if(orders[mid].first < order_id){
            low = mid + 1;
        }
        else{
            high = high - 1;
        }
    }

    return nullptr;
    
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
    vector<pair<int, int>> result;
    for(auto& order:orders){
        pair<int,int>* found = binarySearch(orders,order.first);
        if(found && found->second > 3){
            result.push_back(*found);
        }
    }

    auto stop = high_resolution_clock::now();

    printArray(result);
    auto duration = duration_cast<nanoseconds>(stop-start);
    cout<<duration.count();


    return 0;
}