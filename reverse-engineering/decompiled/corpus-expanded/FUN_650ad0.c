/* Ghidra pseudocode, not original source.
 * ev_73d54611eb9c539f60191f4cc2589103d1525e4e98579cab30a489e0835b3840
 * Entry: 0x650ad0; label: FUN_00650ad0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00650ad0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (int)(short)(&DAT_02920d88)[param_1 * 4];
  iVar2 = *(short *)(&DAT_02920d8a + param_1 * 8) + iVar1;
  if (iVar1 < iVar2) {
    while (*(short *)(&DAT_02921260 + iVar1 * 2) != param_2) {
      iVar1 = iVar1 + 1;
      if (iVar2 <= iVar1) {
        return;
      }
    }
    if (iVar1 != -1) {
      FUN_004ef660(&DAT_02921260 + iVar1 * 2,&DAT_02921262 + iVar1 * 2,
                   (DAT_02962020 - iVar1) * 2 + -2);
      DAT_02962020 = DAT_02962020 + -1;
      *(short *)(&DAT_02920d8a + param_1 * 8) = *(short *)(&DAT_02920d8a + param_1 * 8) + -1;
      *(undefined2 *)(&DAT_02920d8c + param_1 * 8) = 0;
    }
  }
  return;
}

