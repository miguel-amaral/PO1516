/** @version $Id: ChangeTitle.java,v 1.8 2015/11/29 16:47:39 ist178865 Exp $ */
package edt.textui.section;

import static ist.po.ui.Dialog.IO;
import ist.po.ui.DialogException;

import java.io.IOException;

import edt.Document;
import edt.Section;

/**
 * §2.2.1.
 */
public class ChangeTitle extends SectionCommand {
	public ChangeTitle(Document document, Section section) {
		super(MenuEntry.CHANGE_TITLE, document, section);
	}

	@Override
	public final void execute() throws DialogException, IOException {
		String newTitle = IO.readString(Message.requestSectionTitle());
		_receiver.setTitle(newTitle);
	}
}
