#include <iostream>
#include<stdlib.h>
using namespace std;

template <class T>
class List {
	void clear();
	bool isEmpty();
	bool append(const T value);
	bool insert(const int p, const T value);
	bool remove(const int p);
	bool getValue(const int p, T& value);
	bool setValue(const int p, const T value);
	bool getPos(int& p, const T value);
	bool setPos(int pos);
	bool setEnd();
	bool setStart();
	bool prev();
	bool next();
};
template <class T>
class arrList :public List<T> {
private:
	T* aList;
	int maxSize;
	int curLen;
	int position;
public:
	arrList(const int size) {
		maxSize = size;
		aList = new T[maxSize];
		curLen = position = 0;
	}
	~arrList() {
		delete[] aList;
	}
	void clear() {
		delete[] aList;
		curLen = position = 0;
		aList = new T[maxSize];
	}
	void print() {
		for (int i = 0; i < curLen; i++) {
			cout << aList[i] << " \t";
		}
		cout << endl;
		for (int i = 1; i < curLen + 1; i++) {
			cout << i << " \t";
		}
		cout << endl;
		cout << "curlen:" << curLen << endl;
		cout << "maxsize:" << maxSize << endl;
	}
	int length() {
		return curLen;
	}
	bool append(const T value);
	bool insert(const int p, const T value);
	bool remove(const int p);
	bool getValue(const int p, T& value);
	bool setValue(const int p, const T value);
	bool getPos(int& p, const T value);

};
template<class T>
bool arrList<T>::append(const T value) {
	T* p = new T[maxSize + 1];
	for (int i = 0; i < maxSize; i++) {
		p[i] = aList[i];
	}
	delete[]aList;
	aList = p;
	return true;

}
template <class T>
bool arrList<T>::getValue(const int p, T& value) {
	if (p < 0 || p >= curLen) {
		cout << "position is illegal" << endl;
		return false;
	}
	if (p < curLen)
	{
		T& tmp = aList[p];
		value = tmp;
		return true;
	}
}

template <class T>
bool arrList<T>::setValue(const int p, const T value) {
	if (p < curLen) {
		aList[p] = T;
		return true;
	}
	if (p < 0 || p >= curLen) {
		cout << "position is illegal" << endl;
		return false;
	}
}

template<class T>
bool arrList<T> ::getPos(int& p, const T value) {
	int i;
	for (i = 0; i < curLen; i++)
		if (value == aList[i]) {
			p = i;
			return true;
		}
	return false;
}
template<class T>
bool arrList<T>::insert(const int p, const T value) {
	int i;
	if (curLen >= maxSize) {
		cout << "The list is overflow" << endl;
		return false;
	}
	if (p<0 || p>curLen) {
		cout << "Insertion point is illegal" << endl;
		return false;
	}
	for (i = curLen; i > p; i--)
		aList[i] = aList[i - 1];
	aList[p] = value;
	curLen++;
	return true;
}
template<class T>
bool arrList<T> ::remove(const int p) {
	int i;
	if (curLen <= 0) {
		cout << "No elelment to delete \n" << endl;
		return false;
	}
	if (p<0 || p>curLen - 1) {
		cout << "deletion is illegal\n" << endl;
		return false;
	}
	for (i = p; i < curLen - 1; i++)
		aList[i] = aList[i + 1];
	curLen--;
	return true;
}
