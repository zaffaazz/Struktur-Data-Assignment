#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    stackTable S;
    createStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    cout << "[TOP] ";
    view(S);

    cout << "balik stack" << endl;
    balikStack(S);

    cout << "[TOP] ";
    view(S);

    return 0;
}
