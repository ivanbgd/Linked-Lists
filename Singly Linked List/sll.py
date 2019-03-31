class Node(object):
    def __init__(self, value):
        self.value = value
        self.next = None

    def __str__(self):
        return "{}".format(self.value)

    def get_value(self):
        return self.value


class List(object):
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def __str__(self):
        return "Head = {}; Size = {}".format(self.head, self.size)

    def get_head(self):
        return self.head

    def get_tail(self):
        return self.tail

    def add_node(self, value, current = None):
        node = Node(value)
        if (not self.head):
            self.head = node
            self.tail = self.head
            self.size += 1
            return
        if (current):
            node.next = current.next
            current.next = node
            if (current == self.tail):
                self.tail = node
            self.size += 1

    def delete_node(self, current = None):
        """Deletes the next node."""
        if ((not current) or (not current.next)):
            return
        next = current.next
        current.next = current.next.next
        del next
        self.size -= 1

    def reverse(self):
        """Reverses entire list."""
        prev = None
        curr = None
        next = None

        self.tail = self.head
        curr = self.head
        while (curr):
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
        self.head = prev

    def reverse_in_middle(self, start, end):
        """Reverses elements in the middle of a list.
           start >= 1"""
        prev = None
        curr = None
        next = None
        old_prev = None
        start_node = None
        end_node = None
        old_next = None

        old_prev = self.traverse(start)
        start_node = old_prev.next
        curr = old_prev
        for i in range(start, end + 2):
            if (not curr):
                break
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
        end_node = prev
        old_next = curr
        old_prev.next = end_node
        start_node.next = old_next

        if (curr is None):
            self.tail = start_node
        else:
            while (curr):
                self.tail = curr
                curr = curr.next

    def traverse(self, dist):
        current = self.head
        for i in range(dist - 1):
            if (not current):
                break
            current = current.next
        return current





def print_list(current = None):    
    print("[head] => ", end='')
    while (current):
        print(str(current) + " => ", end='')
        current = current.next
    print("[tail]")


    

l = List()
print(l)
current = l.traverse(3)
print(current, l.get_head(), l.get_tail())
print()

for i in range(5):
    l.add_node(i, l.get_tail())
print(l)
print_list(l.get_head())
print()

current = l.traverse(2)
l.delete_node(current)
print(l)
print_list(l.get_head())
print()

current = l.traverse(2)
l.add_node(2, current)
print(l)
print_list(l.get_head())
print()

l.reverse()
print(l)
print_list(l.get_head())
print()

l.add_node(99, l.get_tail())
l.add_node(98, l.get_tail())
print(l)
print_list(l.get_head())
print()

current = l.traverse(6)
l.delete_node(current)
current = l.traverse(5)
l.delete_node(current)
print(l)
print_list(l.get_head())
print()

l.reverse()
l.add_node(5, l.get_tail())
l.add_node(6, l.get_tail())
print(l)
print_list(l.get_head())
print()

print("\n\nReverse in middle:\n")

l.reverse_in_middle(2, 4)
print(l)
print_list(l.get_head())
print()

l.add_node(7, l.get_tail())
l.add_node(8, l.get_tail())
print(l)
print_list(l.get_head())
print()

l.reverse_in_middle(2, 4)
print(l)
print_list(l.get_head())
print()

current = l.traverse(8)
l.delete_node(current)
current = l.traverse(7)
l.delete_node(current)
print(l)
print_list(l.get_head())
print()

l.reverse_in_middle(1, 6)
print(l)
print_list(l.get_head())
print()

l.add_node(7, l.get_tail())
l.add_node(8, l.get_tail())
print(l)
print_list(l.get_head())
print()

l.reverse_in_middle(1, 6)
print(l)
print_list(l.get_head())
print()

current = l.traverse(8)
l.delete_node(current)
current = l.traverse(7)
l.delete_node(current)
print(l)
print_list(l.get_head())
print()

