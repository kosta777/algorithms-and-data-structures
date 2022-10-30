#include <vector>

template <typename RandomIt, typename Compare>
std::vector<typename RandomIt::value_type> merge(RandomIt begin, RandomIt mid, RandomIt end, Compare comp){
    std::vector<typename RandomIt::value_type> v;
    RandomIt it_l{begin}, it_r{mid};
    const RandomIt it_mid {mid}, it_end{ end};

    while(it_l != it_mid && it_r != it_end){
        v.push_back(comp(*it_l, *it_r) ? *it_l++: *it_r++);
    }

    v.insert(v.end(), it_l, it_mid);
    v.insert(v.end(), it_r, it_end);

    return std::move(v);
}

template <typename RandomIt, typename Compare>
void merge_sort(RandomIt begin, RandomIt end, Compare comp){
    auto size = std::distance(begin, end);
    if(size < 2)
        return;

    auto mid = std::next(begin, size/2);
    merge_sort(begin, mid, comp);
    merge_sort(mid, end, comp);

    auto &&v = merge(begin, mid, end, comp);
    std::move(v.cbegin(), v.cend(), begin);
}
