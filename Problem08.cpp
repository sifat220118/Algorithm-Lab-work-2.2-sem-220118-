#include <iostream>
using namespace std;


void towerOfHanoi(int n, char from_peg, char to_peg, char aux_peg) {
    if (n == 1) {
        cout << "Move disk 1 from peg " << from_peg << " to peg " << to_peg << endl;
        return;
    }
    towerOfHanoi(n - 1, from_peg, aux_peg, to_peg)
    cout << "Move disk " << n << " from peg " << from_peg << " to peg " << to_peg << endl;
    towerOfHanoi(n - 1, aux_peg, to_peg, from_peg);
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}

