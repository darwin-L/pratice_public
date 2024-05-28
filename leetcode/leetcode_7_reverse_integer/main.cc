#include<vector>
#include<iostream>
#include<sstream>
#include<string>

// 不使用interger去處理這個問題是因為要特別處理逸位和0結尾
// 用陣列相對單純
class Solution {
public:
    int reverse(int x) {
        
    }
};

int main (void) {
    std::cout<<"w"<<std::endl;
    // std::stringstream sout;
    std::ostringstream sout;
    sout << 123456;
    // std::string test_str;
    std::cout<<sout.str().c_str();
    std::string a = sout.str();

    std::vector<char> v(a.begin(), a.end());
 
    for (const char &c: v) {
        std::cout << c;
    }

    // std::vector<int> dest;
    // std::copy(std::begin(sout.str().c_str()), std::end(sout.str().c_str()), std::back_inserter(dest));
    return 0;
}