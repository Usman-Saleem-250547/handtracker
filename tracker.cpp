#include<iostream>
#include<fstream>
using namespace std;
int main() {
    ifstream inHand("./resources/hand5.ppm");
    ofstream outHand("./resources/output.ppm");
    if (!inHand) { 
        cout << "Input file not found. Inappropriate output will be given." << endl;
        return 0;   
    }
    string fileType;
    int width, height, max_rgb;
    inHand >> fileType >> width >> height >> max_rgb;
    // running some checks
    if (fileType != "P3" || width < 0 || height < 0 || max_rgb < 0 || max_rgb > 255) {
        cout << "Errors in headers of .ppm file" << endl;
        return 0;
    }
    outHand << fileType << endl << width << " " << height << endl << max_rgb << endl; // printing header in output
    unsigned short int colors[height][width][3];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            inHand >> colors[y][x][0] >> colors[y][x][1] >> colors[y][x][2];
            // colors[y][x][2] -= 20;
            if (colors[y][x][0] >= 120 && colors[y][x][1] >= 85 && colors[y][x][1] <= 160 && colors[y][x][2] >= 60 && colors[y][x][2] <= 160 && colors[y][x][0] > colors[y][x][1] * 1.10) {// && colors[y][x][0] > colors[y][x][2]) {
                colors[y][x][0] = 0;
                colors[y][x][1] = 0;
                colors[y][x][2] = 0;
            } else {
                colors[y][x][0] = 255;
                colors[y][x][1] = 255;
                colors[y][x][2] = 255;
            }
            // printing pixels
            outHand << colors[y][x][0] << " " << colors[y][x][1] << " " << colors[y][x][2] << " ";
        }
    }
    inHand.close();
    outHand.close();
    cout << "Successful";
    return 0;
}