package edt;
import java.util.ArrayList;

public abstract class ShowTextElementVisitor{
  public abstract ArrayList<String> visitDocument(Document document);
  public abstract ArrayList<String> visitSection(Section section);
  public abstract ArrayList<String> visitParagraph(Paragraph paragraph);
}
