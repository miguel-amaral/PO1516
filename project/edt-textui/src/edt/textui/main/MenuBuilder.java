/** @version $Id: MenuBuilder.java,v 1.7 2015/11/15 19:07:30 ist178865 Exp $ */
package edt.textui.main;

import ist.po.ui.Command;
import ist.po.ui.Menu;

import edt.Editor;

/**
 * Menu builder for editor operations.
 */
public abstract class MenuBuilder {

  /**
	 * @param editor
	 */
  public static void menuFor(Editor editor) {
    Menu menu = new Menu(MenuEntry.TITLE,
        new Command<?>[] {
            new New(editor),
            new Open(editor),
            new Save(editor),
            new ShowMetadata(editor),
            new AddAuthor(editor),
            new ShowIndex(editor),
            new ShowTextElement(editor),
            new Edit(editor),
    });
    menu.open();
  }
}
