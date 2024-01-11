#include<iostream>
using namespace std;
long long n,m,k,x,y,i;
main(){
	cin>>n>>k>>x;
	for(i=1;i<n;i++){
		cin>>y;
		if(m == k)break;
		if(x > y)m++;
		else{
			x=y;
			m=1;
		}
	}
	cout<<x<<endl;
}
