#include <iostream>
#include<string>
#include <algorithm>
using namespace std;

bool isPossible(int stalls[], int minDist, int numCows, int numStalls){
    int lastCowPos = stalls[0];
    numCows--;
    for(int i = 1; i < numStalls; i++){
        if(stalls[i] - lastCowPos >= minDist){
            lastCowPos = stalls[i];
            numCows--;
        }
    }
    if(numCows <= 0){
        return true;
    } else {
        return false;
    }
}

int main()
{
    string line;
    getline(cin, line);
    int numCases = stoi(line);
    for(int i = 0; i < numCases; i++){
        getline(cin, line);
        int numStalls = stoi(line.substr(0, line.find(' ')));
        int numCows = stoi(line.substr(line.find(' '), line.size()));
        int *stalls = new int[numStalls];
        for(int j = 0; j < numStalls; j++) {
            getline(cin, line);
            stalls[j] = stoi(line);
        }
        sort(stalls, stalls+numStalls);

        int left = stalls[0];
        int right = stalls[numStalls-1];
        int lastSuccess = -1;
        int num = (left + right) / 2;
        while(true){
            if(isPossible(stalls, num, numCows, numStalls)){
                lastSuccess = num;
                left = num;
                num = (num + right)/2;
                if(num == left){
                    break;
                }
            } else {
                right = num;
                num = (num + left)/2;
                if(num == right){
                    break;
                }
            }
        }
        cout << lastSuccess << endl;
    }
    return 0;
}