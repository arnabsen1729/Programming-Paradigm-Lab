#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

template <typename T>
struct RSArray {
    int length, maxLength, populatedIndex;
    T defaultValue;
    T *data;
};

template <typename T1, typename T2>
void initialize(T1 &arr, int length, T2 defaultValue, int maxLength) {
    arr.maxLength = maxLength;
    arr.populatedIndex = -1;
    arr.length = length;
    arr.defaultValue = defaultValue;
    arr.data = new int[length];
    for (int i = 0; i < length; i++) {
        arr.data[i] = defaultValue;
    }
}

template <typename T1>
int inflate(T1 &arr) {
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

template <typename T1>
int addElem(T1 &arr, int value) {
    if (arr.populatedIndex + 1 == arr.maxLength) {
        // Error Condition hence returning 1 exit code
        cout << "Memory Limit Exceeded!!\n\n";
        return 1;
    } else if (arr.populatedIndex + 1 == arr.length) {
        inflate(arr);
    }
    arr.populatedIndex++;
    arr.data[arr.populatedIndex] = value;
    return 0;
}

template <typename T1>
int fetchElem(T1 &arr, int index) {
    if (index <= arr.populatedIndex)
        return arr.data[index];
    else {
        return arr.defaultValue;
    }
}

template <typename T1>
void resetElements(T1 &arr) {
    for (int i = 0; i <= arr.populatedIndex; i++)
        arr.data[i] = arr.defaultValue;
}

template <typename T1>
int getMaxSize(T1 &arr) {
    return arr.maxLength;
}

template <typename T1>
int getCount(T1 &arr) {
    return arr.populatedIndex + 1;
}

template <typename T1>
void displayArrayContents(T1 &arr) {
    for (int i = 0; i < arr.length; i++) {
        cout << arr.data[i] << ", ";
    }
    cout << "\n";
}
int main() {
    RSArray<int> obj;
    int len, def, maxSz;
    cout << "Enter size: ";
    cin >> len;
    cout << "Default value: ";
    cin >> def;
    cout << "Enter max size: ";
    cin >> maxSz;
    initialize(obj, len, def, maxSz);
    while (true) {
        cout << "\n-------------------\n";
        cout << "Enter options\n";
        cout << "1. Display elements\n";
        cout << "2. Append elements\n";
        cout << "3. Reset elements\n";
        cout << "4. Get max size\n";
        cout << "5. Get count\n";
        cout << "6. Fetch elements\n";
        int opt;
        cin >> opt;
        switch (opt) {
            case 1:
                displayArrayContents(obj);
                break;
            case 2:
                int val;
                cout << "Enter value to enter: ";
                cin >> val;
                addElem(obj, val);
                break;
            case 3:
                resetElements(obj);
                break;
            case 4:
                cout << "Max size of the RSA: " << getMaxSize(obj) << "\n";
                break;
            case 5:
                cout << "Cound: " << getCount(obj) << "\n";
                break;
            case 6:
                cout << "Enter the index you want to fetch: ";
                int index;
                cin >> index;
                cout << "Element: " << fetchElem(obj, index);
                break;
            default:
                return 0;
        }
    }
    return 0;
}
