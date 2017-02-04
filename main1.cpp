#include <iostream>
#include <mpgc/gc.h>
#include <mpgc/gc_string.h>

using namespace std;
using namespace mpgc;

// Not used yet :-)
class SomeText : public gc_allocated {
public:
  gc_string text;

  SomeText(gc_token &gc, string pp = "Hello World!")
    : gc_allocated{gc},
      text(pp)
  {}

  static const auto &descriptor() {
    static gc_descriptor d =
      GC_DESC(SomeText)
      .WITH_FIELD(&SomeText::text);
    return d;
  }
};

int main()
{
    gc_ptr<gc_array<int>> arr = make_gc<gc_array<int>>(2);
    arr[0] = 4774;
    arr[1] = 627726;
    persistent_roots().store("51425", arr);
    cout<<"This is process No.1\n"<<"\nStore of array successfull!\n";
    return 0;
}

