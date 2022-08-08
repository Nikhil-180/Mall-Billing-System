#include<iostream>
#include<fstream>
using namespace std;

class shopping
{
    private:
        int pcode;
        float price;
        float discount;
        string pname;

        public:
            void menu();
            void administrator();
            void buyer();
            void add();
            void edit();
            void rem();
            void list();
            void receipt();

};

void shopping:: menu()
{
    m:
    int choice;
    string email;
    string password;
    cout<<"\n";
    cout<<"\t\t\t\t|______________________________|\n";
    cout<<"\t\t\t\t                                \n";
    cout<<"\t\t\t\t      Supermarket Main Menu     \n";
    cout<<"\t\t\t\t                                \n";
    cout<<"\t\t\t\t|______________________________|\n";
    cout<<"\t\t\t\t                                \n";
    cout<<"\t\t\t\t         1) Administrator   \n";
    cout<<"\t\t\t\t                            \n";
    cout<<"\t\t\t\t         2) Buyer           \n";
    cout<<"\t\t\t\t                            \n";
    cout<<"\t\t\t\t         3) Exit            \n\n";
    cout<<"\t\t\t\t       Please Select! ";
    cin>>choice;
     switch(choice)
     {
        case 1:
            cout<<"Enter Email: ";
            cin>>email;
            cout<<"Password: ";
            cin>>password;

            if(email=="nikhil@gmail.com" && password=="nikhil@123")
            {
                administrator();
            }
            else
            {
                cout<<"Invalid email/password";
            }
            break;

        case 2:
            buyer();
        case 3:
            exit(0);
        default:
            cout<<"please select from given options";

     }
     goto m;

}

void shopping:: administrator()
{
    m:
    int choice;
    cout<<"\n\n\n\t\t\t|______________Administrator Menu___________|";
    cout<<"\n\t\t\t               1)Add the product          ";
    cout<<"\n\t\t\t                                          ";
    cout<<"\n\t\t\t               2)Modify the product       ";
    cout<<"\n\t\t\t                                          ";
    cout<<"\n\t\t\t               3)Delete the product       ";
    cout<<"\n\t\t\t                                          ";
    cout<<"\n\t\t\t               4)Back to Main Menu        ";

    cout<<"\nPlease Enter your choice: ";
    cin>>choice;

    switch(choice)
    {
        case 1:
            add();
            break;
        
        case 2:
            edit();
            break;
        
        case 3:
            rem();
            break;

        case 4:
            menu();
            break;

        default:
            cout<<"Invalid choice!";
    }
    goto m;
}

void shopping:: buyer()
{
    m:
    int choice;
    cout<<"\n\t\t\t__________________Buyer____________________\n";
    cout<<"\t\t\t_____________________________________________";
    cout<<"                                                   ";
    cout<<"\n\t\t\t            1) Buy product  \n";
    cout<<"                                    ";
    cout<<"2) Go Back      \n";

    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            receipt();
            break;
        
        case 2:
            menu();

        default:
            cout<<"Invalid choice!";

    }
goto m;
}

void shopping:: add()
{
    m:
    fstream data;
    int c,token=0;
    float p,d;
    string n;

    cout<<"\n\n\t\t\t Add new product";
    cout<<"\n\n\t Product code of the product ";
    cin>>pcode;
    cout<<"\n\n Name of the product ";
    cin>>pname;
    cout<<"\n\n\t Price of the product";
    cin>>price;
    cout<<"\n\n\t Discount on  product";
    cin>>discount;

    data.open("database.txt",ios::in);

    if(!data)
    {
        data.open("database.txt",ios::app|ios::out);
        data<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<discount<<"\n";
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;

        while(!data.eof())
        {
            if(c==pcode)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();

        if(token==1)
        {
            goto m;
        }
        else
        {
            data.open("database.txt",ios::app|ios::out);
            data<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<discount<<"\n";
            data.close();
        }
    }
    cout<<"\n\n\t\t Record Inserted! ";
}

void shopping:: edit()
{
    fstream data,data1;
    int pkey,token=0,c;
    float p,d;
    string n;

    cout<<"\n\t\t\t Modify the record";
    cout<<"\n\t\t\t Product code :";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\nFile doesn't exist!";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);

        data>>pcode>>pname>>price>>discount;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t Product new code :";
                cin>>c;
                cout<<"\n\t\t Name of the product :";
                cin>>n;
                cout<<"\n\t\t Price :";
                cin>>p;
                cout<<"\n\t\t Discount :";
                cin>>d;
                data1<<"  "<<c<<"  "<<n<<"  "<<p<<"  "<<d<<"\n";

                cout<<"\n\n\t\t Record edited ";
                token++;
            }
            else
            {
                data1<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<discount<<"\n";

            }
            data>>pcode>>pname>>price>>discount;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\n Record not found!";
        }
    }
}

void shopping:: rem()
{
    fstream data,data1;
    int pkey,token=0;
    cout<<"\n\n\t Delete product";
    cout<<"\n\n\t Product code :";
    cin>>pkey;
    data.open("database.txt",ios::in);
    
    if(!data)
    {
        cout<<"File doesn't exist";

    }
    else
    {
        data1.open("database1,txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>discount;

        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"Product deleted successfully";
                token++;
            }
            else
            {
                data1<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<discount<<"\n";

            }
            data>>pcode>>pname>>price>>discount;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\n Record not found";
        }
    }
}

void shopping:: list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n_____________________________________________________\n";
    cout<<"ProNo\t\tName\t\tPrice\n";
    cout<<"\n\n_____________________________________________________\n";
    data>>pcode>>pname>>price>>discount;
    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>discount;

    }
    data.close();
}

void shopping:: receipt()
{
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float discount=0,amount=0,total=0;

    cout<<"\n\n\t\t\t RECEIPT ";
    data.open("database.txt",ios::in);

    if(!data)
    {
        cout<<"\n\n Empty database";
    }
    else
    {
        data.close();

        list();
        cout<<"\n\n________________________________________\n";
        //cout<<"\n                                        \n";
        cout<<"\n          Please place the order        \n";
        //cout<<"\n                                        \n";
        cout<<"\n________________________________________\n";
        do
        {
            cout<<"\n\nEnter product code :";
            cin>>arrc[c];
            cout<<"\n\nEnter the product quantity :";
            cin>>arrq[c];

            /*for(int i=0;i<c;i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\n Duplicate product code. Please try again!";
                    goto m;
                }
            }*/
            c++;
            cout<<"\n\n Do you want to buy another? if yes, then press y else n for no: ";
            cin>>choice;
        }
        while(choice=='y');

        cout<<"\n\n\t\t\t_________________________RECEIPT______________________\n";
        cout<<"\nProduct No\t Product Name\t Product Quantity\tPrice\tAmount\tAmount with discount\n";
        int j=0;
        while(j<c)
        {
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>discount;
            while(!data.eof())
            {
                if(pcode==arrc[j])
                {
                    amount=price*arrq[j];
                    discount=amount-(amount*discount/100);
                    total+=discount;
                    cout<<"\n"<<pcode<<"\t\t "<<pname<<"\t\t"<<arrq[j]<<"\t\t\t"<<price<<"\t"<<amount<<"\t\t"<<discount;

                }

                data>>pcode>>pname>>price>>discount;
            }
            j++;
        }
        data.close();
    }

    cout<<"\n\n_______________________________________________";
    cout<<"\n Total Amount :"<<total<<"\n";

}

int main()
{
    shopping s;
    s.menu();
}