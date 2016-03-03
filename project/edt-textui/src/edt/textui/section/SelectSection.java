/** @version $Id: SelectSection.java,v 1.10 2015/11/29 16:47:39 ist178865 Exp $ */
package edt.textui.section;

import static ist.po.ui.Dialog.IO;
import ist.po.ui.DialogException;

import java.io.IOException;

import edt.Document;
import edt.Section;
import edt.NoSuchSectionException;

/**
 * §2.2.4.
 */
public class SelectSection extends SectionCommand {
	public SelectSection(Document document, Section section) {
		super(MenuEntry.SELECT_SECTION, document, section);
	}

	@Override
	public final void execute() throws DialogException, IOException  {
		int intLocalID  = IO.readInteger(Message.requestSectionId());
		try {
					Section newSection = _receiver.getSubSection(intLocalID);
					IO.println(Message.newActiveSection(intLocalID));
					edt.textui.section.MenuBuilder.menuFor(_document, newSection);
		} catch (NoSuchSectionException e) {
					IO.println(Message.noSuchSection(intLocalID));
		}
	}
}
