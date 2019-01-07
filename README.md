### PAT OJ题目
之前也没怎么写过OJ题目，刚接触刷题真的是想死，在这里记录一下自己的代码吧。
如果能帮到也在考研浙大的同学也是一件好事。
* 2018-7-26

  刚开始暑假刷题，好多不会写，心态崩了，握草，看大佬们的代码难的题目要不是解释半天看不懂，要不就是大佬觉得太简单，懒得解释。。。被碾压了。

  接下来打算一个专题一个专题的进行复习。今天主要刷的是树相关的算法，哎！数据结构学的不扎实啊，树的代码没怎么亲自写过，心痛。

* 2018-7-27

  大概写了5、6道左右的树相关算法，主要的就是先序遍历、中序遍历、后续遍历、层序遍历这些变化进行考察，虽然感觉对于我来说还是有点难度。继续加油吧。明天的专题打算写一下 STL的运用以及字符串的处理这两个方面。

  STL 相关的题目一般来说是比较简单的，刷了几道感觉，感觉不错。字符串也是我的一个痛点。看看明天能有什么收获吧。

* 2018-7-28

  果然写到字符串的时候被虐了，好菜啊。记录一下自己学到的处理技巧吧。
  
  * 使用 `cin>>` 进行输入的时候，`\n` 是不会被读入的，所以回车还是在输入缓冲里面。需要使用 `cin.get()` 进行读取，`getline()` 函数是会从缓冲读入回车，但是主动丢弃的。所以两种混用的时候才需要 `cin.get()`。
  * `getline(istream, std::string, char delim)` 
  
    一般来说就是 `getline(cin, str)` 这里的只能是c++的标准类 string，而不是 `char` 数组。然后特殊的时候可以利用字符串作为输入，写法如下：
    ```c++
    #include<stringstream>
    string s = "f**k all";
    string container;
    stringstream ss(s);

    getline(ss, container, ' ');
    ```
    这样就达到了分割 string 的效果。
    然后如果有需要使用原始的 char 数组进行输入的话，可以使用 `fgets(char * str, int num, FILE * stream)` 函数。需要指定读入字符的数目，这个数目 `num` 是包括尾部的 `\0` 符号的，所以实际能够输入的数目是 n-1，但是输出 char 数组的时候比较方便，直接 `cout<<str;`

  写了一道 map 使用的题目，感觉自己用不来 STL。。。总结一下题目：
  如果需要使用的一个 key 对应多个不同的 value，而且需要 value 有序。这里注意是不同的 value，并不一定要使用 `multimap`,有时候会显得过于复杂。可以考虑下面的写法：
  ```c++
  #include<map>
  using namespace std;
  map<string, set<int> > mp;
  mp["Tom"] = 12;
  mp["Tom"] = 14;
  mp["Tom"] = 10;
  auto it = mp.find("Tom");// 找到一个 set 结构的指针
  if(it != mp.end()) {
    for(auto i = it->begin();i!=it->end();i++)
      // 进行遍历操作
  }
  ```

  写了好几道 STL的题目，发现自己对于 STL的用法还是不熟悉啊，好多坑等着踩。今天发现一个关于 `set` 的坑。代码如下：
  ```c++
  map<int, int> mp;
  set<int> someSet;// 假设已经有值了
  for (auto it = someSet.begin(); it != someSet.end(); it++) {
		if (mp[*it] == 1)
			someSet.erase(it);
	}
  ```
  删除操作并不会像想的那样，it 迭代器指向的东西已经没了，那 it 应该指向哪里了呢，看了官方文档之后知道了。
  ```c++
  (1)iterator  erase (const_iterator position);
  (2)size_type erase (const value_type& val);
  (3)iterator  erase (const_iterator first, const_iterator last);
  ```
  `erase` 有三种模板，第二种返回的是删除的值，其他两种返回的是删除值下一个地方的迭代器（也就是顺延了一位）。
  如果想要正确执行上面的代码，可以这样写：
  ```c++
  map<int, int> mp;
  set<int> someSet;// 假设已经有值了
  auto it = someSet.begin();
  while(it != someSet.end()) {
    auto now = it++;
    if(mp[*now] == 1)
      someSet.erase(now);
  }
  ```
  因为标准库的设计思想是这样的：
  > The insert members shall not affect the validity of iterators and references to the container, and the erase members shall invalidate only iterators and references to the erased elements.

* 2018-7-29

  今天刷题太难受了，自己太蠢了，好多细节问题的处理都暴露出来了，对于字符串的处理，看了 KMP 感觉有点恐怖，越来越觉得 ACM 大佬太牛逼了，自己还是掌握基本的字符串的处理，这种高阶的算法 PAT怕是不会考，以后有机会再补上吧。

  总结一下字符串处理里面经常用到的函数吧，除了一些脑子瓦特踩的坑，这些常用函数不熟悉踩的坑也很多。

  ```c++
  #include<string> // 基本的函数包含在这里面
  bool isalpha(char a);
  // 判断一个字符是否是英文字母。
  bool isdigit(char a);
  // 判断字符是否是数字

  int stoi (const string&  str, size_t* idx = 0, int base = 10);
  // 一般用不到那么多参数，数字进制一般就是 10，如果想要知道第一个不是数字的位置，可以传进去第二个参数。不过类型一定要用 std:string::size_type *sz，有点麻烦
  std::string str_dec = "2001, A Space Odyssey";
  std::string::size_type sz;   // alias of size_t
  int i_dec = std::stoi (str_dec,&sz);
  std::cout << "firrst non-digit position is  " << sz << '\n';
  // output "firrst non-digit position is 4"

  double stod(const string&  str, size_t* idx = 0);
  float stof(const string&  str, size_t* idx = 0);
  // 这两个用法都差不多，简单用法就是直接送一个 string 进取就行

  string.push_back();
  string.back();
  // 可以很方便的像字符 vector 那样操作

  int tolower ( int c );
  int toupper ( int c );
  // 标准的 c++ string 库好像没有提供直接的大小写转换函数，可以利用下面这个函数进行。需要配合 algorithm 中的 transform 函数进行。输出 "test pat"。转换大写，只要把 tolower() 改成 toupper。
  #include <algorithm> 
  string strA = "test PAT";
  transform(strA.begin(), strA.end(),strA.begin(), ::tolower); 
  ```
  刷题到现在，感觉代码一定要用自己熟悉的函数和库，不然很容易出现 bug，而且一下子找不到，那就真的要哭了。平时多积累常用标准库的用法吧。
  ```c++
  // char 数组转化为 string 对象
  char arr[] = "this is char array";
  string str(arr);// 如果是还没有出现的string对象，可以直接使用构造函数
  str.assign(arr); // 已经存在的string采用赋值函数。

  string substr (size_t pos = 0, size_t len = npos) const; // 一般来说传入两个整型数据就可以了，一个起始下标，一个子串的长度。如果字串长度不写的话，就是后缀
  ```

  明天开始刷排序的题目，试了几道题目，这种题目一般来说不是很难，要不就是卡运行时间，要不就是 `cmp` 函数逻辑比较复杂，一般都可以用结构体解决，当然这里也要涉及基础的字符串的处理过程。

* 2018-7-31

  今天刷了一晚上的排序题目，感觉出的都是很水的题目，有可能是因为大家使用的都是 c++自带的 sort 函数了，难度都被掩盖了。

  说一个排序题目中经常使用到的技巧吧。很多时候题目会要求给输出排名，但是相同分数的对象要有相同的排名，下一个不同的排名就会有跳跃的情况，为了考场上省时间，还是背一下模板吧。
  ```c++
  int rank = 0, pres = -1;
  // pre 用来记录上一个元素的大小，代码比较简洁，之前很喜欢比较 ans[i] 和 ans[i-1]，但是这样需要考虑边界的情况，太浪费时间了
  vector<int> ans;
  printf("%d\n", (int)ans.size());
  // 输出元素的个数
  for (int i = 0; i < ans.size(); i++) {
    if (pres != ans[i].score) rank = i + 1;
    pres = ans[i].score;
    printf("%d ", rank);
    cout << ans[i].school;
    printf(" %d %d\n", ans[i].score);
  }
  ```

  有的时候排序规则过于复杂，直接写在一个 cmp 函数中很容易出错，这时候可以考虑分组的形式。因为排序复杂的原因往往是有多种不同类型的元素，而且各种类型内部又有不同的规则。
  ```c++
  // PAT 中按照才德区分君子小人的题目，就可以分成四类进行排序
  vector<int> v[4];
  for (int i = 0; i < n; i++)
  {
    scanf("%d %d %d", &temp.num, &temp.de, &temp.cai);
    if (temp.de < low || temp.cai < low)
      total--;
    else if (temp.de >= high && temp.cai >= high)
      v[0].push_back(temp);
    else if (temp.de >= high && temp.cai < high)
      v[1].push_back(temp);
    else if (temp.de < high && temp.cai < high && temp.de >= temp.cai)
      v[2].push_back(temp);
    else
      v[3].push_back(temp);
  }
  printf("%d\n", total);
  for (int i = 0; i < 4; i++)
  {
    sort(v[i].begin(), v[i].end(), cmp);
    for (int j = 0; j < v[i].size(); j++)
      printf("%d %d %d\n", v[i][j].num, v[i][j].de, v[i][j].cai);
  }
  ```

* 2018-8-1

  今天开始看图这一章了，之前对于图可以说是很恐惧的，感觉搜索来搜索去好复杂的样子，而且大部分设计递归的算法，debug真的费劲啊。开始就参考晴神笔记来看，一开始上手肯定是虐的很惨啊。

  参照着晴神和柳神的代码写了两道题，有点收获，还是写一点东西。

  做了一道的利用图的连通量求解的题目，看网上这个可以用并查集和深度搜索来做，就先写写深度搜索的算法吧
  ```c++
  vector<bool> visited = {false};
  int G[maxn][maxn] = {0}; // 假设经过输入的赋值，G里面已经存在图的基本信息了。
  int n; // 已经输入了顶点的个数
  void dfs(int node) {
    visited[node] = true;
    for(int i=0;i<n;i++)
      if(G[node][i] > 0 && visited[i] == false)
        dfs(i);
      // 找到 node 的邻接的节点，并且要没有访问过的
  }
  // 主体里面的代码可以这么写
  int count = 0;
  for(int i=1;i<=n;i++) {
    if(visited[i] == false) {
      dfs(i); // 一次深度搜索就会把一个连通分量的所有节点置为已访问了
      count++;
    }
  }
  ```
  每次写图的算法的时候总会忽略下标的开始位置是从 1 开始的，好蠢。

  经典算法：判断一个图是否是一棵树：
  利用深度优先或者广度优先。并查集也可以判断
  无向图的
  ```c++
  vector<vector<int> > G;
  vector<bool> vis;
  int n;
  G.resize(n);
  vis.resize(n, false);
  bool isTree = true;
  void dfs(int root) {
    if(vis[root]) {
      isTree = false;
      return;
    }
    vis[root] = true;
    for(int i=0;i<G[root].size();i++) {
      dfs(G[root][i]);
    }
  }
  ```

  判断哈密顿回路的算法
  ```c++
  // 给定一个路径的表达存放在 vector数组中，数组中的元素表示路径经过的顶点编号。
  // 要满足哈密顿图的条件，首先要满足这条路径是有效的，也就是路径走的通就可以了，这里是邻接表的表达法
  int isConnected() {
    int pre = path[0];
    for (int i = 1; i < kn; i++) {
        if (graph[pre][path[i]] != 1) return 0;
        pre = path[i];
    }
    return 1;
  }
  // 其次需要每一个顶点通过且仅通过一次，而且最后要回到起点处
  int isHamilt() {
      // kn 是路径数组的长度
      if (v[0] != v[kn-1]) return 0;
      vector<int> times(kn, 0);
      for (int i = 0; i < kn; i++)
          times[v[i]]++;
      for (int i = 1; i < kn; i++)
          if ((i == v[0] && times[i] != 2) || (i != v[0] && times[i] != 1)) return 0;
      return 1;
  } 
  ```
  判断是否是完全图（所有顶点之间都至少有一条边连接）
  ```c++
  int G[maxn][maxn];
  int n; // node number start from 1
  bool isComplete() {
    bool isComplete = true;
    for(int i=1;i<=n && isComplete ;i++) {
      for(int j=i+1;j<=n;j++)
        if(G[i][j] == -1) {
          isComplete = false;
          break;
        }
    }
    return isComplete;
  }
  ```
  Dijkstra 算法（经典的最短路径算法）
  如果给给定一个起点的话，按照贪心算法找到最近可以走的路。
  由于算法需要记录源点到所有结点的目前距离，所以一个距离向量少不了。图的表示方法有两种，
  ```c++
  vector<vector<int> > G; // 建立邻接表
  const int INF = 1e9;
  vector<int> dis(n, INF);
  vector<int> vis(n, false);
  void dijkstra(int s) {
    // 第一步是初始化过程
    for(int i=0;i<n;i++)
      dis[i] = INF; // 因为有的题目需要多次使用这个函数，所以在函数内部初始化是最安全的
    dis[s] = 0; // 起点不能少
    for(int k=0;k<n;k++) {
      int u = -1, min = INF;
      for(int i=0;i<n;i++)
        if(vis[i]== false && dis[i] < min){
          min = dis[i];
          u = i;
        }
      if(u == -1) return; // 所有结点更新完毕
      vis[u] = true;
      for(int v=0;i<G[u].size();v++) {
        if(vis[v]==false && G[u][v]!=INF && dis[v] < G[u][v]+dis[u])
          // 如果能够通过 u 走一条比 dis[v] 的话，更新这个距离
          dis[v] = dis[u]+G[u][v];
      }
    }
  }
  ```
  dijkstra 算法一般不会直接考，会有下面的是那种的考察方式：

  1. 计算有多少种长度相等的路径
  2. 给出另外一种形式的边权，在路径长度相同的情况下，选择这种边权和小（或者大）的路径。比如说每条边给出了时间和距离。要求的是选择最短的距离，如果距离相同的话，选择时间最小的路径。
  3. 引入顶点的权值，要求路径相同长度时，点权值最小（大）

  下面的这种例子基本上三种情况都用到了，题目还真是用心良苦

  ```c++
  const int maxn = 500;
  const int inf = 1e9;
  int n, m, s, e;
  int G[maxn][maxn];
  vector<int> help;
  vector<bool> vis;
  vector<int> dis;
  vector<int> hp; // 设置路径上顶点的权值和
  vector<int> num; // num[i] 存储从 s 城市到 i 城市的可能路径
  void dijkstra(int s) {
    for (int i = 0; i < n; i++)
      dis[i] = inf;
    // hp[s] = help[s] 因题目而异，有的题目出发结点不算入结点权值就设置为 0
    dis[s] = 0; hp[s] = help[s]; num[s] = 1;
    // 老是忘记外层的循环，提醒一下自己
    for (int i = 0; i < n; i++) {
      int u = -1, mini = inf;
      for (int j = 0; j < n;j++)
        if (!vis[j] && mini > dis[j]) {
          mini = dis[j];
          u = j;
        }
      if (u == -1) return;
      vis[u] = true;
      for (int v = 0; v < n; v++) {
        if (!vis[v] && G[u][v] != 0) {
          if (dis[v] > dis[u] + G[u][v]) {
            dis[v] = dis[u] + G[u][v];
            hp[v] = hp[u] + help[v];
            // 如果只有一条路从 u 到 v，那么可能的路径就继承 u 的
            num[v] = num[u];
          }
          else if (dis[v] == dis[u] + G[u][v]) {
            // 注意这里是要求所有一样长的路径个数，并不要求这些一样长的路径
            // 还有一样的 help 值。一开始这里理解有误，两个测试点过不去
            if(hp[v] < hp[u] + help[v]) hp[v] = hp[u] + help[v];
            num[v] += num[u]; // 除了已经找到的路径数目，又可以从 u 结点增加 num[u] 条路径
          }
        }
      }
    }
  }
  ```

* 2018-08-09

  关于质数的几个算法
  1. 小题目中的判断质数的过程

    一般求质数只是一个附加的步骤的题目中，可以使用效率不是很高的原始定义判断法
    ```c++
    bool isPrime(int n) {
      for(int i=2;i*i<=n;i++)// 等于号不能少
        if(n%i == 0) return false;
      return true;
    }
    ```
    对于专门考察质数的题目需要优化算法——埃氏筛法
    好像还是很慢啊，要算出很多的质数的话。
    ```c++
    #include<cmath>
    const int maxn = 1e9;
    int vis[maxn] = {false};
    int prime[maxn], pNum=0;
    void findPrime(int n) {
      for(int i=2;i < n;i++) {
        if(vis[i] == false)
          prime[pNum++] = i; // 如果前面的数字所进行的筛选没有筛掉这个数的话，那么这个数一定是质数
        for(int j=i+i;j < n;j+=i) {
          vis[j] = true;
        }
      }
    }
    ```
    这种算法的复杂降到了 `O(nloglogn)` 对于一般强度的题目还是够用的，还有一种更优化的算法——欧拉筛，复杂度降到了 `O(n)` 有兴趣的可以自己了解
    看到柳神的一种方法，真的没见过
    ```c++
    const int N;// 
    vectr<int> prime[N]
    for(int i = 2; i * i < N; i++)
      for(int j = 2; j * i < N; j++)
        prime[j * i] = 0;
    ```

* 2018-8-16

  今天又写到了一个并查集的题目，感觉这个比较套路（这次的需要路径压缩才能满分）
  并查集的题目基本都要这两个函数，所以可以背出来备用了。
  ```c++
  int father[maxn]; // 假设数组已经初始化好了
  int findFather(int v) {
    if(v == father[v]) return v;
    int F = findFather(father[v]);
    father[v] = F;
    return F;
  }
  void Uion(int a, int b) {
    int af = findFather(a);
    int bf = findFather(b);
    if(af != bf)
      father[af] = bf;
  }
  ```

* 2018-08-17

  关于输入输出的一点小知识：在同时输入字符型和整数型的数据的时候要小心，
  输入字符会把回车和空格当做有效输入
  ```c++
  // `12 c 23` in file
  scanf("%d", &addr);
  scanf("%c %d", &ch, &num[addr]);
  ```
  要小心 ch 读入的其实是一个空格，没有读到真正的字母，常用的解决方法
  ```c++
  // %c 前面多加一个空格就可以
  scanf(" %c %d", &ch, &num[addr]);
  ```
  字符整数混合输入的时候，这样写能保证不出错

  进制转化相关的算法
  ```c++
  // 16进制以内的转化为 10 进制的数，string n 保存源数
  long long convert(string n, long long radix) {
    long long sum = 0;
    int index = 0, temp = 0;
    for (auto it = n.rbegin(); it != n.rend(); it++) {
        temp = isdigit(*it) ? *it - '0' : *it - 'a' + 10;
        sum += temp * pow(radix, index++);
    }
    return sum;
  }
  ```
* 树的相关算法的整理

  1. 算出树中每个层次的结点数
    ```c++
    vector<vector<int> > tree; // 已经建立好了邻接表
    vector<int> level(n);
    void dfs(int root, int depth) {
      level[depth]++;
      for(int i=0;i<tree[root].size();i++)
        dfs(tree[root][i], depth+1);
    }
    ```

  2. 从后续遍历和中序遍历中建立二叉树，输出先序遍历

    ```c++
      int search(int arr[], int x, int n)
      {
        for (int i = 0; i < n; i++)
          if (arr[i] == x)
            return i;
        return -1;
      }
  
    // Prints postorder traversal from given inorder and preorder traversals
    void printPostOrder(int in[], int pre[], int n)
  {
      // The first element in pre[] is always root, search it
      // in in[] to find left and right subtrees
      int root = search(in, pre[0], n);
    
      // If left subtree is not empty, print left subtree
      if (root != 0)
          printPostOrder(in, pre+1, root);
    
      // If right subtree is not empty, print right subtree
      if (root != n-1)
          printPostOrder(in+root+1, pre+root+1, n-root-1);
      // Print root
      cout << pre[0] << " ";
    }
    ```

  3. 从先序遍历构建 BST
  
      先序遍历的第一个就是根，所以基本的思想就是找出左右子树的根节点，进行递归的操作。（本质上是因为根据 BST 的左子树比根小，右子树比根大的性质可以唯一确定左右子树的范围，在用递归就可以解决问题）
    ```c++
    #include<iostream>
    #include<vector>
    using namespace std;
    struct node
    {
      int val;
      int left;
      int right;
      node(int l = -1, int r = -1, int v = 0) : left(l), right(r), val(v) {};
    };
    int n;
    vector<node> tree;
    vector<int> pre;
    // int pre[] = {10 5 1 7 40 50};
    int search(int l, int r)
    // 找到范围内右子树的下标
    {
      for (int i = l + 1; i <= r; i++)
      {
        if (pre[i] > pre[l])
          return i;
      }
      return -1;
    }
    void buildTree(int preL, int preR)
    {
      if (preL == preR)
      {
        tree[preL] = node(-1, -1, pre[preL]);
        return;
      }
      int right = search(preL, preR);
      
      if (right != preL + 1) {
        // 左子树不为空，右子树随便
        tree[preL] = node(preL + 1, right, pre[preL]);
        buildTree(preL + 1, right - 1);
      }
      else {
        // 左子树为空
        tree[preL] = node(-1, right, pre[preL]);
      }
      // 在递归的构建右子树
      if (right != -1) {
        buildTree(right, preR);
      }
    }
    void post(int root)
    {
      if (root == -1)
        return;
      post(tree[root].left);
      post(tree[root].right);
      if(root==0) printf("%d", tree[root].val);
      else printf("%d*", tree[root].val);
    }
    int main()
    {
      scanf("%d", &n);
      tree.resize(n);
      pre.resize(n);
      for (int i = 0; i<n; i++)
        scanf("%d", &pre[i]);
      buildTree(0, n - 1);
      post(0);
    }
    ```

* 2018-8-24

  今天看到柳神的代码真的膜拜，只能记录下来了。
  题目大意：给出n个正整数和一个正整数m，问n个数字中是否存在一对数字a和b(a <= b),使a+b=m成立。如果有多个，输出a最小的那一对。
  分析：建立数组a保存每个数字出现的次数，然后判断输出
  ```c++
  #include <iostream>
  #include<algorithm>
  #include<vector>
  using namespace std;
  int n, m;
  int Hash[1001];
  int main() {
    scanf("%d%d", &n, &m);
    int tmp;
    for(int i=0;i<n;i++) {
      scanf("%d", &tmp);
      Hash[tmp]++;
    }
    for(int i=1;i<1001;i++) {
      if(Hash[i]) {
        Hash[i]--; // 这里是因为有 i 和 m-i 相等的情况，这种情况下需要hash[i] >= 2才满足题意
        if(m>i && Hash[m-i]) {
          printf("%d %d", i, m-i);
          return 0;
        }
        Hash[i]++;
      }
    }
    printf("No Solution");
  }
  ```

* 2018-9-3

  最后一个没有解决的算法，DAG关键路径。这个利用简单的动态规划就可以解决，代码不是很复杂，重要的是思想需要理解。下面看看代码。
  感觉动态规划重要的就是需要想清楚，掌握几种典型的构造的方法，所以基本所有的教材都是先教一个的最长递增子串之类、背包问题的算法。
  ```c++
  int G[maxn][maxn];// 假设已经通过邻接矩阵表示了这个有向无环图
  int dp[n]; // dp[i] 表示从节点 i 开始能够得到的最长路径。按照这样的定义，
  // dp[i] = {max{所有 i 节点能够直接到达的相邻节点中，len(i--->j) + dp[ij]}}。再利用递归很容易写出算法
  // 有的情况下，关键路径不止一条，如果题目要求输出的是字典序最小的一条的话，这个代码已经自动实现了。因为在遍历一个节点的相邻节点的时候就是按照字典序进行遍历的，所以符合要求路径一定排在前面。
  int choice[n] = {-1};
  int DP(int i) {
    if(dp[i]>0) return dp[i];

    for(int j=0;j<n;j++){
      if(G[i][j] != inf) {
        int temp = DP(j)+G[i][j];
        if(temp>dp[i]) {
          dp[i] = temp;
          choice[i] = j;// i号的后继顶点是 j
        }
      }
    }
    return dp[i];
  }
  void printPath(int i) {
    printf("%d", i);
    while(choice[i] != -1) {
      i = choice[i];
      printf("->%d", i);
    }
  }
  ```
  通过一个矩阵嵌套问题进行说明怎么使用 DAG 解决实际问题
  ```c++
  #include<iostream>
  #include<vector>
  using namespace std;
  const int maxn = 101;
  int n;
  struct node {
      int a, b;
  };
  int G[maxn][maxn];
  vector<node> rect;
  vector<int> dp;// dp[i] 表示从节点 i 开始的最长路径的长度
  vector<int> choice;
  int DP(int u) {
      if(dp[u]!=0) return dp[u];
      int mx = 0;
      for(int i=0;i<n;i++) {
          // 在 u 结点直接连接的顶点中，利用能够提升路径最大的进行更新得到最后的结果
          if(G[u][i]!=0) {
              int tmp = DP(i)+1;// 这里一定要写在外面，不然会多次调用DP函数
              if(tmp > dp[u]){
                  dp[u] = tmp;
                  choice[u] = i;
              }
          }
      }
      return dp[u];
  }
  void printPath(int x) {
      while(x!=-1) {
          printf("%d ", x);
          x = choice[x];
      }
  }
  int main() {
      scanf("%d", &n);
      dp.resize(n, 0);
      choice.resize(n, -1);
      int a, b;
      for(int i=0;i<n;i++) {
          scanf("%d%d", &a, &b);
          rect.push_back({a, b});
      }
      // 把矩阵嵌套的关系转化为有向图
      for(int i=0;i<n;i++) {
          for(int j=0;j<n;j++) {
              if((rect[i].a < rect[j].a && rect[i].b < rect[j].b) ||
              (rect[i].a < rect[j].b && rect[i].b < rect[j].a))
              G[i][j] = 1;
          }
      }
      DP(0);
      int maxl = 0, index = -1;
      // 找到最长路径起始的点，才能进行输出路径的操作
      for(int i=0;i<n;i++)
          if(dp[i] > maxl){
              maxl = dp[i];
              index = i;
          }
      printf("%d\n", maxl);
      if(index!=-1) printPath(index);
  }
  ```
* 2018-9-4

  对于普通的二分查找，还是字以下关键的容易出错的地方；
  ```c++
  int v[n];// 一个严格递增的数列
  int mid, l=0, r=n-1, x, ans;// 要找到数据 x
  while(l<=r) { // 等号是一个很容易出错的地方，希望可以记住
    mid = (l+r)/2;
    if(v[mid] > x) r = mid-1;
    else if(v[mid] < x) l = mid+1;
    else {
      ans = mid;
      break;
    }
  }
  ```
  碰到二分查找的时候有可能存在相同值的元素，怎么找到数据的相同元素的上界或者下界，有的时候是一个很重要的问题
  ```c++
  // 寻找最后一个符合要求的元素的问题的模板，要仔细体会和严格单调的数列的区别所在。
  int BinarySearch(int l, int r) {
    int mid;
    while(l<r) {
      mid = (l+r)/2;
      if(v[mid] <= x) l = mid;// 最后一个符合的肯定在 [mid, r] 中。
      else r = mid-1;
    }
  }
  ```
* 2018-9-6

  对于输出一种排序方法中的某一轮排序的中间过程的题目。
  
  insert sort 的特点是前面 k 个是有序的，所以第 k 轮就是对前面 k+1 个数字进行排序就好。

  merge sort 特点是其中的偶数个的元素之间是有序的，外部是无序的。
  ```c++
  // index start from 1
  void mergeSort(int A[]){
    for(int step=2;step/2<n;step*=2) {
      for(int i=1;i<=n;i+=step){
        sort(A+i, A+min(i+step, n+1));
      }
      // 输出一次排序的中间结果
    }
  }
  ```
  发现拓扑排序的还没有写过。拓扑排序主要可以考察以下的方面：（给定一个有向图）
  * 任意给定一个排序序列，判断这个序列是否是有效的拓扑排序。
  ```c++
  // 这种比较简单，记录每一个顶点的入度。再按照给定的序列走一遍。
  int n;// vertical number
  vector<vector<int>> G;// 假设已经存好了图
  vector<int> degree;
  vector<int> vec;
  bool isTopo(vector<int> vec) {
    for(int u=0;u<n;u++) {
      if(degree[u]!=0) return false;
      // 把射出的顶点入度减一
      for(int i=0;j<G[u].size();i++) {
        degree[G[u][i]]--;
      }
    }
    return true;
  }
  int main() {
    scanf("%d", &n);
    int v1, v2;
    G.resize(n);
    degree.resize(n);
    vec.resize(n);
    for(int i=0;i<n;i++) {
      scanf("%d%d", v1, v2);
      G[v1].push_back(v2);
      degree[v2]++;
    }
    // 输入一个序列进行判断这个是否是拓扑排序
    int v;
    for(int i=0;i<n;i++)
      scanf("%d", &vec[i]);
    printf("%s", isTopo(vec) ? "Yes": "No");
  }
  ```
  * 判断这个图是否存在拓扑排序
  ```c++
  // 这个可以用深搜来做，实际上就是判断是不是存在环路，在图那里有说明。这里采用
  ```
  * 输出所有可能的拓扑排序
  ```c++
  #include<iostream>
  #include<vector>
  using namespace std;
  const int maxn = 1001;
  int n, m;
  int G[maxn][maxn];
  vector<int> indegree;
  vector<int> ans;
  vector<bool> vis;

  void dfs(int num){
    // 递归的参数是递归的深度，当发现深度已经超过顶点数目时，进行输出，返回
      if(num==n) {
          // print ans here
          for(int i=0;i<n;i++){
              if(i==0) printf("%d", ans[i]);
              else printf(" %d", ans[i]);
          }
          printf("\n");
          return;
      }
      for(int i=1;i<=n;i++){
          if(vis[i]==false && indegree[i]==0) {
              for(int v=1;v<=n;v++) {
                  if(G[i][v]!=0) indegree[v]--;
              }
              ans.push_back(i);
              vis[i] = true;
              dfs(num+1);
              // 不要下面这段代码就是输出序号最小的一个拓扑排序，下面进行回溯操作，进行多次的输出（按照序列的字典序排列）。
              for(int v=1;v<=n;v++) {
                  if(G[i][v]!=0) indegree[v]++;
              }
              ans.pop_back();
              vis[i] = false;
          }
      }
  }
  int main() {
      scanf("%d%d", &n, &m);
      indegree.resize(n+1, 0);
      // ans.resize(n+1, 0);
      vis.resize(n+1, false);
      int v1, v2;
      for(int i=0;i<m;i++){
          scanf("%d%d", &v1, &v2);
          G[v1][v2] = 1;
          indegree[v2]++;
      }
      dfs(0);
  }
  ```
* 2018-09-7
  
  今天看了一个 LCA（最小公共祖先的问题），不是很熟悉
  这种有两种考法：BST的LCA和普通二叉树的LCA。
  * BST的LCA
  
  给定一棵树，在随便给两个数，输出他们的LCA。这个比较简单，想想一下 BST 先序遍历。顺序走一遍，碰到的第一个符合 `subRoot.val` 在给出的两个数之间的就是他们的 LCA。

  其实可以这么想，从 BST 的根开始判断，如果两个数都比根小，就往左子树搜索。如果都大，那就是搜索右子树。如果一个大，一个小，那么就是找到了LCA
  * BT 的LCA

  这个比较复杂一些。可以进行先序遍历。每次访问从左右子树返回的是所给的数，或者是 null。这样能得到两个数的节点就是LCA。

- 2019-01-01
  各种全排列的问题
  × 首先字符串的排列问题
  ```c++
  void Swap(string &str, int s, int e) {
    char tmp = str[s];
    str[s] = str[e];
    str[e] = tmp;
  }
  // 回溯法输出所有的字符串排列
  void Permutation(string &str, int begin, int end) {
    if(begin == end) {
        cout<<str<<endl;
        return;
    }
    for(int i=begin;i<=end;i++) {
      Swap(str, begin, i);// 固定其中一个字符，对缩小一个字符的字符子串进行递归操作
      Permutation(str, begin+1,end);
      Swap(str, begin, i);// 一定要记得回溯到原始的状态
    }
  }
  ```
- 2019-01-07
  层序遍历之区分不同深度的节点
  ```c++
  // Given binary tree {3,9,20,#,#,15,7},
  // get
  //  [
  //  [3],
  //  [9,20],
  //  [15,7]
  //  ]
    vector<vector<int>> levelOrder(TreeNode * root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        TreeNode* tmp;
        vector<int> level;
        std::queue<TreeNode*> q;
        q.push(root); q.push(NULL);
        while(!q.empty()){
          tmp = q.front(); q.pop();
          if(tmp==NULL) {
            // 这里如果是空队列还要继续添加不同层的标识NULL的话，将是无限循环
            f(!q.empty()) q.push(NULL);
            ans.push_back(level); level.clear();
          } else {
            level.push_back(tmp->val);
              if(tmp->left != NULL)
                q.push(tmp->left); 
              if(tmp->right != NULL)
                q.push(tmp->right);
          }
        }
        return ans;
    }
  ```