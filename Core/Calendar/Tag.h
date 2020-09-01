//
// Created by Dana on 16.03.2020.
//

#ifndef SCHEDULER_TAG_H
#define SCHEDULER_TAG_H


#include <string>
#include <unordered_set>

class Tag {

public:
    //TODO: rework the Tag class, it makes no sense

    Tag(std::string name);
    ~Tag() = default;
    Tag(const Tag& original) = delete;
    Tag(Tag&& original) = delete;
    Tag& operator=(const Tag& original) = delete;
    Tag& operator=(Tag&& original) noexcept = delete;

    void addTag(const Tag& tag);
    void removeTag(const Tag& tag);
    std::unordered_set<Tag> getAllTags() const;
    const std::string &getName() const;
    void setName(const std::string &name);

private:
    std::string name = "";
    static std::unordered_set<Tag> allTags;

};


#endif //SCHEDULER_TAG_H
