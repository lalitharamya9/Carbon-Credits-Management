/*````````````````````````````````````````````````````````````````````````````````````                                                                        /***************************************************************************************
Project: Carbon Credit Management System
Project Developed By: MS Lalitha Ramya, Akshayaa BR, Rajeev AV and Adithya NA
                      Class XII, CMR National Public School (2013-14 batch)
****************************************************************************************/

/***************************************************************************************
Module: Data Acquisition, Carbon Cedit Computation and Display of Credits for Companies 
Module Description:
       



****************************************************************************************/

// include header files
#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

//constant variable initialization
float rr=0.125;
float max_tons=10.0;
float m_tons=1.0;

//Function declaration
float calculatearea(float greenarea,float totalarea);    
float usage(float usage_plastic,float usage_food, float usage_paper);
float usage(float usage_plastic,float usage_food,float usage_paper,float usage_chemicals);

class HeavyMachinery
{
      public:
             float nofm;
             float pwcon;
             float mconspw;
             float noem;
             float pwcone;
             float credits;
             float extra;
             
             float calcmaxpw()
             {
                  if(nofm<=20)
                  {
                              mconspw=nofm*100;
                  }
                  else if(nofm<=100)
                  {
                              mconspw=nofm*800;
                  }
                  else if(nofm<=200)
                  {
                              mconspw=nofm*1600;
                  }
                  else 
                  {
                              mconspw=nofm*2000;
                  }
                  if(pwcon>mconspw)
                  {               
                                  extra=pwcon-mconspw;
                                  credits=(-1)*extra*2;
                  }
                  else
                  {
                      extra=mconspw-pwcon;
                      credits=extra*2;
                  }
                  cout<<"\n\nMax Consumable Power: "<<mconspw<<" kWh";
                  return credits;
                  
             }
             void accept()
             {
                  cout<<"\nENTER THE NUMBER OF MACHINES (including ecofriendly devices): ";
                  cin>>nofm;
                  cout<<"\nENTER THE POWER CONSUMPTION (includes ecofriendly device consumption)(kWh): ";
                  cin>>pwcon;
                  cout<<"\nENTER THE NUMBER OF ECOFRIENDLY DEVICES: ";
                  cin>>noem;
                  cout<<"\nENTER THE POWER CONSUMED BY ECOFRIENDLY DEVICES(kWh): ";
                  cin>>pwcone;
                  pwcon=pwcon-pwcone;
                  
             }
};
            
class LightMachinery
{
      public:
             float nofm;
             float pwcon;
             float mconspw;
             float noem;
             float pwcone;
             float credits;
             float extra;
             float calcmaxpw()
             {
                  if(nofm<=20)
                  {
                              mconspw=nofm*20;
                  }
                  else if(nofm<=100)
                  {
                              mconspw=nofm*80;
                  }
                  else if(nofm<=200)
                  {
                              mconspw=nofm*160;
                  }
                  else 
                  {
                              mconspw=nofm*200;
                  }
                  if(pwcon>mconspw)
                  {               
                                  extra=pwcon-mconspw;
                                  credits=(-1)*extra*2;
                  }
                  else
                  {
                      extra=mconspw-pwcon;
                      credits=extra*2;
                  }
                  cout<<"\n\nMax Consumable Power: "<<mconspw<<" kWh"; 
                  return credits;
                  
             }
             void accept()
             {
                  cout<<"\nENTER THE NUMBER LIGHT DUTY MACHINES (including ecofriendly devices): ";
                  cin>>nofm;
                  cout<<"\nENTER THE POWER CONSUMPTION OF THIS MONTH(FOR LIGHT DUTY MACHINES)\n"<<"(includes ecofriendly device consumption)(kWh): ";
                  cin>>pwcon;
                  cout<<"\nENTER THE NUMBER OF ECOFRIENDLY LIGHT DUTY DEVICES: ";
                  cin>>noem;
                  cout<<"\nENTER THE POWER CONSUMED BY  THESE ECOFRIENDLY DEVICES(kWh): ";
                  cin>>pwcone;
                  pwcon=pwcon-pwcone;
                  
             }
};             
             
class company:public LightMachinery
{
      public://General Attributes
      char company_name[30];
      char address[100]; // Different credits for URBAN, RURAL and FOREST areas
      float tcredits,total_area, green_area;  // in square feet
      int no_of_employees;
      float credits;
      int pin;
      //Negative contribution Attributes
       // utility consumption in units
      float usage_plastic, usage_food, usage_paper, usage_chemicals; // usage quantity in Tons
      
      
      void get_com_data()
      {
           cout<<"Enter an Unique Code for this Record: ";
           cin>>pin;
           cout<<"\nEnter the company name: ";
           cin>>company_name;
           cout<<"\nEnter the address: ";
           cin>>address;
           cout<<"\nEnter total area: ";
           cin>>total_area;
           cout<<"\nEnter green area: ";
           cin>>green_area;
           cout<<"\n\n(Enter the following quantities in tons)\n\n";
           cout<<"\nEnter the amount of plastic usage: ";
           cin>>usage_plastic;
           cout<<"\nEnter the amount of foods usage: ";  
           cin>>usage_food;
           cout<<"\nEnter the amount of paper usage: ";
           cin>>usage_paper;
           cout<<"\nEnter the amount of chemical usage: ";
           cin>>usage_chemicals;
           cout<<"\nEnter existing carbon credits: ";
           cin>>tcredits;
           LightMachinery::accept();
           credits=LightMachinery::calcmaxpw();
           credits= credits+calculatearea(green_area,total_area);
           credits= credits+usage(usage_plastic,usage_food,usage_paper,usage_chemicals);
           tcredits=tcredits+credits;
           
}
      void put_com_data()
      {
           cout<<"\nPin: ";
           cout<<pin; 
           cout<<"\nCompany name: ";
           cout<<company_name;
           cout<<"\nAddress: ";
           cout<<address;
           cout<<"\nTotal Area: ";
           cout<<total_area;
           cout<<"\nGreen Area: ";
           cout<<green_area;
           cout<<"\nPlastic Usage: ";
           cout<<usage_plastic<<" tons";
           cout<<"\nFoods Usage: ";  
           cout<<usage_food<<" tons";
           cout<<"\nPaper Usage: ";
           cout<<usage_paper<<" tons";
           cout<<"\nChemical Usage: ";
           cout<<usage_chemicals<<" tons";
           cout<<"\nExisting Carbon Credits: ";
           cout<<tcredits;
           
           
      }
      
      int getpin()
                { return pin;}
      
};




class household:public LightMachinery
{
      public:
        
    int nf_ppl;
    int pin;
    char address[100];  //includes petrol,diesel,lpg,etc..
    float credits,tcredits;
    float usage_plastic, usage_food, usage_paper;
    float green_area,total_area;
    
    
        
               void details()
               {
               cout<<"ENTER PIN CODE: ";
               cin>>pin;
               cout<<"\nEnter address: ";
               cin>>address;
               cout<<"\nEnter the no. of ppl in the house: ";
               cin>>nf_ppl;
               cout<<"\nEnter total living space(total area): ";
               cin>>total_area;
               cout<<"\nEnter the area of green space in and around the house: ";
               cin>>green_area;
               cout<<"\n\n(Enter the following quantities in tons)\n\n";
               cout<<"\nEnter the amount of plastic usage: ";
               cin>>usage_plastic;
               cout<<"\nEnter the amount of foods usage: ";  
               cin>>usage_food;
               cout<<"\nEnter the amount of paper usage: ";
               cin>>usage_paper;
               cout<<"\nEnter existing carbon credits: ";
               cin>>tcredits;
               LightMachinery::accept();
               credits=LightMachinery::calcmaxpw();
               credits= credits+calculatearea(green_area,total_area);
               credits= credits+usage(usage_plastic,usage_food,usage_paper);
               tcredits=tcredits+credits;
               }
               
               void display()
               {
                    cout<<"\nPin: ";
                    cout<<pin; 
                    cout<<"\nAddress: ";
                    cout<<address;
                    cout<<"\nTotal Area: ";
                    cout<<total_area;
                    cout<<"\nGreen Area: ";
                    cout<<green_area;
                    cout<<"\nPlastic Usage: ";
                    cout<<usage_plastic<<" tons";
                    cout<<"\nFoods Usage: ";  
                    cout<<usage_food<<" tons";
                    cout<<"\nPaper Usage: ";
                    cout<<usage_paper<<" tons";
                    cout<<"\nExisting Carbon Credits: ";
                    cout<<tcredits;
                    
                }
                
                int getpin()
                { return pin;}
}H;


 class universities: public LightMachinery
{ 
       public:     
     char name_uni[20], address_uni[100];
     int working_hrs;
     int pin;
     int  no_of_classes  ;
     float green_area,total_area; 
     float credits,tcredits;
     float usage_plastic, usage_food, usage_paper, usage_chemicals;


   void  getdata()
{                 
                  cout<<"ENTER PIN CODE: ";
                  cin>>pin;
                  cout<<"\nEnter the name of the university: ";
                  cin>>name_uni;
                  cout<<"\nAddress of the university: ";
                  cin>>address_uni;
                  cout<<"\nEnter daily working hours: ";
                  cin>>working_hrs;
                  cout<<"\nEnter number of classes: ";
                  cin>>no_of_classes;
                  cout<<"\nEnter total area: ";
                  cin>>total_area;
                  cout<<"\nEnter green area: ";
                  cin>>green_area;
                  cout<<"\n\n(Enter the following quantities in tons)\n\n";
                  cout<<"\nEnter the amount of plastic usage: ";
                  cin>>usage_plastic;
                  cout<<"\nEnter the amount of foods usage: ";
                  cin>>usage_food;
                  cout<<"\nEnter the amount of paper usage: ";
                  cin>>usage_paper;
                  cout<<"\nEnter the amount of chemical usage: ";
                  cin>>usage_chemicals;
                  cout<<"\nEnter existing carbon credits: ";
                  cin>>tcredits;
                  LightMachinery::accept();
                  credits=LightMachinery::calcmaxpw();
                  credits= credits+calculatearea(green_area,total_area);
                  credits= credits+usage(usage_plastic,usage_food,usage_paper,usage_chemicals);
                  tcredits=tcredits+credits;
}

void  showdata()
{
                cout<<"\nPin: ";
                cout<<pin;
                cout<<"\nUniversity name: ";
                cout<<name_uni;
                cout<<"\nAddress: ";
                cout<<address_uni;
                cout<<"\nDaily working hours: ";
                cout<<working_hrs;
                cout<<"\nNumber of classes: ";
                cout<<no_of_classes;
                cout<<"\nTotal Area: ";
                cout<<total_area;
                cout<<"\nGreen Area: ";
                cout<<green_area;
                cout<<"\nPlastic Usage: ";
                cout<<usage_plastic<<" tons";
                cout<<"\nFoods Usage: ";  
                cout<<usage_food<<" tons";
                cout<<"\nPaper Usage: ";
                cout<<usage_paper<<" tons";
                cout<<"\nChemical Usage: ";
                cout<<usage_chemicals<<" tons";
                cout<<"\nExisting Carbon Credits: ";
                cout<<tcredits;
 
                }
                
                int getpin()
                { return pin;}

}U;

class Factory: public HeavyMachinery,public LightMachinery
{
      public:
      char name[30];
      int pin;
      char addrs[100];
      float credits;
      float tcredits,tarea,garea;
      float usage_plastic, usage_food, usage_paper, usage_chemicals;
      float noemp;
      
             void input()
             {    
                  cout<<"ENTER PIN CODE: ";
                  cin>>pin;
                  cout<<"\nENTER NAME OF FACTORY: ";
                  cin>>name;
                  cout<<"\nENTER ADDRESS: ";
                  cin>>addrs;
                  cout<<"\nENTER TOTAL AREA: ";
                  cin>>tarea;
                  cout<<"\nENTER GREEN AREA: ";
                  cin>>garea;
                  cout<<"\nENTER NUMBER OF EMPLOYEES: ";
                  cin>>noemp;
                  cout<<"\n\n(Enter the following quantities in tons)\n\n";
                  cout<<"\nEnter the amount of plastic usage: ";
                  cin>>usage_plastic;
                  cout<<"\nEnter the amount of foods usage: ";
                  cin>>usage_food;
                  cout<<"\nEnter the amount of paper usage: ";
                  cin>>usage_paper;
                  cout<<"\nEnter the amount of chemical usage: ";
                  cin>>usage_chemicals;
                  cout<<"\nEnter existing carbon credits: ";
                  cin>>tcredits;
                  LightMachinery::accept();
                  HeavyMachinery::accept();
                  credits=LightMachinery::calcmaxpw();
                  credits= credits+HeavyMachinery::calcmaxpw();
                  credits= credits+calculatearea(garea,tarea);
                  credits= credits+usage(usage_plastic,usage_food,usage_paper,usage_chemicals);
                  tcredits=tcredits+credits;
             }
            
             void display()
             {
                  cout<<"\nPin: ";
                  cout<<pin;
                  cout<<"\nFactory name: ";
                  cout<<name;
                  cout<<"\nAddress: ";
                  cout<<addrs;
                  cout<<"\nTotal Area: ";
                  cout<<tarea;
                  cout<<"\nGreen Area: ";
                  cout<<garea;
                  cout<<"\nPlastic Usage: ";
                  cout<<usage_plastic<<" tons";
                  cout<<"\nFoods Usage: ";  
                  cout<<usage_food<<" tons";
                  cout<<"\nPaper Usage: ";
                  cout<<usage_paper<<" tons";
                  cout<<"\nChemical Usage: ";
                  cout<<usage_chemicals<<" tons";
                  cout<<"\nExisting Carbon Credits: ";
                  cout<<tcredits;
             }
             
             int getpin()
                { return pin;}
}F;
//ofstream f("FACTORY.txt",ios::out);
//ofstream i("details.txt",ios::out); 


// main() function
int main()
{   
    int ch, flag, pwcount=0,exitflag=0;
    int ctrh=0, pos=0, hflag;
    //variables for PASSWORD
    char pass[4+1],ch1;
    int j = 0;
    
    system("cls"); 
    cout<<"\n\t\t\tCARBON CREDIT MANAGEMENT SYSTEM\n\n";
    do
    {
       cout<<"\n\n\tEnter the password and press enter key: ";
       // 4 character password   
       for(j=0;j<4;j++)
       {
        pass[j] = getch();
        cout<<"*";
       }
       pass[4]='\0';
       //cout<<pass;
       getch(); 
       if(strcmpi(pass,"rara")==0)
       {
          pwcount=3;
       }   
       else
       {
          cout<<"\n\n\tWrong Password. Trail "<<pwcount+1<<" of 3 Failed.";
          pwcount++;
          exitflag++;
       }  
    }while(pwcount!=3);   
    
    if(exitflag < 3)
    {
      cout<<"\n\n\n\tEntry Granted. Press any key...";
      getch();
    }
    else  
    {
      cout<<"\n\n\tEntry Denied. Press any key...";
      getch();
      return 0; // exiting if the password trails fail for 3 times
    }
    
    // Selecting the category type for Carbon Credit <aManagement
    do
     {
        system("cls");
        cout<<"\n\t\t\tCARBON CREDIT MANAGEMENT SYSTEM\n\n";             
        cout<<"\n\tChoose a CATEGORY\n";
        cout<<"\n\t1. HOUSEHOLD";
        cout<<"\n\t2. COMPANY";
        cout<<"\n\t3. INSTITUTIONS";
        cout<<"\n\t4. FACTORY";
        cout<<"\n\t5. EXIT";
        cout<<"\n\n\nEnter an option (1 or 2 or 3 or 4 or 5): ";
        cin>>ch;
        switch(ch)
        {
            case 1: {
                      system("cls");
                      cout<<"\n\t\t\tCARBON CREDIT MANAGEMENT SYSTEM!";
                      int choice;
                      cout<<"\n\n\n\nWelcome To The Household Section Of CCMS\n\n";
                      do
                      {
                         cout<<"\n\t HOUSEHOLD MENU\n";
                         cout<<"\n\t 1. Add";
                         cout<<"\n\t 2. Search & Display";
                         cout<<"\n\t 3. Modify";
                         cout<<"\n\t 4. Display All";
                         cout<<"\n\t 5. Goto Main Menu";
                         cout<<"\n\n\t Enter your choice (1 or 2 or 3 or 4 or 5): ";
                         cin>>choice;
                         fstream ih("hdetails.dat",ios::out|ios::in|ios::app|ios::binary);
                         fstream h("new hdetails.dat",ios::out|ios::in|ios::binary);
                         switch(choice)
                         {
                            case 1: {
                                       system("cls");
                                       ih.open("hdetails.dat",ios::binary|ios::in);
                                       if(!ih)
                                       {  
                                         ih.seekg(ctrh); 
                                         ih.write((char*)&H,sizeof(H));    
                                         H.details(); 
                                         ih.close();
                                       }  
                                       else
                                       {
                                         ih.seekg(ctrh); 
                                         ih.write((char*)&H,sizeof(H));    
                                         H.details();
                                         ih<<'\0';
                                         ih.close();
                                       }
                                       ctrh++;                       
                                       
                                       //ctrh++;
                                       break;
                                    }      
                                  
                                  case 2: {
                                         system("cls"); 
                                         int p2;
                                         flag=0;      
                                         cout<<"\nEnter the unique code alloted so as to search data: ";
                                         cin>>p2;
                                         ih.open("hdetails.dat",ios::binary|ios::in|ios::out|ios::app); 
                    
                                         ih.seekg(0);

                                         while(!ih.eof()) 
                                         {
                                                         ih.read((char*)&H,sizeof(H));
                                                         if(H.getpin()==p2)  //getpin() is a func that returns the pin
                                                         {
                                                         cout<<"\nMatch Found!";
                                                         H.display();
                                                         flag++;
                                                         break;
                                                         }
                                         }
                                         ih.close();
                                         if(flag==0)
                                                {
                                                  cout<<"\n\n Match not Found!";
                                                }
                                         break;}
                                  case 3: { 
                                         int p3;      
                                         system("cls");
                                         cout<<"\nEnter the unique code alloted so as to modify data: ";
                                         cin>>p3;
                                         ih.open("hdetails.dat",ios::binary|ios::in|ios::out|ios::app);
                                         while(!ih.eof())
                                         {
                                                                      int pos=ih.tellg();
                                                                      ih.read((char*)&H,sizeof(H));
                                                                      if(ih.eof()) // robustness
                                                                      break;
                                                                      if(H.getpin()==p3); //getpin() is a func that returns the pin
                                                                      {
                                                                       ih.seekg(pos);
                                                                       H.details();
                                                                       ih.write((char*)&H,sizeof(H));
                                                                       flag++;
                                                                      }
                                         }
                                         ih.close();
                                         if(flag==0)
                                         cout<<"\n Address not found !! \n";
                                         ih.close();
                                         break;}
                                  case 4: {    
                                         system("cls");    
                                         ih.clear(); 
                                         ih.open("hdetails.dat",ios::in|ios::binary|ios::app);
                                         int ctrp=0;
                                         while(!ih.eof())
                                         {
                                                if(ih.eof()) // robustness
                                                break;       
                                                ih.read((char*)&H,sizeof(H));
                                                H.display();
                                                ctrp++;
                                                cout<<ctrp<<"\n\n!!!!\n\n";
                                         }  
                                         ih.close();
                                         
                                         break;}
                                         
                                  case 5:
                                         {cout<<"\nExit!";
                                         break;}
                                  default:     
                                         cout<<"\n\nINVALID ENTRY!! TRY AGAIN!!!\n\n";
                                         break; 
                          }     
                          }
                          while(choice!=5);
                          
                          break;
                          }
              case 2:    {
                          int opt;
                          do
                          {
                            system("cls");
                            cout<<"\n\t\t\tCARBON CREDIT MANAGEMENT SYSTEM!";
                            cout<<"\n\n\n\nWelcome To The Company Section Of CCMS\n\n";
                            cout<<"\n\n\t COMPANY MENU\n";
                            cout<<"\n\t 1. Add";
                            cout<<"\n\t 2. Search & Display";
                            cout<<"\n\t 3. Modify";
                            cout<<"\n\t 4. Display All";
                            cout<<"\n\t 5. Goto Main Menu";
                            cout<<"\n\nEnter your choice (1 or 2 or 3 or 4 or 5): ";
                            cin>>opt;
                           
                            fstream cmp("details.dat",ios::out|ios::in|ios::binary);
                            fstream fcmp("new details.dat",ios::binary|ios::in|ios::out|ios::app);
                         
                            company C; // Company Object
                        
                         switch(opt)
                         {
                                   case 1: // Add Records
                                         {
                                          system("cls");
                                          ofstream cmp1;
                                          cmp1.open("cdetails.dat",ios::app|ios::binary);
                                          C.get_com_data();
                                          cmp1.write((char*)&C,sizeof(C));
                                          cin.get();
                                          cmp1.close();
                                          break;
                                         }
 
                                   case 2: // Search and Display Records
                                         {
                                          int pin2; 
                                          flag=0; 
                                          system("cls"); 
                                          cout<<"\nEnter the unique code of the record to search:  ";
                                          cin>>pin2;
                                          ifstream cmp2;
                                          cmp2.open("cdetails.dat",ios::in|ios::binary);
                                          cmp2.seekg(0);
                                          while(!cmp2.eof())
                                          {
                                           cmp2.read((char*)&C,sizeof(C));
                                           if(C.getpin()==pin2)  //getpin() is a func that returns the pin
                                           {
                                            C.put_com_data();
                                            flag++;
                                            break;
                                           }
                                          }
                                          if(flag==0)
                                          {
                                           cout<<"\n\n Match not Found!! ";
                                          }
                                         cmp2.close();
                                         getch(); 
                                         break;
                                        }
                                   case 3: // Modify records
                                         {
                                          int pin3, pos, insertpos;
                                          int flag = 0;
                                          system("cls");
                                          cout<<"\nEnter the unique code of the record to modify:  ";
                                          cin>>pin3;
                                          ifstream cmp3;
                                          cmp3.open("cdetails.dat",ios::in|ios::binary);
                                          cmp3.seekg(0);
                                          while(!cmp3.eof())
                                          {
                                            pos=cmp3.tellg();
                                            cmp3.read((char*)&C,sizeof(C));                                           
                                            if(C.getpin()==pin3)  //getpin() is a func that returns the pin
                                            {
                                             insertpos = pos;                     
                                             C.put_com_data();
                                             flag++; 
                                            } 
                                           }
                                           cmp3.close();
                                           if(flag==0)
                                           cout<<"\nRecord not found !! \n";
                                           else
                                           {
                                              fstream cmp3;
                                              cmp3.open("cdetails.dat",ios::in|ios::out|ios::binary);
                                              getch();
                                              cmp3.seekg(insertpos);
                                              cout<<"\nPress any key to modify the above record\n";
                                              getch();
                                              system("cls");
                                              C.get_com_data();
                                              cmp3.seekg(insertpos);
                                              cmp3.write((char*)&C,sizeof(C));
                                              cin.get();
                                              cmp3.close();
                                           }
                                           getch();
                                           break;
                                          }

                                   case 4: // Display all records  
                                         {
                                          system("cls");
                                          ifstream cmp4;
                                          cmp4.open("cdetails.dat",ios::in|ios::binary);
                                          cmp4.seekg(0);
                                          //fcmp.open("cdetails.dat",ios::in|ios::binary);
                                          while(!cmp4.eof())
                                          {
                                           cmp4.read((char*)&C,sizeof(C));
                                           C.put_com_data();
                                           cin.get();
                                          }
                                          cmp4.close();
                                          getch();
                                          break;
                                          }
                                   case 5:
                                          {break;}
                                   default:
                                          {cout<<"\n\nINVALID ENTRY!! TRY AGAIN!!!\n\n";
                                           break;
                                          }
                          
                          }}
                          while(opt!=5);

                          break;
                          }

              
              case 3:     
                          {
                          cout<<"UNIVERSITY!";
                          int c;
                          cout<<"Welcome To The UNIVERSITY Section Of CCMS";
                          do
                          {
                          cout<<"\n\n Menu \n";
                          cout<<"\n 1.Add university";
                          cout<<"\n 2.Search And Display university";
                          cout<<"\n 3.Modify";
                          cout<<"\n 4.Display All universities";
                          cout<<"\n 5.Exit";
                          cout<<"\n\n Enter your choice (1 or 2 or 3 or 4 or 5) : ";
                          cin>>c;
                          fstream f1;
                          fstream ff1;
                          switch(c)
                          {
                                   case 1:
                                         system("cls");
                                         {f1.open("university details.dat",ios::out|ios::binary);
                                         U.getdata();                                 
                                         f1.write((char*)&U,sizeof(U));
                                         f1.close();
                                         break;}  
                                  
                                   case 2: 
                                          system("cls");
                                         {int pinU;
                                         int uflag=0;
                                         cout<<"\nEnter the unique code alloted so as to delete data: ";
                                         cin>>pinU;
                                         f1.open("university details.dat",ios::binary|ios::in|ios::out); 
                    
                                         f1.seekg(0);

                                         while(!f1.eof()) 
                                         {
                                                         f1.read((char*)&U,sizeof(U));
                                                         if(U.getpin()==pinU) // getpin() is the return func. which returns pin
                                                         {
                                                         U.showdata();
                                                         uflag++;
                                                         f1.close();
                                                         break;
                                                         }
                                         }
                                         if(uflag==0)
                                                {
                                                  cout<<"\n\n Match not Found!! ";
                                                }
                                         break;}
                                   case 3:
                                         system("cls");
                                         {int p;
                                         cout<<"\nEnter the unique code alloted so as to delete data: ";
                                         cin>>p;
                                         f1.open("university details.dat",ios::binary|ios::in|ios::out);
                                         int flag=0;
                                         while(f1)
                                         {
                                                                      int pos=f1.tellg();
                                                                      f1.read((char*)&U,sizeof(U));
                                                                      if(f1.eof()) // robustness
                                                                      break;
                                                                      if(U.getpin()==p);
                                                                      {
                                                                       f1.seekg(pos);
                                                                       U.getdata();
                                                                       f1.write((char*)&U,sizeof(U));
                                                                       flag++;
                                                                       f1.close();
                                                                      }
                                         }
                                         if(flag==0)
                                         cout<<"\n Address not found !! \n";
                                         f1.clear();
                                         break;}
                                   case 4:  
                                           system("cls");   
                                         {f1.open("university details.dat",ios::in|ios::binary);
                                         while(!f1.eof())
                                         {
                                                f1.read((char*)&U,sizeof(U));
                                                U.showdata();
                                         }  
                                         f1.close();
                                         break;}
                                   case 5:
                                         {break;}
                                   default:     
                                        { cout<<"\n\nINVALID ENTRY!! TRY AGAIN!!!\n\n";
                                         break; }
                          }     
                          }
                          while(c!=5);

                          break;
                          }
              case 4:     
                          {
                          system("cls");
                          int f;
                          int fflag;
                          cout<<"Welcome To The Factory Section Of CCMS";
                          do
                          {
                          cout<<"\n\nMenu\n";
                          cout<<"\n1)Add";
                          cout<<"\n2)Search And Display";
                          cout<<"\n3)Modify";
                          cout<<"\n4)Display All";
                          cout<<"\n5)Exit";
                          cout<<"\n\nEnter your option(1 or 2 or 3 or 4 or 5) : ";
                          cin>>f;
                          fstream fa1("FACTORY.dat",ios::out|ios::in|ios::binary);
                          fstream t;
                          switch(f)
                          {        
                                   case 1:                              
                                         {
                                          system("cls");
                                          fa1.open("FACTORY.dat",ios::binary|ios::out);
                                          F.input();
                                          fa1.write((char*)&F,sizeof(F));
                                          fa1.close();
                                          break;
                                         }
                                                
                                   case 2 :    
                                          { 
                                            cout<<"\n\nSEARCH AND DISPLAY";
                                            system("cls"); 
                                            int p3;
                                            flag=0;
                                            cout<<"Enter Pin code of Factory: ";
                                            cin>>p3;
                                            fa1.open("FACORY.dat",ios::in|ios::binary);
                                            fa1.seekg(0);
                                            while(!fa1.eof())
                                                {
                                                 fa1.read((char*)&F,sizeof(F));  
                                                 if(F.getpin()==p3);
                                                 {                  
                                                   cout<<"\n\nMatch Found!!";
                                                   F.display();
                                                   flag++;
                                                   fa1.close();
                                                   break;
                                                 }
                                                }
                                                if(flag==0)
                                                {
                                                  cout<<"\n\nMatch not Found!!";
                                                }
                                            break;
                                            }
                                                
                                                
                                   case 3:  
                                          {
                                           cout<<"\n\nMODIFY";
                                           system("cls");
                                           fflag=0;
                                           fa1.open("FACTORY.dat",ios::in|ios::out|ios::binary);
                                           long pos;
                                           int p2;
                                           cout<<"Enter Pin code of Factory: ";
                                           cin>>p2;
                                           while(!fa1.eof())
                                                {
                                                   pos=fa1.tellg();
                                                   fa1.read((char*)&F,sizeof(F));
                                                   if(F.getpin()==p2)
                                                   {
                                                      cout<<"\nEnter details for modification";
                                                      F.input();
                                                      fa1.seekg(pos);
                                                      fa1.write((char*)&F,sizeof(F));
                                                      fflag++;
                                                   }
                                                }
                                                if(fflag==0)
                                                {
                                                           cout<<"\n\nRECORD NOT FOUND!!!";
                                                }
                                                fa1.close();
                                                
                                           break;
                                           }
                                   
                                   case 4:      
                                          {
                                           system("cls");    
                                           fa1.open("FACTORY.dat",ios::in|ios::binary);
                                           while(!fa1.eof())
                                               {
                                                  if(fa1.eof()) // robustness
                                                  break;       
                                                  fa1.read((char*)&F,sizeof(F));
                                                  F.display();
                                                  
                                               }  
                                               fa1.close(); 
                                           break;
                                          }
                                   case 5:      
                                          {break;}
                                   default:    
                                          {
                                           cout<<"\n\nINVALID ENTRY!! TRY AGAIN!!!\n\n";
                                           break;
                                          }
                          }
                          }
                          while(f!=5);
                          break;
                          }
              case 5:     {break;}
              default:{ cout<<"\n\n\nINVALID ENTRY!!";
                       break;}
    }
    }
    while(ch!=5);
    
/*}
else
    cout<<"\n\n\tWrong Password. Entry Denied!";
    cout<<"\n\n\tPress any key to quit. THANK YOU!!!";
    getch();*/
return 0;
}


//function definitions

float usage(float usage_plastic,float usage_food,float usage_paper,float usage_chemicals)
{
     float tot_usage=usage_plastic+ usage_food+ usage_paper+ usage_chemicals;
     float credits=0.0;
     if(tot_usage<=max_tons)
     {
              credits=(max_tons-(tot_usage))*10;
              
     }
     if(tot_usage>max_tons)
     {
              credits=(tot_usage-max_tons)*(-1)*10;
     }
     cout<<"\n\nMax Usage(in tons): "<<max_tons;
     return credits;
}

    
float usage(float usage_plastic,float usage_food, float usage_paper)
{
     float tot_usage=usage_plastic+ usage_food+ usage_paper;
     float credits=0.0;
     if(tot_usage<=m_tons)
     {
               credits=(m_tons-(tot_usage))*10; 
     }
     if(tot_usage>m_tons)
     {
              credits=(tot_usage-m_tons)*(-1)*10;
     }
     cout<<"\n\nMax Usage (in tons): "<<m_tons;
     return credits;
}
float calculatearea(float greenarea,float totalarea)
{
     float gr=greenarea/totalarea;
     cout<<"\n\nGreen Area to Total Area Ratio is: "<<gr;
     cout<<"\nRequired Ratio is: "<<rr;
     float credits=0.0;
     if(gr>rr)
     {
              credits= gr*10;
     }
     if(gr<rr)
     {
              credits=gr*(-1)*10;
     }
     return credits;
}


                                          
                                                
                                   
                                             
                                   
                                                                        
                                                
                                                                                
                                                 
                                                                                
                                                                                                           
                                                                                                    
                                   
                                                                
                                                
                                                          
                                          
                                          
    


