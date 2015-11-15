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
