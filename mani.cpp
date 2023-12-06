#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Image.h"
using namespace std;

struct Header
{
    char idLength;
    char colorMapType;
    char dataTypeCode;
    short colorMapOrigin;
    short colorMapLength;
    char colorMapDepth;
    short xOrigin;
    short yOrigin;
    short width;
    short height;
    char bitsPerPixel;
    char imageDescriptor;
};

void Multiply(vector<Image> v1, vector<Image> v2, vector<int> image) {
    for (int i = 0; i < v1.size(); i++) {
        int blue;
        int green;
        int red;
        blue = (int)v1[i].blue * (int)v2[i].blue;
        green = (int)v1[i].green * (int)v2[i].green;
        red = (int)v1[i].red * (int)v2[i].red;
        if (blue > 255) {
            blue = 255;
        }
        else if (blue < 0) {
            blue = 0;
        }
        else if (green > 255) {
            green = 255;
        }
        else if (green < 0) {
            green = 0;
        }
        else if (red > 255) {
            green = 255;
        }
        else if (red < 0) {
            green = 0;
        }
        image.push_back(blue);
        image.push_back(green);
        image.push_back(red);
    }
    
}


int main() {
    cout << "Choose a task: \n";
    cout << "1" << endl;
    cout << "2" << endl;
    cout << "3" << endl;
    cout << "4" << endl;
    cout << "5" << endl;
    cout << "6" << endl;
    cout << "7" << endl;
    cout << "8" << endl;
    cout << "9" << endl;
    cout << "10" << endl;
    int option;
    cin >> option;

    cout << "" << endl;

    if (option == 1) {
        Header headerObject;
        ifstream inFile;
        inFile.open("input/layer1.tga");
        inFile.read(&headerObject.idLength, sizeof(headerObject.idLength));
        inFile.read(&headerObject.colorMapType, sizeof(headerObject.idLength));
        inFile.read(&headerObject.dataTypeCode, sizeof(headerObject.idLength));
        inFile.read((char*)&headerObject.colorMapOrigin, sizeof(headerObject.colorMapOrigin));
        inFile.read((char*)&headerObject.colorMapLength, sizeof(headerObject.colorMapLength));
        inFile.read(&headerObject.colorMapDepth, sizeof(headerObject.idLength));
        inFile.read((char*)&headerObject.xOrigin, sizeof(headerObject.xOrigin));
        inFile.read((char*)&headerObject.yOrigin, sizeof(headerObject.yOrigin));
        inFile.read((char*)&headerObject.width, sizeof(headerObject.width));
        inFile.read((char*)&headerObject.height, sizeof(headerObject.height));
        inFile.read(&headerObject.bitsPerPixel, sizeof(headerObject.idLength));
        inFile.read(&headerObject.imageDescriptor, sizeof(headerObject.idLength));

        cout << (int)headerObject.idLength << endl;
        unsigned int imageLoop = headerObject.width * headerObject.height;
        
        
        vector<Image> pixelList;

        Image pixels(0, 0, 0);
        for (unsigned int i = 0; i < imageLoop; i += 3) {
            inFile.read((char*)&pixels.blue, sizeof(pixels.blue));
            inFile.read((char*)&pixels.green, sizeof(pixels.green));
            inFile.read((char*)&pixels.red, sizeof(pixels.red));
            pixelList.push_back(pixels);
        }

        inFile.close();
        inFile.clear();


        Header headerObject2;
        inFile.open("input/pattern1.tga");
        inFile.read(&headerObject2.idLength, sizeof(headerObject2.idLength));
        inFile.read(&headerObject2.colorMapType, sizeof(headerObject2.idLength));
        inFile.read(&headerObject2.dataTypeCode, sizeof(headerObject2.idLength));
        inFile.read((char*)&headerObject2.colorMapOrigin, sizeof(headerObject2.colorMapOrigin));
        inFile.read((char*)&headerObject2.colorMapLength, sizeof(headerObject2.colorMapLength));
        inFile.read(&headerObject2.colorMapDepth, sizeof(headerObject2.idLength));
        inFile.read((char*)&headerObject2.xOrigin, sizeof(headerObject2.xOrigin));
        inFile.read((char*)&headerObject2.yOrigin, sizeof(headerObject2.yOrigin));
        inFile.read((char*)&headerObject2.width, sizeof(headerObject2.width));
        inFile.read((char*)&headerObject2.height, sizeof(headerObject2.height));
        inFile.read(&headerObject2.bitsPerPixel, sizeof(headerObject2.idLength));
        inFile.read(&headerObject2.imageDescriptor, sizeof(headerObject2.idLength));

        vector<Image> pixelList2;
        unsigned int imageLoop2 = headerObject2.width * headerObject2.height;
        Image pixels2(0, 0, 0);
        for (unsigned int i = 0; i < imageLoop2; i += 3) {
            inFile.read((char*)&pixels2.blue, sizeof(pixels.blue));
            inFile.read((char*)&pixels2.green, sizeof(pixels.green));
            inFile.read((char*)&pixels2.red, sizeof(pixels.red));
            pixelList2.push_back(pixels2);
        }

        inFile.close();
        inFile.clear();

        vector<int> image;
        ofstream file("output/output.tga", ios_base::binary);
        file.open("output/output.tga");        
        file.write(&headerObject.idLength, sizeof(headerObject.idLength));        
        file.write(&headerObject.colorMapType, sizeof(headerObject.colorMapType));       
        file.write(&headerObject.dataTypeCode, sizeof(headerObject.dataTypeCode));       
        file.write((char*)headerObject.colorMapOrigin, sizeof(headerObject.colorMapOrigin));        
        file.write((char*)headerObject.colorMapLength, sizeof(headerObject.colorMapLength));        
        file.write(&headerObject.colorMapDepth, sizeof(headerObject.colorMapDepth));        
        file.write((char*)headerObject.xOrigin, sizeof(headerObject.xOrigin));        
        file.write((char*)headerObject.yOrigin, sizeof(headerObject.yOrigin));       
        file.write((char*)headerObject.width, sizeof(headerObject.width));        
        file.write((char*)headerObject.height, sizeof(headerObject.height));       
        file.write(&headerObject.bitsPerPixel, sizeof(headerObject.bitsPerPixel));       
        file.write(&headerObject.imageDescriptor, sizeof(headerObject.imageDescriptor));
        
        
        

        file.close();
    }
}

