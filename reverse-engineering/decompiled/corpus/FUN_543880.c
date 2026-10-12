/* Ghidra analysis pseudocode, not original source.
 * ev_5e8001be3994efa046f160ea8bbb155dc91a9aa9b9ccef45a0e0570780a0cbe5
 * Entry: 0x543880; label: FUN_00543880
 */

int FUN_00543880(void)

{
  char *_Filename;
  FILE *_File;
  int iVar1;
  int iVar2;
  
  DAT_00924810 = 0;
  iVar1 = 0;
  iVar2 = 0;
  do {
    (&DAT_02989540)[iVar2] = 0;
    (&DAT_02989320)[iVar2] = 0;
    _Filename = (char *)FUN_005436e0(iVar2);
    _File = _fopen(_Filename,"rb");
    if (_File != (FILE *)0x0) {
      iVar1 = iVar1 + 1;
      (&DAT_02989540)[iVar2] = 1;
      _fseek(_File,-4,2);
      FUN_006e89b3(&DAT_02989320 + iVar2,4,1,_File);
      DAT_00924810 = 1;
      _fclose(_File);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 6);
  return iVar1;
}

