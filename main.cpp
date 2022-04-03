//  Created by Afiq Hafiz on 18/10/2021.
//

#include<iostream>
#include<string>

using namespace std;
class hospital{
  struct patients{
      string Name;
      int IC;
      int contact;
      string disease;
      string doctorNames;
      string patientPriority;
      patients *next;
      patients *prev;
  };
  
public:
  hospital(){
    start = NULL;
    end = NULL;
  }
  
  int menu (){
    //display menu options
    int choice = 0;
    cout << "Menu" << endl;
    cout << "1. Register Patient" << endl;
    cout << "2. Display Patient" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cout<<endl;

    //return user’s choice
    return choice;
  }

  void dataPatient(){
    patients *p = new patients;
      cout<<"Please enter patient name: ";
      fflush(stdin);
      getline(cin,p->Name);
      cout<<"Please enter patient IC: ";
      cin>>p->IC;
      cout<<"Please enter patient contact No: ";
      cin>>p->contact;
      cout<<"Please enter patient disease: ";
      fflush(stdin);
      getline(cin,p->disease);
      cout<<"Doctor Name: ";
      fflush(stdin);
      getline(cin,p->doctorNames);
      int choice;
      cout << "Patient Priority: \n1.Emergency \n2.Normal\n";
      cout << "Patient Priority:";
      cin >> choice;
      if (choice == 1) {
          p->patientPriority = "Emergency";
      }
      else if (choice == 2){
          p->patientPriority = "Normal";
      }
      
    
      registerPatient(p);
  }
  
  void registerPatient(patients* p_ref){
      if (p_ref->patientPriority == "Normal") {
          if(start == NULL){
              start = p_ref;
              end = p_ref;
              p_ref->next=NULL;
              p_ref->prev=NULL;
          }
          else{
              end->prev = p_ref;
              p_ref->next = end;
              p_ref->prev = NULL;
              end = p_ref;
          }
      }
      else if (p_ref->patientPriority == "Emergency"){
          if(start == NULL){
              start = p_ref;
              end = p_ref;
              p_ref->next=NULL;
              p_ref->prev=NULL;
          }
          else{
              p_ref->next = NULL;
              p_ref->prev = start;
              start->next = p_ref;
              start = p_ref;
          }
      }
  }
  
  void displayPatient(){
    int choice;
    int id;
    patients *p = start;

    cout << "1-Display individual record\n"
         << "2-Display all records\n"
         << "3-Display list of emergency or normal patient\n";
    cin >> choice;
    
    if(choice ==1){
      cout << "Enter patient's ID:";
      cin >> id;
      while(p != NULL){
        if(id==p->IC){
          cout << "patient's name: " << p->Name<< endl;
          cout << "patient's IC: " << p->IC<< endl;
          cout << "patient's contact no: " << p->contact<< endl;
          cout << "patient's disease: " << p->disease<< endl;
          cout << "Doctor's name: " << p->doctorNames<< endl;
          cout << "Patient Priority: " << p->patientPriority << endl <<endl;
          break;
        }
        p = p->prev;
      }
    }
    else if(choice==2){
      while(p != NULL){
          cout << "patient's name: " << p->Name<< endl;
          cout << "patient's IC: " << p->IC<< endl;
          cout << "patient's contact no: " << p->contact<< endl;
          cout << "patient's disease: " << p->disease<< endl;
          cout << "Doctor's name: " << p->doctorNames<< endl;
          cout << "Patient Priority: " << p->patientPriority << endl <<endl;
        p = p->prev;
      }
    }
      
    else if(choice==3){
        int choice;
        cout << "1. List of emergency record \n2. List of Normal records \nYour choice(1/2):";
        cin >> choice;
        if (choice == 1) {
            while(p != NULL){
                if (p->patientPriority == "Emergency") {
                    cout << "patient's name: " << p->Name<< endl;
                    cout << "patient's IC: " << p->IC<< endl;
                    cout << "patient's contact no: " << p->contact<< endl;
                    cout << "patient's disease: " << p->disease<< endl;
                    cout << "Doctor's name: " << p->doctorNames<< endl;
                    cout << "Patient Priority: " << p->patientPriority << endl <<endl;
                }
              p = p->prev;
            }
        }
        else if (choice == 2){
            while(p != NULL){
                if (p->patientPriority == "Normal") {
                    cout << "patient's name: " << p->Name<< endl;
                    cout << "patient's IC: " << p->IC<< endl;
                    cout << "patient's contact no: " << p->contact<< endl;
                    cout << "patient's disease: " << p->disease<< endl;
                    cout << "Doctor's name: " << p->doctorNames<< endl;
                    cout << "Patient Priority: " << p->patientPriority << endl <<endl;
                }
              p = p->prev;
            }
        }
    }
  
  }
  
  private:
  patients *start,*end;};

int main(){
  //create class object and variables
  hospital list;
  int choice = 0;
  do{
    choice = list.menu();
    cout << endl;
    switch (choice){
      case 1: //call function registerPatient()
          list.dataPatient();
          break;
      case 2: //call function displayPatient ()
          list.displayPatient();
          break;
    }
  } while (choice != 3);
}
