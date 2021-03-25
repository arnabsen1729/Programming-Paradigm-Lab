#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

class RSArray {
   private:
    int length, maxLength, populatedIndex;
    int defaultValue;
    int *data;

   public:
    RSArray() {
        length = 0;
        maxLength = 0;
        populatedIndex = -1;
        defaultValue = 0;
        data = nullptr;
    }
    RSArray(int len, int def, int maxl) {
        maxLength = maxl;
        populatedIndex = -1;
        length = len;
        defaultValue = def;
        data = new int[length];
        for (int i = 0; i < length; i++) {
            data[i] = defaultValue;
        }
    }

    RSArray(RSArray &array) {
        length = array.length;
        maxLength = array.maxLength;
        populatedIndex = array.populatedIndex;
        data = new int[array.length];
        for (int i = 0; i < length; i++) {
            data[i] = array.data[i];
        }
    }

    RSArray &operator=(const RSArray &t);

    ~RSArray() { delete data; }

    void inflate();
    int addElem();
    int fetchElem();
    void resetElements();
    void getMaxSize();
    void getCount();
    void displayArrayContents();
};

RSArray &RSArray::operator=(const RSArray &rhs) {
    if (this == &rhs) return *this;
    delete data;
    length = rhs.length;
    maxLength = rhs.maxLength;
    populatedIndex = rhs.populatedIndex;
    defaultValue = rhs.defaultValue;
    data = new int[length];
    for (int i = 0; i < length; i++) {
        data[i] = rhs.data[i];
    }

    return *this;
}

void RSArray::inflate() {
    if (length == maxLength) {
        cout << "Max Limit reached!";
    }
    int newSize = min(2 * length, maxLength);
    cout << "Inflating array size to: " << newSize << "\n";
    int *newArr = new int[newSize];
    for (int i = 0; i <= populatedIndex; i++) {
        newArr[i] = data[i];
    }
    length = newSize;
    for (int i = populatedIndex + 1; i < length; i++) {
        newArr[i] = defaultValue;
    }
    int *temp = data;
    data = newArr;
    delete temp;
    temp = NULL;
}

int RSArray::addElem() {
    int value;
    cout << "Enter value: ";
    cin >> value;
    if (populatedIndex + 1 == maxLength) {
        // Error Condition hence returning 1 exit code
        cout << "Memory Limit Exceeded!!";
        return 1;
    } else if (populatedIndex + 1 == length) {
        inflate();
    }
    populatedIndex++;
    data[populatedIndex] = value;
    return 0;
}

int RSArray::fetchElem() {
    int index;
    cout << "Enter index: ";
    cin >> index;
    if (index <= populatedIndex)
        return data[index];
    else {
        cout << "Memory Limit Exceeded!!";
        return defaultValue;
    }
}

void RSArray::resetElements() {
    for (int i = 0; i <= populatedIndex; i++) data[i] = defaultValue;
}

void RSArray::getMaxSize() { cout << "Max Length: " << maxLength << "\n"; }

void RSArray::getCount() { cout << "Count: " << populatedIndex << "\n"; }

void RSArray::displayArrayContents() {
    for (int i = 0; i < length; i++) {
        cout << data[i] << ", ";
    }
    cout << "\n";
}

void displayOptions() {
    cout << "Enter options: \n";
    cout << "1. Add element\n";
    cout << "2. Inflate RSA\n";
    cout << "3. Fetch element\n";
    cout << "4. Reset RSA\n";
    cout << "5. Get max size\n";
    cout << "6. Get count\n";
    cout << "7. Display contents\n";
    cout << "8. Copy to another RSArray\n";
    cout << "9. Exit\n";

    cout << "\nChoice: ";
}

int main() {
    int len, def, maxL;
    cout << "Enter length: ";
    cin >> len;
    cout << "Enter default value: ";
    cin >> def;
    cout << "Enter max size: ";
    cin >> maxL;

    RSArray obj(len, def, maxL);
    while (1) {
        displayOptions();
        RSArray temp;
        int c;
        cin >> c;
        switch (c) {
            case 1:
                obj.addElem();
                break;
            case 2:
                obj.inflate();
                break;
            case 3:
                obj.fetchElem();
                break;
            case 4:
                obj.resetElements();
                break;
            case 5:
                obj.getMaxSize();
                break;
            case 6:
                obj.getCount();
                break;
            case 7:
                obj.displayArrayContents();
                break;
            case 8:
                temp = obj;
                temp.displayArrayContents();
                break;
            default:
                return 0;
        }
    }
    return 0;
}
