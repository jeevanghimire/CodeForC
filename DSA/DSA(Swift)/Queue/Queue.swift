import CoreFoundation
var array  = [Int]()
var front = 0

func isEmpty () -> Bool{
    return array.isEmpty;
}
func Count () -> Int{
    return array.count;
}

func push(_ data:Int) {
    array.append(data)
} 

func pop() -> Int? {
    if isEmpty() {
        return nil
    } else {
        print("popped element is \(array.last!)")
        return array.removeLast()
    }
}
func display() {
    // Display like a stack FILO
    for element in array.reversed() {
        print(element, terminator: " ")
    }
    print()
}

func peek() ->Int?{
    if isEmpty()
{
    return nil
} else{
    return array.last
}
}
    //pushing the element in the queue
    push(10)
    push(20)
    push(30)
    push(40)
    push(50)
    push(60)
    //displaying the queue
    display()
    //popping the element from the queue
    if let _ = pop() {    
    } else {
        print("Queue is empty")
    }
    //displaying the queue
    display()
    //peeking the element from the queue
    print(peek()!)
    //displaying the queue
    display()