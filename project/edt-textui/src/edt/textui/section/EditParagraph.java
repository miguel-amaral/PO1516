/** @version $Id: EditParagraph.java,v 1.8 2015/11/29 16:47:39 ist178865 Exp $ */
package edt.textui.section;

import static ist.po.ui.Dialog.IO;
import ist.po.ui.DialogException;

import java.io.IOException;

import edt.Document;
import edt.Section;
import edt.NoSuchParagraphException;

/**
 * §2.2.10.
 */
public class EditParagraph extends SectionCommand {
	public EditParagraph( Document document, Section section ) {
		super(MenuEntry.EDIT_PARAGRAPH, document, section);
	}

	@Override
	public final void execute() throws DialogException, IOException {
  	int intLocalID = IO.readInteger(Message.requestParagraphId());
		String text = IO.readString(Message.requestParagraphContent());
		try{
			_receiver.editParagraph(intLocalID, text);
		}
		catch (NoSuchParagraphException e){
	      IO.println(Message.noSuchParagraph(intLocalID));
    }
	}
}
