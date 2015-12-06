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
