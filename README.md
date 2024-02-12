# CS260_Assignment_05_Bonus
Auto-sorting array based list 

Description: this program reimplements the sorted linked-list program, but uses an array list instead of a linked-list. The program is able to print out the list as a string, insert values in ascending order in the list, and to search for a specific value in the list. 

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Design: There will be 3 files in my program

1- array_list.h: This file says what an array list will be for this program. An array is simply a one dimensional vector. For this class list, an empty list will be defined on private and the functions insert, search, and to_string will be defined on public. 

2- array_list.cpp: this file will define the 3 functions that I will use on this program, the functions are:

- insert(): iterate through all values of the list until value inserted is smaller than the value stored in the current index of the iteration. Store value in the index location. If you use insert function it will already shift the numbers to the right of the index one spot to the right.

- to_String(): iterates thhough all index values of the array putting them all in order inside one single string. It is pretty much same function as linked list. The only difference is that during the iteration the index is incremneted before adding the number in the array to the string, while on the linked list code the index was incremented after adding the number to the string. That is because with arrays the program is able to directly access any index, while with linked lists the program needs the previous node next pointer to access it.

- search(): this function searches and returns an exact value from the list. With the linked-list we had to traverse the entire list in the search for this value. With the array I will be using binary search to make this program faster. Binary search is a method in which the searched value it only compared to the value on the middle of the list, instead of to all elements of the list. If the value you are searching for is not the middle value of the list, at least you are able to know if it is higher or lower than then middle value. You adjust your boundaries accordngly, the left boundary changes to middle + 1 if you know the value is higher than middle, or the right boundary changes to middle - 1 if the value is lower than the middle. Then a witht the new left and right boundaries another middle is defined, this new middle value is compared to the value we are searchign for, if again they do not match, then the left and right boundaries change accordingly. And this loop continues until there are only one,two, or three values in the list. See a visual representation of binary search on the figure below:

![image](https://github.com/dudareolon/CS260_Assignment_05_Bonus/assets/102680672/2586d03b-cc62-438e-8df9-8ab824aabd3a)




3-testing: This is the testing file, and these were the tests that I performed:
- test_autosort_list_constructor();
- test_autosort_list_search_empty();
- test_autosort_list_insert_first_node();
- test_autosort_list_insert_second_node();
- test_autosort_list_search_correct_value();
- test_autosort_list_search_wrong_value();
- test_autosort_list_insert_odd();
- test_autosort_list_insert_even();
- test_autosort_list_insert_node_with_same_value_as_head();
- test_autosort_list_insert_node_before_head();
- test_autosort_list_insert_node_in_middle_of_list();

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Requirements:

1- automatically inserts values in the correct position based on some order of sorting (perhaps ascending integers or lexicographical sorting of words):

![image](https://github.com/dudareolon/CS260_Assignment_05_Bonus/assets/102680672/9432cc21-2a2a-475f-a1e4-d096a6569041)


2- efficiently searches for elements (likely binary search for the array list, but what about the linked-list?):

![image](https://github.com/dudareolon/CS260_Assignment_05_Bonus/assets/102680672/f9118813-cbf6-44dd-a7d2-e2629f674452)


---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Complexity Analysis:

- Insert: This function has a while loop that searched for the correct index to insert the value. In the best scenario, after the first time the while loop runs we would already have the correct index, and that would be O(1) notation, but that is not the case most of the times. So for this function I would consider it O(n) notation being n the aount of elements in the array.

- Search: At first I thought this function was O(n) because of the one while loop it has, but I was not sure because of all the if statemnets so I searched on the internet and then I asked ChatGPT what he thought. I came to the conclusion this function fits in the O(log n) notation for its eworst case scenario. That is becuase each time the while loop runs, it not only restarts the lines, but it also halves the search space, being that the worst case scenario is when the list is halved to the point it has 1 or 2 elements. For very long lists, this logarithmic behavior is expetional as it makes the program much simpler and much faster.

Here is the graph visual of these big O notations:

![image](https://github.com/dudareolon/CS260_Assignment_05_Bonus/assets/102680672/860c7def-1137-422d-aef9-703f7c0c34ac)

See how O(log n) is much less steep and more desirable behavior than O(n).

