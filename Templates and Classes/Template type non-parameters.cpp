#include <iostream>
#include<array>

template<typename T, int size>  // size is an integral non-type parameter
class StaticArray
{
private:
	//the non-type parameter controls the size of the array
	std::array<T, size> m_array{};

public:
	T* getArray();

	T& operator[](int index)
	{
		return m_array[index];
	}
};

//function for a class with a non-type parameter is defined outise of the class
template <typename T, int size>
T* StaticArray<T, size>::getArray()
{
	return m_array.data(); //to get a pointer to the array
}

int main()
{
	//declare an integer array with room for 12 integers
	StaticArray<int, 12> intArray;

	//Fill it up in order, then print it backwards
	for (int count{ 0 }; count < 12; ++count)
		intArray[count] = count;

	for (int count{ 11 }; count >= 0; --count)
		std::cout << intArray[count] << ' ';
	std::cout << '\n';

	//declare a double buffer with room for 4 doubles
	StaticArray<double, 4> doubleArray;

	for (int count{ 0 }; count < 4; ++count)
		doubleArray[count] = 4.4 + 0.1 * count;

	for (int count{ 0 }; count < 4; ++count)
		std::cout << doubleArray[count] << ' ';



	return 0;
}