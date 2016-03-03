package edt;

import java.util.ArrayList;
import java.io.Serializable;
/**
 * This is an abstrat class.
 * Paragraphs and Sections can hava an unic ID (strig)
 */

public abstract class TextElement implements Serializable{

	/** TextElement uniqueId */
	private String _uniqueId = "";

	/**
	 * @param uniqueId 		unic ID to identify a Paragraph or Section
	 *
	 */
	public TextElement(String uniqueId){
		setUniqueId(uniqueId);
	}



	/**
	 * @param visitor that will visit the TextElement
	*/
	public abstract ArrayList<String> accept(ShowTextElementVisitor visitor);



	/* ---------- Getters & Setters ----------------*/

	/**
	 * @param uniqueId 		unic ID to identify a Paragraph or Section
	 *
	 */
	public void setUniqueId(String uniqueId){ _uniqueId = uniqueId; }

	/**
	 * @return 		uniqueId
	 */
	public String getUniqueId(){ return _uniqueId; }

	public Boolean hasUniqueId(){ return ! _uniqueId.equals("") ; }

	public void resetUniqueId(){ _uniqueId = "" ; }

	/* ---------------------------------------------*/



}
