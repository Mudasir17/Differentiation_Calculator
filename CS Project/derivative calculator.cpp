// start of the program
#include<iostream>
#include<regex>
#include<string>
#include<algorithm>

using namespace std;

// function for coefficient of a term
int coef(string a){
	
	regex part(R"(-\s*x\^\d+)");
	// pattern for extracting the coefficient from the term
	regex parse(R"(([+-]?\s*\d+)(?=[a-z]))");
	
	smatch co;
	
	// if there's no coefficient and exponent then considering it 1 or -1 depending on the sign
	if(a=="+x"|| a=="x")
		return 1;
	
	else if(a=="-x")
		return -1;
	
	if(regex_search(a,co,part)){
	
			return -1;
	}
	// extracting the coefficient
	if(regex_search(a,co,parse)){
		
		// variable for storing the coefficient
    	string matched=co[0].str();
    	
    	//returning the coefficient
		return stoi(matched);
	}
	return 1;
}


//function for exponent of a term
int exp(string e){

	// pattern for extracting the exponent from the term
	regex parse(R"(\^(-?\d+))");
	
	smatch exp;
	
	//extracting the exponent
	if (regex_search(e,exp,parse)){
		
			return stoi(exp[1]);

	}
	return 1;
}

//main function
int main(){
	
	// declaration of the variables	
	int coefficient{0}, exponent{0}, new_coefficient{0}, new_exponent{0};
	string new_term, result, equation;
	char answer;
	
	//Introduction
	cout<<"**********Welcome To Derivatives Calculator**********"<<endl;
	
	
	do{
		
		
		result.clear();
		// taking the equation from the user
		cout << "\nEnter the equation : " <<endl;
		getline(cin,equation);

		smatch te;
	
		// general pattern for extracting the terms i.e., x^3, 2x^2,2x etc
		regex parse(R"(([+-]?\s*\d*[a-zA-Z](\^\-?\d+)?))");

		// loop for extracting terms one by one 
		while( regex_search (equation,te,parse)){

			string term = te[0].str();
			term.erase(remove(term.begin(), term.end(), ' '), term.end());
		
			// getting the coefficient from the term using coefficient function
			coefficient = coef(term);
			
			// getting the exponent from the term using exponent function
			exponent = exp(term);

			// taking the derivative using power rule
			new_coefficient = coefficient * exponent;
			new_exponent = exponent-1;
		
			// term after differentiation
        	if (new_exponent > 1)
        		new_term = to_string(new_coefficient) + "x" + "^" + to_string(new_exponent);
		
        	else if (new_exponent == 1)
            	new_term = to_string(new_coefficient) + "x"; 

      		else if (new_exponent == 0)
        		new_term = to_string(new_coefficient);

    		else if (new_exponent <0)
        	    new_term = to_string(new_coefficient) + "x" + "^" + to_string(new_exponent);
            
        	// condition for adding '+' or '-' sign after every term
       		 if (!result.empty() && new_coefficient >0){
        
				result += "+";
			}
        
        	// merging all terms to make the final result
        	result += new_term;

			equation=te.suffix().str();


		}
		// printing the final result
		cout<<"\nDerivative : "<<endl;
		cout<<result;
	
		regex parses(R"([+-]?\d+)");
		if(regex_search(equation,te,parses)){
		
			cout<<"+0";
		}
	
		cout<<"\nDo you want to do it one more time? (y for yes / n for no)"<<endl;
		cin>>answer;
		cin.ignore();


	}while(!(answer=='n' || answer=='N'));

}

