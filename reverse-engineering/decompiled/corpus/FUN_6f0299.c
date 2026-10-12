/* Ghidra analysis pseudocode, not original source.
 * ev_526838828e273a637259fe0c0b8910ed57fcbb113f7ca97b4fe0b36ecb2b0c42
 * Entry: 0x6f0299; label: __mtterm
 */

/* Library Function - Single Match
    __mtterm
   
   Library: Visual Studio 2005 Release */

void __cdecl __mtterm(void)

{
  code *pcVar1;
  
  if (DAT_00829ab4 != -1) {
    pcVar1 = (code *)FUN_006f01bc(DAT_0297c544,DAT_00829ab4);
    (*pcVar1)();
    DAT_00829ab4 = -1;
  }
  if (DAT_00829ab8 != 0xffffffff) {
    TlsFree(DAT_00829ab8);
    DAT_00829ab8 = 0xffffffff;
  }
  __mtdeletelocks();
  return;
}

