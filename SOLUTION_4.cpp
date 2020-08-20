#include<iostream>
#include<math.h>
#include<stack>
using namespace std;
int soln(int n,int x,int y,int arr[],int sum){
	int m=pow(10,9)+7;
	stack<int>s;
	long long res=0,ans=0,tp;
	for(int i=0;i<n;i++){
		while(s.empty()==false && arr[i]<=arr[s.top()]){
			tp=s.top();
			s.pop();
			res=arr[tp]*(s.empty()?i:(i-s.top()-1));
			ans=max(ans%m,res);
		}
		s.push(i);
	}
	while(s.empty()==false){
		tp=s.top();
		s.pop();
		res=arr[tp]*(s.empty()?n:(n-s.top()-1));
		ans=max(ans%m,res);
	}
	return ((sum%m-ans%m)%m*x%m*y%m)%m;
}

int main(){
	int n,x,y,sum=0;
	cin>>n>>x>>y;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	cout<<soln(n,x,y,arr,sum)<<endl;
	return 0;
}
