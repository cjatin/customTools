#include "common.h"

using namespace std;

int main(int argc, char** argv) {
    if (argc < 2) {
        cout << "Insufficient arguments... bye" << endl;
    }
    string s(argv[1]);
    cout << convertToNum(s) << endl;
}
