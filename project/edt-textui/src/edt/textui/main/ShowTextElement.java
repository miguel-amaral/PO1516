/** @version $Id: ShowTextElement.java,v 1.11 2015/11/30 20:44:03 ist180915 Exp $ */
package edt.textui.main;

import static ist.po.ui.Dialog.IO;
import ist.po.ui.Command;
import ist.po.ui.DialogException;

import java.io.IOException;
import java.util.ArrayList;

import edt.Editor;
import edt.TextElement;
import edt.NoSuchTextElementException;
import edt.textui.section.ShowContentVisitor;
/**
 * §2.1.5.
 */
public class ShowTextElement extends Command<Editor> {
  public ShowTextElement(Editor editor) {
    super(MenuEntry.SHOW_TEXT_ELEMENT, editor );
  }

  @Override
  public final void execute() throws DialogException, IOException {
    String uniqueId = IO.readString(Message.requestElementId());
    try{
      ShowContentVisitor visitor = new ShowContentVisitor();
      ArrayList<String> toPrint = _receiver.showTextElement(visitor, uniqueId);
      for (String elementString : toPrint ) {
        IO.println(elementString);
      }
    } catch (NoSuchTextElementException e) {
      IO.println(Message.noSuchTextElement(uniqueId));
    }
  }
}
