/* Ghidra analysis pseudocode, not original source.
 * ev_5e4e6a590c471e22d2a814bcf9fd12a554b410855fef8706c3d4a3775c91fbe8
 * Entry: 0x6e95f0; label: swap
 */

/* Library Function - Single Match
    _swap
   
   Library: Visual Studio 2005 Release */

void __cdecl swap(void)

{
  undefined1 uVar1;
  undefined1 *in_EAX;
  undefined1 *in_ECX;
  int in_EDX;
  
  if (in_EAX != in_ECX) {
    for (; in_EDX != 0; in_EDX = in_EDX + -1) {
      uVar1 = *in_EAX;
      *in_EAX = *in_ECX;
      *in_ECX = uVar1;
      in_EAX = in_EAX + 1;
      in_ECX = in_ECX + 1;
    }
  }
  return;
}

