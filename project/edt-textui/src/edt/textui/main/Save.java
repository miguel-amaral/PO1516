/** @version $Id: Save.java,v 1.12 2015/11/29 16:47:39 ist178865 Exp $ */
package edt.textui.main;

import static ist.po.ui.Dialog.IO;
import ist.po.ui.Command;
import ist.po.ui.DialogException;

import java.io.IOException;

import edt.Editor;

/**
 * Save to file under current name (if unnamed, query for name).
 */
public class Save extends Command<Editor> {
	public Save(Editor editor) {
		super(MenuEntry.SAVE, editor);
	}

	@Override
	public final void execute() throws DialogException, IOException {

		if( ! _receiver.saveDocument()){
			/* When there is no name the savaDocument mehthod returns false */
			String fileName = IO.readString(Message.newSaveAs());
			_receiver.setFileName(fileName);
			_receiver.saveDocument();
		}


	}
}
