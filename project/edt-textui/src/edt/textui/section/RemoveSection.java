/** @version $Id: RemoveSection.java,v 1.10 2015/11/30 16:01:30 ist178865 Exp $ */
package edt.textui.section;

import static ist.po.ui.Dialog.IO;
import ist.po.ui.DialogException;

import java.io.IOException;

import edt.Document;
import edt.Section;
import edt.NoSuchSectionException;

/**
 * §2.2.7.
 */
public class RemoveSection extends SectionCommand {
  public RemoveSection(Document document, Section section) {
    super(MenuEntry.REMOVE_SECTION, document, section);
  }

  @Override
  public final void execute() throws DialogException, IOException {
    /* FIXME: implement command */
    int intLocalID = IO.readInteger(Message.requestSectionId());
    try{
      _document.removeInnerSections(_receiver, intLocalID);
    }
    catch (NoSuchSectionException e){
      IO.println(Message.noSuchSection(intLocalID));
    }
  }
}
