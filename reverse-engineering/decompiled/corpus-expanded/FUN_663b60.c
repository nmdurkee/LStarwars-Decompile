/* Ghidra pseudocode, not original source.
 * ev_277e9292cb53e7665c3bde753cc9c2d26e6793a349ba78c22fc7a8e115ea3a32
 * Entry: 0x663b60; label: FUN_00663b60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00663b60(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_00810ad8;
  if (*(int *)(param_2 + 0xc) != (int)DAT_0292118b) {
    DAT_0292118b = *(char *)(param_2 + 0xc);
    iVar2 = 1;
    DAT_00810ad8 = -1;
    iVar1 = DAT_00810ad8;
    if (1 < DAT_02962098) {
      do {
        if ((*(int *)(DAT_0296209c + iVar2 * 4) != 0) &&
           (iVar1 = iVar2, *(char *)(*(int *)(DAT_0296209c + iVar2 * 4) + 0x10) == DAT_0292118b))
        break;
        iVar2 = iVar2 + 1;
        iVar1 = DAT_00810ad8;
      } while (iVar2 < DAT_02962098);
    }
  }
  DAT_00810ad8 = iVar1;
  iVar1 = *(int *)(param_1 + 0x40);
  iVar2 = 0;
  if (iVar1 != 0) {
    FUN_006279f0(param_1);
    iVar2 = iVar1;
  }
  if (*(code **)(param_1 + 0x30) != (code *)0x0) {
    (**(code **)(param_1 + 0x30))(param_1,iVar2);
  }
  return;
}

