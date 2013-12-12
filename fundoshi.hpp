#ifndef _FUNDOSHI_HPP_
#define _FUNDOSHI_HPP_

#include <iostream>
#include <string>
#include <cstring>

// すでにconstな文字列が確保されているメモリ上の領域に対し、
// その部分文字列を、メモリを共有したまま別の文字列のごとく扱うためのクラス。
// 名前の由来は「人のふんどしで相撲を取る」より。
// 
// 例えば、x = std::string("abcde"); y = x.substr(1, 3); のように部分文字列を
// 取得してもよいのだが、その場合新たなstringインスタンスが生成されてしまう。
// そうする必要がない場合、y = fundoshi::string(&(x[1]), 3); とすることで、
// 文字列のメモリをxと共有したまま、yにxの部分文字列を表現させることができる。
// 
// APIはC++標準のstring(basic_string)に似せてあります。が最小限の内容しか実装していません。

namespace fundoshi{
    template <class CharType> class basic_string;
    
    template <class CharType>
    static size_t strlen(const CharType * str){
        size_t result = 0;
        
        while(*str != 0){
            str++;
            result++;
        }
        return result;
    }
    
    template <class CharType>
    static void print_char(std::ostream & os, CharType c){
        if(c >= 0x20 && c <= 0x7E){
            os << static_cast<char>(c);
        }else{
            os << '[' << c << ']';
        }
    }
    
    template <>
    void print_char(std::ostream & os, signed char c){
        if(c >= 0x20 && c <= 0x7E){
            os << c;
        }else{
            os << '[' << static_cast<signed int>(c) << ']';
        }
    }
    
    template <>
    void print_char(std::ostream & os, unsigned char c){
        if(c >= 0x20 && c <= 0x7E){
            os << c;
        }else{
            os << '[' << static_cast<unsigned int>(c) << ']';
        }
    }
    
    template <class CharType>
    static int compare(const basic_string<CharType> & str1, const basic_string<CharType> & str2){
        size_t min_length = (str1.length() < str2.length() ? str1.length() : str2.length());
        for(size_t i = 0; i < min_length; i++){
            if(str1[i] < str2[i]){
                return -1;
            }else if(str1[i] > str2[i]){
                return 1;
            }
        }
        
        // if all characters are compared
        if(str1.length() < str2.length()){
            return -1;
        }else if(str1.length() > str2.length()){
            return 1;
        }
        return 0;
    }
    
    // ---------- basic_string ----------
    template <class CharType>
    class basic_string{
    public:
        typedef size_t size_type;
        typedef CharType value_type;
        typedef const value_type & const_reference;
        typedef const value_type * iterator;
        typedef const value_type * const_iterator;
        typedef iterator reverse_iterator;
        typedef const_iterator const_reverse_iterator;
        
    private:
        const CharType * buffer;
        size_type buffer_length;
        
    public:
        // default constructor (empty string)
        basic_string() : buffer(NULL), buffer_length(0) {}
        
        // constructors for fundoshi::basic_string, std::basic_string, const CharType *
        basic_string(const basic_string<CharType> & other) : buffer(other.buffer), buffer_length(other.buffer_length) {}
        basic_string(const std::basic_string<CharType> & newstr) : buffer(newstr.c_str()), buffer_length(newstr.length()) {}
        basic_string(const CharType * newstr){
            buffer = newstr;
            buffer_length = fundoshi::strlen(buffer);
        }
        basic_string(const CharType * newstr, size_type newstr_length) : buffer(newstr), buffer_length(newstr_length) {}
        basic_string(iterator b, iterator e) : buffer(b), buffer_length(e - b) {}
        
        // constructors for obtaining substrings
        basic_string(const basic_string<CharType> & other, size_type offset, size_type length) : buffer(&(other.buffer[offset])), buffer_length(length) {}
        basic_string(const std::basic_string<CharType> & newstr, size_type offset, size_type length) : buffer(&((newstr.c_str())[offset])), buffer_length(length) {}
        basic_string(const CharType * newstr, size_type offset, size_type length) : buffer(&(newstr[offset])), buffer_length(length) {}
        
        ~basic_string() {}
        
        // operations
        const value_type * c_str(void) const{ return buffer; }
        size_type size(void) const{ return buffer_length; }
        size_type length(void) const{ return buffer_length; }
        const_reference operator [](size_t pos) const{ return buffer[pos]; }
        iterator begin(void){ return buffer; }
        iterator end(void){ return &(buffer[buffer_length]); }
        operator std::basic_string<value_type>(void) const{
            return std::basic_string<value_type>(buffer, buffer_length);
        }
        
        // comparisons
        int compare(const basic_string<CharType> & other) const{
            return fundoshi::compare<CharType>(*this, other); }
        
        bool operator ==(const basic_string<CharType> & other) const {
            return fundoshi::compare<CharType>(*this, other) == 0; }
        
        bool operator !=(const basic_string<CharType> & other) const {
            return fundoshi::compare<CharType>(*this, other) != 0; }
        
        bool operator < (const basic_string<CharType> & other) const {
            return fundoshi::compare<CharType>(*this, other) < 0; }
        
        bool operator <=(const basic_string<CharType> & other) const {
            return fundoshi::compare<CharType>(*this, other) <= 0; }
        
        bool operator > (const basic_string<CharType> & other) const {
            return fundoshi::compare<CharType>(*this, other) > 0; }
        
        bool operator >=(const basic_string<CharType> & other) const {
            return fundoshi::compare<CharType>(*this, other) >= 0; }
    };
    
    typedef basic_string<char> string;
    typedef basic_string<wchar_t> wstring;
};

template <class CharType>
static std::ostream & operator <<(std::ostream & os, const fundoshi::basic_string<CharType> & str){
    for(size_t i = 0; i < str.length(); i++){
        fundoshi::print_char(os, str[i]);
    }
    return os;
}

#endif // _FUNDOSHI_HPP_

