// Autosort array list 

#include <iostream>
#include <sstream>
#include <string>

#include "autosort_array_list.h"

using std::cout;
using std::endl;
using std::string;
using std::advance;

// initialize list class 
list::list(){
    //empty list
}

// this function inserts the value in the array list in ascending order
void list::insert(int value) {

    // it is important to note that arrays start at the index 0 and not at 1
    // so a 3 element array has the positions 0,1, and 2
    int index = 0; // start index to first position on the array

    while (index<array_list.size() && array_list[index]<value){ 
        // back to the 3 element list example, the size() function would count the size as being 3, but the index would go only until 2
        // that is why I am doing while index<size and not index<=size

        // the array[index]<value takes the ascending order into consideration
        // the index will keep increasing if that the value at that index is smaller than the value we want to insert in the array
        index++;
    }

    // at the end of this while loop index is the position of the array that we want to insert value
    // but index is simply an integer, it is not an iterator, so you can't simply say insert value at index

    // I created an iterator called index_pointer, because it is the pointer that will go through the array
    // I was not sure how to declare an iterator in C++ (or in any language) so the internet showed me this nifty auto feature
    // 'auto' will make the variable on the left side be the same data type of the variable on the right side
    auto index_pointer = array_list.begin(); // iterator is pointing to the beginning of the list

    advance(index_pointer, index); // advanced iterator for it to point to the index position of the list

    array_list.insert(index_pointer, value); // insert value in the iterator position
}

// this function turns the array list into a string that includes the data of all the nodes of the list in the sequence they are located in the list
string list::to_string() {

    std::stringstream result_string_stream;
    int size = array_list.size();

    if (size==0){
        result_string_stream << "[empty list]";
    } else {
        result_string_stream << "[";
        int i = 0;
        while (i<size){
            result_string_stream << array_list[i];
            i++;
            if (i<size){
                result_string_stream << ", ";
            }

        }
        result_string_stream << "]";

    }

    return result_string_stream.str();

}


// this function searches for a specific value in the list using binary search
// binary search is to cut a sorted list in half, identify if your number is higher or lower than the middle number
// then cut the half you chose in half again, compare your value to the middle value, and keep repeating until you find the value you are looking for
// Binary search takes less time, money, and power than iterating through all values of the list 
int list::search(int value){
    
    int size = array_list.size();
    // check if empty
    if (size==0){
        cout << "It was not possible to find the value you entered because the list is empty" << endl;
        return -1;
    } else {
        // for the binary search you need to know the initial left boundary and the initial right boundary
        int left_boundary = 0;
        int right_boundary = size-1; // indexes start at 0 but the size start counting at 1 so they are one number off

        if (left_boundary==right_boundary){
            if (array_list[left_boundary]==value){
                return value;
            } else {
                cout << "The number " << value << "is not in the list" << endl;
                return -1;
        }
        } else {
            while (left_boundary<=right_boundary){
                int middle= left_boundary + (right_boundary) / 2;
                if (array_list[middle] == value) {
                    return value; // Element found
                } else if (array_list[middle] < value) {
                    left_boundary = middle + 1;
                } else {
                    right_boundary = middle - 1;
                }
            }
        }

        cout << "The number " << value << " is not in the list" << endl ; 
        return -1; 
    }
}
