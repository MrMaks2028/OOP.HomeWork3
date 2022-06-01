#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
 
class DynamicArray {
public:
	DynamicArray(){
		_size = 0;
		_capacity = 0;
		_data = nullptr;
	}
	DynamicArray(const DynamicArray &other) {
		_size = other._size;
		_capacity = _size;
		_data = nullptr;
		if (_size != 0)
			_data = new int[_size];
		else
			_data = 0;
		for (int i = 0; i < _size; i++)
			_data[i] = other._data[i];
	}
	DynamicArray(DynamicArray &&other){}
	DynamicArray(int size) {
		_size = size;
		_capacity = _size;
		if (_size != 0)
			_data = new int[_size];
		else
			_data = 0;
	}
	~DynamicArray() {
		if (_data)
			delete[] _data;
	}

	
	auto at(int pos)->int& {
		return _data[pos];
	}
	auto at(int pos)const->const int& {
		return _data[pos];
	}
	auto operator[] (int i)->int& {
		return _data[i];
	}
	auto operator[](int i)const->const int& {
		return _data[i];
	}
	auto front()->int& {
		return _data[0];
	}
	auto front()const->const int& {
		return _data[0];
	}
	auto back()->int& {
		return _data[_size - 1];
	}
	auto back()const->const int& {
		return _data[_size - 1];
	}
	int &data(){
		
	}
	bool empty() {
		if (_size > 0) {
			return false;
		}
		else{
			return true;
		}
	}
	void resize(int size) {
		if (size > _capacity)
		{
			int new_capacity = size;
			int* new_data = new int[new_capacity];
			for (int i = 0; i < _size; i++)
				new_data[i] = _data[i];
			delete[] _data;
			_data = new_data;
			_capacity = new_capacity;
		}
		_size = size;
	}
	void reverse() {}
	void push_back(int el){
		resize(_size + 1);
		_data[_size - 1] = el;
	}
	int size() const{
		return _size;
	}
	int capacity() const {
		return _capacity;
	}
	
	DynamicArray operator= (const DynamicArray& other)
	{
		if (this == &other)
			return *this;
		delete[] _data;
		_data = new int[other._size];

		_size = other._size;
		_capacity = other._capacity;

		for (int i = 0; i < _size; i++)
			_data[i] = other._data[i];

		return *this;
	}
	DynamicArray operator= (DynamicArray &&other){}

private:
	int _size;
	int _capacity;
	int* _data;

	int* allocate(int size) {
		int* _data = new int[size];
	}
};

int main() {
	setlocale(LC_ALL,"Russian");
	
	DynamicArray mas(10);
	mas[0] = 5;
	cout << mas.at(0);






	/*DynamicArray a(10);
	cout << "a.size: " << a.size();
	cout << "\na.capacity: " << a.capacity();
	a.resize(20);
	a.push_back(22);
	cout << "\n\nSize: " << a.size();
	cout << "\nNew Capacity: " << a.capacity();*/
	
	/*DynamicArray mas();
	DynamicArray arr(2);
	DynamicArray brr(2);
	arr[0] = 10;
	arr[1] = 20;
	brr[0] = 30;
	brr[1] = 40;
	DynamicArray crr(2);
	crr = arr;
	cout << arr;
	cout << endl;
	cout << crr;*/

	/*vector<int>mas(10);
	for (int i = 0; i < 10; i++)
		cin >> mas[i];
	cout << "\n[";
	for (int i = 0; i < 10; i++)
		cout << mas[i] << ", ";
	cout << "\b\b]\n";*/

	return 0;
}