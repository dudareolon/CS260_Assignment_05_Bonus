# CS260_Assignment_05_Bonus
Auto-sorting array based list 

Description: this program reimplements the sorted linked-list program, but uses an array list instead of a linked-list. The program is able to print out the list as a string, insert values in ascending order in the list, and to search for a specific value in the list. 

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Design: There will be 3 files in my program

1- array_list.h: This file says what an array list will be for this program. An array is simply a one dimensional vector. For this class list, an empty list will be defined on private and the functions insert, search, and to_string will be defined on public. 

2- array_list.cpp:

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
