import Foundation

var input = readLine()!.split(separator: " ").map { str in
    return Int(str)!
}

var N = input[0]
var M = input[1]

if (N == M) { print("1") }
else { print("0") }