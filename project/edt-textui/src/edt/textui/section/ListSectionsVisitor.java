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

public class ListSectionsVisitor extends ShowTextElementVisitor{

	private ArrayList<String> visitEachInnerElement(Section section){
		ArrayList<String> sectionStrings = new ArrayList<String>();

		ArrayList<Section> sections = section.getSections();
		for (Section subsection : sections){
			sectionStrings.add(Message.sectionIndexEntry( subsection.getUniqueId(), subsection.getTitle()));
			sectionStrings.addAll( subsection.accept(this) );
		}

		return sectionStrings;
	}

	public ArrayList<String> visitDocument(Document document) {
	    ArrayList<String> sectionStrings = new ArrayList<String>();

			sectionStrings.addAll( visitEachInnerElement( document ));

	    return sectionStrings;
  	}

  	public ArrayList<String> visitSection(Section section){
	    ArrayList<String> sectionStrings = new ArrayList<String>();

	    sectionStrings.addAll( visitEachInnerElement( section ));

	    return sectionStrings;
  	}

  	public ArrayList<String> visitParagraph(Paragraph paragraph){
  		ArrayList<String> textoParagrafo = new ArrayList<String>();
    	return textoParagrafo;
  	}
}
