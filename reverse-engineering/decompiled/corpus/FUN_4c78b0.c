/* Ghidra analysis pseudocode, not original source.
 * ev_d6cfc7f984a94bc477afc350e10de4c03e30e64e3e924293972bd20ad72e1aa6
 * Entry: 0x4c78b0; label: FUN_004c78b0
 */

undefined4 FUN_004c78b0(int param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (*(int *)(param_1 + 0x5064) != 0) {
    return 0;
  }
  iVar3 = FUN_006217e0();
  iVar4 = FUN_006217e0();
  iVar5 = 0;
  *(int *)(param_1 + 0x5064) = iVar4;
  if (0 < iVar4) {
    iVar4 = 0;
    do {
      FUN_006216f0(*(int *)(param_1 + 0x5060) + iVar4,0x10);
      FUN_00621900(iVar4 + 0x50 + *(int *)(param_1 + 0x5060));
      uVar1 = FUN_006218c0();
      *(undefined1 *)(iVar4 + 0x68 + *(int *)(param_1 + 0x5060)) = uVar1;
      if (iVar3 < 2) {
        *(undefined1 *)(iVar4 + 0x69 + *(int *)(param_1 + 0x5060)) = 0x62;
        *(undefined2 *)(iVar4 + 0x5c + *(int *)(param_1 + 0x5060)) = 0;
      }
      else {
        uVar1 = FUN_006218c0();
        *(undefined1 *)(iVar4 + 0x69 + *(int *)(param_1 + 0x5060)) = uVar1;
        uVar2 = FUN_00621860();
        *(undefined2 *)(iVar4 + 0x5c + *(int *)(param_1 + 0x5060)) = uVar2;
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0x94;
    } while (iVar5 < *(int *)(param_1 + 0x5064));
  }
  return 1;
}

