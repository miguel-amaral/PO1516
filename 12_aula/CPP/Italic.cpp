#include <forward_list>

class Italic : public TextFormat {
public:
    Italic(std::shared_ptr<TextItem> textItem) : TextFormat(textItem){}

    std::string render() {
        return "<i>" + TextFormat::render() + "</i>";
    }
};
