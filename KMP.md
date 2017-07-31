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

在`常数时间`内，判断串2， 是否是串1的字串。

## 举个栗子

串1:`BBC ABCDAB ABCDABCDABDE`
串2:`ABCDABD`

我们的直觉告诉我们，可以这样解决这个问题。

![](http://image.beekka.com/blog/201305/bg2013050103.png)
>首先，字符串"BBC ABCDAB ABCDABCDABDE"的第一个字符与搜索词"ABCDABD"的第一个字符，进行比较。因为B与A不匹配，所以搜索词后移一位。


![](http://image.beekka.com/blog/201305/bg2013050104.png)
>因为B与A不匹配，搜索词再往后移。

![](http://image.beekka.com/blog/201305/bg2013050105.png)
>就这样，直到字符串有一个字符，与搜索词的第一个字符相同为止。

![](http://image.beekka.com/blog/201305/bg2013050106.png)
>接着比较字符串和搜索词的下一个字符，还是相同。

![](http://image.beekka.com/blog/201305/bg2013050107.png)
>直到字符串有一个字符，与搜索词对应的字符不相同为止。

![](http://image.beekka.com/blog/201305/bg2013050108.png)
>然后回到开头，重新比较。
我们的直觉这时候又告诉我们，这样做的话，时间复杂度啊一定很高。然后我们要因为每个字符我们都重复判断
了多变。浪费了不少的时间。一个基本事实是，当空格与D不匹配时，你其实知道前面六个字符是"ABCDAB"。
KMP算法的想法是，设法利用这个已知信息，不要把"搜索位置"移回已经比较过的位置，继续把它向后移，
这样就提高了效率。

![](http://image.beekka.com/blog/201305/bg2013050109.png)
>如果这个时候我们能搞到这么一张表。（管他怎么搞到的，其实就是后面代码里的next数组）

![](http://image.beekka.com/blog/201305/bg2013050107.png)
>已知空格与D不匹配时，前面六个字符"ABCDAB"是匹配的。查表可知，最后一个匹配字符B对应的"部分匹配值"为2，因此按照下面的公式算出向后移动的位数:`移动位数 = 已匹配的字符数 - 对应的部分匹配值`因为 6 - 2 等于4，所以将搜索词向后移动4位。

![](http://image.beekka.com/blog/201305/bg2013050110.png)
>因为空格与Ｃ不匹配，搜索词还要继续往后移。这时，已匹配的字符数为2（"AB"），对应的"部分匹配值"为0。所以，移动位数 = 2 - 0，结果为 2，于是将搜索词向后移2位。

![](http://image.beekka.com/blog/201305/bg2013050111.png)
>因为空格与A不匹配，继续后移一位。

![](http://image.beekka.com/blog/201305/bg2013050112.png)
>逐位比较，直到发现C与D不匹配。于是，移动位数 = 6 - 2，继续将搜索词向后移动4位。

![](http://image.beekka.com/blog/201305/bg2013050113.png)
>逐位比较，直到搜索词的最后一位，发现完全匹配，于是搜索完成。如果还要继续搜索（即找出全部匹配），移动位数 = 7 - 0，再将搜索词向后移动7位，这里就不再重复了。

现在我们明白了，只要有这个移动位数表，就一切好办了。那么这个表是什么呢，其实这个表就是一个next
数组。这个数组里存的就是串2中前缀和后缀最多相同时的前缀最后一个元素的下标。这样的话，就可以实现
跳过中间不同的部分，直接跳回到可能匹配的部分。

以 ABCDAB 时为例，这个时候：

ABCD**AB**

**AB**CDAB

其实就是发现了**AB**CD**AB**相同， 这个时候，就记下第一个B的位置值2给next数组。

```
其实说白了就是找：下面这几个串从前向后和从后向前有几个按顺序重叠的字母（当然并不能找完整个字符串）。
这样就可以省下再匹配相同串的时间了。next数组里存的就是下一次应该跳到的位置

A 
AB
ABC 
ABCD 
ABCDA
^---^ 
ABCDAB
^^--^^ 
ABCDABD 
```

```
___   ___
ABCCCCABC  
  ^-----^
012345678

next数组中next[8]记录的便是ABC`上一次`出现的位置的尾坐标。

也就是说这个next数组记录的是，已经匹配好的序列的上一次出现的位置。即012位置的ABC。

```

另外这一值得一提的是，对于`优化后`的nextval[]数组，记录的是已匹配好的字串`最早`出现的位置。

## coding

#### kmp基本款

```cpp
const int N = 30;
int my_next[N];

void getNext(char str[], int len)
{
    int j = -1;
    my_next[0] = -1;
    for(int i=1;i < len;i++){
        while(j != -1 && str[i] != str[j+1]){
            j = my_next[j];
        }
        if(str[i] == str[j+1]){
            j++;
        }
        my_next[i] = j;
    }
}

bool kmp(char text[], char pattern[])
{
    int n = (int)strlen(text);
    int m = (int)strlen(pattern);
    getNext(pattern, m);
    int j = -1;
    for(int i=0;i < n;i++){
        while(j != -1 && text[i] != pattern[j+1]){
            j = my_next[j];
        }
        if(text[i] == pattern[j+1]){
            j++;
        }
        if(j == m-1){//出现匹配，则存在
            return true;//是否存在
        }
    }
    return false;
}

int main(void)
{
    char text[N] = "abababaabc";
    char pattern[N] = "ababaab";
    kmp(text, pattern);
    return 0;
}
```

## 总结

	wait...... 

## 参考
[阮一峰KMP算法](http://www.ruanyifeng.com/blog/2013/05/Knuth–Morris–Pratt_algorithm.html)