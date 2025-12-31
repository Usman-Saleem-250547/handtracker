#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    ofstream File("write.ppm");
    // header created
    File<<"P3\n"<<width<<" "<<height<<"\n255\n";
    // writing colors
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j % 3 == 0) File<<"255 0 0"<<endl; 
            if (j % 3 == 1) File<<"0 255 0"<<endl; 
            if (j % 3 == 2) File<<"0 0 255"<<endl; 
        }
    }
    File.close();
    return 0;
}