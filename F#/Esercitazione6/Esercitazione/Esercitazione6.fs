module Esercitazione6

let NomeCognome = "Kevin Wiederstein"

let rec fibonacci (n : int) : float = 
    let rec fibAux n a b =
        match n with
            0 -> a
           | _ -> fibAux (n-1) b (a+b)
    in fibAux n 0.0 1.0

let rec trovaValorePiuPiccoloDellaLista lst =
    let rec trovaValorePiuPiccoloDellaListaDue lst var = 
            match lst with 
                [] -> var
               |x::xs when x < var -> trovaValorePiuPiccoloDellaListaDue xs x
               |x::xs when x >= var -> trovaValorePiuPiccoloDellaListaDue xs var
     
    in match lst with 
            [] -> 0
           |x::xs -> trovaValorePiuPiccoloDellaListaDue xs x

let rec quick_sort (xs : int list) : int list =  
    let rec restituisciListaSenzaElementoN lst n = 
        match lst with 
            [] -> []
           |x::xs when x = n -> restituisciListaSenzaElementoN xs n
           |x::xs when x <> n -> [x]@restituisciListaSenzaElementoN xs n
           |_ -> []

    let rec internalQuickSort xsDestra =
        if(xsDestra <> [])then
            [trovaValorePiuPiccoloDellaLista xsDestra]@(internalQuickSort (restituisciListaSenzaElementoN xsDestra (trovaValorePiuPiccoloDellaLista xsDestra)))
        else
            []
    in internalQuickSort xs

let rec split (x : char) (xs : char list) : char list list = 
    let rec countElement c lst =
        match lst with
            [] -> 0
           |x::xs when x = c -> 1 + countElement c xs
           |x::xs when x <> c -> 0 + countElement c xs
           |_ -> 0
      
    let rec auxSplit c lst = 
        match lst with
           |x::xs when x <> c -> x::auxSplit c xs
           | _ -> []

    let rec auxSplitMain c lst lst2 n = 
        match lst with 
          |x::xs when x <> c -> auxSplitMain c xs lst2 n
          |x::xs when x = c -> [auxSplit c lst2]@auxSplitMain c xs xs (n-1)
          |_ -> []

    let rec AddFinaleMuahah c lst n =
        match lst with 
           |x::xs when x = c && n <> 0 -> AddFinaleMuahah c xs (n-1)
           |x::xs when x = c && n = 0 -> AddFinaleMuahah c xs 0
           |x::xs when x <> c && n = 0 -> [x]@AddFinaleMuahah c xs 0
           |x::xs when x <> c && n <> 0 -> AddFinaleMuahah c xs n
           |_ -> []
    
    let rec ControllaPrimaLetteraListaUltraLongFunctionFamous c lst =
        match lst with
            [] -> []
           |x::xs when x = c -> ControllaPrimaLetteraListaUltraLongFunctionFamous c xs
           |x::xs when x <> c -> x::xs
           |_ -> []

    let rec PulisciListaDiListe lst =
        match lst with
            [] -> []
           |x::xs when x = [] -> PulisciListaDiListe xs
           |x::xs when x <> [] -> [x]@PulisciListaDiListe xs
           |_ -> []

    in PulisciListaDiListe (auxSplitMain x (ControllaPrimaLetteraListaUltraLongFunctionFamous x xs) (ControllaPrimaLetteraListaUltraLongFunctionFamous x xs) (countElement x xs)@[AddFinaleMuahah x xs (countElement x xs)])

