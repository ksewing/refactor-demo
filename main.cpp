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
#include <algorithm> // Sorry. Had to use <algorithm>'s sort() method.
using namespace std;

// Vector printing function.  Provided for convenience for intermediate testing.
void printVector(vector<int> vector){
    for (int element: vector){
        cout << element << " ";
    }
    cout << endl;
}



void barGraph(vector<int> vector) {
    if (vector.empty()) {
        cout << "ERROR: Empty vector! Aborting.\n";
        return;
    }
    
    int minVal = vector.front();
    int maxVal = vector.back();
    
    for (int i = minVal; i <= maxVal; ++i) {
        int count = 0;
    
        for (int val : vector) {
            if (val == i) count++;
        }
    
        cout << i << ": ";
        for (int j = 0; j < count; ++j) cout << "|";
        cout << endl;
    }
 
}

void stats(vector<int> v) {
    int sum = 0;
    int mode = v.at(0); // Already handled empty vector error in barGraph()
    int modeCount = 0;
    int modeValMax = 0;
    int modeCountMax = 0;
    for (unsigned int i = 0; i < v.size(); ++i) {
        sum += v.at(i);
        if (v.at(i) == mode) modeCount++;
        else {
            if (modeCount >= modeCountMax) {
                if (i != v.size() - 1) modeValMax = v.at(i - 1);
                else modeValMax = v.at(i);
                modeCountMax = modeCount;
            }
            mode = v.at(i);
            modeCount = 1;
        }
    }

    float mean =  (double) sum / v.size();
    float median = v.at(v.size() / 2);

    printf("Mean: %.2f\n", mean);
    printf("Median: %d\n",median );
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
            if (nextInt >= 0 && nextInt <= 200) dataVec.push_back(nextInt);
            else if (nextInt != -1) {   // Avoid error message if entry is -1
                cout << "Invalid entry: " << nextInt << ". Skipping this entry.\n";
            }
        } while (nextInt != -1);
        // Call functions to process data
        if (dataVec.size() > 0) sort(dataVec.begin(), dataVec.end());   // Makes stats functions easier.
        barGraph(dataVec);
        stats(dataVec);
        dataVec.clear();
        
        cout << "Would you like to do another? (Enter Y for yes)" << endl;
        cin >> yesNo;
    } while(yesNo == 'Y' || yesNo == 'y');
    
    return 0;
}