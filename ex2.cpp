#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

typedef unsigned int UnsInt;
int main()
{
vector<UnsInt> vector(15);
auto print = [](UnsInt value){cout<<value<<endl;};
auto randomassign=[](UnsInt& pos){UnsInt r = (rand() % 100) + 1;pos = r;};
for_each(vector.begin(), vector.end(), randomassign);
for_each(vector.begin(), vector.end(), print);
return 0;
}