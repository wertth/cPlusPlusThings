//
// Created by miaohaochu on 2023/12/2.
//
#include "json.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <future>

const std::string PREFIX_URL =  "/Users/miaohaochu/CLionProjects/cPlusPlusThings/regex/";


void remove_pattern(std::string& str,const  std::regex& pattern) {
    str = std::regex_replace(str,pattern, "");

}

void dealJson(nlohmann::json& jsonObject) {
    // merge title and abstract
    std::string title = jsonObject["title"];
    std::string abstract = jsonObject["abstract"];
    // add new attr
    title += "-" + abstract;

    std::vector<std::regex> regexes = {
            std::regex(R"(\$[^$]*\$)"),
            std::regex(R"(\\\[.*?\\\])")
    };


    for(const auto& regex: regexes) {
        remove_pattern(title,regex);
    }

    jsonObject["text"] = title.c_str();

    jsonObject.erase("title");
    jsonObject.erase("abstract");


}


bool readAndDealJson(int id) {
    try {
        char buffer [128], outBuffer [128];
        snprintf(buffer,sizeof(buffer), "%sraw-arxiv/train_%d.jsonl", PREFIX_URL.c_str(),id);
        snprintf(outBuffer, sizeof(outBuffer), "%smodified/train_modified_%d.jsonl", PREFIX_URL.c_str(),id);
        std::ifstream file(buffer);
        std::ofstream outFile(outBuffer);
        std::string line;

        if (file.is_open() && outFile.is_open()) {
            while (getline(file, line)) {
                nlohmann::json json_line = nlohmann::json::parse(line);
                // 处理 json_line 对象
                dealJson(json_line);

                outFile << json_line.dump(4);

            }
            file.close();
            outFile.close();
            return true;
        } else {
            std::cout << "无法打开文件" << std::endl;
            return false;
        }
    } catch (std::exception& err) {
        return false;
    }
}



int main() {
    const int num_files = 21;
    std::vector<std::future<bool>> futures;

    futures.reserve(num_files);
    for (int i = 0; i < num_files; ++i) {
        // 使用 std::async 启动异步任务
        futures.push_back(std::async(std::launch::async, readAndDealJson, i));
    }

    for (auto& f : futures) {
        bool result = f.get();  // 这将阻塞，直到相应的任务完成
        // 处理结果
    }


    return 0;
}
