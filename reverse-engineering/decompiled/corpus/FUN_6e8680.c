/* Ghidra analysis pseudocode, not original source.
 * ev_eecf13eba2be62f78d2c2fac028dc2e8e01e29bc459957490b66b8c35bfd6df7
 * Entry: 0x6e8680; label: _fclose
 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _fclose
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release */

int __cdecl _fclose(FILE *_File)

{
  undefined4 *puVar1;
  int local_20;
  
  local_20 = -1;
  if (_File == (FILE *)0x0) {
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
    local_20 = -1;
  }
  else if ((_File->_flag & 0x40) == 0) {
    FUN_006e82ae(_File);
    local_20 = FUN_006e860e(_File);
    FUN_006e86f4();
  }
  else {
    _File->_flag = 0;
  }
  return local_20;
}

