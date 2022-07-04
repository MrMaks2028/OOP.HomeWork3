#include <iostream>
#include <vector>
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
	DynamicArray operator= (DynamicArray&& other) {}
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
	int *data(){
		return _data;
	}
	int capacity() const {
		return _capacity;
	}
	bool empty() {
		if (_size > 0) {
			return false;
		}
		else{
			return true;
		}
	}
	int size() const {
		return _size;
	}
	void reserve(int size){
		if (size > _size) {
			int* tmp = new int[_size];
			for (int i = 0; i < _size; i++) {
				tmp[i] = _data[i];
			}
			delete[]_data;
			_capacity = _size + size;
			_size = _capacity;
			_data = new int[_capacity];
			for (int i = 0; i < _capacity - size; i++) {
				_data[i] = tmp[i];
			}
			delete[]tmp;
		}
	}
	void shrink_to_fit() {}
	void clear(){}
	void insert(int pos, int val, int count){}
	void erase(int first, int last){}
	void push_back(int el) {
		resize(_size + 1);
		_data[_size - 1] = el;
	}
	void emplace_back(int pos){}
	void pop_back(){}
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
	void swap(DynamicArray other1, DynamicArray other2){}

private:
	int _size = 0;
	int _capacity = 0;
	int* _data = nullptr;

	int* allocate(int size) {
		int* _data = new int[size];
	}
};

int main() {
	setlocale(LC_ALL,"Russian");
	
	DynamicArray arr(5);
	arr.at(0) = 0;
	arr.at(1) = 1;
	arr.at(2) = 2;
	arr.at(3) = 3;
	arr.at(4) = 4;
	arr.reserve(5);
	cout << arr.capacity();

	return 0;
}