/*
 * Namespaces are a way of gathering a set of named items in our program
 * under a single name. Within the rules for identifiers we can choose
 * any name that we like for things in our program. That obviously means
 * that we might choose a name for something that's already used for some
 * other purpose within the standard library. Namespaces are useful when
 * two or more programmers are working concurrently on parts of a larger
 * project and there is potential for name collisions. Clearly, using the
 * same name for two or more different things is bound to cause collisions,
 * and namespaces are there to alleviate this problem. Following is an
 * example where cout (also used in standard library under namespace std)
 * is used to name a variable that we are using.
 */

#include <iostream>

int main() {
    int cout;
    cout = 10;

    std::cout << "The value of cout is: " << cout << std::endl;

    return 0;
}
