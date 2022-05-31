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
	DynamicArray(const DynamicArray& arr) {
		_size = arr._size;
		_capacity = _size;
		_data = nullptr;
		if (_size != 0)
			_data = new int[_size];
		else
			_data = 0;
		for (int i = 0; i < _size; i++)
			_data[i] = arr._data[i];
	}
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

	void resize(int size) {
		if (size > _capacity)
		{
			int new_capacity = max(size, _size * 2);
			int* new_data = new int[new_capacity];
			for (int i = 0; i < _size; i++)
				new_data[i] = _data[i];
			delete[] _data;
			_data = new_data;
			_capacity = new_capacity;
		}
		_size = size;
	}
	void push_back(int el){
		resize(_size + 1);
		_data[_size - 1] = el;
	}
	int size() const{
		return _size;
	}
	int& operator[] (int i){
		return _data[i];
	}
	friend ostream& operator<< (ostream& out, DynamicArray& arr) {
		for (int i = 0; i < arr.size(); ++i)
			out << arr[i] << " ";
		return out;
	}
	DynamicArray operator= (const DynamicArray& arr)
	{
		if (this == &arr)
			return *this;
		delete[] _data;
		_data = new int[arr._size];

		_size = arr._size;
		_capacity = arr._capacity;

		for (int i = 0; i < _size; i++)
			_data[i] = arr._data[i];

		return *this;
	}

private:
	int _size;
	int _capacity;
	int* _data;
};

int main() {
	setlocale(LC_ALL,"Russian");
	DynamicArray mas();
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
	cout << crr;

	/*vector<int>mas(10);
	for (int i = 0; i < 10; i++)
		cin >> mas[i];
	cout << "\n[";
	for (int i = 0; i < 10; i++)
		cout << mas[i] << ", ";
	cout << "\b\b]\n";*/

	return 0;
}