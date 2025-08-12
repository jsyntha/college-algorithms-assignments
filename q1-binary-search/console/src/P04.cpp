#include <iostream>
#include <string>
using namespace std;

// TO DO
// search bv name (NEED TO ADD CASE SENSITIVTY)

// Optional
// output position of found name
// let user enter multiple searches until they choose to stop
// GUI :)

struct ListType {
    string info[100];
    int length = 1;
};

void BinarySearch(ListType list, string& item, bool& found, int& position)
{
    int midPoint;
    int first = 0;
    int last = list.length - 1;
    bool moreToSearch = first <= last;
    found = false;
    int splitCount = 0;

    while (moreToSearch && !found)
    {
        midPoint = (first + last) / 2;
        splitCount++;

        cout << "Split Count: " << splitCount << endl;

        if (item < list.info[midPoint])
        {
            last = midPoint - 1;
            moreToSearch = first <= last;
        }
        else if (item > list.info[midPoint])
        {
            first = midPoint + 1;
            moreToSearch = first <= last;
        }
        else
        {
            item = list.info[midPoint];
            found = true;
            //int& position = midPoint;
            position = midPoint;
        }
    }
}

int main() {
    string size[] = { "Jon", "Dot", "Eva", "Guy", "Jan", "Tom", "Jim", "Ann", "Kim", "Ron", "Tim", "Kay", "Amy" };

    ListType list;
    list.length = sizeof(size) / sizeof(size[0]);

    for (int i = 0; i < list.length - 1; i++) {
        for (int j = 0; j < list.length - i - 1; j++) {
            if (size[j] > size[j + 1]) {
                string temp = size[j];
                size[j] = size[j + 1];
                size[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < list.length; i++) {
        list.info[i] = size[i];
    }

    cout << "Sorted names: ";
    for (int i = 0; i < list.length; i++) {
        cout << list.info[i] << " ";
    }
    cout << endl;
    cout << endl;

    while (true) {
        string searchInput;

        cout << endl;
        cout << "Enter a name to search for: " << endl;
        cout << "Enter '!' to quit\n\n";
        cin >> searchInput;
        if (searchInput == "!") break;

        bool found;
        int position;
        BinarySearch(list, searchInput, found, position);

        if (found) {
            cout << "Name found: " << searchInput << endl;
            // ADD POSITION COUNTER HERE
            cout << "Position: " << position << endl;
        }
        else {
            cout << "Name not found" << endl;
        }
    }
    return 0;
}
