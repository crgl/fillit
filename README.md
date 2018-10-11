# fillit
Have you ever had a bunch of Tetris pieces and needed to choose a box to put them in? Neither have I, but in the general spirit of preparedness this algorithm might be of interest nonetheless.

This is an implementation of Donald Knuth's dancing links algorithm, performing depth first search with backtracking to find the smallest square that would fit a collection of non-rotatable tetris pieces. The dancing links algorithm relies on choosing the minimum possible branching for each step, providing a potentially exponential increase in speed over the naive solution. In practice, this means that for the elegantly named rample.tetrimino, we have not been able to find another implementation which finishes (at least within the space of two hours.

Example Piece:

. . . .</br>
# # . .</br>
. # . .</br>
. # . .</br>

Output format:

B B B B F F F F</br>
D D A A J J J J</br>
C D D A H H E E</br>
C C C A G H H E</br>
N N N N G G G E</br>
L L I I P P M M</br>
K L L I O P P M</br>
K K K I O O O M
