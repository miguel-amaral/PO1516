/** @version $Id: SectionCommand.java,v 1.8 2015/11/29 16:47:39 ist178865 Exp $ */
package edt.textui.section;

import ist.po.ui.Command;

import edt.Document;
import edt.Section;

/**
 * Superclass of all section-context commands.
 */
public abstract class SectionCommand extends Command<Section> {

	protected Document _document;

	public SectionCommand(String title, Document document, Section receiver) {
		super(title, receiver);
		_document = document;
	}

}
