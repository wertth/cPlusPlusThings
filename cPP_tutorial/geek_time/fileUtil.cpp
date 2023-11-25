//
// Created by miaohaochu on 2023/10/26.
//
#include "iostream"
#include "fstream"
#include "nocopyable.h"
#include "stdexcept"
#include "cassert"
#define BLOCK_SIZE (64*1024)
namespace muduoExp {
    namespace fileUtil {
        using ReadBlockCallBack = std::function<void(const char*, std::size_t)>;



        auto defaultCallback = [](const char* str, std::size_t size) {
            std::cout<< std::string(str,size);
        };

        template<typename ContentType>
        bool read(std::string & path, ContentType&  content,std::size_t blockSize = BLOCK_SIZE , const ReadBlockCallBack& callback = defaultCallback) {
            static_assert(std::is_same_v<ContentType, std::string> || std::is_same_v<ContentType, std::vector<char>>,"ContentType must be std::string or std::vector<char>");
            std::ifstream in(path, std::ios::binary);
            if(!in.is_open()) {
                throw std::runtime_error("Failed to open the file: "+path );
            }
            std::vector<char> buffer(blockSize);
            while(!in.eof()) {
                in.read(buffer.data(), blockSize);
                std::size_t readSize = in.gcount();
                if(readSize > 0) {
                    callback(buffer.data(),readSize);
                    content.insert(content.end(),buffer.begin(),buffer.begin() + readSize);
                }
            }
            in.close();
            return true;
        }

        template<typename ContentType>
        bool write(std::string& path, ContentType & content, std::size_t blockSize = BLOCK_SIZE , const ReadBlockCallBack& callback = defaultCallback){
            static_assert(std::is_same_v<ContentType, std::string> || std::is_same_v<ContentType, std::vector<char>>,"ContentType must be std::string or std::vector<char>");
            std::ofstream out(path,std::ios::binary);
            if(!out.is_open()){
                throw std::runtime_error("Failed to open the file: "+path );
            }
            auto contentSize = content.size();
            int blockNum = (contentSize + blockSize -1)/ blockSize;  // 向上取整
            for(std::size_t block = 0; block < blockNum ; block ++ ) {
               auto begin = content.begin() + block* blockSize;
               auto end = (block == blockNum - 1) ? content.end() : begin + blockSize;
               std::vector<char> buffer(begin, end);
               out.write(buffer.data(), buffer.size());
                if (!out) {
                    throw std::ios_base::failure("Failed to write data to file");
                }

                if (callback) {
                    callback(buffer.data(), buffer.size());  // 调用回调函数，如果有的话
                }
            }
            out.close();
            return true;
        }



    }
}
