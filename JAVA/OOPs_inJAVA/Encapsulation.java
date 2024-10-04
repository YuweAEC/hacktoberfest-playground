public class Encapsulation {
    public static void main(String[] args) {
        Person p = new Person();

        p.setName("Pranav");
        p.setAge(21);
        System.out.println(p.getName());
        System.out.println(p.getAge());
    }
}

class Person{
    private String name;
    private int age;

    public void setName(String name){
        this.name = name;
    }
    public String getName(){return name;}

    public void setAge(int age){
        this.age = age;
    }

    public int getAge(){
        return age;
    }
}