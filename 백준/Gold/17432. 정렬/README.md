# [Gold III] 정렬 - 17432 

[문제 링크](https://www.acmicpc.net/problem/17432) 

### 성능 요약

메모리: 2752 KB, 시간: 52 ms

### 분류

해 구성하기, 정렬

### 제출 일자

2024년 5월 17일 14:17:29

### 문제 설명

<p>크기가 N인 순열 A = [A<sub>1</sub>, A<sub>2</sub>, ..., A<sub>N</sub>]이 있을 때, 아래 코드를 이용하면 순열을 정리할 수 있다. 크기가 N인 순열은 1부터 N까지의 자연수가 한 번씩 등장하는 수열이다.</p>

<table class="table table-bordered" style="width: 100%;">
	<tbody>
		<tr>
			<td style="width: 100%;">
			<pre>input: n, a[1 .. n]
cnt = 0
for j = 2 to n:
  <wbr>x = a[j]
  <wbr>i = j - 1
  <wbr>while i >= 1 and a[i] > x:
  <wbr>  <wbr>cnt = cnt + 1
  <wbr>  <wbr>a[i+1] = a[i]
  <wbr>  <wbr>i = i-1
  <wbr>a[i+1] = x
</pre>
			</td>
			
		</tr><tr>
			<td style="width: 100%; text-align: center;">의사코드</td>
		</tr>
	</tbody>
</table>

<p>길이가 N인 순열을 정렬하는 경우 cnt는 항상 0 이상 N×(N-1)/2 이하이다. 두 정수 N과 M이 주어졌을 때, 위의 코드를 이용해 정렬이 완료된 후의 cnt의 값이 M이 되는 길이가 N인 순열을 찾아보자.</p>

### 입력 

 <p>첫째 줄에 테스트 케이스의 수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, N과 M이 주어진다.</p>

### 출력 

 <p>각 테스트 케이스마다, 한 줄에 하나씩 cnt의 값이 M인 순열을 출력한다.</p>

<p>조건을 만족하는 순열이 여럿인 경우 아무 것이나 하나 출력하면 된다.</p>

