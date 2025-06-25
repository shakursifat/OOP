public interface Fly {
    public String fly();
}

class Dog implements Fly { 
    public String fly() {
        return "I cannot fly.";
    }
    public String MakeSound() {
        return "I sound berk";
    }
}

class Bird implements Fly {
    public String fly() {
        return "I fly in the sky.";
    }
    public String MakeSound() {
        return "I sound chi-chi";
    }
}

class Biman implements Fly {
    public String fly() {
        return "I fly too high in the sky.";
    }
}




