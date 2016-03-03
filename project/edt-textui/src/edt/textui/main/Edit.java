/** @version $Id: Edit.java,v 1.8 2015/11/28 17:46:17 ist178865 Exp $ */
package edt.textui.main;

import static ist.po.ui.Dialog.IO;
import ist.po.ui.Command;
import ist.po.ui.DialogException;

import java.io.IOException;

import edt.Editor;

/**
 * §2.3.1.
 */
public class Edit extends Command<Editor> {
  public Edit(Editor editor) {
    super(MenuEntry.OPEN_DOCUMENT_EDITOR,editor);
  }

  @Override
  public final void execute() throws DialogException, IOException {
    edt.textui.section.MenuBuilder.menuFor( _receiver.getDocument(), _receiver.getDocument() );
    _receiver.makeChanges();
  }

}
