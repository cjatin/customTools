#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// Config
string fileName = ".state.config";

void writeFile(size_t numOfStates, vector<string> &v, size_t currentState) {
    ofstream file;
    file.open(fileName);
    file << numOfStates << '\n';
    for(auto i: v) {
            file << i << '\n';
    }
    file << currentState << '\n';
    file.close();
}

void setup() {
    size_t numOfStates;
    cout << "\nEnter the number of States:: ";
    cin >> numOfStates;
    vector<string> v;
    v.reserve(numOfStates);
    for(size_t i = 0; i< numOfStates; i++) {
        string str;
        cout << "Enter " << i+1 << " State Name:: ";
        cin >> str;
        v.push_back(str);
    }
    writeFile(numOfStates, v, 0);
}

void readFile(size_t& numOfStates, vector<string>& v, size_t& currentState) {
    ifstream file(fileName);
    string line;
    if (!getline(file, line)) {
        cout << "File " << fileName << " Not Present, rerun setup\n";
        exit(1);
    }
    numOfStates = stoi(line);
    for (size_t i = 0; i < numOfStates; i++) {
        if (!getline(file, line)) {
            cout << "Invalid Config, rerun setup\n";
            exit(1);
        }
        v.push_back(line);
    }
    if (!getline(file, line)) {
        cout << "Current State Not Present, rerun setup\n";
        exit(1);
    }
    currentState = stoi(line);
    file.close();
}

void showCurrentState() {
    size_t num, curr;
    vector<string> v;
    readFile(num, v, curr);
    cout << "Current Task:: " << v[curr] << std::endl;
}

void next() {
    size_t num, curr;
    vector<string> v;
    readFile(num, v, curr);
    cout << "State:: " << v[curr] << " - Done" << endl;
    if ((num - 1) == curr) {
        cout<< "All States done, restarting...\n";
        curr = 0;
    } else {
        curr++;
    }
    cout << "Now working on:: " << v[curr] << endl;
    writeFile(num, v, curr);
}

void back() {
    size_t num, curr;
    vector<string> v;
    readFile(num, v, curr);
    curr--;
    if(curr > num) {
        cout << "Already in first state... going back to laste state\n";
        curr = num - 1;
    }
    cout << "Now working on:: " << v[curr] << endl;
    writeFile(num, v, curr);
}

void showall() {
    size_t num, curr;
    vector<string> v;
    readFile(num, v, curr);
    cout << "Done::\n";
    for (size_t i = 0; i < curr; i++) {
        cout << v[i] << endl;
    }
    cout << "Current:: \n" << v[curr] << '\n';
    cout << "Pending:: \n";
    for (size_t i = curr + 1; i < num; i++) {
        cout << v[i] << endl;
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        cout<<"Invalid number of args.\n";
        exit(1);
    }
    string s(argv[1]);
    if (s == "setup") {
        setup();
    } else if (s == "next") {
        next();
    } else if (s == "back") {
        back();
    } else if (s == "show") {
        showCurrentState();
    } else if(s == "showall") {
        showall();
    } else {
        cout<< "Valid commands:: \n\tsetup\n\tnext\n\tback\n\tshow\n\tshowall\n";
    }
    return 0;
}
