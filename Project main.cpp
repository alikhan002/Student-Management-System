#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <time.h>
#include <typeinfo>
#include <stdlib.h>
#include <sstream>

using namespace std;

class user{
	private:
		string username  , password;
		    
	public:
		
};

class Admin : public user
{   private:
        string username,password;
    public:
        
        
        
        
int m = 0;
int k =0;


int adminLogin()
{
	system("cls");
	cout<<"\n -------------------- Admin Login --------------------";	

    string username;
	string password;
	
	cout<<"\n Enter username : ";
	cin>>username;
	cout<<"\n Enter password : ";
	cin>>password;
	
	if(username=="admin" && password=="admin") 
	{
	    adminView();
	    getchar();	
       }   
       else
       {
        cout<<"\n Error ! Invalid Credintials..";	
        cout<<"\n Press any key for main menu ";
        getchar();getchar();
      }
   
   return 0;
	
}

int adminView()
{	
    int goBack = 0;
    while(1)
    {
		system("cls");
		cout<<"\n 1 Register a Student";
		cout<<"\n 2 Delete All students name registered";
		cout<<"\n 3 Check List of Student registered by username";
		cout<<"\n 0. Go Back <- \n";
		int choice;
		
		cout<<"\n Enter you choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1: registerStudent();break;  
			case 2: deleteAllStudents(); break;
			case 3: checkListOfStudentsRegistered(); break;  
			case 0: goBack = 1;break;
	                default: cout<<"\n Invalid choice. Enter again ";
	                 getchar();           	
	   }   
	   
	   if(goBack == 1)
	   {
	   	break; 
           }     
    	
   }
   
   
   return 0;

}


int deleteAllStudents()
{
	remove("db.dat");
	cout<<"\n Please any key to continue..";
	
	getchar(); getchar();
	return 0;
}


int checkListOfStudentsRegistered(){
    cout<<"\n ---------- Check List of Student Registered by Username----------- ";	
	
	    //check if record already exist..
    ifstream read;
    read.open("db.dat");
    
    if(read)
    {       int recordFound =0; 
	    string line;
    	    while(getline(read, line)) {
    	    	
				char name[100];
    	    	strcpy(name, line.c_str());
    	    	string filename = name;
				cout<<"\n"<<filename;

				int total_lines = 0;
            ifstream read1;
			read1.open(filename.c_str(), ios::app);
			string line;
			while(getline(read1,line)){
				++ total_lines;
			}
    		read1.close();
			ifstream read;
			read.open(filename.c_str(), ios::app);
			string l;
                if(read)
                {	
                    int line_no = 0;
                while (line_no != total_lines && getline(read, l)) {
                ++line_no;
                }
                if (line_no == total_lines) {
					cout<<"-> "<<l<<"\n";}
				read.close();

            }
    read.close();        
    }
	}
    else
    {
    	cout<<"\n No Record found :(";
    }
	
	
    cout<<"\n Please any key to continue..";
    getchar(); getchar();
    return 0;
}



int registerStudent()
{
    cout<<"\n ----- Form to Register Student ---- \n";	

    string name, username, password, rollno, branch;
     int total;

    cout<<"\n Enter Name : ";     cin>>name;
    
    cout<<"\n Enter Username : ";     cin>>username;
    
    
    cout<<"\n Enter password : ";     cin>>password;
    
    cout<<"\n Enter rollno : ";     cin>>rollno;
    getchar();
    
    cout<<"\n Enter branch : ";     cin>>branch;
	cout<<"\n Enter initial number of presents :"; cin>>m;

    
    //check if record already exist..
    ifstream read;
    read.open("db.dat");
    
    if(read)
    {      int recordFound =0; 
	   string line;
    	    while(getline(read, line)) {
        	if(line == username+".dat" )
        	{
        		recordFound = 1 ;
        	    break;
			}
        }
        if(recordFound == 1)
        {
        	cout<<"\n Username already Register. Please choose another username ";
        	getchar(); getchar();
        	read.close();
        	return 0;
		}
	}
    read.close();

    ofstream out;
	out.open("db.dat", ios::app);
	out<<username+".dat"<<"\n";
	out.close();

	ofstream out1;
	string temp = username+".dat";
	out1.open(temp.c_str());
	out1<<name<<"\n"; 	out1<<username<<"\n"; 	out1<<password<<"\n";
	out1<<rollno<<"\n"; 	out1<<branch<<"\n"; 

	out1<<m<<"\n";  

	out1.close();

	cout<<"\n Student Registered Successfully !!";
    
        cout<<"\n Please any key to continue..";
	getchar(); getchar();
	return 0;		
}


        
};

class student : public user
{   
    string username,password;
    public:

 
int total=10;

//student part
int studentView()
{
cout<<"\n Enter username : ";
cin>>username;

cout<<"\n Enter password : ";
cin>>password;

int res = checkStudentCredentials(username, password);

if(res  == 0)
{
   cout<<"\n Invalid Credentials !!";
   cout<<"\n Press any key for Main Menu..";
   getchar(); getchar();	
   return 0;
} 

    int goBack = 0;
	while(1)
    {
		
		system("cls");
		cout<<"\n 1 To count my Attendance";
		cout<<"\n 2 To send a leave application";
		cout<<"\n 0. Go Back <- \n";
		int choice;
		
		cout<<"\n Enter you choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1: Attendance(username); break;
			case 2: sendLeaveApplication(username);break;
			case 0: goBack = 1;break;
	                default: cout<<"\n Invalid choice. Enter again ";
	                getchar();           	
	   }   
	   
	   if(goBack == 1)
	   {
	   	break;
           }     
    	
   }
   
}



int studentLogin()
{   student s;      // creating object of class studentt
    system("cls");
    cout<<"\n -------------------- Student Login ----------------------";	
    s.studentView();
    return 0; 
}

int checkStudentCredentials(string username, string password)
{
	
	ifstream read;
	read.open("db.dat");
	int recordFound = 0;
	if (read) {
  		string line;
        string temp = username +".dat";
        while(getline(read, line)) {
        	if(line == temp)
        	{
        		recordFound = 1;
		}
        }
	}
    read.close();   
        if(recordFound == 1)
            {
				ifstream read;
				string filename = username+".dat";
				read.open(filename.c_str(), ios::app);
				int line_number = 0;
				string line;
				while (line_number != 3 && getline(read, line)) {
                ++line_number;
                }
				if(password == line)
					return 1;
				else
					return 0;
			}
		else
			return 0;
       	
}



int Attendance(string username)							// Function OVERLOADING
{		int total_lines = 0;
	string filename = username+".dat";


	ifstream read;
	read.open(filename.c_str(), ios::app);
	string line;
	while(getline(read,line)){
			++ total_lines;
		}

	read.close();


	ifstream read1;
	 read1.open(filename.c_str(), ios::app);
	if(read1)
	{	
		int line_no = 0;

	while (line_no != total_lines && getline(read1, line)) {
    ++line_no;
	}
	if (line_no == total_lines) {
		
		cout<<"\nTotal present: "<<line;
		int i;
		istringstream(line) >> i;
		cout<<"\nPercentage of attendance :\t"<< (i*100/total)<<"%";
	}
	}
	
cout<<"\n Please any key to continue..";

getchar();getchar();

return 0;	
} 




int sendLeaveApplication(string username)
{	
	char add[100];
	cout<<"\n Write your application here: ";
	getchar();
	cin.getline(add, 100);

	time_t now = time(0);
	tm *ltm = localtime(&now);
	
	ofstream out;
	out.open("application.dat", ios::app);
	out<<add<<" -> "<<ltm->tm_mday<<"/"<<1+ltm->tm_mon<<"/"<<1900+ltm->tm_year<<" -> "<<username<<"\n";
	out.close();
	cout<<"\n Application successfully sent !!";
	cout<<"\n Please any key to continue..";
	getchar();
	return 0;
}
       
        
};


class teacher: public user
{   
    string username,password;
public:
	        
	int teacherlogin()
	{
		system("cls");
		cout<<"\n -------------------- Teacher Login ----------------------";	
	
	        string username;
		string password;
		
		cout<<"\n Enter username : ";
		cin>>username;
		cout<<"\n Enter password : ";
		cin>>password;
		
		if(username=="teacher" && password=="teacher") 
		{   teacherView();
		    getchar();	
	       }   
	       else
	       {
	        cout<<"\n Error ! Invalid Credintials..";	
	        cout<<"\n Press any key for main menu ";
	        getchar();getchar();
	      }
	   
	   return 0;
		
	}
	
	
	int Attendance()
	{   ifstream read;
	    read.open("db.dat");
	    
	    if(read)
	    {       int recordFound =0; 
		    string line;
	    	    while(getline(read, line)) {
	    	    	
	    	    	char name[100];
	    	    	strcpy(name, line.c_str());
	    	    	string filename = name;
	
	    int total_lines = 0;
	            ifstream read1;
		read1.open(filename.c_str(), ios::app);
		string line;
		while(getline(read1,line)){
				++ total_lines;
			}
	    read1.close();
	
	
		ifstream read;
		read.open(filename.c_str(), ios::app);
		// ifstream read;
		// read.open("db.dat");
	    cout<<"name:"<<filename<<endl;
	    int c;
	    cout<<"1: present:"<<"\t"<<"O : absent:"<<endl;
	    cout<<"enter choice:"<<endl;
	    cin>>c;
	    switch(c)
	    {
	        case 1: 
	                { string line;
	                if(read)
	                {	
	                    int line_no = 0;
	                while (line_no != total_lines && getline(read, line)) {
	                ++line_no;
	                }
	                if (line_no == total_lines) {
	                    int i;
	                    istringstream(line)>>i;
	                    i++;
	
	                    ofstream out1;
	                    string temp = name;
	                    out1.open(temp.c_str(), ios::app);
	                    out1<<i<<"\n";
	
	                }
	                }	
	                break;
	                }
	        case 0:
	                break;
	
	    }
		
	    read.close();        
	    }
	     
	    }
	    read.close();
	
	cout<<"\n Please any key to continue..";
	
	getchar();getchar();
	
	return 0;	
	}
	
	
	
	int teacherView()
	{	
	    int goBack = 0;
	    while(1)
	    {
			system("cls");
			cout<<"\n 1 Mark Attendance";
			cout<<"\n 0. Go Back <- \n";
			int choice;
			
			cout<<"\n Enter you choice: ";
			cin>>choice;
			
			switch(choice)
			{
				case 1: Attendance();break;  
				case 0: goBack = 1;break;
		                default: cout<<"\n Invalid choice. Enter again ";
		                 getchar();           	
		   }   
		   
		   if(goBack == 1)
		   {
		   	break; 
	           }     
	    	
	   }
	   
	   
	   return 0;
	
	}

        
        
};



int main(){
		
while(1)
{
	system("cls");
	cout<<"\n Student Management System \n";
	cout<<"-------------------------------------\n\n";
	
	cout<<"1. Student Login\n";
	cout<<"2. Admin Login\n";
	cout<<"3. Teacher Login\n";
	
	cout<<"0. Exit\n";
	int choice;
	
	cout<<"\n Enter you choice: ";
	cin>>choice;
	
	if(choice ==1){
		student obj;
		obj.studentLogin();
	}
	
	else if(choice == 2){
		Admin object;
		object.adminLogin();
	}
	
	else if(choice == 3 ){
		teacher objj;
		objj.teacherlogin();
	}

	else if(choice== 0){
	
	        while(1)
	        {
		    system("cls");
        	cout<<"\n Are you sure, you want to exit? y | n \n";
        	char ex;
        	cin>>ex;
        	if(ex == 'y' || ex == 'Y')
        	   exit(0);
        	else if(ex == 'n' || ex == 'N')
             {
             	 break;
             }
             else{
             	cout<<"\n Invalid choice !!!";
             	getchar();
             }

     	   }
        
            
        }
             	 
    else{
	 cout<<"\n Invalid choice. Enter again ";
    getchar();
	}   		        

}
	
return 0;
}

