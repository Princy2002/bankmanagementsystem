//BANK MANAGEMENT SYSTEM
#include <bits/stdc++.h>
using namespace std;

class customer{
    
    public:
    
    string name;
    int acc_no;
    string type_acc;
    float balance;
    string address;
};

class bank: public customer{
    
    public:
  
	void createaccount();
	void displayall();
	void checkaccount();
    void updatename();
	void updateaddress();
	void deleteaccount();
	void displaybalance();
    void display_details();
	void display_acctype();
    void deposit();
    void withdraw();
};


void bank ::createaccount()  //function for creating new account
{
  
	fstream file;
	string name;
    int acc_no;
    string type_acc;
    float balance;
	string address;
	cout<<"Enter details for creating new account : "<<endl;
	cout << "ACCOUNT NO : ";
	cin >> acc_no;
	cout << "CUSTOMER's NAME: ";
	cin>>name;
	cout << "\nACCOUNT TYPE : ";
	cin>>type_acc;
	cout << "\nBALANCE: ";
	cin >> balance;
	cout << "\nADDRESS: ";
	cin>>address;


	file.open("bank1.txt",
			ios::out | ios::app);
	file << " " << acc_no << " "
		<< name << " " << type_acc
		<< " " << balance << " " << address << "\n";
	file.close();
}


void bank::displayall()   //function for displaying all details
{
  
	fstream file;
	string name;
    int acc_no;
    string type_acc;
    float balance;
	string address;
	cout << "ALL DETAILS : ";

	// Open the file in input mode
	file.open("bank1.txt", ios::in);
	if (!file)
		cout << "\n\nFile Opening Error!";
	else {

		cout << "\n\n\nACC NO\t\tCUST"
			<< "\t\tACC TYPE\tBALANCE\t\tADDRESS"
				"\n\n";
		file >> acc_no >> name>>type_acc >> balance>> address;

	
		while (!file.eof()) {

			cout << " " << acc_no
				<< "\t\t" << name
				<< "\t\t" << type_acc
				<< "\t\t" << balance
				<< "\t\t" << address
				<< "\n\n";
			file >> acc_no >> name>>type_acc >> balance >> address;
		}
       

		// Close the file
		file.close();
	}
}

// Function to check bank account 
void bank ::checkaccount()
{
    
	fstream file;
    string name;
    int acc_no;
    string type_acc;
    float balance;
	string address;
	int count = 0;
	int raccno;

	cout << "Check account : ";

	// Open the file in input mode
	file.open("bank1.txt", ios::in);
	if (!file)
		cout << "\n\nFile Opening Error!";
	else {

		cout << "\n\nEnter account no : ";
		cin >> raccno;
		file >> acc_no >> name;
		file >> type_acc >> balance >>address;

		while (!file.eof()) {

			if (raccno == acc_no) {
               
				cout << "\n\n"	<< "YES ACCOUNT EXISTS";
				
				cout << endl;
				
				count++;
				break;
			}
			file >> acc_no >> name;
			file >> type_acc >> balance>>address;
		}
       
		file.close();
		if (count == 0)
			cout << "\n\n Invalid account number"<<endl;
			
	}
}


void bank::updatename() //function for updating name
{

	fstream file, file1;
	int balance, new_bal, count = 0;
	string name, new_cname, type_acc, address;
	int  raccno, acc_no;

	cout << "\n\n\t\t\t\tUpdate Bank Record";
	file1.open("bank2.txt",
			ios::app | ios::out);
	file.open("bank1.txt", ios::in);

	if (!file)
		cout << "\n\nFile Opening Error!";
	else {

		cout << "\n\nBANK ACC NO : ";
		cin >> acc_no;
		file >> raccno >> name;
		file >> type_acc >> balance>> address;

		// Till end of file is reached
		while (!file.eof()) {
			if (acc_no == raccno) {
			
				cout << "\t\t\t\t"
					<< "Update Record";
				cout << "\n\nNew account holder  Name : ";
				cin >> new_cname;
				file1 << " " << acc_no << " "
					<< new_cname << " "
					<< type_acc << " " << balance<< " " << address
					<< "\n\n";
				count++;
			}
			else
				file1 << " " << raccno
					<< " " << name
					<< " " << type_acc
					<< " " << balance
					<< " " << address
					<< "\n\n";
			file >> raccno >> name;
			file >> type_acc >> balance>> address;
		}
		if (count == 0)
			cout << "\n\nInvalid Account number "<<endl;
				
	}
	cout << endl;
   

	// Close the files
	file.close();
	file1.close();
	remove("bank1.txt");
	rename("bank2.txt",
		"bank1.txt");
}

void bank::updateaddress() //function for updating address
{
   
	fstream file, file1;
	int balance, new_bal, count = 0;
	string name, type_acc, address, new_address;
	int  raccno, acc_no;

	cout << "\n\n\t\t\t\tUpdate Bank Record";
	file1.open("bank2.txt",
			ios::app | ios::out);
	file.open("bank1.txt", ios::in);

	if (!file)
		cout << "\n\nFile Opening Error!";
	else {

		cout << "\n\nBANK ACC NO : ";
		cin >> acc_no;
		file >> raccno >> name;
		file >> type_acc >> balance>> address;

		// Till end of file is reached
		while (!file.eof()) {
			if (acc_no == raccno) {
			
				cout << "\t\t\t\t"
					<< "Update Book Record";
				cout << "\n\nNew Address : ";
				cin >> new_address;
				file1 << " " << acc_no << " "
					<< name << " "
					<< type_acc << " " << balance << " " << new_address
					<< "\n\n";
				count++;
			}
			else
				file1 << " " << raccno
					<< " " << name
					<< " " << type_acc
					<< " " << balance
					<< " " << address
					<< "\n\n";
			file >> raccno >> name;
			file >> type_acc >> balance>> address;
		}
		if (count == 0)
			cout << "\n\nInvalid " <<endl;
			
	}
	cout << endl;
    

	// Close the files
	file.close();
	file1.close();
	remove("bank1.txt");
	rename("bank2.txt",
		"bank1.txt");
}

// Function for deleting
void bank::deleteaccount()
{

	fstream file, file1;
	int balance, count = 0;
	string acc_no, raccno, name, type_acc, address;
	cout << "\n\n\t\t\t\tDelete BANK ACCOUNT";

	// Append file in output mode
	file1.open("bank2.txt",
			ios::app | ios::out);
	file.open("bank1.txt",
			ios::in);

	if (!file)
		cout << "\n\nFile Opening Error...";
	else {

		cout << "\n\nACC_NO : ";
		cin >> acc_no;
		file >> raccno >> name;
		file >> type_acc >> balance>> address;
		while (!file.eof()) {

			if (acc_no == raccno) {

				cout << "\n\nBank account Deleted "
						"Successfully...\n\n";
				count++;
			}
			else
				file1 << " " << raccno
					<< " " << name
					<< " " << type_acc
					<< " " << balance
					<< " " << address
					<< "\n\n";
			file >> raccno >> name;
			file >> type_acc >> balance>> address;
		}
		if (count == 0)
			cout << "\n\nInvalid  "<<endl;
				
	}
   
	// Close the file
	file.close();
	file1.close();
	remove("bank1.txt");
	rename("bank2.txt",
		"bank1.txt");
}
void bank::displaybalance(){
   
	fstream file;
    string name;
    int acc_no;
    string type_acc;
    float balance;
	string address;
	int count = 0;
	int raccno;

	cout << "\n\n\t\t\t\tCheck "
		<< "Particular ACCOUNT";

	// Open the file in input mode
	file.open("bank1.txt", ios::in);
	if (!file)
		cout << "\n\nFile Opening Error!";
	else {

		cout << "\n\nEnter Acc No : ";
		cin >> raccno;
		file >> acc_no >> name;
		file >> type_acc >> balance>> address;

		while (!file.eof()) {

			if (raccno == acc_no) {
                system("cls");
				cout << "\nBALANCE : "
					<< balance;
				cout << endl
					<< endl;
				count++;
				break;
			}
			file >> acc_no >> name;
			file >> type_acc >> balance>> address;
		}
       
		file.close();
		if (count == 0)
			cout << "\n\nInvalid " <<endl;
				
	}
}
void bank ::display_acctype()
{
  
	fstream file;
    string name;
    int acc_no;
    string type_acc;
    float balance;
	string address;
	int count = 0;
	int raccno;

	cout << "\n\n\t\t\t\tCheck "
		<< "Particular ACCOUNT";

	// Open the file in input mode
	file.open("bank1.txt", ios::in);
	if (!file)
		cout << "\n\nFile Opening Error!";
	else {

		cout << "\n\nREQ ACC NO : ";
		cin >> raccno;
		file >> acc_no >> name;
		file >> type_acc >> balance>> address;

		while (!file.eof()) {

			if (raccno == acc_no) {
                
				cout << "\n\n\t\t\t\t"
					<< "Check Particular ACCOUNT";
				
				cout << "\nCUSTOMER Name : "
					<< name;
				cout << "\nACCOUNT TYPE : "
					<< type_acc;
				
				cout << endl ;
					
				count++;
				break;
			}
			file >> acc_no >> name;
			file >> type_acc >> balance>> address;
		}
       
		file.close();
		if (count == 0)
			cout << "\n\nInvalid "<<endl;
				
	}
}
void bank ::display_details()
{
    
	fstream file;
    string name;
    int acc_no;
    string type_acc;
    float balance;
	string address;
	int count = 0;
	int raccno;

	cout << "\n\n\t\t\t\tCheck "
		<< "Particular ACCOUNT";

	// Open the file in input mode
	file.open("bank1.txt", ios::in);
	if (!file)
		cout << "\n\nFile Opening Error!";
	else {

		cout << "\n\nEnter account no : ";
		cin >> raccno;
		file >> acc_no >> name;
		file >> type_acc >> balance>> address;

		while (!file.eof()) {

			if (raccno == acc_no) {
                system("cls");
				cout << "\n\n\t\t\t\t"
					<< "Check Particular ACCOUNT";
				cout << "\n\nACC NO : "
					<< acc_no;
				cout << "\nCUSTOMER Name : "
					<< name;
				cout << "\nACCOUNT TYPE : "
					<< type_acc;
				cout << "\nBALANCE : "
					<< balance;
				cout << "\nADDRESS : "
					<< address;
				cout << endl ;
				
				count++;
				break;
			}
			file >> acc_no >> name;
			file >> type_acc >> balance>> address;
		}
      
		file.close();
		if (count == 0)
			cout << "\n\nINVALID"<<endl;
			
	}
}

void bank::deposit()
{

	fstream file, file1;
	int balance, new_bal, count , amnt = 0;
	string name, new_cname, type_acc, address;
	int  raccno, acc_no;

	cout << "\n\n\t\t\t\tUpdate Bank Record";
	file1.open("bank2.txt",
			ios::app | ios::out);
	file.open("bank1.txt", ios::in);

	if (!file)
		cout << "\n\nFile Opening Error!";
	else {

		cout << "\n\nBANK ACC NO : ";
		cin >> acc_no;
		file >> raccno >> name;
		file >> type_acc >> balance>> address;

		// Till end of file is reached
		while (!file.eof()) {
			if (acc_no == raccno) {
			
				cout<<"Enter amount u want to deposit: "<<endl;
				cin>>amnt;
				new_bal=balance+amnt;
				    
			
				file1 << " " << acc_no << " "
					<< name << " "
					<< type_acc << " " << new_bal<< " " << address
					<< "\n\n";
				count++;
			}
			else
				file1 << " " << raccno
					<< " " << name
					<< " " << type_acc
					<< " " << balance
					<< " " << address
					<< "\n\n";
			file >> raccno >> name;
			file >> type_acc >> balance>> address;
		}
		if (count == 0)
			cout << "\n\nInvalid Account number "<<endl;
				
	}
	cout << endl;
   

	// Close the files
	file.close();
	file1.close();
	remove("bank1.txt");
	rename("bank2.txt",
		"bank1.txt");
}

void bank::withdraw()
{

	fstream file, file1;
	int balance, new_bal, count , amnt = 0;
	string c_name, new_cname, type_acc, c_address;
	int  raccno, acc_no;

	cout << "\n\n\t\t\t\tUpdate Bank Record";
	file1.open("bank2.txt",
			ios::app | ios::out);
	file.open("bank1.txt", ios::in);

	if (!file)
		cout << "\n\nFile Opening Error!";
	else {

		cout << "\n\nBANK ACC NO : ";
		cin >> acc_no;
		file >> raccno >> name;
		file >> type_acc >> balance>> address;

		// Till end of file is reached
		while (!file.eof()) {
			if (acc_no == raccno) {
			
				cout<<"Enter amount u want to withdraw : "<<endl;
				cin>>amnt;
				if(balance>=amnt)
				{
			            	new_bal=balance-amnt;
				}
				else 
				{
				    cout<<"sorry u cant't !!"<<endl;
				    return;
				}
				file1 << " " << acc_no << " "
					<< name << " "
					<< type_acc << " " << new_bal<< " " << address
					<< "\n\n";
				count++;
			}
			else
				file1 << " " << raccno
					<< " " << name
					<< " " << type_acc
					<< " " << balance
					<< " " << address
					<< "\n\n";
			file >> raccno >> name;
			file >> type_acc >> balance>> address;
		}
		if (count == 0)
			cout << "\n\nInvalid Account number "<<endl;
				
	}
	cout << endl;
   

	// Close the files
	file.close();
	file1.close();
	remove("bank1.txt");
	rename("bank2.txt",
		"bank1.txt");
}
// Driver Code
int main()
{
    bank *bobj=new bank();
	int choice;
	char s;
    do 
    {
        cout<<"WELCOME !! "<<endl;
        cout<<"Enter 1 to add account "<<endl;
        cout<<"Enter 2 to display all account details"<<endl;
        cout<<"Enter 3 to check particular account exists or not "<<endl;
        cout<<"Enter 4 to update name " <<endl;
        cout<<"Enter 5 to update address "<<endl;
        cout<<"Enter 6 to delete account "<<endl;
        cout<<"Enter 7 to display balance "<<endl;
        cout<<"Enter 8 to display account type "<<endl;
        cout<<"Enter 9 to display particular account details  "<<endl;
        cout<<"Enter 10 to deposit money "<<endl;
        cout<<"Enter 11 to withdraw money "<<endl;
        cout<<"Enter 12 to exit "<<endl;
        cin>>choice;
        
        switch(choice)
        {
            
            case 1:
              
               do{
                    bobj->createaccount();
                   	cout << "\n\nWant to add another account (y\n) : " <<endl ;
    				cin >> s;
 		     	} while (s == 'y');

                break;
            case 2:
               bobj->displayall();
                break;
            case 3:
               bobj->checkaccount();
                break;
            case 4:
               bobj->updatename();
                break;
            case 5:
               bobj->updateaddress();
                break;
            case 6:
               bobj->deleteaccount();
                 break;
            case 7:
               bobj->displaybalance();
                 break;
            case 8:
               bobj->display_acctype();
                 break;
            case 9:
               bobj->display_details();
                 break;
            case 10:
                bobj->deposit();
                 break;
            case 11:
                 bobj->withdraw();
                 break;
            case 12:
                 exit(0);
                 break;
            default:
                cout<<"Invalid choice "<<endl;
        }
    }while(choice!=0);
     


	return 0;
}
