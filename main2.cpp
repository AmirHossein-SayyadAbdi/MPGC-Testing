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
    gc_ptr<gc_array<int>> arr = persistent_roots().lookup<gc_array<int>>("51425");
    cout<<"This is process No.2\n"<<"array[0] = "<<arr[0]<<"\n"<<"array[1] = "<<arr[1]<<"\n";
    cout<<"Restore of array successfull!\n";
    return 0;
}

