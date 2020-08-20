#include<iostream>
using namespace std;
void soln(int cars[],int n){
	double per=1,gp=0;
	for(int i=1;i<=n;i++){
		per*=i;
		for(int j=1,m=1;j<=i;m*=++j){
			gp+=(per/m);
		}
	}
	if(n%2==0){
		gp--;
	}
	gp-=n;
	printf("%0.6f\n",gp/per);
}
int main(){
	int n;
	cin>>n;
	int cars[n];
	for(int i=0;i<n;i++){
		cin>>cars[i];
	}
	soln(cars,n);
	return 0;
}
