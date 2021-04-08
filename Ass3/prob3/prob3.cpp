#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

struct person {
    string name;
    int age;
};

template <typename T>
class RSArray {
   private:
    int length, maxLength, populatedIndex;
    T defaultValue;
    T *data;

   public:
    RSArray(int len, T def, int maxl) {
        maxLength = maxl;
        populatedIndex = -1;
        length = len;
        defaultValue = def;
        data = new T[length];
        for (int i = 0; i < length; i++) {
            data[i] = defaultValue;
        }
    }

    RSArray(RSArray &array) {
        length = array.length;
        maxLength = array.maxLength;
        populatedIndex = array.populatedIndex;
        data = new T[array.length];
        for (int i = 0; i < length; i++) {
            data[i] = array.data[i];
        }
    }

    void inflate();
    int addElem(T);
    T *getData();
    int getLength();
    T fetchElem();
    void resetElements();
    void getMaxSize();
    void getCount();
    void displayArrayContents();
};

template <typename T>
T *RSArray<T>::getData() {
    return data;
}

template <typename T>
int RSArray<T>::getLength() {
    return length;
}

template <typename T>
void RSArray<T>::inflate() {
    if (length == maxLength) {
        cout << "Max Limit reached!";
        return;
    }
    int newSize = min(2 * length, maxLength);
    cout << "Inflating array size to: " << newSize << "\n";
    T *newArr = new T[newSize];
    for (int i = 0; i <= populatedIndex; i++) {
        newArr[i] = data[i];
    }
    length = newSize;
    for (int i = populatedIndex + 1; i < length; i++) {
        newArr[i] = defaultValue;
    }
    T *temp = data;
    data = newArr;
    delete temp;
    temp = NULL;
}

template <typename T>
int RSArray<T>::addElem(T value) {
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

template <typename T>
T RSArray<T>::fetchElem() {
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

template <typename T>
void RSArray<T>::resetElements() {
    for (int i = 0; i <= populatedIndex; i++) data[i] = defaultValue;
}

template <typename T>
void RSArray<T>::getMaxSize() {
    cout << "Max Length: " << maxLength << "\n";
}

template <typename T>
void RSArray<T>::getCount() {
    cout << "Count: " << populatedIndex + 1 << "\n";
}

void displayArrayContents(RSArray<person> obj) {
    cout << "\n [ DISPLAYING RARRAY ] \n\n";
    for (int i = 0; i < obj.getLength(); i++) {
        cout << "Name: " << obj.getData()[i].name
             << " \t Age:" << obj.getData()[i].age << "\n";
    }
    cout << "\n";
}

template <typename T>
void displayArrayContents(T obj) {
    cout << "\n [ DISPLAYING RARRAY ] \n\n";
    for (int i = 0; i < obj.getLength(); i++) {
        cout << obj.getData()[i] << ", ";
    }
    cout << "\n";
}

void displayData(person obj) {
    cout << "\n [ DISPLAYING DATA ] \n\n";
    cout << "Name: " << obj.name << " \t Age:" << obj.age << "\n";
}

template <typename T>
void displayData(T obj) {
    cout << "\n [ DISPLAYING DATA ] \n\n";
    cout << obj << " ";
}

void displayOptions() {
    cout << "\n--------------------\n";
    cout << " [ ENTER OPTIONS ] \n\n";
    cout << "1. Add element\n";
    cout << "2. Inflate RSA\n";
    cout << "3. Fetch element\n";
    cout << "4. Reset RSA\n";
    cout << "5. Get max size\n";
    cout << "6. Get count\n";
    cout << "7. Display contents\n";
    cout << "8. Exit\n";

    cout << "\nChoice: ";
}

void userInput(person &value) {
    cout << "\n [ ENTER VALUE ] \n\n";
    cout << "Name: ";
    cin >> value.name;
    cout << "Age: ";
    cin >> value.age;
}

template <typename T>
void userInput(T &value) {
    cout << "\n [ ENTER VALUE ] \n\n";
    cin >> value;
}

template <typename T>
void driverFn(RSArray<T> &obj) {
    while (1) {
        displayOptions();
        int c;
        cin >> c;
        switch (c) {
            case 1: {
                T value;
                userInput(value);
                obj.addElem(value);
                break;
            }
            case 2: {
                obj.inflate();
                break;
            }
            case 3: {
                displayData(obj.fetchElem());
                break;
            }
            case 4: {
                obj.resetElements();
                break;
            }
            case 5: {
                obj.getMaxSize();
                break;
            }
            case 6: {
                obj.getCount();
                break;
            }
            case 7: {
                displayArrayContents(obj);
                break;
            }
            default:
                return;
        }
    }
    return;
}

int main() {
    cout << " [ CHOOSE DATA TYPE ]\n\n";
    cout << "1. Int\n";
    cout << "2. Float\n";
    cout << "3. Struct\n";
    int opt;
    cin >> opt;
    int len, maxL;
    cout << "Enter length: ";
    cin >> len;
    cout << "Enter max size: ";
    cin >> maxL;
    if (opt == 1) {
        int def;
        cout << "\n [ ENTER DEFAULT VALUE ] \n\n";
        cin >> def;
        RSArray<int> obj(len, def, maxL);
        driverFn(obj);
    } else if (opt == 2) {
        float def;
        cout << "Enter default value: \n";
        cin >> def;
        RSArray<float> obj(len, def, maxL);
        driverFn(obj);
    } else if (opt == 3) {
        person def;
        cout << "Enter default struct value: \n";
        cout << "Name: ";
        cin >> def.name;
        cout << "Age: ";
        cin >> def.age;
        RSArray<person> obj(len, def, maxL);
        driverFn(obj);
    }
    return 0;
}
