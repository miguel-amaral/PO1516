/** @version $Id: ShowMetadata.java,v 1.11 2015/11/30 23:42:26 ist178865 Exp $ */
package edt.textui.main;

import static ist.po.ui.Dialog.IO;
import ist.po.ui.Command;
import ist.po.ui.DialogException;

import java.io.IOException;
import java.util.ArrayList;

import edt.Editor;
import edt.Author;

/**
 * §2.1.2.
 */
public class ShowMetadata extends Command<Editor> {
	public ShowMetadata(Editor editor) {
		super(MenuEntry.SHOW_METADATA, editor);
	}

	@Override
	public final void execute() throws DialogException, IOException {
		ShowMetaDataVisitor visitor = new ShowMetaDataVisitor();
    ArrayList<String> toPrint = _receiver.innerDocument(visitor);
    for (String elementString : toPrint )
      IO.println(elementString);
	}
}
