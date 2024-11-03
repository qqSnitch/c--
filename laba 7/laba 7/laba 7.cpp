#include<iostream>
#include<string>
#include<functional>
#include <cstdlib>
#include <ctime>
using namespace std;
string generateRandomURL(int m) {
    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string url;
    srand(time(NULL));

    for (int i = 0; i < m; i++) {
        int index = rand() % alphabet.size();
        url += alphabet[index];
    }
    return url;
}
int hashFunction(const string& url, int N) {
    hash<string> hasher;
    size_t hashValue = hasher(url);
    int result = hashValue % N;
    return result;
}

int main() 
{
    string* url = new string[10];
    for(int i=0;i<10;i++)
    {
        url[i] = generateRandomURL(10);
        cout << url[i];
        int hashValue = hashFunction(url[i], 10);
        cout << " Hash: " << hashValue << endl;
    }
}
