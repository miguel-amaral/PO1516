/** @version $Id: NameSection.java,v 1.10 2015/11/29 15:11:12 ist178865 Exp $ */
package edt.textui.section;

import static ist.po.ui.Dialog.IO;
import ist.po.ui.DialogException;

import java.io.IOException;

import edt.Document;
import edt.Section;
import edt.TextElement;
import edt.NoSuchSectionException;


/**
 * §2.2.6.
 */
public class NameSection extends SectionCommand {
  public NameSection( Document document, Section section) {
    super(MenuEntry.NAME_SECTION, document, section);
  }

  @Override
  public final void execute() throws DialogException, IOException {
    int localId = IO.readInteger(Message.requestSectionId());
    String uniqueId = IO.readString(Message.requestUniqueId());
    try{
    	if( _document.nameSection(uniqueId, _receiver, localId) ){
        IO.println(Message.sectionNameChanged());
      }
    }
    catch (NoSuchSectionException e){
      IO.println(Message.noSuchSection(localId));
    }
  }
}
