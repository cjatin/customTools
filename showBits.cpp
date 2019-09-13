#include "common.h"

using namespace std;

int main(int argc, char** argv) {
    int a = 0x1;
    int b = 12;//0x1 << (sizeof(int) - 1);
    if (argc < 2) {
        cout << "Insufficient arguments... bye" << endl;
    }
    string s(argv[1]);
    a = stoi(s);
    vector<int> v;
    v.reserve(sizeof(int)*8);
    showBits(a, v);
    printBits(v);
    v.clear();
}
