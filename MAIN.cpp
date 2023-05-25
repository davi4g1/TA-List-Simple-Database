/*
Program by Davide Forgione
Assignment for Programming Methedology II, Concordia University
Winter 2023

Learning concepts include:
- Object Oriented Programming
- Use of c++ vectors
- Use of c++ Sort() algorythm 
- Use of c++ string streams
- File Handling
- Exception Handling
- Operator Overloading

This is a program that allows a user to add to a list of TA's (teacher assistants)
TA's have a Satus, Student Number, Name, Year Hired, Age and Program
The program starts by pushing 7 TA's into a vector and then inputting the vector into a file "TAs_list4".
It then filters out all the TA's with status "Alum" using the checkAlum() method.
As per assignment requirements, all TA's with the status "Alum" are then filtered out using the checkAlum() method.
The new list with no "Alums" is displayed.
User is prompted to add a TA or Sort the list.
Sorting can be done by descending or ascending order according to any of the data members of a TA listed before.
TAs_list4 file will be uploaded according to the sort chosen.

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include <algorithm>
using namespace std;


class TAs{

public:

	TAs(string,unsigned int,string,unsigned int,unsigned int,string);
	TAs();

	void setStatus(string);
	void setStudent_Id(unsigned int);
	void setFirst_Name(string);
	void setYear_Hired(unsigned int);
	void setAge(unsigned int);
	void setDept(string);

	void changeTA(string,unsigned int,string,unsigned int,unsigned int,string);
	void TAs_to_file(ofstream&);

	string getStatus(){return Status;}
	unsigned int getStudent_Id(){return Student_Id;}
	string getFirst_Name(){return First_Name;}
	unsigned int getYear_Hired(){return Year_Hired;}
	unsigned int getAge(){return Age;}
	string getDept(){return Dept;}


private:
	string Status;
	unsigned int Student_Id;
	string First_Name;
	unsigned int Year_Hired;
	unsigned int Age;
	string Dept;


};


	void TAs::setStatus(string x){Status=x;}
	void TAs::setStudent_Id(unsigned int x){Student_Id=x;}
	void TAs::setFirst_Name(string x){First_Name=x;}
	void TAs::setYear_Hired(unsigned int x){Year_Hired=x;}
	void TAs::setAge(unsigned int x){Age=x;}
	void TAs::setDept(string x){Dept=x;}

	void TAs::changeTA(string a,unsigned int b,string c, unsigned int d, unsigned int e, string f){

		 	TAs::setStatus(a);
			TAs::setStudent_Id(b);
			TAs::setFirst_Name(c);
			TAs::setYear_Hired(d);
			TAs::setAge(e);
			TAs::setDept(f);
	}

	void TAs::TAs_to_file(ofstream& x){

		 	x<<getStatus()<<"\t"<<getStudent_Id();
		 	x<<"\t"<<getFirst_Name();
		 	x<<"\t"<<getYear_Hired()<<"\t"<<getAge()<<"\t"<<getDept()<<"\t";

	}



	template <typename T>
	ostream& operator<<(ostream& os, vector<T>& v)
	{
	    for (int i = 0; i < v.size(); ++i) {
	    	os <<v[i].getStatus()<<"\t"<<v[i].getStudent_Id();
	    os<<"\t"<<v[i].getFirst_Name();
	    os<<"\t"<<v[i].getYear_Hired()<<"\t"<<v[i].getAge()<<"\t"<<v[i].getDept()<<"\t";
	    os<<endl;
	    }
	    return os;
	}


	TAs::TAs(string status,unsigned int student_id,string first_name, unsigned int year_hired,unsigned int age,string dept){
		Status=status;
		Student_Id=student_id;
		First_Name= first_name;
		Year_Hired=year_hired;
		Age=age;
		Dept= dept;
	}

	TAs::TAs(){
		Status="";
		Student_Id=0;
		First_Name= "";
		Year_Hired=0;
		Age=0;
		Dept= "";
	}

TAs addNewTA(){
		string status, first_name, dept;
		unsigned int student_id, year_hired, age;
		string temp;

	cout<<"Enter new TA info:"<<endl;
		    while (true) {
		        std::cout << "Enter status: ";
		        std::getline(std::cin, status);
		        try {
		             if (status != "Grad"&&status!="UGrad") {
		          throw std::invalid_argument("Error: status must be either Grad or UGrad");
		            }

		            break;
		        }
		        catch (const std::invalid_argument& e) {
		            std::cout << e.what() << std::endl;
		        }
		    }

			    while (true) {

	cout<<endl<<"Student ID: "<<endl;

			  std::getline(std::cin, temp);


			        try {
			           unsigned int x = std::stoi(temp);
			           if (x>99999999|| x<0) {

   throw std::out_of_range("Error: studentID can only be a number greater than 0 and less than 9999999");
			            }
			            break;
			        }
			         catch (const std::invalid_argument& e) {
	            std::cout << "Error: Invalid input. Please enter a number." << std::endl;
	        }
			        catch (const std::out_of_range& e) {
			            std::cout << e.what() << std::endl;
			        }
			    }
		    student_id=stoi(temp);

	cout<<endl<<"First Name: ";

	  while (true) {
		        cout<<endl<<"Enter first Name: ";
		        std::getline(std::cin, first_name);
		        try {
		          if (std::string::npos != first_name.find_first_of("0123456789")) {
	              throw  std::invalid_argument("Name cannot contain numbers");
	}
	        for (char c : first_name) {
	        if (c < 48 || (c > 57 && c < 65) || (c > 90 && c < 97) || c > 122) {
	            throw out_of_range("Name cannot contain special characters");
	        }	   }

		            break;
		    }
		        catch (const std::invalid_argument& e) {
		            std::cout << e.what() << std::endl;
		        }
		        catch (const out_of_range& e){
		            cout<<e.what()<<endl;
		        }
		    }


		 while (true) {
	cout<<endl<<"Enter Year Hired: ";
					  std::getline(std::cin, temp);


					        try {
					           unsigned int x = std::stoi(temp);
					           if (x<=1900|| x>=2023) {

		   throw std::out_of_range("Error: Year Hired can only be a number greater than 1899 and less than 2024");
					            }
					            break;
					        }
					         catch (const std::invalid_argument& e) {
			            std::cout << "Error: Invalid input. Please enter a number." << std::endl;
			        }
					        catch (const std::out_of_range& e) {
					            std::cerr << e.what() << std::endl;
					        }
					    }
      year_hired=stoi(temp);

		 while (true) {
			cout<<endl<<"Enter Age: ";
							  std::getline(std::cin, temp);


							        try {
							           unsigned int x = std::stoi(temp);
							           if (x>=120|| x<=18) {

				   throw std::out_of_range("Error: Age must be 18 or over and 120 or less");
							            }
							            break;
							        }
							         catch (const std::invalid_argument& e) {
					            std::cout << "Error: Invalid input. Please enter a number." << std::endl;
					        }
							        catch (const std::out_of_range& e) {
							            std::cerr << e.what() << std::endl;
							        }
							    }
		      age=stoi(temp);

		while (true) {
cout<<endl<<"Enter Department: ";
std::getline(std::cin, dept);
				        try {
				             if (dept != "BCEE"&&dept!="CSSE"&&dept!="CISSE"&&dept!="CME"&&dept!="ECE"&&dept!="MIAE") {
				          throw std::invalid_argument("Error: Invalid department");
				            }

				            break;
				        }
				        catch (const std::invalid_argument& e) {
				            std::cout << e.what() << std::endl;
				        }
				    }
		cout<<endl;

		 TAs newTA(status,student_id,first_name,year_hired,age,dept);
return newTA;
	}

void changeList(vector<TAs> x){
	 ofstream list;
		list.open("TAs_list4");


		list<<x.size()<<endl;
		for (int i = 0; i<x.size(); i++)
		{
			x[i].TAs_to_file(list);
			list<<endl;
		}

		list.close();

	}


vector<TAs> checkAlum(){

		vector<TAs> x;
		TAs vec;

		ifstream list;
		string a{""};
		stringstream s[10];
		string b[10];
		int i{1},j{0};
		string k;

		list.open("TAs_list4");
		if (!list)
		{
			cerr<<"error";
		}

		getline(list,a);

			while (getline(list, a)) {

					        s[i]<<a;
					        string status, first_name, dept;
					        int student_id, year_hired, age;


					        s[i] >> status >> student_id >> first_name >> year_hired >> age >> dept;


					        if (status != "Alum") {
					            b[i]=s[i].str();
					           vec.changeTA(status,student_id,first_name,year_hired,age,dept);
					           x.push_back(vec);
					           j++;
					        }
					        i++;
		}
			b[0]=to_string(j);
		list.close();
	changeList(x);
	return x;
	}




void Sort(vector<TAs> x){

	int select=1,select2=1;

	cout<<"Select what to sort by:\n1.Status, 2. id, 3. name, 4.year hired, 5. age, 6. department:"<<endl;
	cin>>select;
	cout<<"Enter 1 for ascending order or 2 for descending order";
	cin>>select2;

auto sorting=[&]( TAs& t1,  TAs& t2)->bool{

	switch(select){
	case 1:
		if (select2==1){
			return t1.getStatus()[0]<t2.getStatus()[0];
		}
		else if (select2==2){
			return t1.getStatus()[0]>t2.getStatus()[0];
		}
		break;
	case 2:
		if (select2==1){
			return t1.getStudent_Id()<t2.getStudent_Id();
		}
		else if(select2==2){
			return t1.getStudent_Id()>t2.getStudent_Id();
		}
		break;
	case 3:
		if (select2==1){
					return t1.getFirst_Name()[0]<t2.getFirst_Name()[0];
				}
				else if (select2==2){
					return t1.getFirst_Name()[0]>t2.getFirst_Name()[0];
				}

		break;
	case 4:
		if (select2==1){
			return t1.getYear_Hired()<t2.getYear_Hired();
				}
		else if(select2==2){
			return t1.getYear_Hired()>t2.getYear_Hired();
				}
		break;
	case 5:
		if (select2==1){
			return t1.getAge()<t2.getAge();
					}
		else if(select2==2){
			return t1.getAge()>t2.getAge();
					}
			break;

	case 6:
	if (select2==1){
			return t1.getDept()[0]<t2.getDept()[0];
		}
		else if (select2==2){
			return t1.getDept()[0]>t2.getDept()[0];
		}
		break;
	}

};


sort(x.begin(),x.end(),sorting);
changeList(x);

}

int main() {

	int totalTA{0};
	vector<TAs> tas;

	TAs a{};

a.changeTA("Grad", 3056738, "Sarmad", 2018, 26, "CSSE");
tas.push_back(a);
a.changeTA("UGrad",1652126, "Fernando", 2015, 28, "BCEE");
tas.push_back(a);
a.changeTA("UGrad", 3926930, "Mazen" ,2017 ,37, "BCEE");
tas.push_back(a);
a.changeTA("Grad", 5392054, "Abdullah", 2018, 37, "BCEE");
tas.push_back(a);
a.changeTA("UGrad", 5436083, "Chems-Eddine" ,2015, 36, "CSSE");
tas.push_back(a);
a.changeTA("UGrad" ,8255588 ,"Muhammad", 2018, 31, "CSSE");
tas.push_back(a);
a.changeTA("Alum",1658887,"jim",2015,35,"CSSE");
tas.push_back(a);

cout<<"List with Alum"<<endl;
changeList(tas);
cout<<tas<<endl;

cout<<"List without Alum:"<<endl;
tas=checkAlum();
cout<<tas<<endl;

int menu;
cout<<"Select 1 to add a TA, 2 to sort, 3 to quit";
cin>>menu;
while (true){
if (menu==1){
tas.push_back(addNewTA());
changeList(tas);
cout<<"Select 1 to add a TA, 2 to sort, 3 to quit";
cin>>menu;
}
else if (menu==2){
    Sort(tas);
    cout<<"Select 1 to add a TA, 2 to sort, 3 to quit";
    cin>>menu;
}
else if (menu==3){
	cout<<"bye";
	break;
}
}


}

//Works Cited

//https://www.walletfox.com/course/sortvectorofcustomobjects11.php WalletFox for the sort function
//https://stackoverflow.com/questions/9438209/for-every-character-in-string Kerrek SB for the exception
//https://stackoverflow.com/questions/2346599/how-to-test-if-a-string-contains-any-digits-in-c KitsuneYMG for the FindFirst function

