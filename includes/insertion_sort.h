#include <vector>
#include <iostream>

template <typename RandomIt, typename Compare>
void insertion_sort(RandomIt first, RandomIt last, Compare comp){
	RandomIt j = first+1;
	while(j < last){
		// Insert *j into the sorted sequence 0..j-1, by swaping places of consecutive elements until *j is in the right spot
		RandomIt i = j-1;
		while(i >= first && comp(*(i+1), *i)){
			std::iter_swap(i+1, i);
			i--;
		}
		j++;
	}
}
