/** @version $Id: TextEditor.java,v 1.17 2015/11/15 19:07:30 ist178865 Exp $ */
package edt.textui;

import static ist.po.ui.Dialog.IO;

import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;

import edt.Editor;
import edt.Document;
//import edt.editor;

/**
 * Class that starts the application's textual interface.
 */
public class TextEditor {
	public static void main(String[] args) {
		Editor editor;
		String datafile = System.getProperty("import"); //$NON-NLS-1$
		if (datafile != null) {
			editor = new Editor(datafile);
		}
		else {
			editor = new Editor();
		}
		edt.textui.main.MenuBuilder.menuFor(editor);
		IO.closeDown();
	}
}
