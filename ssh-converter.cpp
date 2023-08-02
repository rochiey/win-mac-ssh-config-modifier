#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    string username;
    cout << "Enter your username: ";
    cin >> username;

    string path = "C:\\Users\\" + username + "\\.ssh\\config";
    string tempPath = "C:\\Users\\" + username + "\\Desktop\\config";
    string search = "C:\\Users\\" + username;
    string replace = "~";

    ifstream file(path);
    ofstream temp(tempPath);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            while (line.find(search) != string::npos) {
                line.replace(line.find(search), search.length(), replace);
            }
            temp << line << endl;
        }
    }

    file.close();
    temp.close();

    return 0;
}