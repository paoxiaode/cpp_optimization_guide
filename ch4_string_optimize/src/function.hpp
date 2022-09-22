#include <iostream>

std::string remove_ctrl(std::string s);
std::string remove_ctrl_mutating(std::string s);
std::string remove_ctrl_reserve(std::string s);
std::string remove_ctrl_ref_args(std::string const& s);
std::string remove_ctrl_ref_args_it(std::string const& s);
std::string remove_ctrl_block(std::string const& s);
std::string remove_ctrl_block_append(std::string const& s);



std::string remove_ctrl(std::string s){
    std::string result;
    for(std::size_t i = 0; i < s.size(); i++){
        if(s[i] >= 0x20){
            result = result + s[i];
        }
    }
    return result;
}

std::string remove_ctrl_mutating(std::string s){
    std::string result;
    for(std::size_t i = 0; i < s.size(); i++){
        if(s[i] >= 0x20){
            result += s[i];
        }
    }
    return result;
}

std::string remove_ctrl_reserve(std::string s){
    std::string result;
    result.reserve(s.length());
    for(std::size_t i = 0; i < s.size(); i++){
        if(s[i] >= 0x20){
            result += s[i];
        }
    }
    return result;
}

std::string remove_ctrl_ref_args(std::string const& s)
{
    std::string result;
    result.reserve(s.length());
    for(std::size_t i = 0; i < s.size(); i++){
        if(s[i] >= 0x20){
            result += s[i];
        }
    }
    return result;
}

std::string remove_ctrl_ref_args_it(std::string const& s)
{
    std::string result;
    result.reserve(s.length());
    for(auto i = s.begin(), end = s.end(); i != end; ++i){
        if(*i >= 0x20){
            result += *i;
        }
    }
    return result;
}

std::string remove_ctrl_block(std::string const& s){
    std::string result;
    result.reserve(s.length());
    for(std::size_t i = 0, e = s.length(), j = i; i < e; i = j + 1){
        while (s[j] >= 0x20)
        {
            ++j;
        }
        result += s.substr(i, j - i);
    }
    return result;
}

std::string remove_ctrl_block_append(std::string const& s){
    std::string result;
    result.reserve(s.length());
    for(std::size_t i = 0, e = s.length(), j = i; i < e; i = j + 1){
        while (s[j] >= 0x20)
        {
            ++j;
        }
        result.append(s, i, j - i);
    }
    return result;
}
