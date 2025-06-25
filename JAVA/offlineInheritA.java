import java.lang.String;

interface PaymentGateway {
    boolean processPayment(double amount);
    default boolean refund(double amount) {
        return true;
    }
}

abstract class AbstractPayment {
    public String accountIdentifier;
    private double lastTransactionAmount;

    public AbstractPayment(String accountIdentifier) {
        this.accountIdentifier = accountIdentifier;
        lastTransactionAmount = 0;
    }

    public void recordTransaction(double amount) {
        lastTransactionAmount += amount;
    }

    abstract boolean validateDetails();
}

class CreditCardPayment extends AbstractPayment implements PaymentGateway {
    public CreditCardPayment(String accountIdentifier) {
        super(accountIdentifier);
    }

    public boolean validateDetails() {
        if(accountIdentifier.length() != 16) {
            return false;
        }else {
            for(int i = 0; i < 16; i++) {
                if(accountIdentifier[i] )
            }
        }
    }


}




public class offlineInheritA {
    
}
