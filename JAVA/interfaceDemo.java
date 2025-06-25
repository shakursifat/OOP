
public class interfaceDemo {
    public static void main(String[] args) {
        Fly doggy = new Dog();
        Bird sweety = new Bird();
        Fly gogon = new Biman();

        System.out.println("I am a dog." + doggy.fly() + ((Dog)doggy).MakeSound());
        System.out.println("I am a bird." + sweety.fly() + sweety.MakeSound());
        System.out.println("I am a biman. " + gogon.fly());
    }
}
