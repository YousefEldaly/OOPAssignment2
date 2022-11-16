//#include <windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>


using namespace std;

class process
{
public:
    vector<string> LinesFromtextFile;
};


void swap(string& x, string& y) {
    string temp;
    temp = x;
    x = y;
    y = temp;
}

void sort_name(vector<string>& vs) {
    int n = vs.size() + 2;
    for (int i = 2; i < n; i++) {
        for (int j = 3; j < n - i - 1; j++) {
            if ((vs[j][0] > vs[j + 1][0]) || (vs[j][0] > vs[j + 1][0] + 32) /* && !(vs[j][0] == vs[j + 1][0] + 32) && !(vs[j][0] + 32 == vs[j + 1][0])*/) {
                swap(vs[j], vs[j + 1]);
            }
        }
    }
}
int pid(string l) {
    stringstream ss;
    /* Storing the whole string into string stream */
    ss << l;
    /* Running loop till the end of the stream */
    string temp;
    int found;
    while (!ss.eof()) {
        /* extracting word by word from stream */
        ss >> temp;
        /* Checking the given word is integer or not */
        if (stringstream(temp) >> found) return found;
    }
}
void sort_pid(vector<string>& vs) {
    int n = vs.size() + 2;
    for (int i = 2; i < n; i++) {
        for (int j = 3; j < n - i - 1; j++) {
            if (pid(vs[j]) > pid(vs[j + 1])) {
                swap(vs[j], vs[j + 1]);
            }
        }
    }
}


class process_list : public process
{
public:

    void fill()
    {
        int j = 0;
        char* cmd = new char[256];
        string line;
        //string fileName ="";
        // copies a single character for a specified number of times to an object.
        memset(cmd, ' ', sizeof(cmd));
        //copy one string to another as char array
        strcpy_s(cmd
            , strlen("tasklist > tasklist.txt") + 1, "tasklist > tasklist.txt");

        // not work in VS
        //strcpy(cmd, "tasklist > tasklist.txt");

        //cout << "\n\n" << cmd << "\n\n";

        // launch tasklist from visual c++
        system(cmd);

        //open text file tasklist.txt
        ifstream TextFile("tasklist.txt");

        // store lines from textfile into vector
        while (getline(TextFile, line)) {
            LinesFromtextFile.push_back(line);
            LinesFromtextFile[j] += "\n";
            j++;
        }
        TextFile.close();
        delete[] cmd;


    }

    void display_s_name() {
        sort_name(LinesFromtextFile);
        for (string h : LinesFromtextFile) cout << h;
    }

    void display_s_pid() {
        sort_pid(LinesFromtextFile);
        for (string h : LinesFromtextFile) cout << h;
    }
};

int main() {
    process_list p1;
    p1.fill();
    p1.display_s_name();
    p1.display_s_pid();
}
