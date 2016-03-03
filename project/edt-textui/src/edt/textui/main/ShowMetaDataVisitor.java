package edt.textui.main;

import edt.TextElement;
import edt.Section;
import edt.Paragraph;
import edt.Document;
import edt.Author;
import edt.ShowTextElementVisitor;
import java.util.ArrayList;

public class ShowMetaDataVisitor extends ShowTextElementVisitor{

	public ArrayList<String> visitDocument(Document document){
  		ArrayList<String> showMetaDatatext = new ArrayList<String>();

  		showMetaDatatext.add(Message.documentTitle(document.getTitle()));

			ArrayList<Author>  authorsList = document.getListAuthors();
			for(Author author: authorsList){
				showMetaDatatext.add(Message.author( author.getName(), author.getEmail()));
			}

			showMetaDatatext.add(Message.documentSections(document.getNTopSections()));
			showMetaDatatext.add(Message.documentBytes(document.getDim()));
			showMetaDatatext.add(Message.documentIdentifiers(document.getNIdentifiers()));
    	return showMetaDatatext;
  	}

	public ArrayList<String> visitSection(Section section){
  		ArrayList<String> sectionText = new ArrayList<String>();
    	return sectionText;
  	}


	public ArrayList<String> visitParagraph(Paragraph paragraph){
  		ArrayList<String> sectionText = new ArrayList<String>();
    	return sectionText;
  	}


}
