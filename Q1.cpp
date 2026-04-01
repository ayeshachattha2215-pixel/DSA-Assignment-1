#include <iostream>
using namespace std;

// Recursive function for Tower of Hanoi
void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
    // Base case: if only 1 disk
    if (n == 1)
    {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }

    // Step 1: Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, destination, auxiliary);

    // Step 2: Move nth disk from source to destination
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;

    // Step 3: Move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main()
{
    int n;

    cout << "Enter number of disks: ";
    cin >> n;

    cout << "\nSequence of moves:\n";

    // A = Source, B = Auxiliary, C = Destination
    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}
