/* Ghidra analysis pseudocode, not original source.
 * ev_5e8001be3994efa046f160ea8bbb155dc91a9aa9b9ccef45a0e0570780a0cbe5
 * Entry: 0x543990; label: FUN_00543990
 */

int FUN_00543990(void)

{
  char *_Filename;
  FILE *_File;
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = 0;
  do {
    _Filename = (char *)FUN_005436e0(iVar1);
    _File = _fopen(_Filename,"rb");
    if (_File != (FILE *)0x0) {
      iVar2 = iVar2 + 1;
      _fclose(_File);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 6);
  return iVar2;
}

