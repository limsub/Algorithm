//
//  main.swift
//  백준연습
//
//  Created by 임승섭 on 2023/07/01.
//

import Foundation

var N = Int(readLine()!)


var numbers = readLine()

var ans_num: [Int] = []

if let numbers = numbers {
    var inputs = numbers.components(separatedBy: " ")
    
    ans_num = inputs.map({ str in
        return Int(str) ?? 0
    })
}

var ans_count = 0;

var k = readLine()
if let k = k {
    var a = Int(k)
    
    for i in 0...(ans_num.count - 1) {
        if a == ans_num[i] {
            ans_count += 1
            
        }
    }
    
    
}

print(ans_count)
