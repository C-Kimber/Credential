<<<<<<< Updated upstream



#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
=======
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
>>>>>>> Stashed changes
#include <string>
using namespace std;

void addName();
void createEmployer();
void searchEmployer();
void readName();
void sortFunction();
int main ()
{
    string which = "";
    string newOr = "";

	cout << "Are you an employer, or an applicant? ";
	cin >> which;
	if(which == "employer" || which == "Employer"){

	    cout << "New or existing employer? ";
	    cin >> newOr;
	    if (newOr == "new" || newOr == "New"){
	        createEmployer();
	    }
	    else{
	        searchEmployer();
	        }

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
		if (line == " "){
			string FULLNAME; // Student's name
			int age = 0;
            double gpa = 0.0;
            string gender = "";

			cout << "Enter the student\'s full name: ";
			getline(cin,FULLNAME);

            cout << "What is your age? : ";
            cin >> age;

            cout << "What is your GPA? : ";
            cin >> gpa;

<<<<<<< Updated upstream
            cout << "What is your gender? : ";
=======
            cout << "What is your Gender? : ";
>>>>>>> Stashed changes
            cin >> gender;

			cout << "Writing student record to disk..." << endl;
			File << endl << FULLNAME << " " << age << " " << gpa << " " << gender << endl;

			File.close();
			cout << "Student record written to disk file: applicants.txt " << endl;
		}
		else{
			cout << "next line..";
		}
	}
	}
}

void readName(string FULLNAME){
	string line;
    cout << "Reading files... " << endl <<endl;
    ifstream myfile ("example.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            cout << line << '\n';
        }
        myfile.close();
    }
    
    else cout << "Unable to open file";
    
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

void searchEmployer(){
    string line;
	string s;
	ifstream File("employers.txt");
	if (File.is_open()){
    	while ( getline (File,line) ){
			s += line +  '\n';
    	}
	File.close();
	}
	
	
	string USERNAME;
	string PASSWORD;

	cout << "What is your username? ";
	cin >> USERNAME;
	size_t userfound = s.find(USERNAME);
	if (userfound==string::npos){
		cout <<"No User by that name";}
	else{
		
		cout << "User found"<<endl;
		cout << "What is your password? ";
		cin >> PASSWORD;
		size_t passfound = s.find(PASSWORD);
		
		if (passfound!=string::npos)
			cout << "Password is correct";
		
		else
			cout << "Password is incorrect";}
	
}

void sortFunction()
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
			
			std::vector<string> first;
			
			//men then female sort
			while(x == 1)
			{	
				
				
				if(dummyVariable1 == male)
				{
				  
				}
				
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
		
	
	}//End of age sort
	
	//sorting by GPA
	while(sortingMethod == 3)
	{   
		
	}//End of gpa sorting
}	

