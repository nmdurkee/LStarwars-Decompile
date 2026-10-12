/* Ghidra pseudocode, not original source.
 * ev_e99a99ac40850efc4319cfa1070f50eca7ba45fd57a73000da90cd7b4a6a9b3b
 * Entry: 0x645dc0; label: FUN_00645dc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00645dc0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 + 0xc);
  if (iVar2 < 7) {
    iVar1 = iVar2 * 2 + 0x90;
    do {
      *(undefined2 *)(iVar1 + DAT_02920970) = *(undefined2 *)(iVar1 + 2 + DAT_02920970);
      *(undefined1 *)(DAT_02920970 + 0xa0 + iVar2) = *(undefined1 *)(DAT_02920970 + 0xa1 + iVar2);
      iVar1 = iVar1 + 2;
      iVar2 = iVar2 + 1;
    } while (iVar1 < 0x9e);
  }
  *(undefined2 *)(DAT_02920970 + 0x9e) = 0xffff;
  *(undefined1 *)(DAT_02920970 + 0xa7) = 0xff;
  *(char *)(DAT_02920970 + 0xb0) = *(char *)(DAT_02920970 + 0xb0) + -1;
  DAT_0291f66c = DAT_0291f66c + -1;
  iVar2 = *(int *)(param_1 + 0x40);
  iVar1 = 0;
  if (iVar2 != 0) {
    FUN_006279f0(param_1);
    iVar1 = iVar2;
  }
  if (*(code **)(param_1 + 0x30) != (code *)0x0) {
    (**(code **)(param_1 + 0x30))(param_1,iVar1);
  }
  return;
}

