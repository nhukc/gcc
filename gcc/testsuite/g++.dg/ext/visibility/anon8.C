// PR c++/34213
// { dg-do compile }

template <void (*fn) ()>
void call ()			// { dg-message "note" "" { target c++14_down } }
{
  fn ();
}

namespace
{
  struct B1
  {
    static void fn1 () {}
    static void fn4 ();
  };
  void fn3 () {}
  void B1::fn4 () {}
  static void fn5 () {}
}

int main ()
{
  struct B2
  {
    static void fn2 () {}
  };
  call<&B1::fn1> ();
  call<&B2::fn2> ();	// { dg-error "linkage|no matching" "PR83258" { target c++14_down } }
  call<&fn3> ();
  call<&B1::fn4> ();
  call<&fn5> ();	// { dg-error "linkage|no matching" "" { target { ! c++11 } } }
}
