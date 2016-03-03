
package edt;
import java.io.ObjectOutputStream;
import java.io.BufferedOutputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;

public class Editor{

	/**
	 * The Document that is currently open
	 */
	private Document _document;

	/**
	 * boolean that represents if the current Document has any non-saved changes
	 */
	private boolean _altered = false;

	public Editor(){
		this.createDocument();
	}

	/**
	 * When there is a file to import we use this constructor
	 */
	public Editor(String fileName) {
		this();
		try {
			this.makeChanges();
			BufferedReader reader = new BufferedReader(new FileReader(fileName));

			/* Read Documents Title */
			_document.setTitle(reader.readLine());

			/* Add authors to Document */
			String authors = reader.readLine();
			for(String author : authors.split("\\|")){
				String[] string = author.split("\\/");
				try {
					_document.addAuthor(string[0], string[1]);
				}
				catch(DuplicateAuthorException e) {
					// On import no Error Messages need to be print
				}
			}

			/* Read Content */
			String line;
			Section curSection = _document;
			while((line = reader.readLine()) != null){
				String[] string = line.split("\\|");
				if(string[0].equals("SECTION")){
					curSection = new Section(string[2]);
					_document.insertSection(-1 , curSection);
	        _document.nameTextElement( string[1], curSection);

				}
				else {
					curSection.insertParagraph(-1, string[1]);
				}
			}
		}
		catch(IOException e) { e.printStackTrace(); }
  }


  /* ---------------------------------------------------- */
	/* -------------- Document Functions ------------------ */
  /* ---------------------------------------------------- */

	/**
	 * @return returns the editor current Document
	 */
	public Document getDocument(){
		return _document;
	}

	public int getDim(){
		return _document.getDim();
	}

	public String getTitle(){
		return _document.getTitle();
	}


	public TextElement getTextElement(String uniqueId) throws NoSuchTextElementException{
		return _document.getTextElement(uniqueId);
	}

	public ArrayList<Author> getListAuthors(){
		return _document.getListAuthors();
	}

	public int getNTopSections(){
		return _document.getNTopSections();
	}

	public int getNIdentifiers(){
		return _document.getNIdentifiers();
	}

	public void addAuthor(String name, String email) throws DuplicateAuthorException{
		_document.addAuthor(name, email);
		makeChanges();
	}
	public void setFileName(String fileName){
		_document.setFileName(fileName);
	}

	public String getFileName(){
		return _document.getFileName();
	}

	public ArrayList<String> innerDocument(ShowTextElementVisitor visitor){
		return _document.accept(visitor);
	}

	public ArrayList<String> showTextElement(ShowTextElementVisitor visitor, String uniqueId) throws NoSuchTextElementException{

		return _document.getTextElement(uniqueId).accept(visitor);

	}


  	/* ---------------------------------------------------- */
	/* ------- End of Document Relatad Functions ---------- */
  	/* ---------------------------------------------------- */



	public void makeChanges(){
		_altered = true;
	}
	public void saveChanges(){
		_altered = false;
	}



	public void createDocument(){
		_document = new Document();
		makeChanges();
	}


	public boolean saveDocument() throws IOException {

		if( _altered ){
			String fileName = _document.getFileName();

			//If the document does not have a fileName it is not saved
			if( ! _document.hasFileName() ) return false;

			//The actual saving
			ObjectOutputStream oos = new ObjectOutputStream(new BufferedOutputStream(new FileOutputStream(fileName)));
			oos.writeObject(_document);
			this.saveChanges();
			oos.close();
		}

		//Return that everything went ok
		return true;

	}
	/*
	public void saveDocument(String fileName) throws IOException {
		_document.setFileName(fileName);
		saveDocument();
	}*/

	public void openDocument(String fileName) throws IOException {
		try {
			ObjectInputStream ois = new ObjectInputStream(new BufferedInputStream(new FileInputStream(fileName)));
			_document = (Document)ois.readObject();
			_altered = false;
		}
		catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
	}
}
