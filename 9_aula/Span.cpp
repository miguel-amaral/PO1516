#include "PageElement.cpp"

class Span : public PageElement {
public:
    std::string render() {
        return "<span>TEXT</span>";
    }
};
