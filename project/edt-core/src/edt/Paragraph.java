package edt;

import java.util.ArrayList;


public class Paragraph extends TextElement{

	/**Paragraph's text*/
	private String _text;

	/**
	 * Creats a new Paragraph
	 * @param text 		Paragraph's text
	 * @param unicID 	Paragrph's unic ID
	 *
	 */
	public Paragraph(String text, String unicID) {
		super(unicID);
		_text = text;
	}

	/**
	 * Creats a new Paragraph
	 * @param text 		Paragraph's text
	 *
	 */
	public Paragraph(String text) {
		super("");
		_text = text;
	}




	/**
	 * @return 	the paragraph text in the way defined by the visitor
	 */
	public ArrayList<String> accept(ShowTextElementVisitor visitor){
		return visitor.visitParagraph(this);
	}



	/* --------------------------------------------- */
	/* ---------- Getters & Setters ---------------- */
	/* --------------------------------------------- */

	/**
	 * @return 	the paragraph text
	 */
	public String getText(){
		return _text;
	}

	/**
	 * @param text 		Paragraph's new text
	 */
	public void setText(String text){
		_text = text;
	}

	/**
	 * @return 			(int) size of text (bytes)
	 */
	public int getDimension(){
		return _text.length();
	}

	/* --------------------------------------------- */
	/* -------- End of Getters & Setters ------------*/
	/* --------------------------------------------- */

}
