/* Ghidra pseudocode, not original source.
 * ev_167fb1af16662301ac7ec00e42056ea51ba92ee67c43a8d5117ba6e42cb74a01
 * Entry: 0x6f0299; label: __mtterm
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

