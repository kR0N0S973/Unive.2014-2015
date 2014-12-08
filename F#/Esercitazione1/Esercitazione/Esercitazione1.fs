//// Learn more about F# at http://fsharp.net

module Esercitazione1


let NomeCognome : string = "Kevin Wiederstein"

let rec encode_char (ch : char) (n : int) : char = 
    if (ch >= 'a') && (ch <= 'z') then
        if ( n >= 0 ) then 
            if ( (int ch)+n > 122 ) then
                if ( n-(122-int(ch)))  > 25 then
                    encode_char 'a' (n-(122-int(ch)))
                else
                    char (96+(n-(122-int(ch))))  
            else char ( (int ch) + n )
        else
            if ( (int ch)+n <= 96 ) then
                if ( (int('a')-((int ch)+n)) ) > 25 then
                    encode_char 'z' (( int(ch) - (97) )+n)
                else
                    char (  122-(96-((int ch)+n)))  
            else char ( (int ch) + n ) 
    else '\n'

    
let leap_year (year : int) : bool = 
     if  ( year % 4 ) =  0 && ( year %  100 ) <>  0  then
        true
     else
        if  ( year % 400 ) =  0 then
            true
        else
            false

let perpetual_calendar (day : int) (month : int) (year : int) : int = 
        if(month<3) then
            (day + 2*(month+12) + int(6*(month+13) /10) + (year-1) + int((year-1)/4) - int((year-1)/100) + int((year-1)/400) + 1) % 7
        else
            ((day + 2*(month) + int(6*(month+1) /10) + (year) + int(year)/4) - int(year/100) + int(year/400) + 1) % 7

