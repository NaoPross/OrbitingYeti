What is this?
=============
OrbitingYeti is a tool to write Nassi-Schneidermann diagrams. The name is just a
randomly generated codename.

What is a NS diagram?
---------------------
Nassi-Schneidermann diagrams aka structograms are a way to graphically represent
a structured program, which in modern terms are programs written with a
procedural paradigm. Structograms were first introduced in the '70 by Isaac
Nassi and Ben Schneiderman to replace flowcharts that were becoming
inadequate as they couldn't represent concepts like recursion.

Paper from 1973:
[http://www.cs.umd.edu/hcil/members/bshneiderman/nsd/1973.pdf](http://www.cs.umd.edu/hcil/members/bshneiderman/nsd/1973.pdf)

Why?
----
Because I wanted to practice C++ and try QT, and also because there aren't many
(good, non web based, cross platform) tools to draw these kind of diagrams.

Alternatives
------------
I don't have much time to work on this so here's an alternative.

Structorizer: 
[http://structorizer.fisch.lu/](http://structorizer.fisch.lu/)

![relevant xkcd](https://imgs.xkcd.com/comics/estimating_time.png)


How to build
============

```
$ git clone https://github.com/NaoPross/OrbitingYeti.git && cd OrbitingYeti  
$ mkdir -p build && cd build  
$ qmake .. && make   
```

Project
=======
TODO
----

- [x] Ui
- [ ] Draw diagrams
- [ ] Save / load diagrams
- [ ] Export diagrams to
    * [ ] PDF
    * [ ] TikZ
    * [ ] Svg
    * [ ] PNG
- [ ] Cross platform
- [ ] DEB / RPM Package

Coding style
------------
I use QtCreator's default coding style. 

For more details see:
[https://wiki.qt.io/Qt\_Coding_Style](https://wiki.qt.io/Qt_Coding_Style)

Git
---
If you want to contribute write commits in the imperative (default) form.
