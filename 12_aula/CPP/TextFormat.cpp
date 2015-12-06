class TextFormat : public TextItem {
private:
    std::shared_ptr<TextItem> _textItem;

public:
    TextFormat(  std::shared_ptr<TextItem> textItem) {
        _textItem = textItem;
    }

    std::shared_ptr<TextItem> getTextItem() {
        return _textItem;
    }

    std::string render() {
        return _textItem->render();
    }
};
