#include<iostream>
#include<vector>
using namespace std;

void print()
{
	
}
//Variadic templates
template<typename T,typename... Types>
void print(const T& firstArg ,const Types&... args)
{
	cout<<firstArg<<endl;
 	print(args...);
}


//ranged base for
void ranged()
{
	vector<double> vec;
	vec.push_back(2.3);
	vec.push_back(100);
	for(auto i:vec)
	{
		cout<<elem<<" ";
	}
}

int main()
{
	print(7.5,"hello",42);
	ranged();
}

