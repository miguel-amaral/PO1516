/** @version $Id: ShowContent.java,v 1.16 2015/11/29 16:47:39 ist178865 Exp $ */
package edt.textui.section;

import static ist.po.ui.Dialog.IO;
import ist.po.ui.DialogException;

import java.io.IOException;
import java.util.ArrayList;

import edt.Document;
import edt.Section;
import edt.TextElement;

/**
 * §2.2.3.
 */
public class ShowContent extends SectionCommand {
	public ShowContent( Document document, Section section) {
		super(MenuEntry.SHOW_CONTENT, document, section);
	}

	@Override
	public final void execute() throws DialogException, IOException {
		ShowContentVisitor visitor = new ShowContentVisitor();
		ArrayList<String> printedElements = _receiver.accept(visitor);
		for (String element : printedElements){
			IO.println(element);
		}

	}
}
