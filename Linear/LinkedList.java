public class LinkedList<T> implements ADTList<T> {
    private Node<T> head;
    private int size;

    public LinkedList() {
        head = null;
        size = 0;
    }
    
    public void add(T element) {
        Node<T> newNode = new Node<>(element);
        if (head == null) {
            head = newNode;
        } else {
            Node<T> current = head;
            while (current.getNext() != null) {
                current = current.getNext();
            }
            current.setNext(newNode);
        }
        size++;
    }
    
    public void remove(T element) {
        if (head == null) {
            return;
        }
        if (head.getData().equals(element)) {
            head = head.getNext();
            size--;
            return;
        }
        Node<T> current = head;
        Node<T> previous = null;
        while (current != null && !current.getData().equals(element)) {
            previous = current;
            current = current.getNext();
        }
        if (current != null) {
            previous.setNext(current.getNext());
            size--;
        }
    }
    
    public Node<T> removeFirst() {
        if (head == null) {
            return null;
        }
        Node<T> removed = head;
        head = head.getNext();
        size--;
        return removed;
    }

    public Node<T> removeLast() {
        if (head == null) {
            return null;
        }
        Node<T> current = head;
        Node<T> previous = null;
        while (current.getNext() != null) {
            previous = current;
            current = current.getNext();
        }
        if (previous == null) {
            head = null;
        } else {
            previous.setNext(null);
        }
        size--;
        return current;
    }

    public boolean contains(T element) {
        Node<T> current = head;
        while (current != null) {
            if (current.getData().equals(element)) {
                return true;
            }
            current = current.getNext();
        }
        return false;
    }
    
    public int size() {
        return size;
    }
    
    public boolean isEmpty() {
        return size == 0;
    }
    
    public void clear() {
        head = null;
        size = 0;
    }

    
    public void print() {
        Node<T> current = head;
        while (current != null) {
            System.out.print(current.getData() + " ");
            current = current.getNext();
        }
        System.out.println();
    }
}