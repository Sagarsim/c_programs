#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
bool f(int x, int y){
    return x > y;
}

void vectorDemo(){
    cout << "VECTORS:" << endl;
     vector<int> A = { 11, 2, 3, 14};
    cout << A[1] << endl;
    cout << endl;

    sort(A.begin(), A.end()); //O(nlogn) Merge Sort
    for(int j = 0;j < A.size(); j++)
        cout << A[j] << " ";
    cout << endl;

    A.push_back(7);
    sort(A.begin(), A.end());
    for(int j = 0;j < A.size(); j++)
        cout << A[j] << " ";
    cout << endl;

    bool present = binary_search(A.begin(), A.end(), 7); //O(logn)
    cout << present << endl;
    present = binary_search(A.begin(), A.end(), 5);
    cout << present << endl;
    cout << endl;

    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(123);// A.pop_back() for removing last element
    //vector iterators are pointers
    vector<int>::iterator it = lower_bound(A.begin(), A.end(), 100); // >= 100 , for sorted vector takes O(logn)
    //OR
    auto it2 = upper_bound(A.begin(), A.end(), 100); // > 100 , for sorted vector takes O(logn)
    cout << *it << " " << *it2 << endl;
    cout << it2 - it << endl; //O(1), no. of occurences of 100
    cout << endl;
    //sort in descending order
    sort(A.begin(), A.end(), f);// f is a comparative function and is overloaded
    //short syntex to print vector
    for(int j: A)// read as for int j in A..
        cout << j << " ";
    cout << endl;

    for(int &j: A)// use for(int &j: A) for modifying the original vector A
        j++;
        
    cout << endl;

    for(int j: A)
        cout << j << " ";
    cout << endl;

}

int setDemo(){
    cout << "SET:" << endl;
    set<int> S;//set of integers
    S.insert(1);//takes O(logn) with sorting, better than O(nlogn) in vector;
    S.insert(2);
    S.insert(5);
    S.insert(-1);
    S.insert(3);// S.erase(3) for removing no. in O(logn)

    for(int i: S)
        cout << i << " ";
    cout << endl;

    auto it = S.find(-1);//if not found, iterator points to S.end()

    if(it == S.end())
        cout << "not present" << endl;
    else
        cout << "present: "<< *it << endl; 
    auto it2 = S.lower_bound(-1); // >= -1
    auto it3 = S.upper_bound(-1); // > -1
    auto it4 = S.upper_bound(7); //points to S.end() as not found value gt 7
    cout << *it2 << " " << *it3 << " " << *it4 << endl;
}

void mapDemo(){
    cout << "MAPS:"<< endl;
    map<int, int> no; // map int to int
    no[1] = 27;
    no[2] = 30;
    //no.find(key), no.erase(key) takes O(logn)
    map<char, int> charCnt;
    string me = "Sagar Gujarati";
    for(char a: me)
        charCnt[a]++;
    cout << "No. of occurences of 'a': " << charCnt['a'] << endl;
}
void sample(){
    
    set< pair<int, int> > interval;// pairs eg. {1, 2}, {1, 'a'} etc.
    interval.insert({20, 30});
    interval.insert({31, 40});
    interval.insert({41, 50});
    interval.insert({51, 60});
    
    int point = 0; //find interval of this point
    cout << "Get interval for: ";
    cin >> point;
    auto finterval = interval.upper_bound({point, INT_MAX});

    if(finterval == interval.begin()){
        cout << "Interval not found..." << endl;
        return;
    }

        //select previous interval as answer
    finterval--;
    //{first, second} for pairs
    pair<int, int> temp = *finterval;
    if(temp.first <= point && temp.second >= point)
        cout << "Interval found: " << "between " << temp.first << " and " << temp.second << endl;
    else 
        cout << "Interval not found..." << endl;
   
}
int main(){
   vectorDemo();
   setDemo();
   mapDemo();
   sample();
}