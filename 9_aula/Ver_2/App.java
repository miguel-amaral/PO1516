public class App {
    public static void main(String[] args) {
        Page page = new Page();
        Paragraph p1 = new Paragraph();
        p1.addElement(new Span());
        p1.addElement(new Span());
        Paragraph p2 = new Paragraph();
        p2.addElement(new Image());
        page.addParagraph(p1);
        page.addParagraph(p2);
        System.out.println(page.render());
    }
}
