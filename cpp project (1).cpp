#include <iostream.h>
#include <conio.h>
#include <process.h>
#include <stdio.h>
#include <fstream.h>
#include <ctype.h>

class user
{
	public:
   	char username[80];
   	char password[80];
}l;

int search();
void payment();
int signin()
{
	
	int ch;
	char usr[80], pwd[80];
	ifstream f("logindetails.dat",ios::in | ios::binary);
	cout<<"Enter Username: ";
	cin>>usr;
	cout<<"Enter Password: ";
	cin>>pwd;
   	while(f.read((char *)&l, sizeof(user))){
  		if ((strcmp(l.username, usr) == 0) && (strcmp(l.password, pwd) == 0))
		  	{
		  	cout<<"Logged in\n";	
  			do {
  				cout<<"\n";
			  cout<<"Enter\n 1 to Search\n 2 To proceed for payment\n";
			  cout<<" 3 To Exit\n";
			  cin>>ch;
  			switch(ch){
  			case 1: if(search() == -1)cout<<"Product not found\n";
					break;
			case 2: payment();
			case 3: break;
			default: cout<<" Wrong choice"<<endl;break;
  			}
		  	}while(ch != 3 );
		  	
      		return 0;
      		break;
		}
 	}
   	return 1;
   	f.close();	
}

	//ofstream fout("file.dat",ios::app | ios::out);
	void signup()
{
	char usr[80], pwd[80];
	fstream fio("logindetails.dat",ios::app | ios::binary|ios::out);
	cout<<"Enter Username: ";
	cin>>l.username;
	cout<<"Enter Password: ";
	cin>>l.password;
	fio.write((char *)&l,sizeof(user));
	fio.close();
}



class mobile
{
int model_no;
char brand[50];
char os[50];
int ram;
int megapixel;
int storage;
float screen_size;
int battery;
char core_processor[80];
char price[80];
public:
void getinfo()
{
cout<<" Enter info "<<endl;
cout<<endl;
cout<<" Enter the Model_no : "<<endl;
cin>>model_no;
cout<<" Enter the Brand : "<<endl;
cin>>brand;
cout<<" Enter the Operating System : "<<endl;
cin>>os;
cout<<" Enter the Ram ( GB ) : "<<endl;
cin>>ram;
cout<<" Enter the Megapixel : "<<endl;
cin>>megapixel;
cout<<" Enter the Storage (GB) : "<<endl;
cin>>storage;
cout<<" Enter the Screen size ( INCH ) :"<<endl;
cin>>screen_size;
cout<<" Enter the Battery (mAH) :"<<endl;
cin>>battery;
cout<<" Enter the Core processor (Ghz)  :"<<endl;
cin>>core_processor;
cout<<" Enter the Price (in AED) :"<<endl;
cin>>price;
}

void putinfo()
{
cout<<" The Model_no is : "<<model_no<<endl;
cout<<" The Brand is : ";
puts(brand);
cout<<" The Operating System is : ";
puts(os);
cout<<" The Ram is (GB) : "<<ram<<endl;
cout<<" The Megapixel is : "<<megapixel<<endl;
cout<<" The Storage is (GB) : "<<storage<<endl;
cout<<" the Screen size is (INCH) : "<<screen_size<<endl;
cout<<" the Battery is (mAH) : "<<battery<<endl;
cout<<" the Core processor is (Ghz) : ";
puts(core_processor);
cout<<" the Price is (AED) : ";
puts(price);
}

int getmodel_no()
{
return model_no;
}

char* getspec()
{return brand;}

char* getprice()
{
	return price;
}



}m,cart;

char model[100];


int search()

	{

	int ch,found;
	char brand[80];
	ifstream f("file.dat", ios::in | ios::binary);
	if (!f)
		cout<<"File doesn't exist. Add mobiles to the database. \n";
	else{
	cout<<" Enter the brand to be searched for: \n";
	cin>>brand;
	while(f.read((char *)&m ,sizeof(mobile)))
		{
		if (strcmp(m.getspec(), brand) == 0)
		{
			cout<<"Product found\n";
			cout<<endl;
			m.putinfo();
			found=1;
			cout<<"\n";
			cout<<"Press \n 1. To add to cart \n 2. To search again \n"; 
			cin>>ch;
			switch(ch)
				{
				case 1: cart = m;
						strcpy(model, m.getspec()); 
			}
			return 0;
			
		}
	}
	}
	return -1;

}

int adminsearch()

	{

	int ch,found;
	char brand[80];
	ifstream f("file.dat", ios::in | ios::binary);
	if (!f)
		cout<<"File doesn't exist. Add mobiles to the database. \n";
	else{
	cout<<" Enter the brand to be searched for: \n";
	cin>>brand;
	while(f.read((char *)&m ,sizeof(mobile)))
		{
		if (strcmp(m.getspec(), brand) == 0)
		{
			cout<<"Product found\n";
			cout<<endl;
			m.putinfo();
			found=1;
		

		}
	}
	}	
	}

void payment()
	{
	char price[89];
	int ch1,ccn,pc;
	cout<<"Your cart contains: \n";
	cout<<endl;
	fstream fio("file.dat", ios::in | ios::binary);
	cart.putinfo();	
	/*while(fio.read((char *)&m ,sizeof(mobile)))
	{
		strcpy(m.getprice(),price);
		cout<<endl;
		cout<<" The price for your product is "<<endl;
		cout<<price;
		cout<<endl;*/
		cout<<" How would you like to pay "<<endl;
		cout<<" \n1.Credit Card" "\n2.COD" <<endl;
		cin>>ch1;
		if(ch1==1)
		{
			cout<<" Enter the Credit Card number "<<endl;
			cin>>ccn;
			cout<<" Enter the Pin Code "<<endl;
			cin>>pc;
			cout<<" THANK YOU FOR PURCHASING"<<endl;
			
		}
		else
		{
			cout<<" THANK YOU FOR PURCHASING"<<endl;
		}
	
	//}
	
}

void add()
{
	ofstream fout("file.dat",ios::app | ios::out);
	m.getinfo();
	fout.write((char*)&m,sizeof(mobile));

}
void del()
{
	ifstream fio("file.dat",ios::in|ios::binary);
	ofstream fillin("temp.dat",ios::out);
	int model_no;
	char found='f';
	char confirm='n';
	cout<<"Enter the model which is to be deleted"<<endl;
	cin>>model_no;
	while(!fio.eof())
	{ fio.read((char*)&m,sizeof(m));
	if(m.getmodel_no()==model_no)
	{
		m.putinfo();
		found='t';
		cout<<"Are you sure to delete the record"<<endl;
		cin>>confirm;
		if(confirm=='n')
			fillin.write((char*)&m,sizeof(m));
	}
	else
		fillin.write((char*)&m,sizeof(m));
	}
	if(found=='f')
	cout<<"record not found"<<endl;
	fio.close();
	fillin.close();
	remove("file.dat");
	rename("temp.dat","file.dat");
	fio.open("file.dat",ios::in);
	fio.close();
}
void modify()
	
	{
	char brand[60]; long pos; char found='f';
	fstream fio("file.dat",ios::in|ios::out|ios::binary);
	cout<<" Enter the brand which has to be modified"<<endl;
	cin>>brand;
	while(fio.read((char*)&m,sizeof(mobile)))
	{
	pos = fio.tellg();
	if(strcmp(m.getspec(),brand) == 0);
	{
		m.getinfo();
		fio.seekg(pos);
		fio.write((char*)&m,sizeof(mobile));
		found ='t';
		break;
	}
	}
	if(found=='f')
	cout<<" Record not found "<<endl;
	fio.seekg(0);
	cout<<" Now the file contains: "<<endl;
	while(fio.read((char*)&m,sizeof(mobile)))
	{
	
	m.putinfo();
	}
	fio.close();
	
}


void show()
{
    ifstream fin("file.dat", ios::binary);
    while(fin.read((char *)&m, sizeof(m)))
    {
   	m.putinfo();
    	cout<<"\n\n";
     }
   getch();
}

void admin()
{
char adminpw[80];
int ch;

cout<<" Enter adminpassword: ";
cin>>adminpw;
if(strcmp(adminpw,"shreyas123")==0){
cout<<"\n  Access granted "<<endl;
cout<<"\n";
do{
cout<<" What you would like to do "<<endl;
cout<<"\n";

cout<<" 1. Modify "<<endl;
cout<<" 2. Add "<<endl;
cout<<" 3. Delete "<<endl;
cout<<" 4. Search "<<endl;
cout<<" 5. Show All "<<endl;
cout<<" 6. Exit "<<endl;
cin>>ch;
switch(ch)
{
case 1 : modify(); break;
case 2 : add();    break;
case 3 : del(); break;
case 4 : if(adminsearch() == -1) cout<<"Product not found\n";	break;
case 5 : show(); break;
case 6 : exit(0); break;
}
}
while(ch != 6);
}
else
cout<<" Access denied "<<endl;
cout<<"\n";
}



int main()
{
	int ch;
	cout<<"   ************* MOBILE RETAIL SYSTEM *************** "<<endl;
	cout<<"\n";
	do{
	cout<<" ADMIN "<<endl;
	cout<<" Enter 1 for admin access "<<endl;
	cout<<"\n";
	cout<<" USER MENU "<<endl;
    cout<<" Enter 2 for signing in your account "<<endl;
	cout<<"\n";
	cout<<" Enter 3 for signing up for an account "<<endl;
	cout<<"\n";
	cout<<" enter 4 for exit\n\n";
   	cout<<" Enter the choice: "<<endl;
   	cin>>ch;

   switch(ch)
   	{
	case 1: admin(); break;
	case 2: if ( !signin() == 0 ) cout<<"Wrong details\n"; break;
 	case 3: signup();  break;
  	case 4: exit(0);  break;
  	default: cout<<"Wrong choice"<<endl;
	}
   }while( ch != 4 );
  ifstream i("file.dat",ios::binary);
  i.read((char *)&i, sizeof(mobile));
  m.putinfo();
   getch();
   return 0;
}