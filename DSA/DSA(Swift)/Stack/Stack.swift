import Foundation


var data = [Int]()
var Front:Int = 0;
func push(_ Data:Int){
    data.append(Data)
}
func pop(){
    data.removeFirst();
}
