// Autosort array list 

#include <iostream>
#include <sstream>
#include <string>

#include "autosort_array_list.h"

using std::cout;
using std::endl;
using std::string;
using std::advance;

// this function inserts the value in the linked list in ascending value
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

// this function turns the linked list into a string that includes the data of all the nodes of the list in the sequence they are located in the list
// string list::to_string() {

//     // stringstream is a stream class defined in the sstream included on the beginning of this file
//     // strings only store data but with stringstreams the programmer has the ability to manipulate the data in the string
//     std::stringstream result_string_stream;

//     // check if the list is empty
//     if(head == nullptr){ //if head is the last node of the list, last node points to nullptr
//         result_string_stream << "[empty list]";
//     } else {
        
//         // start the iteration at the head/beginning of the list
//         node *iteration_pointer = head;

//         result_string_stream << "["; // springstreams allow you to add different values to the string variable and compose it on multiple code lines
//         while (iteration_pointer != nullptr) { // until it reaches the end of the list
//             result_string_stream << iteration_pointer->data; // more data is added to the string
//             if(iteration_pointer->next != nullptr) { // if iteration reaches end of list then it would not need the comma
//                 result_string_stream << ", ";
//             }
//             iteration_pointer = iteration_pointer->next; // equivalent to ++i
//         }
//         result_string_stream << "]";
//     }

//     // str() is a function of the stringstream class that turns the stringstream into a normal string of the ones we are used to working
//     // C++ is not capable of returning a stringstream
//     return result_string_stream.str();
// }


// // this function searches for a specific value in the list
// // you can't do binary search with linked lists so I had to a more costly option which is to traverse the entire list in the search of the value
// int list::search(int value){

//     // check if the list is empty
//     if(head == nullptr){ //if head is the last node of the list, last node points to nullptr
//         cout << "the value you searched is not in the list because the list is empty" << endl;
//         return -1;
//     } else {
//         node *iteration_pointer = head; 

//         while (iteration_pointer != nullptr) { // runs the iteration until nullptr is pointing to nullptr, in other words until it passes the last node
//             if (iteration_pointer->data == value){
//                 return value; // exit the function with the value
//             }
//             iteration_pointer = iteration_pointer->next;
//         }
        
//         // if program got to this lines it means the value was not the data of any of the nodes so it was not on the list or it was an invalid number
//         cout << "The number " << value << " is not in the list" << endl ; 
//         return -1; 
//     }
// }