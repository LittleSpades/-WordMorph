# WordMorph
#### Algorithms and Data Structures IST Project

### O problema – Caminhos entre palavras

In this project we intend to develop a program that is capable of producing "paths" between portuguese words.
A path between two words (of the same size), is given by a starting point and an end point, a sequence of words of equal size, in which each word is obtained from its predecessor by replacing one or more characters for another(s). 
The path presented in the final file corresponds to the lowest cost path. In this project the cost is the sqare of the number of characters replaced between two consecutive words.

EX.:
      carro 
      corro
      corto
      porto
      porta
      posta
      pista

      Cost = 6

### How to run?

      ./wordmorph <nome1>.dic <nome2>.pal
  
<name1>: Variable that identifies the file containing the dictionary to use. The application is restricted to dictionaries composed exclusively of words containing Latin characters, not accented and not hyphenated.
  
<name2>: Variable that identifies the file containing one or more problems to solve.
