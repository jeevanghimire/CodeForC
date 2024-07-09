func mergeSort(numbers: inout [Int], start: Int, end: Int) {
    if start >= end {
        return
    }
    
    let mid = start + (end - start) / 2
    mergeSort(numbers: &numbers, start: start, end: mid)
    mergeSort(numbers: &numbers, start: mid + 1, end: end)
    merge(numbers: &numbers, start: start, mid: mid, end: end)
}

func merge(numbers: inout [Int], start: Int, mid: Int, end: Int) {
    var temp: [Int] = []
    var idx1 = start, idx2 = mid + 1
    
    while idx1 <= mid && idx2 <= end {
        if numbers[idx1] < numbers[idx2] {
            temp.append(numbers[idx1])
            idx1 += 1
        } else {
            temp.append(numbers[idx2])
            idx2 += 1
        }
    }
    
    while idx1 <= mid {
        temp.append(numbers[idx1])
        idx1 += 1
    }
    
    while idx2 <= end {
        temp.append(numbers[idx2])
        idx2 += 1
    }
    
    for i in start...end {
        numbers[i] = temp[i - start]
    }
}

func main() {
    var numbers = [3, 4, 2, 77, 43, 44, 23, 34, 64, 21, 33, 44, 55, 66, 77, 88, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120]
    let start = 0, end = numbers.count - 1
    mergeSort(numbers: &numbers, start: start, end: end)
    
    for number in numbers {
        print("\(number) ", terminator: "")
    }
}

main()