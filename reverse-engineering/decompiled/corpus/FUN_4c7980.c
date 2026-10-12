/* Ghidra analysis pseudocode, not original source.
 * ev_d6cfc7f984a94bc477afc350e10de4c03e30e64e3e924293972bd20ad72e1aa6
 * Entry: 0x4c7980; label: FUN_004c7980
 */

void FUN_004c7980(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x5064)) {
    iVar3 = 0;
    do {
      uVar1 = FUN_0067c4f0(iVar3 + 0x10 + *(int *)(param_1 + 0x5060),2);
      *(undefined2 *)(iVar3 + 0x90 + *(int *)(param_1 + 0x5060)) = uVar1;
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x94;
    } while (iVar2 < *(int *)(param_1 + 0x5064));
  }
  return;
}

