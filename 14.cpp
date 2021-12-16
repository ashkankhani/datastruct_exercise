#include <iostream>
using namespace std;
 
struct Student {
    string name;
    unsigned long int std_num;
    float moadel;
    Student *link;
}*start;


void insert_std(Student **start,
int index,
string name ,
unsigned long int std_num ,
float moadel){
    Student *n;
    n = new Student();
    n->name = name;
    n->std_num = std_num;
    n -> moadel = moadel;
    
    if(index){
        //
        Student *p;
        p = *start;
        //darj dar vasat
        int i = 0;
        while(p!=NULL && i < index - 1){
            p = p->link;
            i++;
        }
        if(p!=NULL){
            n->link = p->link;
            p->link = n;
        }else{
            cout << "index is out of range!";
        }
        


    }else{
        //darj ebteda
        n->link = *start;
        *start = n;
    }

    



}
void delete_std(Student **start,string name){
    Student *q,*p;
    q = NULL;
    p = *start;
    while(p!= NULL && p->name != name){
        q = p;
        p = p->link;
    }
    if(p!=NULL){
        //found
        if(q == NULL){
            //first index
            *start = p->link;
            

        }else{
            q->link = p->link;

        }
        delete p;
        cout << "delete was successful!";
        
    }else{
        cout << "student not found!";
    }
}
void delete_std(Student **start,int std_num){
    Student *q,*p;
    q = NULL;
    p = *start;
    while(p!= NULL && p->std_num != std_num){
        q = p;
        p = p->link;
    }
    if(p!=NULL){
        //found
        if(q == NULL){
            //first index
            *start = p->link;
            

        }else{
            q->link = p->link;

        }
        delete p;
        cout << "delete was successful!";
        
    }else{
        cout << "student not found!";
    }

}

void display_students(Student *start){
    Student *p;
    p = start;
    cout << "name" <<"\t|\t"<<"std_number" << "\t|\t"<< "moadel" <<endl;
    while(p!=NULL){
        cout << p->name <<"\t|\t"<< p->std_num << "\t|\t" << p -> moadel <<endl;
        p = p->link;
    }

}

int main()
{
    
    int gozine,index;
    string name;
    unsigned long int std_num;
    float moadel;
    start = new Student();
    start = NULL;

    cout << "be menue barname khosh amadid!\n";
    cout << "1.afzoodane daneshjoo be list\n";
    cout << "2.hazfe daneshjoo az list\n";
    cout << "3.namayeshe liste daneshjooyan\n";
    cout << "4.search by name and lastname\n";
    cout << "5.moratab sazi\n";
    cout << "6.binary search\n";
    cout << "0.exit\n";
    cout << "lotfan yek gozine entekhab konid:\n";
    cin >> gozine;

    while(gozine){
        if(gozine == 1){
            cout << "enter full name: \n";
            cin.ignore();
            getline(cin,name);
            cout << "enter stdnum:\n";
            cin >> std_num;
            cout << "enter moadel:\n";
            cin >> moadel;
            cout << "enter the index of insertion:\n";
            cin >> index;
            insert_std(&start ,index, name , std_num , moadel);
            cout << "your linked list is:\n";
            display_students(start);


        }else if(gozine == 2){
            int delete_choice;
            cout << "choose:\n"
            <<"1.delete by name\n"
            <<"2.delete by std number:\n";
            cin >> delete_choice;
            if(delete_choice == 1){
                cin.ignore();
                cout << "enter std name:\n";
                getline(cin , name);
                delete_std(&start,name);

            }else if(delete_choice == 2){
                cout << "enter stdnum:\n";
                cin >> std_num;
                delete_std(&start,std_num);
            }else{
                cout << "wrong choice\n";
            }
            cout << "your linked list is:\n";
            display_students(start);

        }else if(gozine == 3){
            cout << "your linked list is:\n";
            display_students(start);
        }else if(gozine == 4){
            
        }else if(gozine == 5){
            
        }else if(gozine == 6){
            
        }else{
            cout << "wrong choice!\n";
        }



    cout << "lotfan yek gozine entekhab konid:\n";
    cin >> gozine;

    }


    




 
  
 
    return 0;
}
 
