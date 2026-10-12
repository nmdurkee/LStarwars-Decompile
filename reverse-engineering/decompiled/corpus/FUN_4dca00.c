/* Ghidra analysis pseudocode, not original source.
 * ev_d881831d71d8ed35fa38d5b5eaee7ca2bcae4cde952964886fd1c7ddf43d442a
 * Entry: 0x4dca00; label: FUN_004dca00
 */

void FUN_004dca00(int param_1,undefined2 *param_2,undefined2 *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  piVar1 = &DAT_00882420;
  while ((param_1 == 0 || (*piVar1 != param_1))) {
    piVar1 = piVar1 + 4;
    iVar3 = iVar3 + 1;
    if (0x88247f < (int)piVar1) {
      return;
    }
  }
  if (DAT_008824a7 == '\0') {
    *param_2 = 0;
    *param_3 = *(undefined2 *)(&DAT_00882424 + iVar3 * 0x10);
    return;
  }
  iVar2 = (int)DAT_008824a7;
  if (4 < iVar2) {
    iVar2 = 5;
  }
  iVar2 = iVar2 + iVar3 * 8;
  *param_2 = *(undefined2 *)((int)&DAT_00882420 + iVar2 * 2 + 2);
  *param_3 = *(undefined2 *)(&DAT_00882424 + iVar2 * 2);
  return;
}

