#include <forward_list>

class Underline : public TextFormat {
public:
    Underline(std::shared_ptr<TextItem> textItem) : TextFormat(textItem){}

    std::string render() {
        return "<u>" + TextFormat::render() + "</u>";
    }
};
