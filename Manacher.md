<p align="center">
  <a href="http://shallweitalk.com">
    <img src="https://raw.githubusercontent.com/Haut-Stone/ACM/master/photos/me.png" width=220 height=220>
  </a>
  <h3 align="center">Stone</h3>
  <p align="center">
    <a href="http://shallweitalk.com">
      <img src="https://raw.githubusercontent.com/Haut-Stone/ACM/master/photos/CodeChangeWorld.png" width=300 height=40>
    </a>
  </p>
</p>
<br>

## 这个算法的用处

在常数时间内找到`串1`的`最长回文子串`的长度

## 举个栗子

aaaa的最长回文子串就是`aaaa`长度为4

abab的最长回文子串饰`aba`或`bab`长度为3

## 思路

很明显，纯暴力的话，复杂度会很高，这个时候就需要用manacher了。这是一个相对简单的算法，我们就直接看实现的过程就好了

首先以abab为例，需要构造这么一个新的字符串：`$#a#b#a#b#*`

代码实现如下,其实就是从头开始把字符一个个全都填进去。

```cpp
void init(char text[])
{
    newString[0] = '$';
    newString[1] = '#';
    for(int i=0;i< strlen(text);i++){
        newString[(i+1)*2] = text[i];
        newString[(i+1)*2+1] = '#';
    }
    newString[(strlen(text)+1)* 2 ] = '*';
    newString[(strlen(text)+1)*2+1] = '\0';
}
```
当我们有了这么一个串之后，一切就变得简单了。只需要像下面这样不断的搜索就好了。下面的代码中可以看出是按顺序
遍历点，对每一个点寻找其自身的回文半径。同时记录半径所触及的最远的位置。

```cpp
const int N = 110;
char newString[N<<1];
int book[N];//i点的回文半径

int manachr(char text[])
{
    init(text);
    int lastPos = 0;
    int ans = 0;
    int id = 0;
    
    for(int i=1;i<strlen(newString);i++){
        if(lastPos > i){
            book[i] = min(book[2*id - i], lastPos - i);
        }else{
            book[i] = 1;
        }
        while(newString[i+book[i]] == newString[i-book[i]]){
            book[i]++;
        }
        if(book[i]+i > lastPos){
            lastPos = book[i] + i;
            id = i;
        }
    }
    
    for(int i=1;i<strlen(newString);i++){
        ans = max(ans, book[i]);
    }
    return ans - 1;
}
```
这里唯一不好理解的就是当`lastPos > i`时。这里我们举一个栗子，当找过b时，通过代码可以知道现在
lastPos = 8也就是回文半径所能触及到的下一个地方。这时如果我们再判断第5个点的时候。

```
             lastPos
  _____________ |
$ # a # b # a # b # *
        i
0 1 2 3 4 5 6 7 8 9 10
        |
        id
       
             lastPos
  _____________ |
$ # a # b # a # b # *
          i
0 1 2 3 4 5 6 7 8 9 10
        |
        id
```
>if( lastPos > i) book[i] = min(book[3], 3);

其实就是说因为3和5已知是以b为中点的回文串的对称的一部分，所以3处‘#’所拥有的回文半径是5也拥有的。
但是我们知道，回文半径所触及到的最远的地方才是lastPos，所以如果3处‘#’拥有的半径超出了lastPos。
就要从lastPos处截断。如果3处‘#’拥有的半径小于lastPos，那么5处‘#’便和3处‘#’拥有同样的性质，即
同样的回文半径。


## 总结

	wait...... 