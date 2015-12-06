#include <forward_list>

class Bold : public TextFormat {
public:
    Bold(std::shared_ptr<TextItem> textItem) : TextFormat(textItem){}

    std::string render() {
        return "<b>" + TextFormat::render() + "</b>";
    }
};
