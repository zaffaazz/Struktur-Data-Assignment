#include <iostream>
using namespace std;
 
int main(){
    //Aray 1 dimensi 
    int arrID[5] = {10,20,30,40,50};
    cout << "Array 1 Dimensi:"<< endl;
    for (int i = 0; i < 5; i++){
        cout << "arr1D[" << i << "] = "<< arrID[i] << endl;
    }
    cout << endl;

    // Array 2 DimensI
    int arr2D[2][3] = {
        {1,2,3},
        {4,5,6}
    };
    cout << "Array 2 Dimensi:" << endl;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            cout << "arr2D[" << i << "]["<< j << "] =" << arr2D[i][j]
            << " ";
        }
        cout << endl;
    }
    cout << endl;


// array multi dimensi 
int arr3D[2][3][3] = {
    { {1,2,3}, {4,5,6}},
    { {7,8,9}, {10,11,12}}
};
cout << "Array 3 Dimensi:" << endl;
for (int i = 0; i < 2; i++) {
    for (int j = 0; j  < 2; j++) {
        for ( int k = 0; k < 3; k++){
            cout <<"arr3D[" << i << "]["<< j<<"]["
            << k << "] = "<<arr3D[i][j][k] <<  endl;
        }
    }
}
 return 0;
}


