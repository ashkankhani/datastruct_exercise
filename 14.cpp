#include <iostream>
using namespace std;
 
struct Student {
    string first_name,lastname;
    unsigned long int std_num;
    float moadel;
    Student *link;
}*start;


void insert_std(Student **start,
int index,
string first_name ,
string last_name , 
unsigned long int std_num ,
float moadel){
    Student *n;
    n = new Student();
    n->first_name = first_name;
    n->lastname = last_name;
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

void display_students(Student *start){
    Student *p;
    p = start;
    cout << "first_name" <<"\t|\t"<< "lastname" << "\t|\t" << "std_number" << "\t|\t"<< "moadel" <<endl;
    while(p!=NULL){
        cout << p->first_name <<"\t|\t"<<p -> lastname << "\t|\t" << p->std_num << "\t|\t" << p -> moadel <<endl;
        p = p->link;
    }

}

int main()
{
    
    int gozine,index;
    string first_name,lastname;
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
            cout << "enter firstname:\n";
            cin >> first_name;
            cout << "enter lastname:\n";
            cin >> lastname;
            cout << "enter stdnum:\n";
            cin >> std_num;
            cout << "enter moadel:\n";
            cin >> moadel;
            cout << "enter the index of insertion:\n";
            cin >> index;
            insert_std(&start ,index, first_name , lastname , std_num , moadel);
            display_students(start);


        }else if(gozine == 2){

        }else if(gozine == 3){
            
        }else if(gozine == 4){
            
        }else if(gozine == 5){
            
        }else if(gozine == 6){
            
        }



    cout << "lotfan yek gozine entekhab konid:\n";
    cin >> gozine;

    }


    




 
  
 
    return 0;
}
 
