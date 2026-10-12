/* Ghidra analysis pseudocode, not original source.
 * ev_d9778a7e5954a243ecb5357ce6ca10d0e931dd6eaae906e14f50961a2e2268e2
 * Entry: 0x4c0130; label: FUN_004c0130
 */

undefined4 FUN_004c0130(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x5094) != 0) {
    return 0;
  }
  iVar2 = FUN_006217e0();
  iVar3 = FUN_006217e0();
  iVar4 = 0;
  *(int *)(param_1 + 0x5094) = iVar3;
  if (0 < iVar3) {
    iVar3 = 0;
    do {
      FUN_006216f0(*(int *)(param_1 + 0x5090) + iVar3,0x10);
      FUN_00621900(*(int *)(param_1 + 0x5090) + 0x10 + iVar3);
      if (iVar2 < 2) {
        uVar1 = 0;
        *(undefined2 *)(*(int *)(param_1 + 0x5090) + 0x36 + iVar3) = 0;
      }
      else {
        uVar1 = FUN_00621860();
        *(undefined2 *)(*(int *)(param_1 + 0x5090) + 0x36 + iVar3) = uVar1;
        uVar1 = FUN_00621860();
      }
      *(undefined2 *)(*(int *)(param_1 + 0x5090) + 0x38 + iVar3) = uVar1;
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x54;
    } while (iVar4 < *(int *)(param_1 + 0x5094));
  }
  return 1;
}

