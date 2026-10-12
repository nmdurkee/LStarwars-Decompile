/* Ghidra pseudocode, not original source.
 * ev_e99a99ac40850efc4319cfa1070f50eca7ba45fd57a73000da90cd7b4a6a9b3b
 * Entry: 0x645e70; label: FUN_00645e70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00645e70(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar4 = 0x90;
  iVar3 = DAT_02920970;
  do {
    if (*(short *)(iVar3 + iVar4) == 0x270e) {
      iVar1 = iVar4;
      iVar2 = iVar5;
      if (iVar5 < 7) {
        do {
          *(undefined2 *)(iVar1 + iVar3) = *(undefined2 *)(iVar1 + 2 + iVar3);
          *(undefined1 *)(DAT_02920970 + 0xa0 + iVar2) =
               *(undefined1 *)(DAT_02920970 + 0xa1 + iVar2);
          iVar1 = iVar1 + 2;
          iVar2 = iVar2 + 1;
          iVar3 = DAT_02920970;
        } while (iVar1 < 0x9e);
      }
      *(undefined2 *)(iVar3 + 0x9e) = 0xffff;
      *(undefined1 *)(DAT_02920970 + 0xa7) = 0xff;
      *(char *)(DAT_02920970 + 0xb0) = *(char *)(DAT_02920970 + 0xb0) + -1;
      iVar5 = iVar5 + -1;
      iVar4 = iVar4 + -2;
      iVar3 = DAT_02920970;
    }
    iVar5 = iVar5 + 1;
    iVar4 = iVar4 + 2;
  } while (iVar5 < 8);
  DAT_0291f66c = 0;
  iVar3 = *(int *)(param_1 + 0x40);
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    FUN_006279f0(param_1);
  }
  if (*(code **)(param_1 + 0x30) != (code *)0x0) {
    (**(code **)(param_1 + 0x30))(param_1,iVar3);
  }
  return;
}

