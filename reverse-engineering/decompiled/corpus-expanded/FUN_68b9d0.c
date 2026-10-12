/* Ghidra pseudocode, not original source.
 * ev_119981038e8c19adfdb272c0e357e55b3a12ebc602b993d3e023990f2be0b94d
 * Entry: 0x68b9d0; label: FUN_0068b9d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068b9d0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < DAT_02962a08) {
    iVar1 = 0;
    iVar3 = DAT_02962a14;
    do {
      if (*(int *)(iVar1 + 4 + iVar3) != 0) {
        *(undefined4 *)(iVar1 + 0x38 + iVar3) = _DAT_00810a98;
        *(undefined4 *)(iVar1 + 0x3c + DAT_02962a14) = _DAT_00810a9c;
        iVar3 = DAT_02962a14;
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x50;
    } while (iVar2 < DAT_02962a08);
  }
  FUN_00689f70();
  iVar2 = *(int *)(param_1 + 0x40);
  iVar3 = 0;
  if (iVar2 != 0) {
    FUN_006279f0(param_1);
    iVar3 = iVar2;
  }
  if (*(code **)(param_1 + 0x30) != (code *)0x0) {
    (**(code **)(param_1 + 0x30))(param_1,iVar3);
  }
  return;
}

