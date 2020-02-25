Example: Tagging Commits in a Local Repository
===============================================================================


A tag is used to label and mark a specific commit in the history.
It is usually used to mark release points.
Although a tag may appear similar to branch, a tag however does not change.
It points directly to a specific commit in the history.

Use an existing repository
---------------------------

```
$ cd sandbox/hello-world

$ git log --pretty=oneline
c5fce964ca9f70c9ec17fc06ba62282c43854d61 Add output text.
b4eddc4586397cf114e9d96f644adff857a54d04 Changed output text.
750335327a7a203678529dda474c68601e297604 Initial commit.
```


Creating tags
--------------

```
$ git tag -a version-1.0.0 -m "A first working version of this project."
```

```
$ git tag
version-1.0.0
```

Make some modifications, commit them and tag the new commit.

``` 
$ vi src/org/se/lab/Hello.java 
Do some modifications...

$ git commit -a -m "Removed output text."

$ git tag version-2.0.0
```

```
$ git tag
version-1.0.0
version-2.0.0
```

Checkout tags
--------------

```
$ git checkout tags/version-1.0.0
Note: checking out 'tags/version-1.0.0'.

You are in 'detached HEAD' state. You can look around, make experimental
changes and commit them, and you can discard any commits you make in this
state without impacting any branches by performing another checkout.

If you want to create a new branch to retain commits you create, you may
do so (now or later) by using -b with the checkout command again. Example:

  git checkout -b <new-branch-name>

HEAD is now at c5fce96... Add output text.
```

```
$ cat src/org/se/lab/Hello.java 
You will see the old version of this file.
```

```
$ git checkout tags/version-2.0.0
HEAD is now at a8035b3... Removed output text.	
```

```
$ git status
HEAD detached at version-2.0.0
nothing to commit, working directory clean
```

```
$ cat src/org/se/lab/Hello.java 
You will see the new version of this file again.
```

Tag an older commit
-------------------
We can also tag commits after we have moved past them.

```
$ git log --pretty=oneline
53f4a4261c6eb72814055949cf2b0cd059743fba Changed output text.
a8035b3bd333e69ac6560d0cdedfab6ed52a2153 Removed output.
c5fce964ca9f70c9ec17fc06ba62282c43854d61 Add output text.
b4eddc4586397cf114e9d96f644adff857a54d04 Changed output text.
750335327a7a203678529dda474c68601e297604 Initial commit.
```

```
$ git tag -a version-0.0.1 a8035b3bd333e69ac6560d0cdedfab6ed52a2153 -m "Pretty early version."
$ git tag
version-0.0.1
version-1.0.0
version-2.0.0
```

```
$ git show version-0.0.1
tag version-0.0.1
Tagger: teiniker <egon.teiniker@fh-joanneum.at>
Date:   Fri Apr 7 10:05:51 2017 +0200

Pretty early version.

commit a8035b3bd333e69ac6560d0cdedfab6ed52a2153
Author: teiniker <egon.teiniker@fh-joanneum.at>
Date:   Fri Apr 7 07:49:22 2017 +0200

    Removed output.

diff --git a/src/org/se/lab/Hello.java b/src/org/se/lab/Hello.java
index 5bc09f2..001e06e 100644
--- a/src/org/se/lab/Hello.java
+++ b/src/org/se/lab/Hello.java
@@ -7,7 +7,6 @@ public class Hello
     public static void main(String... args)
     {
         System.out.println("Hello KBerg!");
-        System.out.println("Hello Graz!");
     }
 }
```
 
Go back to the master branch
-----------------------------

```
$ git checkout master
Switched to branch 'master'

$ git status
On branch master
nothing to commit, working directory clean
```

