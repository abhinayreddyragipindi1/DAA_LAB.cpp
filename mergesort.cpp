#include<iostream>
using namespace std;
void merge(int arr[],int low,int mid,int high){
    int i=low,j=mid+1,k=low;
    int c[100];
    while(i<=mid && j<=high){
        if(arr[i]>arr[j]){
            c[k++]=arr[j++];
        }
        else{
            c[k++]=arr[i++];
        }
    }
    while(i<=mid){
        c[k++]=arr[i++];

    }
    while(j<=high){
        c[k++]=arr[j++];
    }

    for(i=low;i<=high;i++){
        arr[i]=c[i];
    }
}

void mergesort(int arr[],int low,int high){
    if(low<high){
        int mid =(low+high)/2;

        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main(){
    int n;
    cout <<"enter the size of array";
    cin >>n;
    int arr[n];
    cout<<"enter the elements of array";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergesort(arr,0,n-1);

    cout<<"after sorting array ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
    
}