#ifndef JSONNODE_H
#define JSONNODE_H
#include <map>
#include <memory>
#include <vector>
#include <stdexcept>
#include <iostream>

namespace JSON {
class JSONNode;
using JSONObject = std::map<std::string, std::shared_ptr<JSONNode>>;
using JSONList = std::vector<std::shared_ptr<JSONNode>>;
class JSONNode;
}

#endif //JSONNODE_H

