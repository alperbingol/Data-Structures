#include <iostream>
#include <vector>

using namespace std;

// Alper Bingol 23661
struct PriorityQueue
{
private:

	vector<int> A; // vector to store heap elements

	int PARENT(int i) // return parent of A[i]
	{
		return (i - 1) / 2;
	}

	int LEFT(int i) // return left child of A[i]
	{
		return (2 * i + 1);
	}

	int RIGHT(int i) // return right child of A[i]	
	{
		return (2 * i + 2);
	}

	void heapify_down(int i) // Recursive Heapify-down algorithm
	{

		int left = LEFT(i); // get left and right child of node at index i
		int right = RIGHT(i);

		int largest = i;

		if (left < size() && A[left] > A[i]) // compare A[i] with its left and right child  and find largest value
			largest = left;

		if (right < size() && A[right] > A[largest])
			largest = right;


		if (largest != i) { // swap with child having greater value and call heapify-down on the child
			swap(A[i], A[largest]);
			heapify_down(largest);
		}
	}

	void heapify_up(int i) // Recursive Heapify-up algorithm
	{
		if (i && A[PARENT(i)] < A[i]) // check if node at index i and its parent violates  the heap property
		{

			swap(A[i], A[PARENT(i)]); // swap the two if heap property is violated

			heapify_up(PARENT(i)); // call Heapify-up on the parent
		}
	}

public:
	//int n;
	// return size of the heap
	unsigned int size()
	{
		return A.size();
	}

	// function to check if heap is empty or not
	bool empty()
	{
		return size() == 0;
	}


	void insert(int key)
	{
		// insert the new element to the end of the vector
		A.push_back(key);


		int index = size() - 1;
		heapify_up(index);
	}


	void remove(int key) // speacil delete function from heap
	{
		auto it = std::find(this->A.begin(), this->A.end(), key); // finds the key 
		if (it != this->A.end()) {
			this->A.erase(it); // delete it

		}

		heapify_down(0);
	}


	int GetMax() // returns the hightest value in heap
	{
		return A.at(0);
	}

};