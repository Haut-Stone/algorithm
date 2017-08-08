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

## GCD（欧几里得算法）

#### 用处

    求a, b的最大公约数。

#### 原理
    
    gcd(a, b) = gcd(b, a%b);

#### 代码实现

```cpp
int gcd(int a, int b)
{
    if(b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}
```

## EX_GCD

#### 原理

    见《算法笔记》p176-->p180

#### 代码实现

```cpp
//这里仍然返回的是最大公约数，但是通过中间的处理将x, y都算了出来。
//x, y的初始值随意，没有要求
int exGcd(int a, int b, int &x, int &y)
{
    if(b == 0){//开始反推的起点
        x = 1;
        y = 0;
        return a;
    }
    int gcd = exGcd(b, a%b, x, y);
    int temp = x;
    x = y;
    y = temp - (a/b)*y;
    return gcd;
}
```


## 总结

	wait...... 

## 参考链接

- [写的还行，但是不好理解， 建议直接看算法笔记](http://blog.csdn.net/zhjchengfeng5/article/details/7786595)
