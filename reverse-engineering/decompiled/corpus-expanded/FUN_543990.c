/* Ghidra pseudocode, not original source.
 * ev_c5dfc397922749c3a3d752de14fd9803558ba6adea5c02b0f86cafc5797b3dfb
 * Entry: 0x543990; label: FUN_00543990
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

