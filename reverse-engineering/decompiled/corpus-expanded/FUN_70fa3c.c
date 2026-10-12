/* Ghidra pseudocode, not original source.
 * ev_b8791f68223111733f427ad79b5f4124aba9c2a357a1adb651c9b460912be2bf
 * Entry: 0x70fa3c; label: _ungetc
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _ungetc
   
   Library: Visual Studio 2005 Release */

int __cdecl _ungetc(int _Ch,FILE *_File)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (_File == (FILE *)0x0) {
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
    iVar2 = -1;
  }
  else {
    FUN_006e82ae(_File);
    iVar2 = __ungetc_nolock(_Ch,_File);
    FUN_0070faa4();
  }
  return iVar2;
}

