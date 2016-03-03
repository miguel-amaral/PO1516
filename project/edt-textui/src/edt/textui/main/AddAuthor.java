/** @version $Id: AddAuthor.java,v 1.15 2015/11/27 19:41:29 ist178865 Exp $ */
package edt.textui.main;

import static ist.po.ui.Dialog.IO;
import ist.po.ui.Command;
import ist.po.ui.DialogException;

import java.io.IOException;

import edt.Editor;
import edt.Document;
import edt.DuplicateAuthorException;

/**
 * §2.1.3.
 */
public class AddAuthor extends Command<Editor> {
	public AddAuthor(Editor editor) {
		super(MenuEntry.ADD_AUTHOR, editor);
	}

	@Override
	public final void execute() throws DialogException, IOException {
			String name = IO.readString(Message.requestAuthorName());
			String email = IO.readString(Message.requestEmail());
	  	try{
		  	_receiver.addAuthor(name, email);
	  	} catch (DuplicateAuthorException e) {
				IO.println(Message.duplicateAuthor(name));
	  	}
	}
}
