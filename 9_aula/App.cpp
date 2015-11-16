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
