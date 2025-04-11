/******************************************************************************

Coding HW: Bar Graphs (Vectors)
This is a program that performs basic statistical analysis on sets of user data
stored as vectors. I'm coding these bar graphs on a bar stool.

(Don't look at me like that. I work here.)

Author: Benjamin DeVore
Date: 1 November 2024

*******************************************************************************/
#include <iostream>
#include <cctype>
#include <vector>

// Sorry. Had to use <algorithm>'s sort() method.
#include <algorithm> 

using namespace std;

// Vector printing function.  Provided for convenience for intermediate testing.
void printVector(vector<int> v) {
    for (int e: v) {
        cout << e << " ";
    }
    
    cout << endl;
}

void barGraph(vector<int> v) {
    int count = 0;
    int currNum = v.at(0);
    
    if (v.size() == 0) {
        // Handle an edge case.
        cout << "ERROR: Empty vector! Aborting.\n";
        return;
    }
    
    for (unsigned int i = v.at(0); i <= v.at(v.size() - 1); ++i) {
        for (int j : v) {
            if (j == i) {
                count++;
            }
        }
        
        // Now, print a bar in the graph.
        cout << i << ": ";
        
        // j was OK, but this is easy to read
        for (int k = 0; k < count; ++k) {
            cout << "|"; 
        }
        
        cout << endl;
        count = 0;
    }
    // God, this went so much better than my first attempt at this function.
}

void stats(vector<int> v) {
    int sum = 0;
    
    // Already handled empty vector error in barGraph()
    int mode = v.at(0); 
    int modeCount = 0;
    int modeValMax = 0;
    int modeCountMax = 0;
    
    for (unsigned int i = 0; i < v.size(); ++i) {
        sum += v.at(i);
        
        if (v.at(i) == mode) {
            modeCount++;
        } else {
            if (modeCount >= modeCountMax) {
                if (i != v.size() - 1) {
                    modeValMax = v.at(i - 1);
                } else {
                    modeValMax = v.at(i);
                }
                
                modeCountMax = modeCount;
            }
            
            mode = v.at(i);
            modeCount = 1;
        }
    }
    
    printf("Mean: %.2f\n", (double) sum / v.size());
    printf("Median: %d\n", v.at(v.size() / 2));
    printf("Mode: %d\n", modeValMax);
}

int main()
{
    vector<int> dataVec;
    int nextInt;
    char yesNo;
    
    do {
        cout << "Enter your data set of positive integers." << endl;
        cout << "Enter -1 as the final number to indicate the end of the data set." << endl;
        
        // Take data from user input
        do {
            cin >> nextInt;
            
            if (nextInt >= 0 && nextInt <= 200) {
                dataVec.push_back(nextInt);
            }
            // Avoid error message if entry is -1
            else if (nextInt != -1) {   
                cout << "Invalid entry: " << nextInt << ". Skipping this entry.\n";
            }
        } while (nextInt != -1);
        
        // Call functions to process data
        if (dataVec.size() > 0) {
            // Makes stats functions easier.
            sort(dataVec.begin(), dataVec.end());
        }
        
        barGraph(dataVec);
        stats(dataVec);
        dataVec.clear();
        
        cout << "Would you like to do another? (Enter Y for yes)" << endl;
        cin >> yesNo;
    } while(yesNo == 'Y' || yesNo == 'y');
    
    return 0;
}

/* NOTE: I tried to write my own vector sorting function but I just couldn't get
it to work. I don't quite understand what I was reading about how I have to set
iterator types using a pointer. I'm going to admit defeat and use <algorithm>
to sort this vector. I would love some feedback on what I'm doing wrong here.

// Vector sorting function. "Makin' Medians EZ" since 2024.
void sortVec(vector<int> &v) {  // Pass by reference to sort the input vector
    int min;
    auto minpos = v.begin();
    for (int i = 0; i < v.size(); ++i) {
        min = 201;
        for (int j = i; j < v.size(); ++j) {
            if (v.at(j) <= min) {
                min = v.at(j);
                *minpos = j;
            }
        }
        v.erase(minpos);
        v.insert(v.begin(), min);
    }
} */
