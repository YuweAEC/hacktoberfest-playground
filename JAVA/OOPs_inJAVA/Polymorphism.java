// Polymorphism Example: Method Overriding
class Bird {
    // Method in the parent class
    public void sound() {
        System.out.println("This bird makes a sound.");
    }
}

// Parrot class overrides the sound() method of the Bird class
class Parrot extends Bird {
    @Override
    public void sound() {
        System.out.println("The parrot says: Squawk!");
    }
}

public class Polymorphism {
    public static void main(String[] args) {
        Bird myBird = new Parrot(); // Runtime polymorphism
        myBird.sound(); // Calls the overridden method in Parrot class
    }
}
