// Learn more about F# at http://fsharp.net

module Esercitazione3

let NomeCognome : string = "Kevin Wiederstein"

let rec gcd (x : int) (y : int) : int = 
    if(y=0)then
        x
    else
        gcd (y) (x%y)


let rec MCD (x:int,y:int,n:int) : int =
    if(n=1)then
        n
    else 
        if(x%n = 0 && y%n = 0)then
            n
        else
            MCD(x,y,n-1)

let rec coprime (x : int) (y : int) : bool = 
    if(x>=y)then
        if(MCD(y,x,y)=1)then true else false
    else
        if(MCD(x,y,x)=1)then true else false



let rec tryD (num : int , div : int) =
    if (div=1) then
        true
    else
        if ( (num % div) = 0 ) then
            false
        else
            tryD ( num , (div-1) )

let is_prime (n : int) : bool = 
    if(n <= 1)then
        false   
    else
        tryD(n,n-1)

        
let rec preGOLDSTAENDER (x:int) (y:int) (n:int) : int * int = 
    if ( y = 0 || x = n) then
        0,0
    else
        if(is_prime(x) && is_prime(y) && x+y=n) then
            x,y
        else
            preGOLDSTAENDER (x+1) (y-1) n 


let rec goldbach (n : int) : int * int = 
   preGOLDSTAENDER (0+1) (n-1) (n)