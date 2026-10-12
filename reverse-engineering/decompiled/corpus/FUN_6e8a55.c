/* Ghidra analysis pseudocode, not original source.
 * ev_eecf13eba2be62f78d2c2fac028dc2e8e01e29bc459957490b66b8c35bfd6df7
 * Entry: 0x6e8a55; label: _fseek
 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _fseek
   
   Library: Visual Studio 2005 Release */

int __cdecl _fseek(FILE *_File,long _Offset,int _Origin)

{
  undefined4 *puVar1;
  int iVar2;
  
  if ((_File == (FILE *)0x0) || (((_Origin != 0 && (_Origin != 1)) && (_Origin != 2)))) {
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
    iVar2 = -1;
  }
  else {
    FUN_006e82ae(_File);
    iVar2 = __fseek_nolock(_File,_Offset,_Origin);
    FUN_006e8ad0();
  }
  return iVar2;
}

