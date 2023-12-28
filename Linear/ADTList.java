public interface ADTList<E> {
    void add(E element);
    void remove(E element);
    Node<E> removeFirst();
    Node<E> removeLast();
    boolean contains(E element);
    int size();
    boolean isEmpty();
    void clear();
    void print();
}