package edt;

import java.io.Serializable;


public class Author implements Serializable{
	/** Author name */
	private String _name;

	/** Author email */
	private String _email;

	/**
	 * @param name 		Author name
	 *
	 * @param mail 		Author email
	 *
	 */
	public Author(String name, String email){
		_name = name;
		_email = email;
	}

	/**
	 * Change the Author name
	 * @param name 		Author name
	 *
	 */
	public void setName(String name) { _name=name; }

	/**
	 * Change the Author email
	 * @param mail 		Author mail
	 *
	 */
	public void setEmail(String email) { _email=email; }

	/**
	 * @return 		Author name
	 */
	public final String getName() { return _name; }

	/**
	 * @return 		Author email
	 */
	public final String getEmail() { return _email; }

	/**
	 * Two authors are considered equal if they have the same name and email
	 */
	public boolean equals(Object author){
		return author instanceof Author &&((Author) author).getName() == _name &&
			((Author) author).getEmail() == _email;
	}
}
