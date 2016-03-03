/** @version $Id: MenuBuilder.java,v 1.9 2015/11/29 16:47:39 ist178865 Exp $ */
package edt.textui.section;

import ist.po.ui.Command;
import ist.po.ui.Menu;


import edt.Document;
import edt.Section;

/**
 * Menu builder for search operations.
 */
public class MenuBuilder {
  public static void menuFor(Document document , Section currentSection) {
    Menu menu = new Menu(MenuEntry.TITLE,
        new Command<?>[] {
            new ChangeTitle(document, currentSection),
            new ListSections(document, currentSection),
            new ShowContent(document, currentSection),
            new SelectSection(document, currentSection),
            new InsertSection(document, currentSection),
            new NameSection(document, currentSection),
            new RemoveSection(document, currentSection),
            new InsertParagraph(document, currentSection),
            new NameParagraph(document, currentSection),
            new EditParagraph(document, currentSection),
            new RemoveParagraph(document, currentSection),
    });
    menu.open();
  }
}
