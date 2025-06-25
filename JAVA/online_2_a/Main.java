import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        if(args.length != 1) {
            System.out.println("no");
            return;
        }

        int numBranches;
        try {
            numBranches = Integer.parseInt(args[0]);
        } catch (NumberFormatException e) {
            System.out.println("Invalid number format.");
            return;
        }

        if(numBranches > 10) {
            System.out.println("more than 10 ");
            return;
        }

        Scanner sc = new Scanner(System.in);
        LibraryBranch[] branches = new LibraryBranch[10];
        int cnt_branch = 0;

        for(int i = 1; i <= numBranches; i++) {
            LibraryBranch branch = new LibraryBranch(i);
            int maxbooks = sc.nextInt();
            sc.nextLine();

            if(maxbooks > 20) {
                System.out.println("maxi");
                maxbooks = 20;
            }

            for(int j = 0; j < maxbooks; j++) {
                System.out.print("Enter book Id: ");
                int bookid = sc.nextInt();
                sc.nextLine();
                System.out.print("Enter book Title: ");
                String title = sc.nextLine();
                System.out.print("Is the book available? : ");
                boolean available = sc.nextBoolean();
                sc.nextLine();

                branch.addBook(new Book(bookid, title, available));
                branches[cnt_branch] = branch;
                cnt_branch++;
            }
        }

        int choice;
            do {
                System.out.println("\nMenu: ");
                System.out.println("1. Borrow a Book");
                System.out.println("2. Return a Book");
                System.out.println("3. Display All Branch Info");
                System.out.println("4. Exit");
                System.out.print("Choose an option: ");
                choice = sc.nextInt();

                switch (choice) {
                case 1 -> {
                    System.out.print("Enter Branch ID: ");
                    int branchID = sc.nextInt();
                    System.out.print("Enter Book ID to borrow: ");
                    int bookID = sc.nextInt();
                    handleBorrow(branches, branchID, bookID, cnt_branch);
                }
                case 2 -> {
                    System.out.print("Enter Branch ID: ");
                    int branchID = sc.nextInt();
                    System.out.print("Enter Book ID to return: ");
                    int bookID = sc.nextInt();
                    handleReturn(branches, branchID, bookID, cnt_branch);
                }
                case 3 -> {
                    for (int i = 0; i < cnt_branch; i++) {
                        branches[i].displayBooks();
                    }
                }
                case 4 -> System.out.println("Exiting...");
                default -> System.out.println("Invalid option. Try again.");
            }
        } while (choice != 4);

        sc.close();
    }

    public static void handleReturn(LibraryBranch[] branches, int branchid, int bookid, int cnt_branch) {
        for(int i = 0; i < cnt_branch; i++) {
            if(branches[i].getBranchid() == branchid) {
                Book temp = branches[i].findBookbyid(bookid);
                if(temp == null) {
                    System.out.println("not available");
                }else if(!temp.isAvailable()) {
                    temp.returnabook();
                    System.out.println("successful");
                }else if(temp.isAvailable()) {
                    System.out.println("can return a book");
                }
            }
        }
    }

    public static void handleBorrow(LibraryBranch[] branches, int branchid, int bookid, int cnt_branch) {
        for(int i = 0; i < cnt_branch; i++) {
            if(branches[i].getBranchid() == branchid) {
                Book temp = branches[i].findBookbyid(bookid);
                if(temp == null) {
                    System.out.println("not available");
                }else if(!temp.isAvailable()) {
                    System.out.println("not available rn");
                }else if(temp.isAvailable()) {
                    temp.borrowabook();
                    System.out.println("succesful");
                }
            }
        }
    }
}