# fundoshi.hpp - A C++ library for multiple string instances with shared memory

(C)2011- H.Hiro/Maraigue (mail: main at hhiro.net)

## Notice (Added on 2016-07-26)

Now the similar feature is available as boost::string_view (former boost::string_ref) in [Boost C++ Libraries](http://www.boost.org/ "Boost C++ Libraries"), or will be standardized as std::string_view in the standard "C++1z" (a.k.a. "C++17"; expected to be standardized in 2017).

## 注記（2016年7月26日追記）

現在は同様の機能が、[Boost C++ Libraries](http://www.boost.org/ "Boost C++ Libraries")中のboost::string_view（元・boost::string_ref）として利用できるほか、C++1z（C++17とも；2017年に標準策定予定）ではstd::string_viewとして標準化される見込みです。

## Outline

This library generates string instances on a shared memory of a `const` string. For example,

    x = std::string("abcde");
    y = x.substr(1, 3);

yields a new `std::string` instance `y` and thus we need to allocate memory in proportion to the length of `y`.

`fundoshi::string` can avoid the problem by sharing the memory. For example,

    x = std::string("abcde");
    y = fundoshi::string(x, 1, 3);

does not copy the memory of `"abcde"` and `y` points the second to the fourth character in `x`. NOTE THAT a change of `x` also changes `y`!

See example.md for the usage. See [http://maraigue.hhiro.net/fundoshi/](http://maraigue.hhiro.net/fundoshi/) for the list of classes, functions and methods.

## The name

[Fundoshi](https://en.wikipedia.org/wiki/Fundoshi "Fundoshi - Wikipedia, the free encyclopedia") is a Japanese-style underwear of a long cloth. In addition to reducing it to a string, the name is also derived from have an Japanese idiom "Wrestle sumo with other's fundoshi" (Conduct something on other's achievement or idea, in a negative sense).

## 概要

このライブラリは、すでにconstな文字列が確保されているメモリ上の領域に対し、そのメモリを共用したまま複数の文字列インスタンスを表現するためのものです。例えば

    x = std::string("abcde");
    y = x.substr(1, 3);

とすると、`y`のために新たに`std::string`のインスタンスが生成され、そのために`y`の大きさに比例したメモリをコピーする必要が生じます。

`fundoshi::string`を用いた場合、この問題を回避できます。例えば

    x = std::string("abcde");
    y = fundoshi::string(x, 1, 3);

とした場合、`y`のために`"abcde"`のメモリをコピーする必要はなくなり、代わりに`y`は`x`の2文字目から4文字目を指し示します。なお、`x`が変化すると`y`も変化することにはご注意を！

利用方法についてはexample.mdを、クラス・関数・メソッドの詳細は[http://maraigue.hhiro.net/fundoshi/](http://maraigue.hhiro.net/fundoshi/)をご覧ください。

## 名前について

「人のふんどしで相撲を取る」が由来です。また、ふんどしは長い布でできていて、文字列という連想に合っている、という理由もあります。
