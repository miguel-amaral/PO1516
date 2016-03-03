/** @version $Id: ListSections.java,v 1.11 2015/11/28 18:34:45 ist178865 Exp $ */
package edt.textui.section;
import java.util.ArrayList;

import static ist.po.ui.Dialog.IO;
import ist.po.ui.DialogException;

import java.io.IOException;

import edt.Document;
import edt.Section;

/**
 * §2.2.2.
 */
public class ListSections extends SectionCommand {
	public ListSections( Document document, Section section ) {
		super(MenuEntry.LIST_SECTIONS, document,  section );
	}

	@Override
	public final void execute() throws DialogException, IOException {


		ListSectionsVisitor visitor = new ListSectionsVisitor();
		ArrayList<String> printedSections = _receiver.accept(visitor);
		for (String section : printedSections){
			IO.println(section);
		}

	}
}
