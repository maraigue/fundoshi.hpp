#include "fundoshi.hpp"
#include <iostream>
#include <string>

int main(void){
    fundoshi::string fs1, fs2;
    
    // const char *からfundoshi::stringを生成する例
    fs1 = fundoshi::string("abcde");
    
    std::cout << fs1.length() << std::endl; // 5 が表示される
    std::cout << fs1[0] << std::endl; // a が表示される
    std::cout << fs1[2] << std::endl; // c が表示される
    
    // std::stringからfundoshi::stringを生成する例
    std::string x("abcde");
    fs1 = fundoshi::string(x);
    
    std::cout << fs1.length() << std::endl; // 5 が表示される
    std::cout << fs1[0] << std::endl; // a が表示される
    std::cout << fs1[2] << std::endl; // c が表示される
    
    // std::stringのインスタンスとメモリを共有したまま、
    // それの部分文字列に相当するfundoshi::stringを生成する例
    fs2 = fundoshi::string(&(x[1]), 3); // ここで、yは「"bcd"」を表している
    
    std::cout << fs2.length() << std::endl; // 3 が表示される
    std::cout << fs2[0] << std::endl; // b が表示される
    std::cout << fs2[2] << std::endl; // d が表示される
    
	// メモリは共有されているので、元のメモリを書き換えると
	// fundoshi::stringインスタンスの内容も変更される
    x[2] = 'f';
    std::cout << fs1[2] << std::endl; // f が表示される
    std::cout << fs2[1] << std::endl; // f が表示される

    // fundoshiにはwstringも存在する
    fundoshi::wstring fws(L"vwxyz");
    
    std::cout << fws.length() << std::endl; // 5 が表示される
    std::cout << fws[0] << std::endl; // vのASCIIコード（118）が表示される
    std::cout << fws[2] << std::endl; // xのASCIIコード（120）が表示される
    
    // charやwchar_t以外も使える
    int y[10] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
    fundoshi::basic_string<int> fi(y, 10);
    
    std::cout << fi.length() << std::endl; // 10 が表示される
    std::cout << fi[5] << std::endl; // 25 が表示される
    std::cout << fi[8] << std::endl; // 64 が表示される
    
    // 文字列比較
    std::cout << "string comparison" << std::endl;
    
    fs1 = fundoshi::string("abc");
    fs2 = fundoshi::string("abc");
    std::cout << (fs1 == fs2); // 1が表示される
    std::cout << (fs1 >  fs2); // 0が表示される
    std::cout << (fs1 >= fs2); // 1が表示される
    std::cout << (fs1 <  fs2); // 0が表示される
    std::cout << (fs1 <= fs2); // 1が表示される
    std::cout << std::endl;
    
    fs2 = fundoshi::string("adc");
    std::cout << (fs1 == fs2); // 0が表示される
    std::cout << (fs1 >  fs2); // 0が表示される
    std::cout << (fs1 >= fs2); // 0が表示される
    std::cout << (fs1 <  fs2); // 1が表示される
    std::cout << (fs1 <= fs2); // 1が表示される
    std::cout << std::endl;
    
    fs2 = fundoshi::string("ab");
    std::cout << (fs1 == fs2); // 0が表示される
    std::cout << (fs1 >  fs2); // 1が表示される
    std::cout << (fs1 >= fs2); // 1が表示される
    std::cout << (fs1 <  fs2); // 0が表示される
    std::cout << (fs1 <= fs2); // 0が表示される
    std::cout << std::endl;

    fs2 = fundoshi::string("abcd");
    std::cout << (fs1 == fs2); // 0が表示される
    std::cout << (fs1 >  fs2); // 0が表示される
    std::cout << (fs1 >= fs2); // 0が表示される
    std::cout << (fs1 <  fs2); // 1が表示される
    std::cout << (fs1 <= fs2); // 1が表示される
    std::cout << std::endl;
    
    return 0;
}
