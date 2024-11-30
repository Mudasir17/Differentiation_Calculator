#include<iostream>

using namespace std;

class car {
	
	public : 
	int model = 2024;
	string name = "Mehran";
	int limit = 60;
	
	int velocity (){
		cout<<"Speed of the car is "<<endl;
		for (int i = 5; i<=limit; i=i+5){
			
			cout<<i<<" km/h"<<endl;
		}
		
	}
	
};


int main(){
	
	car obj;
	cout<<obj.name<<endl;
	cout<<obj.model<<endl;
	
	obj.velocity();
	
}
