#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    const int N = 5;
    int arr[] = {1,2,3,4,5};
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    // safe transform
    for (auto & elem : arr)
      cout << elem;

    // reasonable transform
    for (auto & elem : v)
      cout << elem;

    // reasonable transform
    for (auto & elem : v)
      cout << elem;
}
