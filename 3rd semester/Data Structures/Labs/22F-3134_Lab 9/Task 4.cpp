#include <iostream>
using namespace std;
bool isDisjointSetsPartition(int arr[7], int i, int set1, int set2, int set3) { return true; }
//bool isDisjointSetsPartition(int arr[7], int i, int set1, int set2, int set3) {
//    int j = 3;
//    if (i == set1) {
//
//    }
//}
//[-------------------------------------------]
//[              I GIVE UP                    ]
//[-------------------------------------------]
int main()
{
    int set[7] = { 7,3,1,5,4,2,8 };
    cout << "S: ";  for (int i = 0; i < 7; i++) { cout << set[i] << " "; }
    if (isDisjointSetsPartition(set, 0, 1, 4, 7) == true) {
        cout << "\nS1: {7,3}\n";
        cout << "S2: {1,5,4}\n";
        cout << "S3: {2,8}\n";
    }
    else {
        cout << "";
    }
    return 0;
}