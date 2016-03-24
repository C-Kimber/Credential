/*
Credential Checker
3/24/16
Created by: Taylor Kimber, Austin Glenn, Wyatt Giles, and Jaden Ackroyd
*/
#include <fstream>
#include <iomanip>
#include <iostream>
#include <algorithm> 
#include <string>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

void addName();
void createEmployer();
int searchEmployer();
vector<string> readName();
void sortF(vector<string> myvector);
void writeFile(vector<string> info);

int main ()
{
	
    string which = "";
    string newOr = "";
    string sor= "";

	cout << "Are you an employer(special code), or an applicant(applicant)? ";
	cin >> which;
	
	
	if(which == "Room20"){

	    cout << "New or existing employer? ";
	    cin >> newOr;
	    if (newOr== "new"){
	        createEmployer();
	    }
	    else{
	        if (searchEmployer() == 1){
				cout << "You can now read applicants"<<endl;
				cout << "Do you want to read? ";
				cin >> sor;
				if(sor =="no"){
					cout <<"Ending program ";
				}
				/*if(sor == "sort"){ 
				cout << "Sorting";
				vector<string> myvector = readName();
				sortF(myvector);*/
				
				
				else if (sor == "yes"){
					vector<string> i = readName();
					cout << "| FirstName, LastName, Email, Age, GPA, Gender |"<<endl;
					cout << "----------------------------------------------"<<endl;
					copy(i.begin(), i.end(), ostream_iterator<string>(cout, ""));
				}
				else{
					cout << "Ending program ";
				}
	
	        }
			else{
				cout << "Sorry, You are not authorized to read applicants";
			}
	   }
	}
	else if(which == "applicant"){
		addName();
	}
	else{
	    cout << "Sorry, That is not an option.";
	    }



 return 0; 
}


void addName(){
	
	string line;
	fstream File("applicants.txt");
	if (File.is_open()){
	while ( getline (File,line) ){

		string first = ""; // Student's name
		string last = "";
		string age = "";
            	string gpa = "";
            	string gender = "";
		string email = "";
            
		cout << "Enter the student's first name: ";
			cin >> first;
			
		cout << "Enter the student's last name: ";
		cin >> last;
			
		cout << "What is your Email? :";
		cin >> email;

            	cout << "What is your age? : ";
            	cin >> age;

            	cout << "What is your GPA? : ";
            	cin >> gpa;

            	cout << "What is your gender? : ";
            		cin >> gender;
            

		cout << "Writing student record to disk..." << endl;
		File << " " << endl << first << " " << last << " " <<email <<" " << age << " " << gpa << " " << gender << endl << " " ;
			
			
		cout << "Student record written to disk file: applicants.txt" << endl;
	}
	}File.close();
}

vector<string> readName(){
	string line;
	vector<string> info;
	fstream File("applicants.txt");
	if (File.is_open()){
    		while ( getline (File,line) ){
			if (line != "*****" && line != " "){
			info.push_back(string(line));
	}
	else{
		info.push_back(string("\n"));
	}
    	}
	return info;
	}File.close();

}

void createEmployer(){
    string line;
	fstream File("employers.txt");
	if (File.is_open()){
    	while ( getline (File,line) ){

                string USERNAME;
                string PASSWORD;

                cout << "What will be your username? ";
                cin >> USERNAME;
                cout << "What will be your password? ";
                cin >> PASSWORD;

                cout << "Writing employer to disk..." << endl;
    			File << endl << USERNAME << " " << PASSWORD << endl;
    	}
	}File.close();
}

int searchEmployer(){
    string line;
	string s;
	ifstream File("employers.txt");
	if (File.is_open()){
    	while ( getline (File,line) ){
			if(line != "*****"){
					s += line +  '\n';
			}
    	}
	File.close();
	}
	
	
	string USERNAME;
	string PASSWORD;

	cout << "What is your username? ";
	cin >> USERNAME;
	size_t userfound = s.find(USERNAME);
	if (userfound==string::npos){
		cout <<"No User by that name." <<endl;
		return 0;
		}
	else{
		
		cout << "User found"<<endl;
		cout << "What is your password? ";
		cin >> PASSWORD;
		size_t passfound = s.find(PASSWORD);
		
		if (passfound!=string::npos){
			cout << "Password is correct"<<endl;
			return 1;
		
		}else{
			cout << "Password is incorrect ";
			return 0;}
			
	}
	
}
void sortF(vector<string> myvector)
{
// variables
	int sortingMethod = 0;
	int x = 0;
	
	//user input
	cout << "Would you like to sort by 1: Gender, 2: Age 3: GPA (Please enter 1, 2 or 3): ";
	cin >> sortingMethod;
	
	//begin of sorting function
	while (sortingMethod < 4 && sortingMethod > 0)
	{
		//Sorting by Gender
		while(sortingMethod == 1)
		{
			
			cout << "Would you like to sort by males to females?(1) Or females to males?(2): ";
			cin >> x;
			if(x <= 2 && x >= 1)
			{
				
				//men then female sort
				while(x == 1)
				{
					
				}
				
				//female then men sort
				while(x == 2)
				{
					
				}	
			}
		}
		
	}//end of sorting by gender 
	
	//Sorting by age
	while(sortingMethod == 2)
	{
		int y = 0;
		cout << "Would you like to sort by oldest to youngest?(1) Or youngest to oldest?(2): ";
		cin >> y;
			if(y > 0 && y < 3) {
				while(y == 1)//sorting by oldest to youngest
				{
					
				//std::reverse(myvector.begin(),myvector.end());
				}
				while(y == 2)//sorting by youngest to oldest
				{
				// std::sort (myvector.begin(), myvector.begin()+4);
				 //std::sort (myvector.begin()+4, myvector.end(), myfunction);
				 //std::sort (myvector.begin(), myvector.end(), myobject);
				}
				
				}
			else {
				cout << "Sorry invalid input.";
			}
	}//End of age sort
	
	//sorting by GPA
	while(sortingMethod == 3)
	{   
		
	}//End of gpa sorting
}




void writeFile(vector<string> info){
		//Shows User that program is writing
		cout << "Writing sorted applicants to disk..." << endl;
		//Writes vector to file
    	std::ofstream output_file("applicants.txt");
		std::ostream_iterator<std::string> output_iterator(output_file, " ");
		std::copy(info.begin(), info.end(), output_iterator);
}

void displayFile(vector<string> info){
	copy(info.begin(), info.end(), ostream_iterator<string>(cout, " "));
	
}


