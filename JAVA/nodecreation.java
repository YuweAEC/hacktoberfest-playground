class Node {
int data;
Node next;
Node(int x)
{data=x;
next=null;
}
}
class  nodecreation{
public static void main(String [] args)
{ 
 Node head= new Node(10);
Node temp1=new Node(20);
Node temp2=new Node(30);
head.next=temp1;
temp1.next=temp2;
printList(head);
                                                  //or we can use printhead.data,temp1.data,temp2.data
}
public static void printList(Node head)
{ 
Node t=head;
while(t !=null)
{
System.out.println(t.data);
t=t.next;
}
} 
}
