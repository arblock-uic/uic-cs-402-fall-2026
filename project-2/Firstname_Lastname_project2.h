
// be sure to change FIRSTNAME and LASTNAME with your own first and last name
#ifndef FIRSTNAME_LASTNAME_PROJECT2
#define FIRSTNAME_LASTNAME_PROJECT2

#include <functional>


// function declarations
std::vector<unsigned int> birthday_attack_1(std::function<unsigned short(unsigned int)> hash_function);
std::vector<unsigned int> birthday_attack_2(std::function<unsigned short(unsigned int)> hash_function);

#endif
