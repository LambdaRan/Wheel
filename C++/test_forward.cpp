#include <cassert>
#include <iostream>
#include <string>
#include <type_traits>
// #include <utility>

using namespace std;

template <typename T,
          typename enable_if<is_same<T, string>::value>::type* = nullptr>
void bar(T& value) {
    cout << "bar gets string&" << endl;
}

template <typename T,
          typename enable_if<is_same<T, const string>::value>::type* = nullptr>
void bar(T& value) {
    cout << "bar gets const string&" << endl;
}

void bar(string&& value) noexcept {
    cout << "bar gets string&&" << endl;
}

void bar(const string&& value) {
    cout << "bar gets const string&&" << endl;
}

template <typename T>
void foo(T&& value) {
    if (is_same<T, string>::value) {
        cout << "T is string" << endl;
    } else if (is_same<T, const string>::value) {
        cout << "T is const string" << endl;
    } else if (is_same<T, string&>::value) {
        cout << "T is string&" << endl;
    } else if (is_same<T, const string&>::value) {
        cout << "T is const string&" << endl;
    } else if (is_same<T, string&&>::value) {
        cout << "T is string&&" << endl;
    } else if (is_same<T, const string&&>::value) {
        cout << "T is const string&&" << endl;
    } else {
        assert(false);
    }

    if (is_same<decltype(value), string>::value) {
        cout << "value is string" << endl;
    } else if (is_same<decltype(value), const string>::value) {
        cout << "value is const string" << endl;
    } else if (is_same<decltype(value), string&>::value) {
        cout << "value is string&" << endl;
    } else if (is_same<decltype(value), const string&>::value) {
        cout << "value is const string&" << endl;
    } else if (is_same<decltype(value), string&&>::value) {
        cout << "value is string&&" << endl;
    } else if (is_same<decltype(value), const string&&>::value) {
        cout << "value is const string&&" << endl;
    } else {
        assert(false);
    }

    bar(forward<T>(value));
}

int main() {
    string s1;
    const string s2;
    string& s3 = s1;
    const string& s4 = s2;

    cout << "1" << endl;
    cout << "foo gets string" << endl;
    foo(s1);
    cout << endl;

    cout << "2" << endl;
    cout << "foo gets const string" << endl;
    foo(s2);
    cout << endl;

    cout << "3" << endl;
    cout << "foo gets string&" << endl;
    foo(s3);
    cout << endl;

    cout << "4" << endl;
    cout << "foo gets const string&" << endl;
    foo(s4);
    cout << endl;

    cout << "5" << endl;
    cout << "foo gets string&&" << endl;
    foo(move(s1));
    cout << endl;

    cout << "6" << endl;
    cout << "foo gets const string&&" << endl;
    foo(move(s2));
    cout << endl;
}