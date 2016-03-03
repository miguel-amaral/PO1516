/** @version $Id: RemoveParagraph.java,v 1.9 2015/11/30 16:01:30 ist178865 Exp $ */
package edt.textui.section;

import static ist.po.ui.Dialog.IO;
import ist.po.ui.DialogException;

import java.io.IOException;

import edt.Document;
import edt.Section;
import edt.NoSuchParagraphException;

/**
 * §2.2.11.
 */
public class RemoveParagraph extends SectionCommand {
	public RemoveParagraph( Document document, Section section ) {
		super(MenuEntry.REMOVE_PARAGRAPH, document,  section);
	}

	@Override
	public final void execute() throws DialogException, IOException {
    	int intLocalId = IO.readInteger(Message.requestParagraphId());
    	try{
    		_document.removeInnerParagraph(_receiver, intLocalId);
    	}
	    catch (NoSuchParagraphException e){
	      IO.println(Message.noSuchParagraph(intLocalId));
	    }
	}
}
