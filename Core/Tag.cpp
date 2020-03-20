//
// Created by Dana on 16.03.2020.
//

#include "Tag.h"
#include <algorithm>

Tag::Tag(std::string name) {
//    if (std::find_if(allTags.begin(), allTags.end(), [name](Tag tag)->bool{return name == tag.getName();})
//        != allTags.end())
//        //TODO: Error, tag already exists
//        return;

    this->name = name;
    allTags.insert(*this);
}

Tag::~Tag() {
    allTags.erase(*this);
    delete this;
}

const std::string &Tag::getName() const {
    return name;
}

void Tag::setName(const std::string &name) {
    Tag::name = name;
}

bool operator==(const Tag& lhs, const Tag& rhs) {
    return lhs.getName() == rhs.getName();
}
