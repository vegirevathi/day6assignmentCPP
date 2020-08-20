#include <bits/stdc++.h>
using namespace std;

class Hash
{
	int slots;
	list<int> *table;

public:
	Hash(int b);

	void insertItem(int x);

	int hashFunction(int x) {
		return (x % 11);
	}

	void displayHash();

	void search(int key);
};

Hash::Hash(int b)
{
	this -> slots = b;
	table = new list<int>[slots];
}

void Hash::insertItem(int key)
{
	int index = hashFunction(key);
	table[index].push_back(key);
}

void Hash::displayHash() {
	for (int i = 0; i < slots; i++) {
		cout << i;
		for (auto x : table[i])
			cout << "---->" << x;
		cout << endl;
	}
}

void Hash::search(int key) {
	for (int i = 0; i < slots; i++)
	{
		int index = hashFunction(key);
		if (i == index)
		{
			cout << "Element is found at index : " << index << endl;
			return;
		}
	}
	cout << "Element is not found " << endl;
}

int main() {
	int size, key;

	cout << "Enter num of elements : " << endl;
	cin >> size;

	int array[size];
	cout << "Enter array elements : " << endl;
	for (int i = 0; i < size; i++) {
		cin >> array[i];
	}

	Hash hashTable(10);

	for (int i = 0; i < size; i++) {
		hashTable.insertItem(array[i]);
	}

	hashTable.displayHash();

	cout << "Enter element you want to search : " << endl;
	cin >> key;

	hashTable.search(key);
  return 0;
}
