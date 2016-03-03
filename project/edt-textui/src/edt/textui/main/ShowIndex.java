/** @version $Id: ShowIndex.java,v 1.11 2015/11/30 20:44:03 ist180915 Exp $ */
package edt.textui.main;

import static ist.po.ui.Dialog.IO;
import ist.po.ui.Command;
import ist.po.ui.DialogException;

import java.io.IOException;
import java.util.ArrayList;

import edt.Editor;
import edt.Document;

/**
 * §2.1.4.
 */
public class ShowIndex extends Command<Editor> {
	public ShowIndex(Editor editor) {
		super(MenuEntry.SHOW_INDEX, editor);
	}

	@Override
	public final void execute() throws DialogException, IOException {
		ShowIndexVisitor visitor = new ShowIndexVisitor();
		ArrayList<String> printedElements = _receiver.innerDocument(visitor);
		for (String element : printedElements){
			IO.println(element);
		}
	}
}
