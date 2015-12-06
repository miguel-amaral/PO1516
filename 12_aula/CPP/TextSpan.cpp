#include "TextItem.cpp"

class TextSpan : public TextItem {
private:
    std::string _text = "";
public:
    TextSpan(std::string text) {
        _text = text;
    }
    std::string render() {
        return "<span>" + _text + "</span>";
    }
};
