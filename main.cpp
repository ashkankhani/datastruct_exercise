#include <iostream>

using namespace std;


int main(){

    int gozine,n;

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

        switch (gozine)
        {
        case 1:
            //array input
            break;
        case 2:
            //darj
            break;
        case 3:
            //hazf
            break;
        case 4:
            //sorting
            break;
        case 5:
            //display array
            break;
        case 6:
            //save array
            break;
        case 7:
            //restore array
            break;
        case 0:
            //exit
            break;
        
        default:
            //wrong choice
            break;
        }






        cout << "gozine morede nazar ra vared konid:\n";
        cin >> gozine;
    }


    cout << "shoma az menu kharej shodid";
    cin.get();
    cin.get();


    




}