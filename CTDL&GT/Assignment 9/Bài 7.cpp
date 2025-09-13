#include <bits/stdc++.h>
using namespace std;

struct KeyValuePair {
    string key;
    string definition;

    KeyValuePair(const string& k, const string& def) : key(k), definition(def) {}
};

class Dictionary {
private:
    static const int TABLE_SIZE = 10;  
    vector<list<KeyValuePair>> hashTable;

public:
    Dictionary() : hashTable(TABLE_SIZE) {}
    int hash(const string& key) {
        int hashValue = 0;
        for (char ch : key) {
            hashValue += static_cast<int>(ch);
        }
        return hashValue % TABLE_SIZE;
    }
    void insert(const string& key, const string& definition) {
        int index = hash(key);
        hashTable[index].emplace_back(key, definition);
    }
    string lookup(const string& key) {
        int index = hash(key);
        auto it = find_if(hashTable[index].begin(), hashTable[index].end(),
                          [key](const KeyValuePair& kvp) {
                              return kvp.key == key;
                          });
        if (it != hashTable[index].end()) {
            return it->definition;
        } else {
            return "Definition not found.";
        }
    }
};

int main() {
    Dictionary dictionary;
    dictionary.insert("apple", "A fruit");
    dictionary.insert("car", "A vehicle");
    dictionary.insert("python", "A programming language");
    cout << "Definition of 'apple': " << dictionary.lookup("apple") << endl;
    cout << "Definition of 'car': " << dictionary.lookup("car") << endl;
    cout << "Definition of 'python': " << dictionary.lookup("python") << endl;
    cout << "Definition of 'unknown': " << dictionary.lookup("unknown") << endl;
    return 0;
}
