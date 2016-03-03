/** @version $Id: New.java,v 1.7 2015/11/15 19:07:30 ist178865 Exp $ */
package edt.textui.main;

import static ist.po.ui.Dialog.IO;
import ist.po.ui.Command;
import ist.po.ui.DialogException;

import java.io.IOException;

import edt.Editor;

/**
 * Open a new document.
 */
public class New extends Command<Editor> {
	public New(Editor editor) {
		super(MenuEntry.NEW, editor);
	}

	@Override
	public final void execute() throws DialogException, IOException {
		_receiver.createDocument();
	}
}
