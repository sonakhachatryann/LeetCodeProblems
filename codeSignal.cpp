/*
Write a function that will change the kth bit of n back to 0.
*/

int solution(int n, int k) {
  return n & ~(1 << (k - 1));
}

/*
Example

For n = 37 and k = 3, the output should be
solution(n, k) = 33.

3710 = 1001012 ~> 1000012 = 3310.

For n = 37 and k = 4, the output should be
solution(n, k) = 37
*/