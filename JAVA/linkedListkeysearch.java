//Both iterative and recursive method implemented.O(n),better to use iterative method for avoiding auxulary space.

public class linkedListkeysearch{
     static class Node{
        int data;
        Node next;
    
    Node(int x)
    {
       data=x;
        next=null;
    }
    }
   
    public static void main(String[] args)
    {
        linkedListkeysearch LL=new linkedListkeysearch();
        Node head=null;
        Node node1= new Node(20);
        Node node2=new Node(30);
         Node node3= new Node(40);
         Node node4= new Node(50);
         Node node5= new Node(60);
        head=node1;
        node1.next=node2;
         node2.next=node3;
        node3.next=node4;
        node4.next=node5;
        int h;
                h=  LL. searchkey1(head,10); 
        int h1;
        h1=LL.searchkey(head,40);
        
System.out.println(h);
        System.out.print(h1);
    }
    public int searchkey1(Node head,int key)
    {
        Node curr=head;
        int pos=1;
        while(curr.next!=null)
        {
            if(curr.data==key)
            {
               // System.out.println(key+"found at"+pos);
                return pos;
            }
            else{
                pos++;
                curr=curr.next;
            }
        }
       //System.out.println("Not Found")
        return -1;
    }
    public int searchkey(Node head,int key)
    {
        if (head==null) return -1;
        else if(head.data==key) return 1;
        else{
            int h=searchkey(head.next,key);
            if(h==-1) return -1;
            return (h+1);
        }
    }
}