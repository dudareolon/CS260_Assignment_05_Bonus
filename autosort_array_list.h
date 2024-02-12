#pragma once

#include <string>
#include <vector>

using std::vector;
using std::string;

// define the list class
class list {
    // this a one dimensional array which is a vector
    private:
        // according to the internet there are several ways to initialize an empty vector on C++, I am using this:
        vector<int> array_list;

    public:
        list();
        void insert(int value);
        string to_string();
        int search(int value);
};