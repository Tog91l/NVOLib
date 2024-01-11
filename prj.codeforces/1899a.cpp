#include<iostream>
int main(){
int t,n;
std::cin>>t;
for(int i=1;i<=t;i++){
std::cin>>n;
if(n%3!=0)
std::cout<<"First"<<std::endl;
else
std::cout<<"Second"<<std::endl;
}
return 0;
}
