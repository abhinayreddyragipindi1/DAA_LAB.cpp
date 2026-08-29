#include<iostream>
using namespace std;
#include <unordered_map>

int main(){
    int n,target,i,need;
    cout<<"enter the no of elements";
    cin>>n;
    int arr[n];
    cout<<"enter the elements";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"enter the target";
    cin>>target;
    unordered_map<int,int>map;
    for(i=0;i<n;i++){
        need=target-arr[i];
        if(map.count(need)){
         cout<<map[need]<<"->"<<i <<endl;
        }
        map[arr[i]]=i;
        
        
    }
    cout<<"no solution";

    return 0;
    


}