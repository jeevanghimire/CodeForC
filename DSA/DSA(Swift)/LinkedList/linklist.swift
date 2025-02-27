//implement the link list

import Foundation

class Node<T: Equatable> {
    var value: T
    var next: Node<T>?
    
    init(value: T) {
        self.value = value
    }
}

class LinkedList<T: Equatable> {
    var head: Node<T>?
    
    func append(value: T) {
        if head == nil {
            head = Node(value: value)
            return
        }
        
        var current = head
        while current?.next != nil {
            current = current?.next
        }
        
        current?.next = Node(value: value)
    }
    
    func remove(value: T) {
        if head?.value == value {
            head = head?.next
            return
        }
        
        var prev = head
        var current = head?.next
        while current != nil {
            if current?.value == value {
                prev?.next = current?.next
                return
            }
            prev = current
            current = current?.next
        }
    }
    
    func printList() {
        var current = head
        var result = ""
        while current != nil {
            result += "\(current!.value) "
            current = current?.next
        }
        print(result.trimmingCharacters(in: .whitespaces))
    }
}
    
let list = LinkedList<Int>()
list.append(value: 1)
list.append(value: 2)
list.append(value: 3)
list.append(value: 4)
list.append(value: 5)
list.printList()
list.remove(value: 3)
list.printList()
list.remove(value: 1)
list.printList()

list.remove(value: 5)
list.printList()
list.remove(value: 2)
