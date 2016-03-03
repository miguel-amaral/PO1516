/** @version $Id: InsertSection.java,v 1.7 2015/11/28 19:01:24 ist178865 Exp $ */
package edt.textui.section;

import static ist.po.ui.Dialog.IO;
import ist.po.ui.DialogException;

import java.io.IOException;

import edt.Document;
import edt.Section;

/**
 * §2.2.5.
 */
public class InsertSection extends SectionCommand {
	public InsertSection( Document document, Section section ) {
	super(MenuEntry.INSERT_SECTION, document, section);
	}

	@Override
	public final void execute() throws DialogException, IOException {
		int intLocalID = IO.readInteger(Message.requestSectionId());
		String title = IO.readString(Message.requestSectionTitle());
		_receiver.insertSection(intLocalID, title);
	}
}
