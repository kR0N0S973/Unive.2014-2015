//module Esercitazione5

let NomeCognome = "Kevin Wiederstein"

let rec padding (xs : char list) (n : int) : char list = 
    let rec take n lst =
        match (n, lst) with
            (0,_) -> []
          | (_,[]) -> []
          | (n, x::xs) -> x::(take (n-1) xs)

    let rec getN (lst) =
        match lst with
            [] -> 0
          | x::xs -> 1+getN(xs)

     in 
       if(xs <> [])then 
           match n with
            0 -> []
           |_ when n >= getN(xs) -> xs@padding xs (n-getN(xs))
           |_ when n < getN(xs) -> (take n xs)
           |n -> []
        else []

           
let rec vigenere (key : char list) (plain_text : char list) : char list = 
    let encode_char (ch : char) (n : int) : char = 
        if (ch >= 'a' && ch <= 'z' ) 
        then match (int( ch ) + n%26) > int( 'z' ) , (int( ch ) + n%26) < int( 'a' ) 
                    with (true , false) -> char ((int( ch ) + n%26) - 26) 
                       | (false , true) -> char ((int( ch ) + n%26) + 26) 
                       |_               -> char (int( ch ) + n%26)
        else ch
    
    let rec nth (lst:char list) (k:int) = 
        match (lst, k) with
          [],_ -> 0
        | (x::xs, 0) -> int(x)-int('a')
        | (x::xs, k) -> (nth xs (k-1)) 

    let rec getN lst =
        match lst with
            [] -> 0
          | x::xs -> 1+getN(xs)

    let rec vigenere2 (key : char list) (plain_text : char list) (n1:int) : char list = 
        match plain_text,n1 with
            [],_ -> []
           | x::xs, n when n < (getN key) -> [encode_char x (nth key n1)]@vigenere2 key xs (n1+1) 
           | x::xs, n when n = (getN key) -> vigenere2 key (x::xs) 0
           | _ -> []
    in vigenere2 key plain_text 0
                      

let rec count_occurrences (xs : char list) : (char * int) list = 
    let rec countChars ( lst : char list , ch : char ) : int = 
        match lst with
            [] -> 0
          | x::xs when x = ch -> 1 + countChars(xs,ch)
          | x::xs -> 0 + countChars(xs,ch)


    let rec existsChar ( lst : char list, ch : char) = 
        match lst with
            [] -> false
          | x::xs -> x = ch || existsChar(xs,ch)
    
    let rec count_occurrences (xs : char list) (xs2 : char list) : (char * int) list = 
        match xs with 
            [] -> []
          | x::xz -> if(existsChar(xz, x))then 
                        count_occurrences xz xs2
                     else 
                        [(x,countChars(xs2,x))]@count_occurrences xz xs2
    in 
        count_occurrences xs xs

         