#include <iostream>
#include <string>
#include <vector>

#define DEFAULT_SIZE 8
#define HASH 37
#define REHASH 3.0 / 4.0

const std::string deleted = "!";

int hash( const std::string& s, int size ) {
    int result = 0;
    for ( int i = 0; i < s.length(); ++i ) {
        result = ( HASH * result + s[i] ) % size;
    }
    return result;
}

template<class T>
class HashTable {
public:
    HashTable();
    ~HashTable();

    bool Has( const T &obj );
    bool Add( const T &obj );
    bool Delete( const T &obj);

private:
    void rehash();
    int quadroProbing( int posit, int iter ) ;

    std::vector<T> array;
    size_t keyCount;
    size_t deletedCount;
};

template<class T>
HashTable<T>::HashTable() {
    array.resize( DEFAULT_SIZE, "" );
    keyCount = 0;
    deletedCount = 0;
}

template<class T>
HashTable<T>::~HashTable() {
    array.clear();
}

template<class T>
void HashTable<T>::rehash() {
    std::vector<T> tmp = array;
    array.clear();
    array.resize( tmp.size() * 2, "" );

    keyCount = 0;
    deletedCount = 0;
    for (int i = 0; i < tmp.size(); ++i ) {
        if (tmp[i] != deleted && tmp[i] != "" ) {
            int inPos = hash ( tmp[i], array.size() );
            int posHash = 0;

            for (int j = 0; j < array.size(); ++j ) {
                posHash = quadroProbing( inPos, j );
                if (array[posHash] == "") {
                    array[posHash] = tmp[i];
                    ++keyCount;
                    break;
                }
            }
        }
    }
    tmp.clear();
}

template<class T>
bool HashTable<T>::Has( const T &obj ) {
    int initPos = hash (obj, array.size());
    int posHash = 0;

    for (int i = 0; i < array.size(); ++i) {
        posHash = quadroProbing( initPos, i );
        if (array[posHash] == "") 
            return false;
        else if (array[posHash] == obj) 
            return true;
    }
    return false;
}

template<class T>
bool HashTable<T>::Add(const T &obj) {
    int initPos = hash (obj, array.size());
    int posHash = 0;
     if ( (( keyCount + 1 ) > ( array.size() * REHASH ))
            || ( deletedCount > (array.size() / 2)) ) rehash();

    for (int i = 0; i < array.size(); ++i) {
        posHash = quadroProbing( initPos, i );
        if (array[posHash] == "" || array[posHash] == deleted) {
            array[posHash] = obj;
            if( array[posHash] == deleted)
                --deletedCount;
            ++ keyCount;
            return true;
        }

        else if (array[posHash] == obj) 
            return false;
    }
    array[posHash] = obj;
    if( array[posHash] == deleted) 
        --deletedCount;
    ++ keyCount;
    return true;
}

template<class T>
bool HashTable<T>::Delete( const T &obj ) {
    int initPos = hash (obj, array.size());
    int posHash = 0;

    for (int i = 0; i < array.size(); ++i) {
        posHash = quadroProbing( initPos, i );
        if (array[posHash] == "") 
            return false;
        else if (array[posHash] == obj) 
             array[posHash] = deleted;
            --keyCount;
            ++ deletedCount;
            return true;
    }
    return false;
}

template<class T>
int HashTable<T>::quadroProbing( int posit, int iter ) {
    return (( posit + (( iter * (iter + 1) / 2 ))) % array.size());
} 

int main() {
    char operation = 0;
    std::string word;
    HashTable<std::string>* table = new HashTable<std::string>;
    while (std::cin >> operation >> word) {
        switch ( operation ) {
            case '+': {
                std::cout << (table->Add(word) ? "OK" : "FAIL") << std::endl;
                break;
            }
            case '-': {
                std::cout << (table->Delete(word) ? "OK" : "FAIL") << std::endl;
                break;
            }
            case '?': {
                std::cout << (table->Has(word) ? "OK" : "FAIL") << std::endl;
                break;
            }
        }
    }
    delete table;
    return 0;
}

 
