# About

This folder is contains all the problems that were asked in the interview of various companies. This entire folder is developed with the help of chatgpt

<!-- # Chatgpt prompt used
Hi, I need your help to understand complex DSA problems as I am preparing for a interview

I will provide
1. A problems statement
2. Examples
3. Any constraints or the requirements mentioned

I want you to provide
1. An approach on how to start thinking on solving that particular problem, break it down to some of the basic building block of a programming concepts. I will be using C++ to code them. So, use the concepts from that language

2. A algorithms on how that problems can be solved (This will be my like my flash card that I will be using to practice the problem)

3. A pseudo code which can guide me on how to develop the code.

4. What would be the time complexity and space complexity when an efficient code is written for that problems statement. So, I want you to provide me a detailed C++ code in the end that I can refer to as a solution when I write the code for it.

And here is the format of how I develop my C++ code. as I do the testing locally and then copy the code to online competitive coding platform

Library functions

Specific function developed to solve the problems

Main function developed that takes all the variables and pass it to the specific function

For example: This is the code for finding the majority element
"#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int majorityelement(vector<int> &nums){
    map<int, int> counter;

    for(auto &num: nums){
        counter[num]++;
    }

    for(auto &pair: counter){
        if(pair.second > nums.size()/2){
            cout<<pair.first;
            return pair.first;
        }
    }

    return 0;

}

int main(){

    vector<int> nums;
    int n;
    int ele;

    cout<<"Enter the no.of elements of the array :";
    cin>>n;

    cout<<"Enter the elemenets of the array :";
    for(int i = 0;i<n;i++){
        cin>>ele;
        nums.push_back(ele);
    }

    majorityelement(nums);
    return 0;
}"

I will give the problems from the next chat and make sure you follow these above instructions strictly. 

Can you explain me what you understood from my requirements -->

<!-- Chatgpt response

I understand that you are preparing for coding interviews and require help with understanding and solving complex DSA problems. Here's how I will assist you:

Problem Analysis:
I will break down the problem into smaller, understandable components, focusing on the foundational programming concepts relevant to C++.

Algorithm (Flashcard):
I'll provide a clear, step-by-step algorithm to solve the problem. This will be concise and structured to help you recall and practice the problem efficiently.

Pseudocode:
A guide on how to translate the algorithm into code, serving as a bridge to implementation.

Complexity Analysis:
I'll detail the time and space complexities for the optimal solution, explaining why the complexities are as such.

C++ Code:
I'll provide a complete C++ solution formatted as you prefer, including:

Library imports.
A dedicated function to solve the problem.
A main function to handle input, invoke the solution function, and display results.
You will give me problems to work on, and I will adhere strictly to these instructions to provide structured, thorough guidance. Ready for your first problem whenever you are! -->

# Problems list
- [Date 22/12/24] - Search 2D Matrix
- [Date 23/12/24] - Find the sum of 4 unique quadruplets in array
- [Date 23/12/24] - Kadane algorithm
- [Date 24/12/24] - Clearing backlogs
- [Date 25/12/24] - pow(r,n)
- [Date 26/12/24] - Boyer-Moore Voting algorithm(Majority element (>n/2)) & Majority element (>n/3)
- [Date  2/01/25](Code day) - Solved Search 2D Matrix, Kadane algorithm, Sum 4  
- [Date  3/01/25](Write day)- A new update to a newly named repo