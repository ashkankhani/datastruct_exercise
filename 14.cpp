#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    unsigned long int std_num;
    float moadel;
    Student *link;
}*start;


int get_last_index(Student *start){
    int i = -1;
    Student *p;
    p = start;
    while (p!=NULL)
    {
        p = p->link;
        i++;
    }
    return i;
    
}

int get_index(Student *start,float moadel);


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
        }else if(str1[i] < str2[i]){
            mosavi = false;
            return false;
        }
        i++;
    }
    if(mosavi && len1 > len2){
        swap = true;
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
            if(swap(q->name , p->name)){
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
///////////////
//for searches

bool str_check(string str1 , string str2){
    if(str2 == "0"){
        return true;
    }

    if(str1.find(str2) != string::npos){
        return true;
    }
    return false;

}

bool stdnum_check(unsigned long int stdn1 ,
unsigned long int stdn2){
    if(stdn2 == 0){
        return true;
    }
    return stdn1 == stdn2;
}

bool grade_check(float grade1 , float grade2 , char amal){

    switch (amal)
    {
    case '0':
        return true;
        break;
    case '=':
        return grade1 == grade2;
        break;
    case '>':
        return grade1 > grade2;
        break;
    case '<':
        return grade1 < grade2;
        break;
    default:
        break;
    }
    return true;
}

void linear_search(Student *start ,
string name , 
float grade , 
char amal,
unsigned long int std_num){

    Student *p;
    p = start;
    cout << "name" <<"\t|\t"<<"std_number" << "\t|\t"<< "moadel" <<endl;
    while(p!=NULL){

        if(str_check(p->name,name)
        && grade_check(p->moadel , grade,amal)
        && stdnum_check(p->std_num , std_num)){

            cout << p->name <<"\t|\t"<< p->std_num << "\t|\t" << p -> moadel <<endl;
            
        }


        p = p->link;
    }
}
///////////////
//for searches

int main()
{
    int gozine,index;
    string name;
    unsigned long int std_num;
    float moadel;
    char amal;
    start = new Student();
    start = NULL;

    cout << "be menue barname khosh amadid!\n";
    cout << "1.add new student to list\n";
    cout << "2.delete student from list\n";
    cout << "3.show students list\n";
    cout << "4.linear search by name and stdnum and grade\n";
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
            cout << "choose linear search method:\n"
            <<"1.by name\n"
            <<"2.by stdnum\n"
            <<"3.by grade:\n"
            <<"4.all above\n";
            int l_search;
            cin >> l_search;
            if(l_search == 1){
                cout << "enter name for search:\n";
                cin.ignore();
                getline(cin,name);
                linear_search(start,name,0,'0',0);
            }else if(l_search == 2){
                cout << "enter stdnum for search:\n";
                cin >> std_num;
                linear_search(start,"0",0,'0',std_num);
            }else if(l_search == 3){
                cout << "enter grade for search:\n";
                cin >> moadel;
                cout << "choose grade range:\n"
                << ">\n"
                << "<\n"
                << "=\n";
                cin >> amal;
                linear_search(start,"0",moadel,amal,0);
            }else if(l_search == 4){
                cout << "enter name for search:\n";
                cin.ignore();
                getline(cin,name);
                cout << "enter stdnum for search:\n";
                cin >> std_num;
                cout << "enter grade for search:\n";
                cin >> moadel;
                cout << "choose grade range:\n"
                << ">\n"
                << "<\n"
                << "=\n";
                cin >> amal;
                linear_search(start , name , moadel , amal , std_num);
            }else{
                cout << "wrong choice!";
            }

            
        }else if(gozine == 5){
            int sort_choice;
            cout << "choose sort method:\n"
            <<"1.by name\n"
            <<"2.by grade\n"
            <<"3.by std num\n";
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
 
