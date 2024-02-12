// Code modified from a conversation with ChatGPT

#include <iostream>
#include <sstream>
#include <string>

#include "autosort_array_list.h"

using std::cout;
using std::endl;
using std::string;

// define the list class
list::list() {
    head = nullptr;
}

// this function inserts the value in the linked list in ascending value
void list::insert(int value) {
    // create a new node with the given data
    node *new_node = new node;
    new_node->data = value;
    new_node->next = nullptr; //new node needs to point to nullptr otherwise system will give it garbage address

    // if head is null, then our list is empty and we need to set that node to head
    if(head == nullptr) {
        head = new_node; 
    } else {
        // if the value we are trying to insert is smaller or equal to the first data in the list
        if (value <= head->data) {
            // the new node needs to become the head and be inserted before the first node that is already present
            new_node -> next = head; //the new node will point to the address stored by the head pointer
            head = new_node; // then the new node will become the head itself
            // if we had flipped the order of the 2 lines above it would have not worked because head would have lost the address of the node that was the first one
        } else {

            node *iteration_pointer = head; // we will need to iterate through the list until we find the correct location

            // iteration will continue while we don't reach nullptr which is the end of the linked list
            // and while the value we are trying to insert is bigger than the next data in the list 
            while (iteration_pointer->next != nullptr && iteration_pointer->next->data < value) {
                iteration_pointer = iteration_pointer->next;
            }

            // at this point the node next to the iteration_pointer is bigger than value, so value needs to be inserted in iteration pointer location
            // insert the new node at the position
            new_node->next = iteration_pointer->next;
            iteration_pointer->next = new_node;
        }
    }
}

// this function turns the linked list into a string that includes the data of all the nodes of the list in the sequence they are located in the list
string list::to_string() {

    // stringstream is a stream class defined in the sstream included on the beginning of this file
    // strings only store data but with stringstreams the programmer has the ability to manipulate the data in the string
    std::stringstream result_string_stream;

    // check if the list is empty
    if(head == nullptr){ //if head is the last node of the list, last node points to nullptr
        result_string_stream << "[empty list]";
    } else {
        
        // start the iteration at the head/beginning of the list
        node *iteration_pointer = head;

        result_string_stream << "["; // springstreams allow you to add different values to the string variable and compose it on multiple code lines
        while (iteration_pointer != nullptr) { // until it reaches the end of the list
            result_string_stream << iteration_pointer->data; // more data is added to the string
            if(iteration_pointer->next != nullptr) { // if iteration reaches end of list then it would not need the comma
                result_string_stream << ", ";
            }
            iteration_pointer = iteration_pointer->next; // equivalent to ++i
        }
        result_string_stream << "]";
    }

    // str() is a function of the stringstream class that turns the stringstream into a normal string of the ones we are used to working
    // C++ is not capable of returning a stringstream
    return result_string_stream.str();
}


// this function searches for a specific value in the list
// you can't do binary search with linked lists so I had to a more costly option which is to traverse the entire list in the search of the value
int list::search(int value){

    // check if the list is empty
    if(head == nullptr){ //if head is the last node of the list, last node points to nullptr
        cout << "the value you searched is not in the list because the list is empty" << endl;
        return -1;
    } else {
        node *iteration_pointer = head; 

        while (iteration_pointer != nullptr) { // runs the iteration until nullptr is pointing to nullptr, in other words until it passes the last node
            if (iteration_pointer->data == value){
                return value; // exit the function with the value
            }
            iteration_pointer = iteration_pointer->next;
        }
        
        // if program got to this lines it means the value was not the data of any of the nodes so it was not on the list or it was an invalid number
        cout << "The number " << value << " is not in the list" << endl ; 
        return -1; 
    }
}