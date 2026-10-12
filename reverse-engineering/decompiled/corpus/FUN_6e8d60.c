/* Ghidra analysis pseudocode, not original source.
 * ev_5e4e6a590c471e22d2a814bcf9fd12a554b410855fef8706c3d4a3775c91fbe8
 * Entry: 0x6e8d60; label: _fwrite
 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _fwrite
   
   Library: Visual Studio 2008 Release */

size_t __cdecl _fwrite(void *_Str,size_t _Size,size_t _Count,FILE *_File)

{
  undefined4 *puVar1;
  size_t sVar2;
  
  if ((_Size != 0) && (_Count != 0)) {
    if (_File != (FILE *)0x0) {
      FUN_006e82ae(_File);
      sVar2 = FUN_006e8c01(_Str,_Size,_Count,_File);
      FUN_006e8dd8();
      return sVar2;
    }
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
  }
  return 0;
}

