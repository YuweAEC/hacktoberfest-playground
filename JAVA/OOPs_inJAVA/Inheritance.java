// Inheritance Example
class Animal {
    // Method in the parent class
    public void eat() {
        System.out.println("This animal eats food.");
    }
}

// Dog class inherits from Animal class
class Dog extends Animal {
    // Dog class has its own method
    public void bark() {
        System.out.println("The dog barks.");
    }
}

public class Inheritance {
    public static void main(String[] args) {
        Dog dog = new Dog();
        // Dog class can access methods of Animal class
        dog.eat();
        dog.bark();
    }
}
