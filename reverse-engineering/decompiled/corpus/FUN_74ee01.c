/* Ghidra analysis pseudocode, not original source.
 * ev_7c321bc51ff35622de6c5d479df857df6f5bf01a82339419049d6b39c5416ee3
 * Entry: 0x74ee01; label: write_string
 */

/* Library Function - Single Match
    _write_string
   
   Library: Visual Studio 2005 Release */

void __cdecl write_string(int param_1)

{
  int *in_EAX;
  int *piVar1;
  undefined2 *in_ECX;
  int unaff_EDI;
  
  if (((*(byte *)(unaff_EDI + 0xc) & 0x40) == 0) || (*(int *)(unaff_EDI + 8) != 0)) {
    while (0 < param_1) {
      param_1 = param_1 + -1;
      write_char(*in_ECX);
      in_ECX = in_ECX + 1;
      if (*in_EAX == -1) {
        piVar1 = (int *)FUN_006ead5f();
        if (*piVar1 != 0x2a) {
          return;
        }
        write_char(0x3f);
      }
    }
  }
  else {
    *in_EAX = *in_EAX + param_1;
  }
  return;
}

