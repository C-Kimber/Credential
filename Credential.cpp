


#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <algorithm> 
#include <string>
using namespace std;

void addName();
void createEmployer();
int searchEmployer();
void readName();

int main ()
{
    string which = "";
    string newOr = "";
	string sor= "";

	cout << "Are you an employer, or an applicant? ";
	cin >> which;
	
	
	if(which == "employer"){

	    cout << "New or existing employer? ";
	    cin >> newOr;
	    if (newOr== "new"){
	        createEmployer();
	    }
	    else{
	        if (searchEmployer() == 1){
				cout << "You can now read applicants"<<endl;
				cout << "Do you want to sort or read?";
				cin >> sor;
				if(sor == "sort"){ 
				cout << "Sorting";
				
				}else if (sor == "read"){
					cout << "reading";
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
		if (line == " "){
			string FULLNAME; // Student's name
			int age = 0;
            double gpa = 0.0;
            string sex = "";
    		//These are the scores for the credentials
            int score1 = 0;
            int score2 = 0;
            int score3 = 0;
            int score4 = 0;
            int score5 = 0;
            int score6 = 0;
            
			cout << "Enter the student\'s full name: ";
			getline(cin,FULLNAME);

            cout << "What is your age? : ";
            cin >> age;

            cout << "What is your GPA? : ";
            cin >> gpa;

            cout << "What is your sex? : ";
            cin >> sex;
            
    		/*	
            cout << "You will now be asked questions rate on scale of (1-5)" << endl;
	
			cout << "Mathmatics";
	    	cin >> score1;
		
	    	cout << "Science";
	    	cin >> score2;
			
			cout << "Engineering";
			cin >> score3;
			
			cout << "Construction";
			cin >> score4;
			
			cout << "Problem Solving";
			cin >> score5;
			
			cout << "Social Skills";
			cin >> score6;
            */

			cout << "Writing student record to disk..." << endl;
			File << endl << FULLNAME << " " << age << " " << gpa << " " << sex << endl;

			File.close();
			cout << "Student record written to disk file: scores.txt" << endl;
		}
		else{
    		cout << "next line..";
		}
	}
	}
}

void readName(string FULLNAME){
	string line;
	float S1, S2, S3;  // Three test scores
	cout << "Reading student record from disk file: scores.txt" << endl <<endl;

	ifstream inputFile("applicants.txt");
	if (inputFile.is_open()){
    	while ( getline (inputFile,line) )
    	{
    		if (line == FULLNAME){
    			inputFile >> S1 >> S2 >>S3;
    			inputFile.close();
    		}
    	}



	cout << "Student\'s name: " << FULLNAME << endl;
	}


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
		cout <<"No User by that name";
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
			cout << "Password is incorrect";
			return 0;}
			
	}
	
}


