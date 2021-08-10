// java.util.* and java.util.streams.* have been imported for this problem.
// You don't need any other imports.

public ListNode insertAtTail(ListNode head, int data) {
    ListNode new_node = new ListNode(data);
    new_node.next = null;
    if(head == null){
        return new_node;
    }
    ListNode tmp = head;
    while(tmp.next != null){
        tmp = tmp.next;
    }
    tmp.next = new_node;
    return head;
}