#include<iostream>
 
int main(){
	int n,t;
	std::cin>>t;
	while(t--){
	
	std::cin>>n;
	std::cout<<(n < 3) * 0 + (!(n < 3)) * (n - 2)<<"\n";
	
	
	}
 
return 0;
}
