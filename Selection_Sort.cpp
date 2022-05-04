#include<iostream>
using namespace std;

int main(){

	int n;
	cin>>n;

	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];

	cout<<"Before Sorting : "<<endl;
	for(auto a: arr) cout<<a<<" ";
	cout<<endl;

	int i, j, minIndex;
	for(i=0; i<n-1; i++){
		minIndex = i;
		for(j=i+1; j<n; j++){
			if(arr[j] < arr[minIndex]){
				minIndex = j;
			}
		}
		int temp = arr[minIndex];
		arr[minIndex] = arr[i];
		arr[i] = temp;
	}	

	cout<<"After  Sorting : "<<endl;
	for(auto a: arr) cout<<a<<" ";
	cout<<endl;

	return 0;
}