#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


int main(){
int arr[]={4,1,6,2,5,3};
int n=sizeof(arr)/sizeof(arr[0]);
for(int ele:arr) cout<<ele<<" "; 
cout<<endl;

int i=0;
while(i<n){
    int correctIdx = arr[i] - 1;
    if(i==correctIdx) i++;
    else swap(arr[i],arr[correctIdx]);
}
for(int ele:arr) cout<<ele<<" "; 
}