package edt.textui.main;

import edt.TextElement;
import edt.Section;
import edt.Paragraph;
import edt.Document;
import edt.ShowTextElementVisitor;
import java.util.ArrayList;

public class ShowIndexVisitor extends ShowTextElementVisitor{

  public ArrayList<String> visitDocument(Document document){
    ArrayList<String> sectionStrings = new ArrayList<String>();
    sectionStrings.add("{" + document.getTitle() + "}");
    ArrayList<Section> sectionsList = document.getSections();
    for (Section section : sectionsList){
		  sectionStrings.addAll(section.accept(this));
		}
    return sectionStrings;
  }

  public ArrayList<String> visitSection(Section section){
    ArrayList<String> sectionStrings = new ArrayList<String>();
    sectionStrings.add(Message.sectionIndexEntry(section.getUniqueId(),section.getTitle()));
    return sectionStrings;
  }

  public ArrayList<String> visitParagraph(Paragraph paragraph){
    ArrayList<String> textoParagrafo = new ArrayList<String>();
    //nothing is done
    return textoParagrafo;
  }
}
