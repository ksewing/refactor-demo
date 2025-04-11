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
#include <algorithm> 
using namespace std;

// Vector printing function.  Provided for convenience for intermediate testing.
void printVector(vector<int> v){
    for (int e: v){
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
        for (int j : v) if (j == i) count++;
         
        // Now, print a bar in the graph.
        cout << i << ": ";
        for (int k = 0; k < count; ++k) cout << "|"; 
        cout << endl;
        count = 0;
    }
    
}

void stats(vector<int> vector_data) {
    int sum = 0;
    int mode = vector_data.at(0); 
    int modeCount = 0;
    int modeValMax = 0;
    int modeCountMax = 0;
    for (unsigned int i = 0; i < vector_data.size(); ++i) {
        sum += vector_data.at(i);
        if (vector_data.at(i) == mode) modeCount++;
        else {
            if (modeCount >= modeCountMax) {
                if (i != vector_data.size() - 1) modeValMax = vector_data.at(i - 1);
                else modeValMax = vector_data.at(i);
                modeCountMax = modeCount;
            }
            mode = vector_data.at(i);
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
        
        // Take data from user input. -1 ends the input.
        do {
            cin >> nextInt;
            if (nextInt >= 0 && nextInt <= 200) dataVec.push_back(nextInt);
            else if (nextInt != -1) {
                cout << "Invalid entry: " << nextInt << ". Skipping this entry.\n";
            }
        } while (nextInt != -1);
        // Call functions to process data
        if (dataVec.size() > 0) sort(dataVec.begin(), dataVec.end());
        barGraph(dataVec);
        stats(dataVec);
        dataVec.clear();
        
        cout << "Would you like to do another? (Enter Y for yes)" << endl;
        cin >> yesNo;
    } while(yesNo == 'Y' || yesNo == 'y');
    
    return 0;
}
