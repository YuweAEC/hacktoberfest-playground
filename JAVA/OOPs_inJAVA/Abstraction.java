// Abstraction Example
abstract class Vehicle {
    // Abstract method (does not have a body)
    public abstract void start();

    // Regular method
    public void fuel() {
        System.out.println("Vehicle needs fuel.");
    }
}

class Car extends Vehicle {
    // Providing implementation for the abstract method
    @Override
    public void start() {
        System.out.println("The car starts with a key.");
    }
}

public class Abstraction {
    public static void main(String[] args) {
        Car myCar = new Car();
        myCar.start();  // Calls the implemented method in Car class
        myCar.fuel();   // Calls the inherited method from Vehicle class
    }
}
