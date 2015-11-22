#include <iostream>
#include "Page.cpp"
#include "Paragraph.cpp"
#include "Span.cpp"
#include "Image.cpp"

int main() {
    std::shared_ptr<Page> page = std::make_shared<Page>();
    std::shared_ptr<Paragraph> p1 = std::make_shared<Paragraph>();
    p1->addElement(std::make_shared<Span>());
    p1->addElement(std::make_shared<Span>());
    std::shared_ptr<Paragraph> p2 = std::make_shared<Paragraph>();
    p2->addElement(std::make_shared<Image>());
    page->addElement(p1);
    page->addElement(p2);
    std::cout << page->render();
}


/* Image.cpp */
#include "PageElement.cpp"

class Image : public PageElement {
public:
    std::string render() {
        return "<img src=\"IMG\"/>";
    }
};

/* Page.cpp */
#include <forward_list>
#include <list>
#include "PageElement.cpp"

class Page : public PageElement {
private:
    std::list< std::shared_ptr<PageElement> > _mylist;
public:
    void addElement(std::shared_ptr<PageElement> e){
      _mylist.push_back(std::move(e));
    }

    std::string render() {
        std::string rendered = "<page>\n";
        for (std::shared_ptr<PageElement> e : _mylist)
            rendered += e->render() + "\n";
        return rendered + "</page>";
    }
};
/* PageElement.cpp */
#pragma once

class PageElement {
public:
    virtual std::string render() = 0;
};


















/* Paragraph.cpp */
#include <forward_list>
#include <list>
#include "PageElement.cpp"

class Paragraph : public PageElement {
private:
    std::list< std::shared_ptr<PageElement> > _mylist;
public:
    void addElement(std::shared_ptr<PageElement> e){
      _mylist.push_back(std::move(e));
    }

    std::string render() {
        std::string rendered = "<p>\n";
        for (std::shared_ptr<PageElement> e : _mylist)
            rendered += e->render() + "\n";
        return rendered + "</p>";
    }
};

/* Span.cpp */
#include "PageElement.cpp"

class Span : public PageElement {
public:
    std::string render() {
        return "<span>TEXT</span>";
    }
};
