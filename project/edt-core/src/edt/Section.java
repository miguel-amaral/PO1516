package edt;

import java.util.ArrayList;
import java.util.HashMap;

public class Section extends TextElement{

	/**Title's name*/
	private String _title = "";

	/**List of paragraphs in a Section*/
	private ArrayList<Paragraph> _paragraphs;

	/**List of subsetions*/
	private ArrayList<Section>  _subsections;



	/**
	 * Creats an ArrayList for saving Paragraphs
	 * Creats an ArrayList for saving Sections
	 */
	public Section(){
		super("");
		_paragraphs = new ArrayList<Paragraph>();
		_subsections = new ArrayList<Section>();
	}


	/**
	 * Creats an ArrayList for saving Paragraphs
	 * Creats an ArrayList for saving Sections
	 *
	 * @param title 	Section's title
	 */
	public Section(String title){
		this();
		_title = title;
	}


	/**
	 * Creats an ArrayList for saving Paragraphs
	 * Creats an ArrayList for saving Sections
	 *
	 * @param title 	Section's title
	 * @param uniqueId 	Section's uniqueId
	 */
	public Section(String title, String uniqueId){
		super(uniqueId);
		_paragraphs = new ArrayList<Paragraph>();
		_subsections = new ArrayList<Section>();
		_title = title;
	}


	/**
	 *Inserts a new section in the array
	 *@param id 		local id to insert the sectionimport java.util.ArrayList;
	 *@param section 	section to be inserted
	 */
	protected void insertSection(int id, Section section){
		if (id < 0 || id >= _subsections.size())
			_subsections.add(section);
		else
			_subsections.add(id, section);
	}


	/**
	 *Creats a new section and adds it to the Array
	 * @param id 		local id
	 * @param title 	section's title
	 */
	public void insertSection(int id, String title){
		Section section = new Section(title);
		this.insertSection(id, section);
	}


	/**
	 * Inserts a new paragraph
	 * @param id 			local id
	 * @param paragraph 	object Paragraph
	 */
	protected void insertParagraph(int id, Paragraph paragraph) {
		if (id < 0 || id >= _paragraphs.size())
			_paragraphs.add(paragraph);
		else
			_paragraphs.add(id, paragraph);
	}


	/**
	 * Inserts a new paragraph
	 * @param id 		local id
	 * @param text 		paragraph's text
	 */
	public void insertParagraph(int id, String text) {
		Paragraph paragraph = new Paragraph(text);
		this.insertParagraph(id, paragraph);
	}


	/**
	 * Removes a section from de array
	 *
	 * @exception NoSuchSectionException
	 * @throws NoSuchSectionException		if id bigger than array's size
	 * @param id 							local id
	 * @return unicIdList 					ArrayList of unic IDs in all subsections
	 */
	public ArrayList<String> removeSection(int id) throws NoSuchSectionException{
		if (id >= _subsections.size() || id < 0 )
			throw new NoSuchSectionException();
		else{
			Section section = this.getSubSection(id);
			ArrayList<String> unicIdList = section.getIds();
			_subsections.remove(id);
			return unicIdList;
		}
	}


	/**
	 * Create an ArrayList with all unic IDs in all subsctions
	 *
	 * @return unicIdList 					ArrayList of unic IDs in all subsections
	 */
	public ArrayList<String> getIds(){
		//Section currentSection = section;
		ArrayList<String> unicIdList = new ArrayList<String>();

		if(this.hasUniqueId())
			unicIdList.add(this.getUniqueId());
		// Get all paragraphs' unicId's (if they exist)
		for(Paragraph p: _paragraphs)
			if(p.hasUniqueId())
				unicIdList.add(p.getUniqueId());

		// Get all sections' unicId (if they exist)
		for(Section s: _subsections){
			// get inner uniqueId's from every section
			unicIdList.addAll(s.getIds());

			if(s.hasUniqueId())
				unicIdList.add(s.getUniqueId());
		}
		return unicIdList;
	}


	/**
	 * Removes a paragraph from the array
	 *
	 * @exception NoSuchParagraphException
	 * @throws NoSuchParagraphException		if id bigger than array's size
	 * @param id 							local id
	 */
	public void removeParagraph(int id) throws NoSuchParagraphException{
		if(id >= _paragraphs.size() || id < 0 )
			throw new NoSuchParagraphException();
		else
			_paragraphs.remove(id);
	}


	/**
	 * Edits a paragraph
	 *
	 * @exception NoSuchParagraphException
	 * @throws NoSuchParagraphException		if id bigger than array's size, paragraph doesn't exist
	 * @param id 							local id
	 * @param text 							Paragraph's text
	 */
	public void editParagraph(int id, String text) throws NoSuchParagraphException{
		Paragraph paragraph = getParagraph(id);
		paragraph.setText(text);
	}


	/**
	 * @return 	the paragraph text in the way defined by the visitor
	 */
	public ArrayList<String> accept(ShowTextElementVisitor visitor){
		return visitor.visitSection(this);
	}


	/**
	 * @return 		(int) size of all all Paragraphs in all Sections
	 */
	public int getDim(){
		int dim = 0;
		dim += getTitle().length();
		for(Section s:_subsections) {
			dim += s.getDim();
		}

		for(Paragraph p: _paragraphs){
			dim += p.getDimension();
		}
		return dim;
	}




	/* -------------------------------------------------------------------*/
	/* --------------------- Getters & Setters ---------------------------*/
	/* -------------------------------------------------------------------*/


	 /**
	 * @return 		ArrayList of sections
	 */
	public ArrayList<Section> getSections(){
		return _subsections;
	}


	/**
	 * @return 		ArrayList of paragraphs
	 */
	public ArrayList<Paragraph> getParagraphs(){
		return _paragraphs;
	}


	/**
	 * set a title to a Section
	 * @param sectionsList 			ArrayList of subsections
	 *
	 */
	public void setSections(ArrayList<Section> sectionsList ){
		_subsections = sectionsList;
	}


	/**
	 * Returns a subsection with local id
	 * @param id 	local Id
	 * @return  	subsection
	 */
	public Section getSubSection(int id) throws NoSuchSectionException{
		int size = _subsections.size();
		if (id >= size || id < 0 )
			throw new NoSuchSectionException();
		else
			return _subsections.get(id);
	}


	/**
	 * Returns a paragraph with local id
	 * @param id 	local Id
	 * @return  	paragraph
	 */
	public Paragraph getParagraph(int id) throws NoSuchParagraphException{
		int size = _paragraphs.size();
		if ( id >= size || id < 0 )
			throw new NoSuchParagraphException();
		else
			return _paragraphs.get(id);
	}


	/**
	 * creates a list of TextElements inside the SEction
	 * @return 	    list of TextElements
	 */
	public ArrayList<TextElement> getContent(){
		ArrayList<TextElement> elements = new ArrayList<TextElement>();

		elements.addAll( this.getParagraphs() );
		elements.addAll( this.getSections() );

		return elements ;
	}


	/**
	 * set a title to a Section
	 * @param title 	Section's title
	 *
	 */
	public void setTitle(String title){
		_title = title;
	}


	/**
	 * @return 		Section's title
	 */
	public String getTitle(){
		return _title;
	}


	/**
	 * @return 		(int) number of Sections insade the main Section(Document)
	 */
	public int getNTopSections(){
		return _subsections.size();
	}


}
	/* -------------------------------------------------------------------*/
	/* ---------------------- End of Getters & Setters -------------------*/
	/* -------------------------------------------------------------------*/
