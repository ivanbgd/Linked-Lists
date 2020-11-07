"""
Singly Linked List
"""

from typing import Any, Optional


class Node():
    """An element of the list."""
    def __init__(self, value: Any) -> None:
        self.value: Any = value
        self.next: Optional[Node] = None

    def __str__(self) -> str:
        return f"{self.value}"


class List():
    """Singly Linked List."""
    def __init__(self) -> None:
        self.head: Optional[Node] = None
        self.tail: Optional[Node] = None
        self.size: int = 0

    def __str__(self) -> str:
        return f"Head = {self.head}; Size = {self.size}"

    def add_node(self, value: Any, current: Optional[Node] = None) -> None:
        """Adds a new node and sets head and tail pointers appropriately."""
        node = Node(value)
        if self.head is None:
            self.head = node
            self.tail = self.head
            self.size += 1
            return
        if current is not None:
            node.next = current.next
            current.next = node
            if current is self.tail:
                self.tail = node
            self.size += 1

    def delete_node(self, current: Optional[Node] = None) -> None:
        """Deletes the next node."""
        if current is None or current.next is None:
            return
        next = current.next
        current.next = current.next.next
        del next
        self.size -= 1

    def reverse(self):
        """Reverses entire list."""
        prev: Optional[Node] = None
        curr: Optional[Node] = None
        next: Optional[Node] = None

        self.tail = self.head
        curr = self.head
        while curr is not None:
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
        self.head = prev

    def reverse_in_middle(self, start: int, end: int) -> None:
        """
        Reverses elements in the middle of a list.\n
        start >= 1\n
        """
        prev: Optional[Node] = None
        curr: Optional[Node] = None
        next: Optional[Node] = None
        old_prev: Optional[Node] = None
        start_node: Optional[Node] = None
        end_node: Optional[Node] = None
        old_next: Optional[Node] = None

        old_prev = self.traverse(start)
        if old_prev is None:
            return
        start_node = old_prev.next
        curr = old_prev
        for _ in range(start, end + 2):
            if curr is None:
                break
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
        end_node = prev
        old_next = curr
        old_prev.next = end_node
        if start_node is None:
            return
        start_node.next = old_next

        if curr is None:
            self.tail = start_node
        else:
            while curr is not None:
                self.tail = curr
                curr = curr.next

    def traverse(self, dist: int) -> Optional[Node]:
        """
        Jumps to the given element if it exists and returns it,
        or returns None if it doesn't exist.
        """
        current: Optional[Node] = self.head
        for _ in range(dist - 1):
            if current is None:
                break
            current = current.next
        return current


def print_list(current: Optional[Node] = None) -> None:
    """Prints entire list."""
    print("[head] => ", end='')
    while current is not None:
        print(str(current) + " => ", end='')
        current = current.next
    print("[tail]")


if __name__ == "__main__":
    lst = List()
    print(lst)

    current: Optional[Node] = lst.traverse(3)
    print(current, lst.head, lst.tail)
    print()

    for i in range(5):
        lst.add_node(i, lst.tail)
    print(lst)
    print_list(lst.head)
    print()

    current = lst.traverse(2)
    lst.delete_node(current)
    print(lst)
    print_list(lst.head)
    print()

    current = lst.traverse(2)
    lst.add_node(2, current)
    print(lst)
    print_list(lst.head)
    print()

    lst.reverse()
    print(lst)
    print_list(lst.head)
    print()

    lst.add_node(99, lst.tail)
    lst.add_node(98, lst.tail)
    print(lst)
    print_list(lst.head)
    print()

    current = lst.traverse(6)
    lst.delete_node(current)
    current = lst.traverse(5)
    lst.delete_node(current)
    print(lst)
    print_list(lst.head)
    print()

    lst.reverse()
    lst.add_node(5, lst.tail)
    lst.add_node(6, lst.tail)
    print(lst)
    print_list(lst.head)
    print()

    print("\n\nReverse in the middle:\n")

    lst.reverse_in_middle(2, 4)
    print(lst)
    print_list(lst.head)
    print()

    lst.add_node(7, lst.tail)
    lst.add_node(8, lst.tail)
    print(lst)
    print_list(lst.head)
    print()

    lst.reverse_in_middle(2, 4)
    print(lst)
    print_list(lst.head)
    print()

    current = lst.traverse(8)
    lst.delete_node(current)
    current = lst.traverse(7)
    lst.delete_node(current)
    print(lst)
    print_list(lst.head)
    print()

    lst.reverse_in_middle(1, 6)
    print(lst)
    print_list(lst.head)
    print()

    lst.add_node(7, lst.tail)
    lst.add_node(8, lst.tail)
    print(lst)
    print_list(lst.head)
    print()

    lst.reverse_in_middle(1, 6)
    print(lst)
    print_list(lst.head)
    print()

    current = lst.traverse(8)
    lst.delete_node(current)
    current = lst.traverse(7)
    lst.delete_node(current)
    print(lst)
    print_list(lst.head)
    print()
