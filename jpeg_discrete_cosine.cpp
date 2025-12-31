#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// taking spatial frequency
float alpha(int freq) {
    if (freq == 0) return 1.0 / sqrt(2);
    else return 1;
}

void printArr(int arr[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

void printArr(float arr[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int arr[8][8];
    float G[8][8], sum = 0;
    const int PI = 3.14;
    int midpoint = 128;
    ifstream File("jpeg_discrete_cosine.txt");
    //values are shifted from a positive range to one centered on zero
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            File>>arr[i][j];
            arr[i][j] -= midpoint;
        }
    }
    printArr(arr);
    //discrete cosine transformation
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            // summation
            for (int x = 0; x < 8; x++) {
                for (int y = 0; y < 8; y++) {
                    sum += arr[x][y] * cos((2.0 * x + 1) * i * PI / 16.0) * cos((2.0 * y + 1) * j * PI / 16.0); 
                }
            }
            G[i][j] = 0.25 * alpha(i) * alpha(j) * sum;
            sum = 0;
        }
    }
    printArr(G);
    File.close();
    return 0;
}