/** @version $Id: InsertParagraph.java,v 1.7 2015/11/29 16:47:39 ist178865 Exp $ */
package edt.textui.section;

import static ist.po.ui.Dialog.IO;
import ist.po.ui.DialogException;

import java.io.IOException;

import edt.Document;
import edt.Section;

/**
 * §2.2.8.
 */
public class InsertParagraph extends SectionCommand {
	public InsertParagraph( Document document, Section section ) {
		super(MenuEntry.INSERT_PARAGRAPH, document, section);
	}

	@Override
	public final void execute() throws DialogException, IOException {
		int intLocalID = IO.readInteger(Message.requestParagraphId());
		String text = IO.readString(Message.requestParagraphContent());
		_receiver.insertParagraph(intLocalID, text);

	}

}
