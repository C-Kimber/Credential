


#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

void addName();
void createEmployer();
void searchEmployer();
void readName();

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
			//These is the scores for the credentials
			int score1 = 0;
			int score2 = 0;
			int score3 = 0;
			int score4 = 0;
			int score5 = 0;
			int score6 = 0;

			cout << "Enter the student's full name: ";
			getline(cin,FULLNAME);

            cout << "What is your age? : ";
            cin >> age;

            cout << "What is your GPA? : ";
            cin >> gpa;

            cout << "What is your gender? : ";
            cin >> gender;
			
			/*cout << "You will now be asked questions rate on scale of (1-5)" << endl;
			
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
    ifstream myfile ("applicants.txt");
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
