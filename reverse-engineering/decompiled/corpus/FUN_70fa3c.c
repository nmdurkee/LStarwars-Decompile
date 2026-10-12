/* Ghidra analysis pseudocode, not original source.
 * ev_9b16042430a980d3b9c0d140a3205847c036a5269f23ab8e6a7213cf146d66e1
 * Entry: 0x70fa3c; label: _ungetc
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

