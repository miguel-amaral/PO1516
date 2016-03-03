package edt;
import java.util.Map;
import java.util.HashMap;
import java.util.TreeMap;
import java.util.ArrayList;


public class Document extends Section{

	/** Authors of the Document */
	private Map<String, Author> _authors;

	/** Unic IDs of the document*/
	private Map<String, TextElement> _textElements;
	private String _fileName = "";


	/**
	 * Creates a new Document
	 * Creates a new HashMap for witch element
	 */
	public Document(){
		_authors = new TreeMap<String, Author>();
	 	_textElements = new HashMap<String, TextElement>();
	}


	/**
	 *
	 * @return 		list of all authors
	 */
	public ArrayList<Author> getListAuthors(){
		ArrayList<Author> authorsList = new ArrayList<Author>();
		for (Map.Entry<String, Author> entry : _authors.entrySet())
		{
			authorsList.add(entry.getValue());
		}
		return authorsList;
	}


	/**
	 * Creats an Author and adds to the TreeMap
	 * @param name 		Authors's name
	 * @param email 	Author's email
	 *
	 */
	public void addAuthor(String name, String email) throws DuplicateAuthorException{
        if (_authors.get(name) != null)
            throw new DuplicateAuthorException();
        _authors.put(name, new Author(name, email));
    }


	/**
	 * @param TextElement to be added
	 */
	public void addTextElement(TextElement element){
		_textElements.put(element.getUniqueId(),element);
	}
	/**
	 * @param uniqueId of TextElement to be removed
	 */
	public void removeTextElement(String uniqueId){
		_textElements.remove(uniqueId);
	}

	/**
	 * Sets an uniqueId to a TextElement
	 *
	 * @param uniqueId 							unique ID
	 * @param newElement 						element to be named
	 * @return condition if newElement had name
	 *
	 */
	protected boolean nameTextElement(String uniqueId, TextElement newElement) {
		//Check if newElement already had a uniqueId
		boolean hadName = newElement.hasUniqueId();
		if(hadName){
			String oldUniqueId = newElement.getUniqueId();
			// unlink the old name
			removeTextElement(oldUniqueId);
		}

		TextElement oldElement = _textElements.get(uniqueId);

		// If there was already an element with the new uniqueId
		//  it's name will be removed
		if(oldElement != null){
			oldElement.resetUniqueId();
			removeTextElement(uniqueId);
		}


		newElement.setUniqueId(uniqueId);
		// If user tries to give empty string as name
		//  it will not be considered unique
		if( uniqueId.length() > 0){
			addTextElement(newElement);
		}
		return hadName ;
	}


	/**
	 * gives a unic ID to a section
	 *
	 * @param uniqueId 							unique ID
 	 * @param parentSection					section's father
	 * @param localId 							local id
	 * @return   condition if sectionToChange had name
	 *
	 */
	public boolean nameSection(String uniqueId, Section parentSection, int localId) throws NoSuchSectionException {

		// Get the section that will be named
		Section sectionToChange = parentSection.getSubSection(localId);
		return this.nameTextElement(uniqueId, sectionToChange);
	}

	/**
	 * gives a unic ID to a paragraph
	 *
	 * @param uniqueId 							unique ID
	 * @param parentSection 				section's father
	 * @param localId 							local id
	 * @return  condition if paragraphToChange had name
	 *
	 */
	public boolean nameParagraph(String uniqueId, Section parentSection, int localId) throws NoSuchParagraphException {

		// Get the paragraph that will be named
		Paragraph paragraphToChange = parentSection.getParagraph(localId);
		return this.nameTextElement(uniqueId, paragraphToChange);
	}


	/**
	 * Removes a section from the array
	 * Removes all inner unic IDs
	 *
	 * @exception NoSuchSectionException
	 * @throws NoSuchSectionException		if id bigger than array's size
	 * @param id 							local id
	 * @param section 			  current section
	 */
	public void removeInnerSections(Section section, int id) throws NoSuchSectionException{

		ArrayList<String> unicIdList = section.removeSection(id);
		for(String uniqueId: unicIdList)
			removeTextElement(uniqueId);
	}

	/**
	 * Removes a Paragraph from the array
	 *
	 * @exception NoSuchParagraphException
	 * @throws NoSuchSectionException		if id bigger than array's size
	 * @param id 							local id
	 * @param section 			  current section
	 */
	public void removeInnerParagraph(Section section, int id) throws NoSuchParagraphException{

		Paragraph paragraph = section.getParagraph(id);
		section.removeParagraph(id);
		// Remove from the unicIdList if the paragraph had a name
		if(paragraph.hasUniqueId())
			removeTextElement(paragraph.getUniqueId());

	}



	public ArrayList<String> accept(ShowTextElementVisitor visitor){
		return visitor.visitDocument(this);
	}



	/* -------------------------------------------------------------------*/
	/* --------------------- Getters & Setters ---------------------------*/
	/* -------------------------------------------------------------------*/

	/**
	 * set a name to the file
	 * @param fileName 	file's name
	 *
	 */
	public void setFileName(String fileName) { _fileName = fileName; }


	/**
	 * @return		file's name
	 *
	 */
	public String getFileName(){ return _fileName; }


	/**
	 * verifies if file has a name
	 * @return 		true if has a name, otherwise false
	 *
	 */
	public boolean hasFileName(){ return ! _fileName.equals(""); }



	/**
	 * @return 	vetor's size
	 */
	public int getNIdentifiers(){
		return _textElements.size();
	}


	/**
	 * @param String uniqueId being searched
	 * @return 				TextElement correspondent to uniqueId
	 */
	public TextElement getTextElement(String uniqueId) throws NoSuchTextElementException{
		TextElement element = _textElements.get(uniqueId);
		if (element == null)
			throw new NoSuchTextElementException();
		else
			return element;
	}


	/**
	 * Creats an Author and adds to the HashMap
	 * @param name 	author's name
	 * @return		Author
	 *
	 */
	public Author getAuthor(String name) {
	        Author author = _authors.get(name);
	    return author;
	    }


}


	/* -------------------------------------------------------------------*/
	/* ---------------------- End of Getters & Setters -------------------*/
	/* -------------------------------------------------------------------*/
