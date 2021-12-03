#include <iostream>
#include <stdio.h>
using namespace std;


int main(){

    int gozine,n,*array;

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
            

        }else if(gozine == 3){

        }else if(gozine == 4){
            
        }else if(gozine == 5){
            
        }else if(gozine == 6){
            
        }else if(gozine == 7){
            
        }else if(gozine == 0){
            break;
        }else{
            break;
        }

        
        cout << "gozine morede nazar ra vared konid:\n";
        cin >> gozine;
        
        }


        
        cout << "shoma az menu kharej shodid";
        cin.get();
        cin.get();
    }


    


    




