/* Ghidra pseudocode, not original source.
 * ev_09868580522dc648f316624eb19739c7cb4fa50c58af47c6d946b46a2ca90732
 * Entry: 0x6e95f0; label: swap
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

