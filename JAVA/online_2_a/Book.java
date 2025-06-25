public class Book {
    private int bookId;
    private String bookTitle;
    private boolean avail;

    public Book() {
        bookId = 0;
        bookTitle = "";
        avail = false;
    }

    public Book(int bookId, String bookTitle, boolean avail) {
        this.bookId = bookId;
        this.bookTitle = bookTitle;
        this.avail = avail;
    }

    public int getBookId() {
        return bookId;
    }

    public String getBooktitle() {
        return bookTitle;
    }


    public boolean isAvailable() {
        return avail;
    }

    public void borrowabook() {
        avail = false;
    }
    
    public void returnabook() {
        avail = true;
    }
}
