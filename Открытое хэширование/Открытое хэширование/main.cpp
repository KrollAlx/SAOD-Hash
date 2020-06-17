#include<iostream>
#include<list>
#include<vector>
using namespace std;

class HashTable {
private:
	vector<list<string>> array;
	int m;

	int hashFunction(const string& item) {
		int code = 0;
		for (int i = 0; i < item.size(); ++i) {
			code += (int)item[i];
		}
		return code % m;
	}
public:
	HashTable(int m) {
		this->m = m;
		array.resize(m);
	}
	void add(const string& item) {
		int index = hashFunction(item);
		array[index].push_back(item);
	}
	string search(const string& key, int& countCompares) {
		int index = hashFunction(key);
		for (auto item : array[index]) {
			if (item == key) {
				countCompares++;
				return item;
			}
			countCompares++;
		}
		return "";
	}
	void remove(const string& key) {
		int index = hashFunction(key);
		for (auto item : array[index]) {
			if (item == key) {
				cout << "Ключ удален" << endl;
				array[index].remove(key);
				return;
			}
		}
		cout << "Ключ не найден" << endl;
	}
	friend ostream& operator<<(ostream& out, const HashTable& hashTable);
};

int main() {
	setlocale(LC_ALL, "ru");

	auto fillHashTable = [](HashTable& hash) {
		hash.add("hello");
		hash.add("world");
		hash.add("peace");
		hash.add("count");
		hash.add("number");
		hash.add("class");
		hash.add("integer");
		hash.add("function");
		hash.add("heap");
		hash.add("path");
		hash.add("yellow");
		hash.add("video");
		hash.add("car");
		hash.add("pixel");
		hash.add("image");
		hash.add("sound");
		hash.add("reference");
		hash.add("game");
		hash.add("update");
		hash.add("file");
	};
	auto searchWithCountCompares = [](HashTable hash) {
		int countCompares = 0;
		hash.search("hello", countCompares);
		hash.search("world", countCompares);
		hash.search("peace", countCompares);
		hash.search("count", countCompares);
		hash.search("number", countCompares);
		hash.search("class", countCompares);
		hash.search("integer", countCompares);
		hash.search("function", countCompares);
		hash.search("heap", countCompares);
		hash.search("path", countCompares);
		hash.search("yellow", countCompares);
		hash.search("video", countCompares);
		hash.search("car", countCompares);
		hash.search("pixel", countCompares);
		hash.search("image", countCompares);
		hash.search("sound", countCompares);
		hash.search("reference", countCompares);
		hash.search("game", countCompares);
		hash.search("update", countCompares);
		hash.search("file", countCompares);
		cout << "Суммароное число сравнений необходимое для поиска - " << countCompares << endl;
	};

	HashTable hash1(9);
	HashTable hash2(17);
	HashTable hash3(23);

	fillHashTable(hash1);
	fillHashTable(hash2);
	fillHashTable(hash3);

	cout << hash1 << endl;
	cout << hash2 << endl;
	cout << hash3 << endl;

	searchWithCountCompares(hash1);
	searchWithCountCompares(hash2);
	searchWithCountCompares(hash3);

	system("pause");
	return 0;
}

ostream& operator<<(ostream& out, const HashTable& hashTable)
{
	for (int i = 0; i < hashTable.m; ++i) {
		out << i << " : ";
		for (auto item : hashTable.array[i]) {
			out << item << " ";
		}
		out << endl;
	}
	return out;
}
