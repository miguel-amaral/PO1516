/** @version $Id: NameParagraph.java,v 1.7 2015/11/29 15:11:12 ist178865 Exp $ */
package edt.textui.section;

import static ist.po.ui.Dialog.IO;
import ist.po.ui.DialogException;

import java.io.IOException;

import edt.Document;
import edt.Section;
import edt.Paragraph;
import edt.TextElement;
import edt.NoSuchParagraphException;

/**
 * §2.2.9.
 */
public class NameParagraph extends SectionCommand {
  public NameParagraph( Document document, Section section ) {
    super(MenuEntry.NAME_PARAGRAPH, document,  section);
  }

  @Override
  public final void execute() throws DialogException, IOException {
    int localId = IO.readInteger(Message.requestParagraphId());
    String uniqueId = IO.readString(Message.requestUniqueId());
    try{
    	if( _document.nameParagraph(uniqueId,_receiver, localId ) ){
        IO.println(Message.paragraphNameChanged());
      }
    }
    catch (NoSuchParagraphException e){
      IO.println(Message.noSuchParagraph(localId));
    }
  }
}
