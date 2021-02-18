This program uses derived classes of Product: book, clothing and store to store a list
of Products in a multipmap where keywords act as the keys to the Products.

Keywords were determined by splitting the name and other class specific members
(ex: isbn for books) at puncation and throwing away any segments less than 2 characters.

This program supports the following commands: AND/OR, ADD, VIEWCART, BUYCART

compile with "make"
