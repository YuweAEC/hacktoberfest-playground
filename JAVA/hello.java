// Rock Paper Scissors game
import java.util.concurrent.ThreadLocalRandom;
import java.util.Scanner;
class HelloWorld {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        while(true){
            System.out.println("1.rock 2.paper 3.Scissor 4.exit");
            System.out.println();
            System.out.print("Enter your choice :");
            int userchoice=in.nextInt();
            if (userchoice==4){
                break;
            }
            int computerchoice=ThreadLocalRandom.current().nextInt(1,4);
            if (computerchoice==1){
                System.out.println("computer plays rock.");
                System.out.println();
                if(userchoice==1){
                    System.out.println("MATCH DRAW!!");
                }else if(userchoice==2){
                    System.out.println("YOU WIN!!");
                }else if(userchoice==3){
                    System.out.println("COMPUTER WINS!!");
                }
            }
            if(computerchoice==2){
                System.out.println("computer plays paper.");
                System.out.println();
                if(userchoice==1){
                    System.out.println("COMPUTER WINS!!");
                }else if(userchoice==2){
                    System.out.println("MATCH DRAW!!");
                }else if(userchoice==3){
                    System.out.println("YOU WINS!!");
                }
            }
            if(computerchoice==3){
                System.out.println("computer plays scissor.");
                System.out.println();
                if(userchoice==1){
                    System.out.println("YOU WINS!!");
                }else if(userchoice==2){
                    System.out.println("COMPUTER WINS!!");
                }else if(userchoice==3){
                    System.out.println("MATCH DRAW!!");
                }
            }
            System.out.println();
        }
        System.out.println("Thank You!!");
        
    }
}
