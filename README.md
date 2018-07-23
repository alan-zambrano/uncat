# UNCAT

uncat is a program that takes a concatenated string composed of 2 or more words
and separates it back into its individual words. It does this by iterating
through each letter in the concatenated string and recursively finding existing
words in the dictionary.

Because this recursive approach required  many dictionary lookups, it was
important for them to be fast. It seemed obvious to use a hash table for O(1)
accesses, but I was deterred by the minimum amount of storage necessary and the
amount of wasted storage to prevent collisions. I wanted a dictionary large
enough to contain all words in the English language, so the hash table would
require at least O(n) space for n words in the dictionary. Instead, I settled
for an n-ary tree which becomes very space efficient with large dictionaries at
the expense of quick lookups. It's also extremely easy to make the tree larger
whereas hash tables can be trickier.In the future I'd like to compare the
runtime efficiency of both structures and determine whether the sacrifice to
speed is worth these advantages.

## node.cpp
A simple class structure that contains a letter for identification purposes and
a pointer to its parent node. Each node also contains an array of size 28 that
contains a pointer to another node with value equal to that of its
corresponding position in the array, ie children[0] points to a node with
value='a'. It's important to mention that nodes are not case sensitive and can
only be created with value as an alphabetic value, or '$', or '.'. '$' is an
end-of-word delimiter, and '.' is used for acronym words.

## tree.cpp
Contains a node object called root for navigation purposes. This class also
contains member functions to add words to the tree and to check if a given
string exists in the dictionary.
