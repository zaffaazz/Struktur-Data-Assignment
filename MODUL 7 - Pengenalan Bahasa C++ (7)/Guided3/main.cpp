#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    stackTable S;
    createStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);

    cout << "[TOP] ";
    view(S);
    
    cout << "balik stack" << endl;
    balikStack(S);

    cout << "[TOP] ";
    view(S);

    return 0;
}
