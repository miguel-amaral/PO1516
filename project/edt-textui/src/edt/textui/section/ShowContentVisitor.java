package edt.textui.section;

import static ist.po.ui.Dialog.IO;
import ist.po.ui.Command;
import ist.po.ui.DialogException;

import edt.TextElement;
import edt.Section;
import edt.Paragraph;
import edt.Document;
import edt.ShowTextElementVisitor;
import java.util.ArrayList;


public class ShowContentVisitor extends ShowTextElementVisitor{

  private ArrayList<String> visitEachInnerElement(Section section){
    ArrayList<String> sectionStrings = new ArrayList<String>();

    ArrayList<TextElement> elements = section.getContent();
    for (TextElement element : elements){
      sectionStrings.addAll(element.accept(this));
    }

    return sectionStrings;
  }

  public ArrayList<String> visitDocument(Document document) {
    ArrayList<String> sectionStrings = new ArrayList<String>();

    sectionStrings.add("{" + document.getTitle() + "}");
    // Recursively add each inner element to the array
    sectionStrings.addAll( visitEachInnerElement(document) );

    return sectionStrings;
  }
  public ArrayList<String> visitSection(Section section){
    ArrayList<String> sectionStrings = new ArrayList<String>();

    sectionStrings.add(Message.sectionIndexEntry( section.getUniqueId(), section.getTitle()));
    // Recursively add each inner element to the array
    sectionStrings.addAll( visitEachInnerElement(section) );

    return sectionStrings;
  }
  public ArrayList<String> visitParagraph(Paragraph paragraph){
    ArrayList<String> textoParagrafo = new ArrayList<String>();
    textoParagrafo.add(paragraph.getText());
    return textoParagrafo;
  }
}
