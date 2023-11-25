//
// Created by miaohaochu on 2023/10/20.
//
#include "iostream"

class StrBlob {
public:
   typedef std::vector<std::string>::size_type size_type;
   StrBlob() :data_(std::make_shared<std::vector<std::string>>()) {

   };
   StrBlob(std::initializer_list<std::string> list)
   : data_(std::make_shared<std::vector<std::string>>(list))
   {

   };
private:
    std::shared_ptr<std::vector<std::string>> data_;

};
