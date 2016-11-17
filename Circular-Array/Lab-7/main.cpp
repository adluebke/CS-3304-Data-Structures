/*
* Class: CS 3304/section07
* Term: Fall 2016
* Name: Andrew Luebke
* Instructor: Monisha Verma
* Assignment: Lab 7
 */

#include <iostream>
#include "deque.h"

using namespace std;
using namespace LAB_07_ALUEBKE;

int main()
{
	deque<int> sample1;
	deque<int> sample2;

    cout << "Testing push_front function by passing 3 and then 6 into deque sample1..." << endl;
        sample1.push_front(3);
        sample1.push_front(6);

    cout << "Sample1 is expected to be 6 3 ..." << endl;
        cout << "Deque sample1 is currently: ";
        cout << sample1 << endl;
            cout << endl;

    cout << "Testing push_back function by passing 9 into deque sample1..." << endl;
        sample1.push_back(9);

    cout << "Sample1 is expected to be 6 3 9 ..." << endl;
        cout << "Deque sample1 is currently: ";
        cout << sample1 << endl;
            cout << endl;

	cout << "Testing front() and back() functions for sample1, expected values are 6 and 9.." << endl;
        cout << "Front value: " << sample1.front() << endl;
        cout << "Back value: " << sample1.back() << endl;
            cout << endl;

	cout << "Creating a deque called sample2 with the same values and printing it..." << endl;
        sample2.push_front(3);
        sample2.push_front(6);
        sample2.push_back(9);
    cout << sample2 << endl;
        cout << endl;

    cout << "Testing == operator to ensure sample1 == sample2 returns true..." << endl;
        if (sample1 == sample2)
        {
            cout << "They're the same!" << endl;
        }
        else
        {
                cout << "Nope!" << endl;
        }
            cout << endl;

    cout << "Testing pop_front() function on sample 1. Expected values are 3 9 " << endl;
        sample1.pop_front();
        cout << "Deque sample1 is currently: ";
        cout << sample1 << endl;
        cout << endl;

    cout << "Testing pop_back() function on sample 2. Expected values are 6 3 " << endl;
        sample2.pop_back();
        cout << "Deque sample2 is currently: ";
        cout << sample2 << endl;
        cout << endl;

    cout << "Testing size() function on sample 1. Expected value is 2..." << endl;
        cout << sample1.size() << endl;
        cout << endl;

    cout << "Testing == operator to ensure sample1 == sample2 returns false..." << endl;
        if (sample1 == sample2)
        {
            cout << "They're the same!" << endl;
        }
        else
        {
                cout << "Nope!" << endl;
        }
            cout << endl;

    cout << "Testing complete!" << endl;


}
