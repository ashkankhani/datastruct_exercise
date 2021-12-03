#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;


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
            cout << "enter the length of array(max = 50):\n";
            cin >> n;
            while(n > 50 || n <=0){
                cout << "enter the length of array(min = 1 & max = 50):\n";
                cin >> n;
            }
            array = new int [n];

            for(int i = 0;i<n;i++){
                printf("enter array[%d]: ",(i+1));
                cin >> array[i];
            }
            cout << "your array is:\n";
            for(int i = 0;i<n;i++){
                cout << array[i] << " ";
            }
            cout << "\narray is ready for use ;)\n";



        }else if(gozine == 2){
            int number,index;
            cout << "enter a number witch you want to insert into array:\n";
            cin >> number;
            cout << "enter an index for insertion:\n";
            cin >> index;
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
            array = new_array;
            cout << "new array is:\n";
            for(int i = 0;i<n;i++){
                cout << array[i] << " ";
            }
            cout << "\nnew array is ready for use ;)\n";

        }else if(gozine == 3){
            int index , * new_array;
            cout << "enter a index witch you need to be deleted:\n";
            cin >> index;
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
            array = new_array;
            cout << "new array is:\n";
            for(int i = 0;i<n;i++){
                cout << array[i] << " ";
            }
            cout << "\narray is ready for use ;)\n";


        }else if(gozine == 4){
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
            cout << "sorted array = \n";
            for(int i = 0;i<n;i++){
                cout << array[i] << " ";
            }
            cout << "\narray is ready for use ;)\n";

        
            
        }else if(gozine == 5){
            cout << "your array is:\n";
            for(int i = 0;i<n;i++){
                cout << array[i] << " ";
            }
            cout << endl;
            
        }else if(gozine == 6){
            ofstream myfile;
            myfile.open("array.txt",ios::out);
            if(myfile.is_open()){
                myfile << n << endl;
                for(int i = 0;i<n;i++){
                    myfile << array[i] << endl;
                }
                myfile.close();
            }
        }else if(gozine == 7){
            ifstream myfile("array.txt");
            string line;
            myfile >> n;
            int i = 0;
            delete[] array;
            array = new int[n];
            while(getline(myfile,line)){
                myfile >> array[i++];
            }
            
        }else if(gozine == 0){
            break;
        }else{
            continue;
        }

        
        cout << "gozine morede nazar ra vared konid:\n";
        cin >> gozine;
        
        }


        
        cout << "shoma az menu kharej shodid";
        cin.get();
        cin.get();
    }


    


    




