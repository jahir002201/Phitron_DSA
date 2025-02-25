#include<bits/stdc++.h>
using namespace std;
bool binarySearch(int arr[],int n,int x){
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==x){
            return true;
        }else if(arr[mid]>x){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return false;
}
int main(){
    int n,q;
    cin>>n>>q;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<q;i++){
        int x;
        cin>>x;
        if(binarySearch(arr,n,x)){
            cout<<"Fount"<<endl;
        }else{
            cout<<"No Found"<<endl;
        }
    }
    return 0;
}