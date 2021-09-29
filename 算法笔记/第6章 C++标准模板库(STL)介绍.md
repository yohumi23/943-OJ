# 6.1 vector的常见用法详解

​	vector 翻译为向量，“变长数组”，”长度根据需要而自动改变的数组“。解决只用普通数组会超内存的问题。vector 还可以用来以邻接表的方式储存图，针对无法使用邻接矩阵的题目（结点数太多）、又害怕使用指针实现邻接表的读者是非常友好的，写法简洁。

```cpp
#include <vector>
using name std;
```

##  1.vector的定义

  单独定义一个vector：

```cpp
vector<typename> name;
```

​	相当于name[SIZE],只不过长度可以根据需要进行变化，节省空间。

​	`typename`可以是任何基本类型，int、double、char、结构体等，也可以是STL标准容器，例如vector、set、queue等。:star:**如果`typename`也是一个STL容器，定义的时候要记得在>>符号之间加上空格**，因为一些使用C++11之前标准的编译器会把它视为移位操作，导致编译错误。

```cpp
vector<int> name;
vector<double> name;
vector<char> name;
vector<node> name; //node是结构体类型
```

​	如果`typename`是vector，如下定义：

`vector<vector<int> > name;//>>之间要加空格`可以视作两个维都可变长的二维数组

​	定义只有一个维可以变长的**vector数组**

```cpp
vector<typename> Arrayname[arraySize];
```

##  2.vector容器内元素的访问

 1. 通过下标访问。

    直接 `vi[index]`.下标 的范围是**0到`vi.size()-1`

 2. 通过迭代器访问。

    迭代器(iterator)理解为类似**指针**的东西。其定义为：

    ```cpp
    vector<typename>::iterator it;//typename与vector的一致
    ```

    it是一个`vector<typename>::iterator`型的变量。

    通过`*it`来访问vector里的元素。

    ```cpp
    #include<stdio.h>
    #include<vector>
    using name std;
    int main(){
        vector<int> vi;
        for(int i = 1; i <= 5; ++i){
            vi.push_back(i);
        }
        //vi.begin()为取vi的首元素地址，而it指向这个地址
        vector<int>::iterator it = vi.begin();
        for(int i = 0; i < 5; ++i){
            printf("%d ", *(it + i));
        }
        return 0;
    }
    ```

     end()并不是取vi的尾元素地址，而是取尾元素地址的下一个地址。end())作为迭代器末尾的标志，不储存任何元素。

    迭代器实现两种自加操作(++it) 和(it ++)

    ```cpp
    #include<stdio.h>
    #include<vector>
    using name std;
    int main(){
        vector<int> vi;
        for(int i = 1; i <= 5; ++i){
            vi.push_back(i);
        }
       
        for(vector<int>::iterator it = vi.begin(); it != vi.end(); it++){
            printf("%d", *it);
        }
        return 0;
    }
    ```

    :no_good:最后需要指出的是，在常用的STL容器中，只有在**vector** 和**string** 中，才允许使用**vi.begin() + 3**这种迭代器加上整数的写法

	3. vector常用函数实例解析

    	1. push_back() 

    	2. pop_back() --删除尾元素

        ```c++
        #include <stdio.h>
        #include <vector>
        using namespace std;
        int main(){
            vector<int> vi;
            for(int i = 1; i <= 3; ++i){
                vi.push_back(i);
            }
            vi.pop_back();
            for(int i = 0; i < vi.size(); i++){
                printf("%d ", vi[i]);
            }
            return 0;
        }
        
        //输出结果 1 2
        ```

    	3. size()--用来获得vector中元素的个数，返回值为unsigned 类型，一般来说用%d不会出很大问题，这一点对于所有STL容器都是一样的。

    	4. clear() --用来清空vector中的所有元素，时间复杂度为O(N),N为元素个数

        ```cpp
        vi.clear();
        ```

    	5. insert() --inser(it, x)用来向vector的任意迭代器it处插入一个元素，时间复杂度O(N)

        ```cpp
        #include <stdio.h>
        #include <vector>
        using namespace std;
        int main(){
            vector<int> vi;
            for(int i = 1; i <= 5; ++i){
                vi.push_back(i);
            }
            vi.insert(vi.begin() + 3, -1);//将-1插入vi[2]的位置
         	for(int i = 0; i < vi.size(); i++){
                printf("%d ", vi[i]);
            }
            return 0;
        }
        ```

    	6. erase()

        两种用法：1.删除单个元素；2.删除一个区间内的所有元素。时间复杂度O(N)

        1. 删除单个元素。

           erase(it) 

           ```cpp
           #include <stdio.h>
           #include <vector>
           using namespace std;
           int main(){
               vector<int> vi;
               for(int i = 1; i <= 5; ++i){
                   vi.push_back(i);
               }
               erase(vi.begin() + 3);
            	for(int i = 0; i < vi.size(); i++){
                   printf("%d ", vi[i]);
               }
               return 0;
           }
           ```

        2. 删除一个区间内的所有元素。

           erase(first, last) 即删除[first, last)内所有的元素。

           ```cpp
           #include <stdio.h>
           #include <vector>
           using namespace std;
           int main(){
               vector<int> vi;
               for(int i = 1; i <= 5; ++i){
                   vi.push_back(i);
               }
               vi.erase(vi.begin(), vi.begin() + 2);
            	for(int i = 0; i < vi.size(); i++){
                   printf("%d ", vi[i]);
               }
               return 0;
           }
           ```

	4. vector的常见用途

    	1. 储存数据

        	1. 本身可以作为数组使用，在不确定元素的个树下节省空间。
        	2. 有些场合需要根据一些条件把部分数据数据输出在同一行，数据中间用空格隔开。由于输出数据的个数不确定，为了更方便地处理最后一个满足条件的数据后面不输出额外的空格，可以先用vector记录所有需要输出的数据，然后一次性输出。

    	2. 用邻接表存储图。

        ​	避免使用指针



# 6.2 set的常见用法详解

set 集合。内部自动有序且不含重复元素的容器。

头文件： 

```cpp
#include <set>
using namespace std;
```

## 1. set的定义

与vector基本一致，:star:**如果`typename`也是一个STL容器，定义的时候要记得在>>符号之间加上空格**，因为一些使用C++11之前标准的编译器会把它视为移位操作，导致编译错误。

## 2.set容器内元素的访问

set只能通过迭代器 iterator 访问

```cpp
set<typename>::iterator it;
```

由于**除开vector 和 string之外的STL容器都不支持*（it +i)的访问方式**，因此只能按如下方式枚举

```cpp
#include <stdio.h>
#include <set>
using namespace std;
int main(){
    set<int> st;
    st.insert(3);
    st.insert(5);
    st.insert(2);
    st.insert(3);
    //注意,不支持it < st.end()的写法
    for(st<int>::iterator it = st.begin; it != st.end(); it++){
        printf("%d", *it);
    }
    return 0;
}

```

**set内的元素自动排序，且自动去除重复元素**

## 3.set常用函数实例解析

1. insert(x)可以将x插入set容器中，并自动递增排序和去重。O(longN),其中N为set内的元素个数
2. find(value) 返回set中对应值为value的迭代器，时间复杂度为O(logN)，N为set内的元素个数

```cpp
#include <stdio.h>
#include <set>
using namespace std;
int main(){
    set <int> st;
    for(int i = 1; i <= 3; ++i){
        st.insert(i);
    }
    set<int>::iterator it = st.find(2);
    printf("%d\n", *it);
    
}

//输出结果：
//2
```

3. erase()

   1. 删除单个元素：erase(it),it为所需要元素的迭代器。时间复杂度为O(1).

   ```cpp
   #include <stdio.h>
   #include <set>
   using namespace std;
   int main(){
       set <int>  st;
       st.insert(100);
       st.insert(200);
       st.insert(100);
       st.insert(300);
       st.erase(st.find(100)); //利用函数find()找到100，再用erase删除它
       st.erase(st.find(200));
       for(set<int>::iterator it = st.begin(); i != st.end(); it++){
           printf("%d\n", *it);
       }
   }
   //输出结果：
   300
    
   ```
   ​		st.erase(value):value为删除元素的值。O(logN),N为元素个数。   
   ```cpp
   #include <stdio.h>
   #include <set>
   using namespace std;
   int main(){
       set <int> st;
       st.insert(100);
       st.insert(200);
       st.erase(100);
       for(set<int>::iterator it = st.begin(); i != st.end(); i++){
           printf("%d\n", *it);//只会输出100
       }
   }
   ```

   2. 删除一个区间内的所有元素:

      set.erase(first, last):范围[first, last) 时间复杂度O(last - first)

      ```cpp
      #include <stdio.h>
      #include <set>
      using namespace std;
      int main(){
          set<int> st;
          st.insert(20);
          st.insert(10);
          st.insert(40);
          st.insert(30);
          set<int>iterator it = st.find(30);
          st.erase(it, st.end());
          
      }
      输出：10 20
      ```

4. size() 获得set内元素的个数 O(1)

   ```cpp
   #include <stdio.h>
   #include <set>
   using namespace std;
   int main(){
       set<int> st;
       st.insert(2);
       st.insert(5);
       st.insert(4);
       print("%d\n", st.size());//输出set内元素的个数
   	return 0;
   }
   ```

5. clear() 用来清空set内所有元素 ，时间复杂度O(N)

   ```cpp
   #include <stdio.h>
   #include <set>
   using namespace std;
   int main(){
       set<int> st;
       st.insert(2);
       st.insert(5);
       st.insert(4);
       st.clear();//清空set
       printf("%d\n", st.size()); //输出结果：0
       return 0;
   }
   ```

6. count()用来检查set()中是否有相应元素，有则返回1，无则返回0





## 4. set常见用途

自动去重升序排序

# 6.3 string 的常见用法详解

在C语言中，一般使用字符数组 char str[]来存放字符串，但是操作麻烦，易出错。为了方便，C++在STL中加入了string 类型，对字符串常用的需求功能进行了封装。

头文件：

```cpp
#include <string>
using namespace std;
```

## 1.string的定义

```cpp
string str = "abc";
```

## 2.string中内容的访问

1. 通过下标 访问（像字符数组那样）

```cpp
#include <stdio.h>
#include <stirng>
using namespace std;
int main(){
	string str = "abcd";
    for(int i = 0; i < str.length(); ++i){
        printf("%c", str[i]);
    }
    return 0;
}
//输出结果 abcd
```

 	如果要读入和输出整个字符串，则只能用**cin和cout**:

```cpp
#include <iostream> //cin 和 cout 在iostream头文件中
#include <string>
using namespace std;
int main(){
    string str;
    cin >> str;
    cout << str;
    return  0;
}
```

**如何用printf输出string呢？ 用c_str() 将string类型转换成字符数组进行输出**

```cpp
#include <stdio.h>
#include <string>
using namespace std;
int main(){
    string str = "abcd";
    printf("%c", str.c_str());//将string类型str使用c_str()变为字符数组；
    return 0；
}
//输出abcd
```

2. 通过迭代器访问

   定义方式：

   ```cpp
   string::iterator it;
   ```

   ```cpp
   #include <stdio.h>
   #include <string>
   using namespace std;
   int main(){
       string str = "abcd";
       for(string::iterator it = str.begin(); it != str.end(); it++){//string类型支持加减整数
           printf("%c", *it);
       }
       return 0;
   }
   ```



## 3.string常用函数实例解析

1. `+`:small_red_triangle_down:将两个string连接起来，赋值给前一个字符串

   ```cpp
   #include <iostream>
   #include <string>
   using namespace std;
   int main(){
       string str1 = "abc", str2 = "def", str3;
       str3 = str1 + str2;
   //    printf("%s", str3); 错误写法
       cout<<str1<<endl;
       cout<<str3<<endl;
       return 0;
   }
   //输出结果：
   //abcdef
   //abcdef
   ```

2. 比较大小：

   == 、!=、< 、<= 、> 、>= **字典序**
   
3. length()/size()

   返回字符串长度

4. insert(),时间复杂度O(N)

   1. insert(pos, string)，在pos号位置插入字符串string

      ```cpp
      string str = "abcxyz", str2 = "opq";
      str.insert(3, str2);
      cout<<str<<endl;
      //输出结果：
      abcopqxyz
      ```

   2. insert(it, it2, it3)表示串[it2, it3) 将在it位置插入

      ```cpp
      #include <iostream>
      #include <string>
      using namespace std;
      int main(){
          string str = "abcxyz", str2 = "opq";
          str.insert(str.begin() + 3, str2.begin, str2.end());
          cout<<str<<endl;
          return 0;
      }
      //输出结果：
      //abcopqxyz
      ```

5. erase()

   1. 删除单个元素

      str.erase(it)

      ```cpp
      #include <iostream>
      #include <string>
      using namespace std;
      int main(){
          string str = "abcdefg";
          str.erase(str.begin() + 4); //删除4号位(e)
          cout<<str<<endl;
          return 0;
      }
      //输出结果：
      //abcdfg
      ```

   2. 删除一个区间内的所有元素

      1. str.erase(first, last),[first, last)

         ```cpp
         #include <iostream>
         #include <string>
         using namespace std;
         int main(){
             string str = "abcdefg";
             str.erase(str.begin() + 2, str.end() - 1);//即删除cdef
             cout<<str<<endl; 
             return 0;
         }
         //输出结果
         //abg
         
         ```

      2. str.erase(pos, length):pos表示要开始的起始位置，length表示要删除的字符个数

         ```cpp
         #include <iostream>
         #include <string>
         using namespace std;
         int main(){
             string str = "abcdefg";
             str.erase(3, 2); //删除下标3,4的元素即d,e
             cout<<str<<endl;
             return 0;
         }
         ```

6. clear() 清空string中的数据时间复杂度O(1)

   ```cpp
   #include <stdio.h>
   #include <string>
   using namespace std;
   int main{
       string str = "abcd";
       str.clear();//清空字符串
       printf("%d\n", str.length());
       return 0;
   }
   //output:
   //0
   ```

7. substr(pos, len) 返回从pos位置开始、长度为len的子串，时间复杂度O(len)

   ```cpp
   #include <iostream>
   #include <string>
   using namespace std;
   int main(){
       string str = "Thank you for your smile.";
       cout << str.substr(0, 5) << endl;
       cout << str.substr(14, 4) << endl;
       cout << str.substr(19, 5) << endl;
       return 0;
   }
   ```

8. string::npos

   string::npos是一个常数，其本身的值为-1，但由于是unsinged_int类型，因此实际上也可以认为是unsigned_int类型的最大值。string::npos用以作为find函数失配时的返回值。例如在下面的事例中可以认为string::npos等于-1或者4294967295。

   ```cpp
   #include <iostream>
   #include <string>
   using namespace std;
   int main(){
       if(string::npos == -1) cout<<"-1"<<endl;
       if(string::npos === 4294967295) cout<<"4294967295"<<endl;
   }
   //output:
   //-1
   //4294967295
   ```

9. str.find()

   str.find(str2) ,当 str是str的子串时，返回子串第一次在子串中出现的位置；如果str2不是str的子串，那么返回string::npos

   str.find(str2, pos)，指定位置开始匹配

10. replace()

    str.replace(pos, len, str2)把str从pos号位开始、长度为len的子串替换为str2

    str.replace(it1, it2, str2)把从str的迭代器[it1, it2)范围的子串替换为str2

    时间复杂度为O(str.length()).

    ```cpp
    #include <iostream>
    #include <string>
    using namespace std;
    int main(){
      	string str1 = "May you will turn around.";
        string str2 = "will not";
        string str3 = "surely";
        cout << str.replace(10, 4, str2) <<endl;
        cout << str.replace(str.begin(), str.begin() + 5, str3) << endl;
        return 0;
      
    }
    //output:
    //Maybe you will not turn around
    //surely you will turn around
    ```



# 6.4 map的 常见用法详解

map翻译：映射，也是常用的STL容器。**常见数组都是用整型（下标）映射char、int、double等等，能不能用如：字符串-->映射-->整型呢？**

**map可以将任何基本类型（包括STL类型）映射到任何基本类型（包括STL容器）**

头文件：

```cpp
#include <map>
using namespace std;
```

## 1.map的定义

```cpp
map<typename1, typename2> mp;
```

前者是键(key)的类型，第二个是值(value)的类型。

如果是字符串到整型的映射，就必须使用string而不是char数组

```cpp
map<string, int> mp;
```

## 2.map容器内元素的访问

1. 通过下标访问

   ```cpp
   #include <stdio.h>
   #include <map>
   using namespace std;
   int main(){
       map<char, int> mp;
       mp['c'] = 20;
       mp['c'] = 30; //20被覆盖
       printf("%d\n", mp['c']);
       return 0;
   }
   //output:
   //30；
   ```

2. 通过迭代器访问

   ```cpp
   map<typename1, typename2>::iterator it;
   it -> first, it -> second
   ```

   ```cpp
   #include <stdio.h>
   #include <map>
   using namespace std;
   int main(){
       map<char, int> mp;
       mp['m'] = 20;
       mp['r'] = 30;
       mp['a'] = 40;
       for(map<char, int>::iterator it = mp.begin(); it != mp.end(); it++){
           printf("%c %d\n", it-> first, it-> second);
       }
       return 0;
   }
   //output:
   /*
   a 40
   m 20
   r30
   */
   ```

   :star:**map会根据key值自动排序**

## 3.map常用函数实例解析

1. find()

   * find(key) 返回值为key的映射的迭代器 ，时间复杂度O(logN),N为map中映射的个数
   * 若果没找到，返回的是mp.end();

   ```cpp
   #include <stdio.h>
   #include <map>
   using namespace std;
   int main(){
       map<char, int> mp;
       mp['a'] = 1;
       mp['b'] = 2;
       mp['c'] = 3;
       map<char, int>::iterator it = mp.find('b');
       printf("%c %d\n", it->first, it->second);
       
       return 0;
   }
   /*
   output:
   b 20
   */
   ```

2. erase()

   1. 删除单个元素

      * mp.erase(it)	it为需要删除的元素的迭代器。时间复杂度O(1)

        ```cpp
        #include <stdio.h>
        #include <map>
        using namespace std;
        int main(){
            mp<char, int> mp;
            mp['a'] = 1;
            mp['b'] = 2;
            mp['c'] = 3;
            map<char, int>::iterator it = mp.find('b');
            mp.erase(it);//删除b 2
            for(map<char, int>::iterator it = mp.begin(), it != mp.end(); ++it){
                printf("%c %d\n", it -> first, it -> second);
            }
            return 0;
        }
        ```

      * mp.erase(key) 。时间复杂度O(N)

        ```cpp
        #include <stdio.h>
        #include <map>
        using namespace std;
        int main(){
            mp<char, int> mp;
            mp['a'] = 1;
            mp['b'] = 2;
            mp['c'] = 3;
            mp.erase('b');//删除键为b的映射， 即 b 2
            for(map<char, int>::iterator it = mp.begin(); it != mp.end(); it++)
            {
                printf("%c %d\n", it->first, it->second);
            }
            return 0;
        }
        ```

   2. 删除一个区间内的所有元素

      * mp.erase(first, last) 删除[first, last)时间复杂度O(last - first).

        ```cpp
        #include <stdio.h>
        #include <map>
        using namespace std;
        int main(){
            mp<char, int> mp;
            mp['a'] = 1;
            mp['b'] = 2;
            mp['c'] = 3;
            map<char, int>::iterator it = mp.find('b');
            mp.erase(it, mp.end());
            for(map<char, int>::iterator it = mp.begin(); it != mp.end(); it++)
            {
                printf("%c %d\n", it->first, it->second);
            }
            return 0;
        }
        /*
        output: 删除了b 2,c 3
        */
        ```

   3. size()

      * 用来获得map中映射的对数，时间复杂度O(1)

   4. clear()

      * 清空。时间复杂度O(N)

   

   ## 4.map的常见用途

   1. 需要建立字符与整数之间映射的题目，节省代码量
   2. 判断打证书或者其他类型是否存在的题目，可以把map当bool数组用
   3. 字符串和字符串的映射

   
#  6.5 queue的常见用法详解

   ## 1.queue的定义

   ```cpp
   queue <typeaname> name;
   using namespace std;
   ```

   ## 2.queue容器内元素的访问

   **先进先出，只能通过front()来访问队首元素 ，或是通过back()来 访问队尾元素**

   ```cpp
   #include<stdio.h>
   #include<queue>
   using namespace std;
   int main(){
       queue<int> q;
       for(int i = 1; i <= 5; i++){
           q.push(i); //push(i)将i压入队列，一次入队 1 2 3 4 5
       }
       printf("%d %d", q.front(), q.back()); //输出结果 1 5
       
       return 0;
   }
   ```

   ## 3.queue常用函数实例解析

   1. push()

      * push(x)   时间 复杂度O(1)

   2. front()、back()    时间复杂度O(1)

   3. pop()    令队首元素出队，时间复杂度O(1)

      ```cpp
      #include <stdio.h>
      #include <queue>
      using namespace std;
      int main(){
      	queue<int> q;
          for(int i = 1; i <= 5; ++i){
              q.push(i);
          }
          for(int i = 1; i <= 3; ++i){
              q.pop();  //出队3次元素
          }
      	return 0;
      }
      //输出结果 ：
      // 4
      ```

   4. empty()     检查queue 是否为空，返回true为空

   5. size()        返回queue内的元素个数，时间复杂度 O(1)

      

## 4.queue的常见用途

* 当需要实现广度优先搜索时，可以不用手动实现一个队列，而是用queue代替，以提高程序的准确性
* :star:使用front() 和 pop() 函数前，必须用empty()判断队列是否为空
* 双端队列   deque
* 优先队列   priority_queue

# 6.6 priority_queue 的常见用法详解

* 又称优先队列，底层是用堆实现的。
* **队首元素一定是当前队列中优先级最高的那一个**
* 可以再任意时刻push元素，而优先队列底层 的数据结构堆heap会随时调整结构，使得**每次的队首元素都是优先级最大的**

## 1.priority_queue的定义

头文件：

```cpp
#include <queue>
using namespace std;
priority_queue <typename> name;
```

## 2.priority_queue容器内元素的访问

* 没有front() 和 back() 函数，**只能通过top() 函数访问队首元素（也可以称为堆顶元素）**也就是优先级最高的元素

  ```cpp
  #include <stdio.h>
  #include <queue>
  using namespace std;
  int main(){
      priority_queue <int> q;
      q.push(3);
      q.push(4);
      q.push(1);
      printf("%d", q.top());
      return 0;
  }
  //输出：4(优先级最高)
  ```

## 3.priority_queue常用函数实例解析

* push()

  pushi(x)将令x入队，时间复杂度为O(logN)，其中N为当前优先队列中的元素个数。

* top()

  获得队首元素，时间复杂度O(1)

* pop()

  令队首元素出队，时间复杂度O(logN)

  ```cpp
  #include <stdio.h>
  #include <queue>
  using namespace std;
  int main(){
      priority_queue <int> q;
      q.push(3);
      q.push(4);
      q.push(1);
      printf("%d", q.top());
      q.pop();
      printf("%d", q.top());
      return 0;
  }
  //输出结果:4 3   
  ```

* empty()

  空，返回true

* size()

  返回个数 O(1)



## 4.priority_queue内元素优先级的设置

1.  基本数据类型的优先级设置(int、double、char)

   int、double 数最大优先级最高； char 字典序

   下面两种定义方式等价：

   ```cpp
   priority_queue<int> q;
   priority_queue<int,  vector<int>, less<int> > q; 
   ```

   less<int>表示数字大的优先级越大，greater<int>表示数字约小优先级越大

2. **结构体的优先级设置**
   现在希望按水果的价格高的为优先级高，就需要重载人overload 小于号“<”。重载是指对已有的运算符进行重新定义读者此处只需要知道它的写法即可：

   ```cpp
   struct fruit{
   	string name;
   	int price;
   	friend bool operator < (fruit fl, fruit f2)
   		return f1.price < f2.price;
   };
   ```

   **重载大于号会编译错误，因为从数学上来说只需要重载小于号，改变元素位置**

   要想价低优先，改变`return f1.price > f2.price;`即可

   * 写在结构体外面，但是同时也要更改定义方法

     ```cpp
     #include <iostream>
     #include <string>
     #include <queue>
     using namespace std;
     struct fruit{
         string name;
         int price;
     }f1, f2, f3;
     
     //封装成结构体
     struct cmp{
         bool operator () (fruit f1, fruit f2){
             return f1.price > f2.price; //价格越低，优先级越高 
         }
     };
     int main(){
      	priority_queue <fruit, vector<fruit>, cmp> q;  //第二种定义方法
         f1.name = "桃子";
         f1.price = 3;
         f2.name = "梨子";
         f2.price = 4;
         f3.name = "苹果";
         f3.price = 1;
         q.push(f1);
         q.push(f2);
         q.push(f3);
         cout<<q.top().name<<" "<<q.top().price<<endl;
         return 0;
     }
     ```

   * 如果结构体内的数据较为庞大(例如出现了字符串或者数组)，建议使用引用来提高效率，此时比较累的参数中需要加上“const”和“&”:

     ```cpp
     friend bool operator < (const fruit & f1, const fruit &f2){
         return f1.price > f2.price;
     }//这是定义在数据类型结构体内的
     
     bool operator () (const fruit &f1, const fruit &f2){
         return f1.price > f2.price;
     }//这是单独封装成结构体cmp的
     ```



## 5.priority_queue的常见用途

* 贪心问题
* Dijkstra算法进行优化（因为优先队列的本质是堆）
* 注意：**使用top()函数前，必须有empty()判断队里 是否为空**，否则可能因为队空而出错



# 6.7 stack的常见用法详解

后进先出

## 1.stack的定义

```cpp
#include<stack>
using  namespace std;
stack<typename> name;
```

## 2.stack容器内元素的访问

在STL中的 stack只能通过**top()来访问栈顶元素**

## 3.stack常用函数实例解析

1. push()	O(1)
2. top()       O(1)
3. pop()      O(1)
4. empty    为空返回true    O(1)
5. size()      O(1)

## 4.stack的常见用途

* 模拟递归程序，防止程序撑爆占内存，自己做一个就不怕被撑爆了



# 6.8 pair的常见用法详解

看做一个内部有两个元素的结构体，且这两个元素的类型可以指定

```cpp
struct pair{
    typename1 first;
    typaname2 second;
};
```

## 1.pair的定义

```cpp
#include <utility>
using namespace std;
```

map的内部实现设计pair，因此添加map头文件后自动添加utility头文件，无序额外添加。

```cpp
pair<typename1, typename2> name;

pair<string, int> p("haha", 5);
```

如果想要在代码中临时构建一个pair，有如下两种方法：

* 将类型定义卸载前面，后面用小括号内两个元素

  * ```cpp
    pair<string, int>("haha", 5);
    ```

* 使用自带的make_pair函数

  * ```cpp
    make_pair("haha", 5);
    ```



## 2.pair中元素的访问

p.first()         p.second()

## 3.pair常用函数实例解析

比较操作数== 、!=、< 、<= 、> 、>= ，比较规则是**先以first的大小作为标准，只有当first相等时才去判别second的大小**

## 4.pair的常见用途

1. 用来代替二元结构体及其构造函数，节省时间。

2. 作为map的键值对来进行插入

   * ```cpp
     #include <iostream>
     #include <string>
     #include <map>
     using namespace std;
     int main(){
         map<string, int> mp;
         mp.insert(make_pair("heihei", 5));
         mp.insert(pair<string, int>("haha", 10));
         for(map<string, int>::iterator it = mp.begin(); it != mp.end(); ++it){
             cout << it->first << " " << it->second <<endl;
         }
         return 0;
     }
     ```



# 6.9 algorithm头文件下的常用函数

```cpp
#include<algorithm>
using namespace std;
```

## 6.9.1 max()、min()和abs()

max(a, b) 返回最大值，a、b可以是整数也可以是浮点数

abs(x) 返回绝对值，x必须是整数

fabs(x) double型的绝对值。头文件math.h

## 6.9.2 swap()

swap(x, y) 交换x,y的值

## 6.9.3 reverse()

reverse(it, it2)   将数组指针在[it, it2)之间的元素或容器的迭代器在[it, it2)范围内的元素进行反转

```cpp
#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
    int a[10] = {10, 11, 12, 13, 14, 15};
    reverse(a, a+4); //将a[0]~a[3]反转
    for(int i = 0; i < 6; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
//output:13 12 11 10 14 15
```

## 6.9.4 next_permutation

next_permutation()给出一个排列在**当前全排列**中的**下一个排列**

```cpp
#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	int a[10] = {1, 2, 3};
    //a[0] ~ a[2] 之间的序列需要求解next_permutation
    do{
        printf("%d%d%d\n", a[0], a[1], a[2]);
        
    }while(next_permutation(a, a + 3));
	return 0;
}
123
132
213
231
312
321
```

使用do--while是应为next_permutation在达到全排列最后一个时会返回false，如果使用while会失去一个123

## 6.9.5 fill()

fill()可以把数组或容器中的某一段区间赋值为某个相同的值。和memset不同，这里的赋值可以是数组类型对应范围内的任意值

```cpp
#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	int a[10] = {1, 2, 3, 4, 5};
    fill(a, a + 5, 233);//将a[0]~a[4]全部赋值为233
    for(int i = 0; i < 5; ++i){
        printf("%d ", a[i]);
    }
    return 0;
}
//233 233 233 233 233
```

## 6.9.6 sort()

* 根据具体情形使用不同 的排序方法，效率较高。
* 不推荐使用C语言中的qsort函数，繁琐且涉及到指针
* sort在视线中规避了经典快排中可能出现的会导致实际时间复杂度退化到O(N²)的极端情况
* 愉快使用sort函数

### 1.如何使用sort排序

* 头文件

* 使用方式

  sort(首元素地址(必填)， 尾元素地址的**下一个 地址**(必填), 比较函数(非必填)`cmp`);默认**递增排序**

* 示例：

  ```cpp
  #include <stdio.h>
  #include <algorithm>
  using namespace std;
  int main(){
      int a[6] = {9, 4, 2, 5, 6, -1};
      //将a[0]~a[3]从小到大排序
      sort(a,  a + 4);
      for(int i = 0; i < 6; ++i){
          printf("%d ", a[i]);
      }
      printf("\n");
      //将a[0]~a[5]从小到大排序
      sort(a, a + 6);
      printf(int i = 0; i < 6; ++i){
          printf("%d ", a[i]);
      }
      return 0;
  }
  ```



### 2.如何实现比较函数cmp

1. 基本数据类型

   * 对int(char, double同理)

     ```cpp
     #include <stdio.h>
     #include <algorithm>
     using namespace std;
     int main(){
         int a[5] = {3, 1, 4, 2};
         sort(a, a + 4);
         for(int i = 0; i < 4; ++i){
             printf("%d ", a[i]);
         }
         return 0;
     }
     //output:1, 2, 3, 4
     ```

     使用比较函数cmp递减排序

     ```cpp
     #include <stdio.h>
     #include <algorithm>
     using namespace std;
     bool cmp(int a, int b){
         return a > b; //可以理解为a > b时把a放在b前面
     }
     int main(){
         sort(a, a + 4， cmp);
         for(int i = 0; i < 4; ++i){
             printf("%d ", a[i]);
         }
         return 0;
     }
     //output:4, 3, 2, 1
     ```

2. 结构体数组的排序

   ```cpp
   struct node{
       int x, y;
   }ssd[10];
   ```

   如果想将ssd数组按照x从大到小（以及排序)排序，那么可以这样写cmp函数

   ```cpp
   bool cmp(node a, node b){
       return a.x > b.x;
   }
   ```

   示例如下：

   ```cpp
   #include <stdio.h>
   #include <algorithm>
   using namespace std;
   struct node{
       int x, y;
   }ssd[10];
   bool cmp(node a, node b){
       return a.x > b.x;//将x值从大到小对结构体数组排序
   }
   int main(){
       ssd[0].x = 2;
       ssd[0].y = 2;
       ssd[1].x = 1;
       ssd[1].y = 3;
       ssd[2].x = 3;
       ssd[2].y = 1;
       sort(ssd, ssd + 3, cmp);
       for(int i = 0; i < 3; i++){
           printf("%d %d\n", ssd[i].x, ssd[i].y);
       }
       return 0;
   }
   ```

3. 容器的排序

   在STL标准容器中，只有vector、string、deque是可以使用sort的。这是因为像sort、map这种容器是用**红黑树**实现的，元素本身有序

   以vector为例：

   ```cpp
   #include <stdio.h>
   #include <vector>
   #include <algorithm>
   using namespace std;
   bool cmp(int a, int b){//因为vector中的元素为int型，因此仍然是int型的形参
       return a > b;
   }
   int main(){
       vector<int> vi;
       vi.push_back(3);
       vi.push_back(1);
       vi.push_back(2);
       sort(vi.begin(), vi.end(), cmp);//对整个vector排序
       for(int i = 0; i < 3; ++i){
           printf("%d ", vi[i]);
       }
       return 0;
   }
   
   //output: 3 2 1
   ```

   string:

   ```cpp
   #include <stdio.h>
   #include <vstring>
   #include <algorithm>
   using namespace std;
   int main(){
       string str[3] = {"bbbb", "cc", "aaa"};
       sort(str, str + 3);
       for(int i = 0;i < 3; ++i){
           cout<<str[i]<<endl;
       }
   }
   //output:
   aaa
   bbbb
   cc
   ```

   如果需要字符串长度从小到大排序

   ```cpp
   #include <stdio.h>
   #include <vstring>
   #include <algorithm>
   using namespace std;
   bool cmp(string str1, string str2){
       return str1.length() < str2.length();//按string的长度从小到大排序
   }
   int main(){
       string str[3] = {"bbbb", "cc", "aaa"};
       sort(str, str + 3, cmp);
       for(int i = 0;i < 3; ++i){
           cout<<str[i]<<endl;
       }
   }
   /*
   output:
   cc
   aaa
   bbbb
   */
   ```

   

## 6.9.7 lower_bound() 和 upper_bound()

* 需要用在一个有序数组或容器，4.5.1讲过如何实现

* lower_bound(first, last, val)用来寻找在数组或容器的[first, last)范围内**第一个值大于等于val**的元素的位置，如果是数组，返回该位置的指针；如果是容器，返回该位置的迭代器

* upper_bound(first, last, val)用来寻找在数组或容器的[first, last)范围内**第一个值大于val**的元素的位置，如果是数组，返回该位置的指针；如果是容器，返回该位置的迭代器

* 如果没有需要寻找的元素，则返回可以插入该元素val的指针或迭代器

* 时间复杂度O(log(last - first))

  ```cpp
  #include <stdio.h>
  #include <algorithm>
  using namespace std;
  int main(){
      int a[10] = {1, 2, 2, 3, 3, 3, 5, 5, 5, 5};
      //寻找-1
      int* lowerPos = lower_bound(a, a + 10, -1);
      int* upperPos = upper_bound(a, a + 10, -1);
      printf("%d %d", lowerPos - a, upperPos - a);
      return 0;
  }
  ```

  

