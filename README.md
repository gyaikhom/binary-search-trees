# Implementing Binary Search Trees

In this project, we implement the following binary search trees:

* Simple Binary Search Tree
* Splay Tree

These programs were written for self-study. Few functions have not been
implemented yet.

I have written articles describing these implementations at my
[homepage](http://yaikhom.com/articles.html).


## Interesting stuff

In addition to **recursive** implementations of in-order, pre-order
and post-order tree traversal and tree destruction, we also provide
**non-recursive** implementations.

Note that in these non-recursive implementations, we do not use
a _Stack_, which is a common method for non-recursive implementations.
Instead, we use a node property `visited` which is a boolean variable.
This removes the overhead of maintaining a _Stack_.
