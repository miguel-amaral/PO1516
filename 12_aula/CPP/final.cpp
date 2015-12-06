/* -------------- */
/*  TextItem.cpp  */
/* -------------- */
#include <string>

class TextItem {
public:
    virtual std::string render() = 0;
};

/* -------------- */
/*  TextSpan.cpp  */
/* -------------- */
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

/* -------------- */
/* TextFormat.cpp */
/* -------------- */
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

/* -------------- */
/*    Bold.cpp    */
/* -------------- */
#include <forward_list>

class Bold : public TextFormat {
public:
    Bold(std::shared_ptr<TextItem> textItem) : TextFormat(textItem){}

    std::string render() {
        return "<b>" + TextFormat::render() + "</b>";
    }
};

/* -------------- */
/*  Underline.cpp */
/* -------------- */
#include <forward_list>

class Underline : public TextFormat {
public:
    Underline(std::shared_ptr<TextItem> textItem) : TextFormat(textItem){}

    std::string render() {
        return "<u>" + TextFormat::render() + "</u>";
    }
};

/* -------------- */
/*   Italic.cpp   */
/* -------------- */
#include <forward_list>

class Italic : public TextFormat {
public:
    Italic(std::shared_ptr<TextItem> textItem) : TextFormat(textItem){}

    std::string render() {
        return "<i>" + TextFormat::render() + "</i>";
    }
};

/* -------------- */
/*    main.cpp    */
/* -------------- */
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <forward_list>

#include "TextSpan.cpp"
#include "TextFormat.cpp"
#include "Bold.cpp"
#include "Underline.cpp"
#include "Italic.cpp"


int main() {
    std::shared_ptr<TextItem> span1 = std::make_shared<TextSpan>("BATATA");
    std::shared_ptr<TextItem> text1 = std::make_shared<Bold>(span1);
    std::shared_ptr<TextItem> text2 = std::make_shared<Underline>(std::make_shared<Bold>(std::make_shared<Italic>(span1)));

    std::cout << std::endl<< std::endl<< span1->render() << std::endl<< std::endl;
    std::cout << std::endl<< std::endl<< text1->render() << std::endl<< std::endl;
    std::cout << std::endl<< std::endl<< text2->render() << std::endl<< std::endl;
}
