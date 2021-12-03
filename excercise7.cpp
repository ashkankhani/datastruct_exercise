#include <iostream>
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

void selection_sort(int *array,int n){
    int temp;
        for(int i = 0;i<n-1;i++){
            for(int j = i + 1;j<n;j++){
                if(array[j] > array[i]){
                    temp = array[j];
                    array[j] = array[i];
                    array[i] = temp;
                    
                }
            }
        }
}

int binary_search(int *array , int n , int number){
    int mid , b=0 , e=n-1;
    mid = (b + e)/2;

    while(b <= e && array[mid] != number){
        if(number > array[mid]){
            e = mid - 1;
        }else{
            b = mid + 1;
        }
        mid = (b + e)/2;
    }
    if(array[mid] == number){
        return mid;
    }
    return -1;


}

int main(){

    int n,*array,number;
    array = new int[n];

    array = input_array(array , n);
    selection_sort(array , n);
    cout << "array after sort:\n";
    display_array(array , n);
    cout << "\nenter a number witch you want to find:\n";
    cin >> number;
    int res = binary_search(array , n , number);
    if(res != -1){
        cout << "the index of the element is: "<<res;
    }else{
        cout << "element not found!";
    }

    cout << "\npress any key to exit!";
    _getch();




}