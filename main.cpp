#include <iostream>
#include <stdio.h>
#include <fstream>
#include <conio.h>
using namespace std;

int *input_array(int *array,int &n){

    cout << "enter the length of array(max = 50):\n";
    cin >> n;
    while(n > 50 || n <=0){
        cout << "enter the length of array(min = 1 & max = 50):\n";
        cin >> n;
    }
    array = new int [n];
    for(int i = 0;i<n;i++){
        printf("enter array[%d]: ",i);
        cin >> array[i];
    }

    return array;

}
void display_array(int *array,int n){
    for(int i = 0;i<n;i++){
        cout << array[i] << " ";
    }
}
int *insert_into_array(int *array ,int & n){
    int number,index;
    cout << "enter a number witch you want to insert into array:\n";
    cin >> number;
    cout << "enter an index between 0 and "<<n<<" for insertion:\n";
    cin >> index;
    while(index < 0 || index > n){
        cout << "enter an index between 0 and "<<n<<" for insertion:\n";
        cin >> index;
    }
    int *new_array;
    new_array = new int[n + 1];
    new_array[index] = number;
    for(int i = 0;i<n;i++){
        if(i >= index){
            new_array[i+1] = array[i];

        }else if(i < index){
            new_array[i] = array[i];
        }
    }
    n++;
    delete[] array;
    return new_array;
    
}

int *delete_element(int *array ,int &n){
    int index , * new_array;
    cout << "enter a index witch you need to be deleted between 0 and "<<n-1<<":\n";
    cin >> index;
    while(index <0 || index >= n){
        cout << "enter a index witch you need to be deleted between 0 and "<<n-1<<":\n";
        cin >> index;
    }
    new_array = new int[n - 1];
    for(int i = 0;i<n;i++){
        if(i<index){
            new_array[i] = array[i];
        }else{
            new_array[i] = array[i + 1];
        }
    }
    n--;
    delete[] array;
    return new_array;
}


void selection_sort(int *array,int n){
    int temp;
        for(int i = 0;i<n-1;i++){
            for(int j = i + 1;j<n;j++){
                if(array[j] < array[i]){
                    temp = array[j];
                    array[j] = array[i];
                    array[i] = temp;
                    
                }
            }
        }
}

void save_array(int *array,int n){
    ofstream myfile;
    myfile.open("array.txt",ios::out);
    if(myfile.is_open()){
        myfile << n << endl;
        for(int i = 0;i<n;i++){
            myfile << array[i] << endl;
        }
        myfile.close();
    }
}

int *restore_array(int &n){
    int *array;
    ifstream myfile("array.txt");
    string line;
    myfile >> n;
    int i = 0;
    array = new int[n];
    while(getline(myfile,line)){
        myfile >> array[i++];
    }
    return array;
}



int main(){

    int gozine,n,*array;
    cout << "pay attention:\nyou should define array first or had saved array in save section before use 2+ choices:\n";
    cout << "gozine morede nazar ra vared konid:\n";
    cout << "1.daryafte adad az voroodi\n";
    cout << "2.darj\n";
    cout << "3.hazf\n";
    cout << "4.sort kardan arraye\n";
    cout << "5.namayeshe arraye\n";
    cout << "6.save arraye\n";
    cout << "7.restore arraye\n";
    cout << "0.exit\n";

    cin >> gozine;
    

    while(gozine){

        if(gozine == 1){
            array = input_array(array , n);
            cout << "your array is:\n";
            display_array(array , n);
            cout << "\narray is ready for use ;)\n";

        }else if(gozine == 2){
            
            array = insert_into_array(array,n);
            cout << "new array is:\n";
            display_array(array , n);
            cout << "\nnew array is ready for use ;)\n";

        }else if(gozine == 3){

            array = delete_element(array,n);
            cout << "new array is:\n";
            display_array(array,n);
            cout << "\narray is ready for use ;)\n";


        }else if(gozine == 4){
            selection_sort(array , n);
            cout << "sorted array = \n";
            display_array(array , n);
            cout << "\narray is ready for use ;)\n";

        
            
        }else if(gozine == 5){
            cout << "your array is:\n";
            display_array(array , n);
            cout << endl;
            
        }else if(gozine == 6){
            save_array(array , n);
            cout << "array successfully saved in array.txt\n";
        }else if(gozine == 7){
            array = restore_array(n);
            cout << "array successfully restored from array.txt\n";

        }else if(gozine == 0){
            break;
        }else{
            cout << "your choice is wrong!\n";
            continue;
        }

        
        cout << "gozine morede nazar ra vared konid:\n";
        cin >> gozine;
        
        }

        
        cout << "press any key to exit.";
        _getch();
        
    }


    


    




