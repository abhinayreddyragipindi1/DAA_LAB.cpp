#include <iostream>
using namespace std;
int main(){
    int n,key,i,j=1;
    int index;
    cout<<"enter the size of the hash table";
    cin>>n;
    int hash[n];
    for(i=0;i<n;i++){
        hash[i]=-1;
    }

    cout<<"enter the elements of hash table";
    for(i=0;i<n;i++){
        cin>>key;
        index=key%n;
    
        while(hash[index]!=-1){
            
            index=(key%n+j*j)%n;
            j++;


        }
        hash[index]=key;
        
    }
    cout<<"hash index and key are :"<<endl;
    for(i=0;i<n;i++){
        cout<< i << " " << "->";
        if(hash[i]==-1){
            cout<<"empty";

        }
        else{
            cout<<hash[i];
        }
        cout<<endl;
    
        }
    return 0;
}
