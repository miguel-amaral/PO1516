#include "PageElement.cpp"

class Image : public PageElement {
public:
    std::string render() {
        return "<img src=\"IMG\"/>";
    }
};
