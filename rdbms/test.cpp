#include <iostream>
#include <fstream>
#include <boost/variant.hpp>
#include <boost/algorithm/string.hpp>
using namespace std;

int main(){
    string buff;
    ifstream inFile;
    string filepath = "/Users/yuki/Desktop/addressbook.csv";
    inFile.open(filepath, ios::in);
    inFile.seekg(8 , ios::beg);  // 跳过xefxbbxbf
    if(!inFile.is_open())
        cout << "Failed to open " << filepath << endl;
    cout << "File is open" << filepath << endl;

    while(inFile >> buff){
        cout << buff<<endl;
        vector<string> result;
        boost::trim(buff);
        boost::split(result, buff, boost::is_any_of(","));

        for(int i = 0 ; i< result.size(); i++)
            cout <<result[i]<<endl;
    }
}
