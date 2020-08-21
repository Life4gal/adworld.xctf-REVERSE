# [攻防世界](https://adworld.xctf.org.cn/)逆向题

#### 第一题: hackme

​	难度系数: 2.0(好像2020-8-7左右变成了3.0)

​	题目来源: XCTF 3rd-GCTF-2017

​	用时: 26分18秒

​	原题链接:[传送门](https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=4881&page=1)

#### 第二题: Guess-the-Number

​	难度系数: 2.0(不知道啥时候变成了3.0, 2020-8-15左右?)(2020-8-20难度变回2.0)

​	题目来源: su-ctf-quals-2014

​	用时: 17分1秒

​	原题链接:[传送门](https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=4908&page=1)

​	吐槽: 居然给我一个 jar 包,我蒙了...突然不知道干嘛了,鬼使神差的打开了 IDA 看的一脸蒙蔽,突然想起自己装了个 IDEA (只多了个E),把jar包里的class文件反编译一下代码就出来了....

#### 第三题: re2-cpp-is-awesome

​	难度系数: 2.0

​	题目来源: alexctf-2017

​	用时: 34分46秒

​	原题链接:[传送门](https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=5031&page=1)

​	吐槽: 一眼看过去全是 std: :__ cxx11: :basic_string<char, std: :char_ traits<char>, std: :allocator<char>>, 我都要吐了.....

#### 第四题: 666

​	难度系数: 2.0

​	题目来源: 2019_UNCTF

​	用时: 18分17秒

​	原题链接: [传送门](https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=5573&page=1)

​	吐槽: 终于见一次反汇编出来的代码这么少的了...

#### 第五题: easyRE1

​	难度系数: 2.0

​	题目来源: 无

​	用时: 14分58秒

​	原题链接: [传送门](https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=5592&page=1)

​	吐槽: 屎一样的原创题目, 花了三分钟得到答案 **FLAG:db2f62a36a018bce28e46d976e3f9864**,高高兴兴地填了上去,**答案错误**. 我: ??? 什么鬼,就那么几条破代码,怎么藏答案?绞尽脑汁想了半天放弃了,查看 WP 发现我的过程完全正确,但是填入的格式是**flag{db2f62a36a018bce28e46d976e3f9864}**. 我: ??? 拜托,不要再出这种题目了OK?

#### 第六题: re1-100

​	难度系数: 2.0

​	题目来源: 无

​	用时: 35分30秒

​	原题链接: [传送门](https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=4720&page=1)

​	吐槽: 忍不住爆粗口,原创题真是恶心死我了,上一题是把**FLAG:db2f62a36a018bce28e46d976e3f9864** 换成 **flag{db2f62a36a018bce28e46d976e3f9864}**,这次是把**{53fc275d81053ed5be8cdaf29f59034938ae4efd}**换成**53fc275d81053ed5be8cdaf29f59034938ae4efd**(去掉花括号),我又多花了20分钟然后放弃了看 WP ,关键是官方WP也是屎一样,要不是别人的WP说了句记得把花括号去掉我估计永远都对不了,真的***...

#### 第七题: Shuffle

​	难度系数: 2.0

​	题目来源: SECCON-CTF-2014

​	用时:  11分45秒

​	原题链接: [传送门](https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=4942&page=1)

​	吐槽: 下载的文件被谷歌浏览器拦截,搞得我浪费很多时间,丢人!

#### 第八题: re-for-50-plz-50

​	难度系数: 2.0

​	题目来源: tu-ctf-2016

​	用时: 12分24秒

​	原题链接: [传送门](https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=4952&page=1)

​	吐槽: 完全看不懂的汇编代码,虚拟机执行不了(不是可执行的二进制文件),IDA不能把它反编译(不是可反编译的文件),挣扎了10分钟放弃了.WP也是一坨屎,直接说该怎么整的,吐了...(附截图)

![re-for-50-plz-50](./008-re-for-50-plz-50/过程.png)

​	追加吐槽: 上面的代码是 **mips架构(Microprocessor without Interlocked Pipeline Stages)**,虽然题目我放弃了,但是解题方法还是要留下的.Retdec的IDA插件: [1.看雪论坛](https://bbs.pediy.com/thread-227079-1.htm)   [2.Gayhub](https://github.com/avast/retdec-idaplugin)

#### 第九题: dmd-50

​	难度系数: 2.0

​	题目来源: suctf-2016

​	用时: 20分50秒

​	原题链接: [传送门](https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=4959&page=1)

​	吐槽: 第一眼看到 MD5 我其实是拒绝的,因为你不能让我算 MD5 我就去算.但是不算题目又做不出来,所以我只好乖乖去算了. [十分钟后....] WTF,我是笨蛋吗?不是有 MD5 在线加/解密的网站吗?我为什么要自己算????????????????

#### 第十题: parallel-comparator-200

​	难度系数: 2.0

​	题目来源: school-ctf-winter-2015

​	用时: 24分25秒

​	原题链接: [传送门](https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=4706&page=1)

​	吐槽: 刚开始看到随机数的时候我有点懵逼,毕竟这是不可控因素.但是我发现它没有指定任何参数,那么就有可能是伪随机.我们把代码搬到linux虚拟机上

![结果](./010-parallel-comparator-200/截图/结果.png)

由于有源代码,我们可以很容易得到结果.

#### 第十一题: secret-galaxy-300

​	难度系数: 2.0

​	题目来源: school-ctf-winter-2015

​	用时: 8分16秒

​	原题链接: [传送门](https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=4707&page=1)

​	吐槽: 好家伙,答案居然不在主逻辑里,还好我眼尖发现其他有地方的引用

![引用](./011-secret-galaxy-300/截图/3.png)

#### 第十二题: srm-50

​	难度系数: 2.0

​	题目来源: suctf-2016

​	用时: 10分35秒

​	原题链接: [传送门](https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=4963&page=1)

#### 第十三题: Mysterious

​	难度系数: 2.0(2020-8-20难度变为1.0)

​	题目来源: BUUCTF-2019

​	用时: 11分18秒

​	原题链接: [传送门](https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=5480&page=1)

​	吐槽: 题目很简单,主要是和别人吐槽了很久.题目描述是[有一天，一个论坛老鸟给小明发了一个神秘的盒子，里面有开启逆向思维的秘密。],一看程序居然是百度的图标,好家伙,一点没骗我.....

#### 第十四题: answer_to_everything

​	难度系数: 2.0

​	题目来源: 2019_ISCC

​	用时: 5分43秒

​	原题链接: [传送门](https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=5511&page=1)

​	吐槽: 啊哈,我知道了是42,但是这个答案的问题是什么呢?

#### 第十五题: elrond32

​	难度系数: 2.0

​	题目来源: tinyctf-2014

​	用时: 14分4秒

​	原题链接: [传送门](https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=4750&page=1)

#### 	第十六题: tt3441810

​	难度系数: 2.0

​	题目来源: tinyctf-2014

​	用时: 4分57秒

​	原题链接: [传送门](https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=4751&page=1)

#### 第十七题: re4-unvm-me

​	难度系数: 2.0

​	题目来源: alexctf-2017

​	用时: 15分44秒

​	原题链接: [传送门](https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=5033&page=1)

​	吐槽: 欺负我不会 python ? (编码用的 UTF-16, 用 IDLE 打不开, 用 np++ 打开才知道)

![反编译](./017-re4-unvm-me/截图/反编译.png)

#### 第十八题: Reversing-x64Elf-100

​	难度系数: 1.0

​	题目来源: 无

​	用时: 8分28秒

​	原题链接: [传送门](https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=4826&page=1)

#### 第十九题: IgniteMe

​	难度系数: 1.0

​	题目来源: 高校网络信息安全运维挑战赛

​	用时: 21分30秒

​	原题链接: [传送门](https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=4590&page=1)

#### 第二十题: 流浪者

​	难度系数: 2.0

​	题目来源: 无

​	用时: 32分34秒

​	原题链接: [传送门](https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=5570&page=1)

​	吐槽: 主函数分析倒是不难,找主函数花点时间...

#### 第二十一题: EasyRE

​	难度系数: 2.0

​	题目来源: 无

​	用时: 21分55秒

​	原题链接: [传送门](https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=5446&page=1)



#### 第二十二题: SignIn

​	难度系数: 2.0

​	题目来源: 2019_SUCTF

​	用时: 18分50秒

​	原题链接: [传送门](https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=5583&page=2)

​	吐槽: 这道题不应该放在 [逆向] 栏中,应该放在 [PWN] 栏,毕竟flag也是**suctf{Pwn_@_hundred_years}**.内容大概是用几个函数进行了 **RSA** 加密,部分属于我的知识盲区(我承认我当时偷懒了...下次还偷懒) ....