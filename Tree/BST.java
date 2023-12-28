public class BST<T extends Comparable<T>>{
    private Node<T> root;

    public BST() {
        this.root = null;
    }

    public boolean isEmpty() {
        return root == null;
    }

    public boolean insert(T data) {
        if (search(data) == true) {
            return false;
        } else {
            root = insert(root, data);
            return true;
        }
    }

    private Node<T> insert(Node<T> node, T data) {
        if (node == null) {
            node = new Node<T>(data);
        } else {
            if (data.compareTo(node.getData()) < 0) {
                node.setLeft(insert(node.getLeft(), data));
            } else {
                node.setRight(insert(node.getRight(), data));
            }
        }
        return node;
    }

    public boolean search(T data) {
        return search(root, data);
    }

    private boolean search(Node<T> node, T data) {
        boolean found = false;
        while ((node != null) && !found) {
            T nodeData = node.getData();
            if (data.compareTo(nodeData) < 0) {
                node = node.getLeft();
            } else if (data.compareTo(nodeData) > 0) {
                node = node.getRight();
            } else {
                found = true;
                break;
            }
            found = search(node, data);
        }
        return found;
    }

    public Node<T> delete(Node<T> node, T data) {
        if (node == null) {
            return node;
        }
        if (data.compareTo(node.getData()) < 0) {
            node.setLeft(delete(node.getLeft(), data));
        } else if (data.compareTo(node.getData()) > 0) {
            node.setRight(delete(node.getRight(), data));
        } else {
            if (node.getLeft() == null && node.getRight() == null) {
                node = null;
            } else if (node.getLeft() == null) {
                node = node.getRight();
            } else if (node.getRight() == null) {
                node = node.getLeft();
            } else {
                Node<T> temp = findMin(node.getRight());
                node.setData(temp.getData());
                node.setRight(delete(node.getRight(), temp.getData()));
            }
        }
        return node;
    }

    public Node<T> findMin(Node<T> node) {
        if (node == null) {
            return null;
        } else if (node.getLeft() == null) {
            return node;
        } else {
            return findMin(node.getLeft());
        }
    }

    public void inorder() {
        inorder(root);
    }

    private void inorder(Node<T> node) {
        if (node != null) {
            inorder(node.getLeft());
            System.out.print(node.getData() + " ");
            inorder(node.getRight());
        }
    }

    public void preorder() {
        preorder(root);
    }

    private void preorder(Node<T> node) {
        if (node != null) {
            System.out.print(node.getData() + " ");
            preorder(node.getLeft());
            preorder(node.getRight());
        }
    }

    public void postorder() {
        postorder(root);
    }

    private void postorder(Node<T> node) {
        if (node != null) {
            postorder(node.getLeft());
            postorder(node.getRight());
            System.out.print(node.getData() + " ");
        }
    }

    public static void main(String[] args) {
        BST<Integer> tree = new BST<Integer>();
        tree.insert(5);
        tree.insert(3);
        tree.insert(7);
        tree.insert(2);
        tree.insert(4);
        tree.insert(6);
        tree.insert(8);
        System.out.println("Inorder traversal:");
        tree.inorder();
        System.out.println("\nPreorder traversal:");
        tree.preorder();
        System.out.println("\nPostorder traversal:");
        tree.postorder();
    }
}