// test with:
// g++ -o ex3 ex3.cpp && ./ex3 1 2 3 3 4 2
// or
// g++ -o ex3 ex3.cpp && ./ex3 1 
#include <random>
#include <iostream>
#include <assert.h>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef unsigned short int UnsShInt;

void test(const UnsShInt a)
{
	assert(a>=1 && a<=6);
}
void test_vector_length(const UnsShInt argc)
{
	assert(argc<=7);
}


int main(int argc, char *argv[])
{	
	UnsShInt tmp=0;
	test_vector_length(argc);

    
	vector<UnsShInt> vect{};

	for( UnsShInt i = 1;i<argc;i++)
	{
		vect.push_back(atoi(argv[i]));
	}


	for (UnsShInt user_number : vect) 
		test(user_number);

	cout<<"You declared the next values: ";
	auto print = [](UnsShInt value){cout<<value<<" ";};
	for_each(vect.begin(), vect.end(), print);
	cout<<endl;

    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist6(1,6); // distribution in range [1, 6]
    UnsShInt win_value = dist6(rng);
    cout<<"Random chose the: "<<win_value<<endl;

   
    	tmp=count(vect.begin(), vect.end(), win_value);
    	if (tmp)
    	{
			cout << "You chose right answer: "<<tmp<< " times." << std::endl;
		}
		else
		cout << "You lost." << std::endl;
	return 0;

}
