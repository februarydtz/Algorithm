#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v1;
    v1.push_back(1);
    vector<int> v2(10, 2);
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    vector<int> v3(arr, arr+10);
    vector<int> v4(v3.begin(), v3.end());
    vector<int>::iterator it = v2.begin();
    while (it != v2.end()){
        cout << *it << " ";
        it++;
    }
    cout << endl;
    v3.push_back(2);
    for (auto i : v3)
        cout << i << " ";
    cout << endl;
    v3.pop_back();
    for (auto i : v3)
        cout << i << " ";
    cout << endl;
    v3.insert(v3.begin()+2, 10);
    for (auto i : v3)
        cout << i << " ";
    cout << endl;
    v3.erase(v3.begin());
    for (auto i : v3)
        cout << i << " ";
    cout << endl;
    v3.erase(v3.begin(), v3.begin()+2);
    for (auto i : v3)
        cout << i << " ";
    cout << endl;
    v3.clear();
    cout << v3.size() << endl;
    cout << v3.empty() << endl;
    return 0;
}