#include<iostream>
#include<vector>

using namespace std;
int main(){
	
	
//	vector<int> nums = {1,2,3,4,5};
//	
//	for(int num : nums){
//		
//		cout<< num<<"\n";
//	}
//	
//	nums[0] = 10;
//	nums[1] = 20;
//	nums[2] = 30;
//	
//	for(int num : nums){
//		
//		cout<< num<<"\n";
//	}
//
//cout<<nums.front()<<endl;	
//cout<<nums.back()<<endl;
//cout<<nums.at(3);
//
//vector<string> cars = {"Honda", "Suzuki", "Toyota"};
//
//cars.push_back("lamborghini");
//cars.push_back("farari");
//cars.push_back("bolan");
//for(string car : cars){
//	
//	cout<<"\n"<<car; 
//	
//}

vector<int> nums = {};

for(int i= 1; i<=20; i++){
	
	nums.push_back(i);
}

for(int i=1; i<nums.size(); i++){
	
	cout<<nums.at(i)<<endl;
}

for(int j= 1; j<=20; j++){
	
	nums.pop_back();
}

for(int num : nums){
	
	cout<<num<<endl;
}

cout<<"size of the vector array is "<<nums.size();



cout<<"\n"<<nums.empty();
}


