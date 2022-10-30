#include <vector>
#include <iostream>
#include "includes/insertion_sort.h"
#include "includes/merge_sort.h"

int main(){
	std::vector<int> a = {8, 7, 6, 5, 4, 3, 2, 1};

	merge_sort(a.begin(), a.end(), [](int a, int b){ return a<b; });
	for(auto val: a)
		std::cout<<val<<std::endl;
	return 0;
}
