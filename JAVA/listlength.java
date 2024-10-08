class Node {
int data;
Node next;
Node(int x)
{data=x;
next=null;
}
}
class  listlength{
public static void main(String [] args)
{ 
 Node head= new Node(10);
Node temp1=new Node(20);
Node temp2=new Node(30);
head.next=temp1;
temp1.next=temp2;
printlength(head);
                                                  //or we can use printhead.data,temp1.data,temp2.data
}
public static void printlength(Node head)
{ int length=0;
Node curr= head;
while(curr!=null){ 
length++;
curr=curr.next;
}
System.out.println(length);
}
}
