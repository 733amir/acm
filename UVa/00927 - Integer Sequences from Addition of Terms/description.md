## 927 - Integer Sequences from Addition of Terms

There is a relation between _n_, _d_ and _k_.

If `A = (n * (n + 1) * d) / 2` =>

1. `A >= k`
2. `abs(A - k) should be minimum`

From 1 & 2 we will get:

`n * (n + 1) >= (2 * k) / d` => `n * (n + 1) >= n ** 2 => (2 * k) / d`=>  
`n = round(sqrt((2 * k) / d))`

And then what will remain is to calculate _nth_ element in _`a`_ sequence.
