// Learn more about F# at http://fsharp.net

module Esercitazione0

let NomeCognome : string = "Kevin Wiederstein"

let pythagoras (c1 : float) (c2 : float) : float = 
  sqrt (( c1 * c1 ) + ( c2 * c2 ))

let angular_coeff (x1 : float) (y1 : float) (x2 : float) (y2 : float)  : float = 
  (( y2 - y1 ) / ( x2 - x1 ))

let rhombus_perimeter (d1 : float) (d2 : float) : float = 
  4.0 * sqrt((( d1 / 2.0 ) * ( d1 / 2.0 )) + (( d2 / 2.0 ) * ( d2 / 2.0 )))
