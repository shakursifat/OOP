public class LibraryBranch {
    private int branchId;
    private int numBooks;
    private Book[] books = new Book[20];

    public LibraryBranch() {
        branchId = 0;
        numBooks = 0; 
    }

    public LibraryBranch(int branchId) {
        this.branchId = branchId;
        numBooks = 0;
    }

    public int getBranchid() {
        return branchId;
    }

    public boolean addBook(Book book) {
        if(numBooks >= 20) {
            System.out.println("Cannot add more books to Branc " + branchId + ".");
            return false;
        }
        books[numBooks] = book;
        numBooks++;
        return true;
    }

    public Book findBookbyid(int bookId) {
        for(Book book: books) {
            if(book.getBookId() == bookId) {
                return book;
            }
        }
        return null;
    }

    public void displayBooks() {
        System.out.println("Branch ID: " + branchId);
        if(numBooks <= 0) {
            System.out.println("No books available.");
        }else {
            for(Book book : books) {
                System.out.println(book.getBookId() + " " + book.getBooktitle() + " " + book.isAvailable());
            }
        }
    }
}