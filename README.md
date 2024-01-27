# c-language-important-terms
## 1.ARRAY-An array is a collection of items of same data type stored at contiguous memory locations. 

for example-

![Screenshot 2024-01-27 111414](https://github.com/Riyatomar14/c-language-important-terms/assets/143107173/c07ec1be-47ad-494b-a2cf-5e16ace9769d)

![Screenshot 2024-01-27 111447](https://github.com/Riyatomar14/c-language-important-terms/assets/143107173/b6c9fb1e-baee-43af-9ced-4e819c46bde8)

![Screenshot 2024-01-27 111128](https://github.com/Riyatomar14/c-language-important-terms/assets/143107173/23993811-751a-4ebf-bcd5-cd0c562fd7b7)

# remember -  “Location of next index depends on the data type we use”.

# Note- why indexes start with 0 ?

Because as it save the subtraction (operation) cost and hence some time.It is a more efficient way. 

Let us assume a 2D array and write a row-major formula  with two different approaches:

CASE1: array indices starting from 1
CASE2 :array indices starting from 0
let the 2D array be arr[m][n] of type int

let &arr be “address”
![Screenshot 2024-01-27 113422](https://github.com/Riyatomar14/c-language-important-terms/assets/143107173/0efa0d22-2135-4d03-82df-5316f8c0d5e0)

# case 1 may look user-friendly but case 2 is more efficient. That’s why most languages like C++, PYTHON, JAVA use arrays starting with index 0 and rarely languages like Lua arrays starting with index 1.

## 2. ROW-MAJOR ORDER SET AND COLUMN-MAJOR ORDER SET
In computing, row-major order and column-major order are methods for storing multidimensional arrays in linear storage such as random access memory.

a) ROW-MAJOR ORDER SET-the elements in row-major order are arranged consecutively along the row.for example-In C (and many other languages like C++, Java etc), 2-D arrays are stored in row-major order.

b) COLUMN-MAJOR ORDER SET-The elements in the column-major order are arranged consecutively along the column. for example- Pascal and Fortran follows column major order.

![image](https://github.com/Riyatomar14/c-language-important-terms/assets/143107173/9618373e-8390-4e60-aafc-8d187fdc123e)

## 2. FUNCTION-A function is a set of statements that takes input, does some specific computation, and produces output. The idea is to put some commonly or repeatedly done tasks together to make a function so that instead of writing the same code again and again for different inputs, we can call this function.

for example-
![Screenshot 2024-01-27 111109](https://github.com/Riyatomar14/c-language-important-terms/assets/143107173/9a15bb05-b1e7-480f-bcc5-09e884abcccf)

# PARAMETER PASSING TECHNIQUES











