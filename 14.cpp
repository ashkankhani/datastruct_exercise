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

bool swap(string str1 , string str2){
    if(str1 == str2){
        return false;
    }
    bool swap = false,mosavi = true;
    int len,len1=str1.length(),len2=str2.length(),i = 0;
    if(len1 < len2){
        len = len1;
    }else{
        len = len2;
    }
    while(i < len && mosavi){
        if(str1[i] > str2[i]){
            mosavi = false;
            return true;
        }
        i++;
    }
    if(mosavi && len1 > len2){
        swap = true;;
    }
    return swap;



}

void str_sort(Student **start){
    Student *q , *p;
    string name;
    unsigned long int std_num;
    float moadel;
    q = *start;
    p = q->link;
    while (q->link != NULL)
    {
        while(p!=NULL){
            //cout << "q = "<<q->moadel << " "<<"p = "<<p->moadel << endl;
            if(q->moadel > p->moadel){
                //temp
                name = q->name;
                std_num = q->std_num;
                moadel = q->moadel;

                //swap

                q->name = p->name;
                q->std_num = p->std_num;
                q->moadel = p->moadel;
                //-----------------

                p->name = name;
                p->std_num = std_num;
                p->moadel = moadel;

            }
            
            p = p->link;
        }
        q = q->link;
        p = q->link;


    }

}
void grade_sort(Student **start){
    Student *q , *p;
    string name;
    unsigned long int std_num;
    float moadel;
    q = *start;
    p = q->link;
    while (q->link != NULL)
    {
        while(p!=NULL){
            //cout << "q = "<<q->moadel << " "<<"p = "<<p->moadel << endl;
            if(q->moadel > p->moadel){
                //temp
                name = q->name;
                std_num = q->std_num;
                moadel = q->moadel;

                //swap

                q->name = p->name;
                q->std_num = p->std_num;
                q->moadel = p->moadel;
                //-----------------

                p->name = name;
                p->std_num = std_num;
                p->moadel = moadel;

            }
            
            p = p->link;
        }
        q = q->link;
        p = q->link;


    }
    
}
void stdnum_sort(Student **start){
    Student *q , *p;
    string name;
    unsigned long int std_num;
    float moadel;
    q = *start;
    p = q->link;
    while (q->link != NULL)
    {
        while(p!=NULL){
            //cout << "q = "<<q->moadel << " "<<"p = "<<p->moadel << endl;
            if(q->std_num > p->std_num){
                //temp
                name = q->name;
                std_num = q->std_num;
                moadel = q->moadel;

                //swap

                q->name = p->name;
                q->std_num = p->std_num;
                q->moadel = p->moadel;
                //-----------------

                p->name = name;
                p->std_num = std_num;
                p->moadel = moadel;

            }
            
            p = p->link;
        }
        q = q->link;
        p = q->link;


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
    cout << "1.add new student to list\n";
    cout << "2.delete student from list\n";
    cout << "3.show students list\n";
    cout << "4.search by name and lastname and grade\n";
    cout << "5.sort list(by grade stdnum and name)\n";
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
            int sort_choice;
            cout << "choose sort method:\n"
            <<"1.by name\n"
            <<"2.by grade\n"
            <<"3.by std num";
            cin >> sort_choice;
            if(sort_choice == 1){
                str_sort(&start);
            }else if(sort_choice == 2){
                grade_sort(&start);

            }else if(sort_choice == 3){
                stdnum_sort(&start);
            }else{
                cout << "wrong choice";
            }
            cout << "your linked list is:\n";
            display_students(start);
        }else if(gozine == 6){
            
        }else{
            cout << "wrong choice!\n";
        }



    cout << "lotfan yek gozine entekhab konid:\n";
    cin >> gozine;

    }


    




 
  
 
    return 0;
}
 
