#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

//#include "/grading_dir/tests/extra/testing.h"
#include "/grading_dir/tests/extra/testing.cpp"

const std::string who_am_i();
const std::string filename = "/grading_dir/results/feedback/" + who_am_i() + " [quick_sort].txt";


template<typename T>
void quicksort(std::vector<T>& list, bool descending = false);


int main() {

    double total_points = 17.0;
    double score = 0.0;
    

    std::ofstream out_file(filename);

    // different type tests; 1 point each (6 total)
    std::vector<StableChar> char_test = gen_stable_char_one_percent(9);
    std::vector<StableString> string_test = gen_stable_string_one_percent(9);

    quicksort(char_test);
    if(std::is_sorted(char_test.begin(), char_test.end())) ++score;
    else out_file << "char_test failed" << std::endl;

    char_test.clear();

    quicksort(string_test);
    if(std::is_sorted(string_test.begin(), string_test.end())) ++score;
    else out_file << "string_test failed" << std::endl;

    string_test.clear();

    std::vector<short> short_test = gen_unique_short_list(259);
    std::vector<unsigned short> unsigned_short_test = gen_unique_unsigned_short_list(250);

    quicksort(short_test);
    if(std::is_sorted(short_test.begin(), short_test.end())) ++score;
    else out_file << "short int test failed" << std::endl;
    short_test.clear();

    quicksort(unsigned_short_test);
    if(std::is_sorted(unsigned_short_test.begin(), unsigned_short_test.end())) ++score;
    else out_file << "unsigned short int test failed" << std::endl;
    unsigned_short_test.clear();


    std::vector<long> long_test = gen_unique_long_list(601);
    std::vector<unsigned long> unsigned_long_test = gen_unique_unsigned_long_list(598);

    quicksort(long_test);
    if(std::is_sorted(long_test.begin(), long_test.end())) ++score;
    else out_file << "long int test failed" << std::endl;

    long_test.clear();

    quicksort(unsigned_long_test);
    if(std::is_sorted(unsigned_long_test.begin(), unsigned_long_test.end())) ++score;
    else out_file << "unsigned long int test failed" << std::endl;

    unsigned_long_test.clear();






    // (unsigned) int different number tests; one point per pair (10 total)
    double asc_des_score = 0.0;
    unsigned int size_list[10] = {32, 64, 128, 256, 1024, 4098, 16384, 65536, 262144, 1048576}; 
    int perturb_list[10] = {0, 0, 13, -5, -19, 17, 7, -3, 9, -11};
    for(int i = 0; i < 5; ++i) {

        std::vector<int> ascending_test1 = gen_unique_int_list(size_list[i]+perturb_list[i]);
        std::vector<int> descending_test1(ascending_test1);
        quicksort(ascending_test1);
        quicksort(descending_test1,true);
        if(std::is_sorted(ascending_test1.begin(), ascending_test1.end())) ++asc_des_score;
        else out_file << "Ascending test 1 failed" << std::endl;
        ascending_test1.clear();

        if(std::is_sorted(descending_test1.begin(), descending_test1.end(), std::greater<>{})) ++asc_des_score;
        else out_file << "Descending test 1 failed" << std::endl;
        descending_test1.clear();

        std::vector<unsigned int> ascending_test2 = gen_unique_unsigned_int_list(size_list[i]+perturb_list[i]);
        std::vector<unsigned int> descending_test2(ascending_test2);

        quicksort(ascending_test2);
        quicksort(descending_test2,true);



        if(std::is_sorted(ascending_test2.begin(), ascending_test2.end())) ++asc_des_score;
        else out_file << "Ascending test 2 failed" << std::endl;
        ascending_test2.clear();

        if(std::is_sorted(descending_test2.begin(), descending_test2.end(), std::greater<>{})) ++asc_des_score;
        else out_file << "Descending test 2 failed" << std::endl;
        descending_test2.clear();

    }

    score += (asc_des_score / 2);
    
    
    // Empty list test; 1 point
    std::vector<int> empty_test {};

    quicksort(empty_test);
    if(std::is_sorted(empty_test.begin(), empty_test.end())) ++score;
    else out_file << "Empty test failed" << std::endl;

    out_file.close();

    RESULT(100*(score / total_points));


    return 0;
}
