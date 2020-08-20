#include<iostream>
#include<map>
using namespace std;
int getxy(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0) return x/i;
	}
	return 1;
}
void swap(int x,int y){
	int t=x;
	x=y;y=t;
}
int soln(int x,int y){
	if(x<y) swap(x,y);
	if(x==y) return 0;

	map<int, int>m;
	int c=0;
	while(x!=1){
		c++;
		x=getxy(x);
		m[x]=c;
	}
	c=0;
	while(!m.count(y)){
		c++;
		y=getxy(y);
	}
	return (c+m[y]);
}

int main(){
	int x,y;
	cin>>x>>y;
	cout<<soln(x,y)<<endl;
	return 0;
}
