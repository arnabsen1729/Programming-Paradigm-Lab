#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

struct RSArray {
    int length, maxLength, populatedIndex;
    int defaultValue;
    int *data;
};

void initialize(RSArray &arr, int length, int defaultValue = 0,
                int maxLength = MAX_SIZE) {
    arr.maxLength = maxLength;
    arr.populatedIndex = -1;
    arr.length = length;
    arr.defaultValue = defaultValue;
    arr.data = new int[length];
    for (int i = 0; i < length; i++) {
        arr.data[i] = defaultValue;
    }
}

int inflate(RSArray &arr) {
    if (arr.length == arr.maxLength) {
        cout << "Max Limit reached!";
        return 1;
    }
    int newSize = min(2 * arr.length, arr.maxLength);
    cout << "Inflating array size to: " << newSize << "\n";
    int *newArr = new int[newSize];
    for (int i = 0; i <= arr.populatedIndex; i++) {
        newArr[i] = arr.data[i];
    }
    arr.length = newSize;
    for (int i = arr.populatedIndex + 1; i < arr.length; i++) {
        newArr[i] = arr.defaultValue;
    }
    int *temp = arr.data;
    arr.data = newArr;
    delete temp;
    temp = NULL;

    return 0;
}

int addElem(RSArray &arr, int value) {
    if (arr.populatedIndex + 1 == arr.maxLength) {
        // Error Condition hence returning 1 exit code
        cout << "Memory Limit Exceeded!!";
        return 1;
    } else if (arr.populatedIndex + 1 == arr.length) {
        inflate(arr);
    }
    arr.populatedIndex++;
    arr.data[arr.populatedIndex] = value;
    return 0;
}

int fetchElem(RSArray &arr, int index) {
    if (index <= arr.populatedIndex)
        return arr.data[index];
    else {
        cout << "Memory Limit Exceeded!!";
        return arr.defaultValue;
    }
}

void resetElements(RSArray &arr) {
    for (int i = 0; i <= arr.populatedIndex; i++)
        arr.data[i] = arr.defaultValue;
}

int getMaxSize(RSArray &arr) { return arr.maxLength; }

int getCount(RSArray &arr) { return arr.populatedIndex + 1; }

void displayArrayContents(RSArray &arr) {
    for (int i = 0; i < arr.length; i++) {
        cout << arr.data[i] << ", ";
    }
    cout << "\n";
}
int main() {
    RSArray obj;
    cout << "Initialising...\nlength: 2\ndefault: -1\n";
    initialize(obj, 2, -1);
    cout << "\n";
    cout << "Current array contents:\n";
    displayArrayContents(obj);
    cout << "\n";
    cout << "Adding element value: 2\n";
    addElem(obj, 2);
    cout << "\n";
    cout << "Current array contents:\n";
    displayArrayContents(obj);
    cout << "\n";
    cout << "Adding element value: 1\n";
    addElem(obj, 1);
    cout << "\n";
    cout << "Current array contents:\n";
    displayArrayContents(obj);
    cout << "\n";
    cout << "Trying to overflow the current size...\n\nAdding element value: "
            "1\n";
    addElem(obj, 1);
    cout << "\n";
    cout << "Current array contents:\n";
    displayArrayContents(obj);
    cout << "\n";

    cout << "Reseting elements\n";
    resetElements(obj);
    cout << "Current array contents:\n";
    displayArrayContents(obj);
    cout << "\n";
    cout << "Max Size: " << getMaxSize(obj) << "\n";
    cout << "Elements Count: " << getCount(obj) << "\n";
    cout << "Fetching element at position 1: " << fetchElem(obj, 1) << "\n";

    cout << "\n\n-: DEMONSTRATING MULTIPLE RSARRAY:-\n\n";
    RSArray obj1, obj2;

    cout << "Initialising...\n\n";

    cout << "RSArray1: \nlength=2\ndefault=0\nmax-size=5\n";
    initialize(obj1, 4, 0);
    cout << "Current array contents of RSArray1\n";
    displayArrayContents(obj1);
    cout << "\n";
    cout << "RSArray2: \nlength=3\ndefault=-1\nmax-size=10\n";
    initialize(obj2, 3, -1, 10);
    cout << "Current array contents of RSArray1\n";
    displayArrayContents(obj2);
    cout << "\n";
    cout << "\nAdding element value: 1 in RSArray1\n";
    addElem(obj1, 1);
    cout << "Current array contents of RSArray1\n";
    displayArrayContents(obj1);

    cout << "\nAdding element value: 2 in RSArray2\n";
    addElem(obj1, 2);
    cout << "Current array contents of RSArray2\n";
    displayArrayContents(obj1);

    return 0;
}
