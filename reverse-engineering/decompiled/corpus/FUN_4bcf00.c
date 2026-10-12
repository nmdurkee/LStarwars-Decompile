/* Ghidra analysis pseudocode, not original source.
 * ev_d9778a7e5954a243ecb5357ce6ca10d0e931dd6eaae906e14f50961a2e2268e2
 * Entry: 0x4bcf00; label: FUN_004bcf00
 */

undefined4 FUN_004bcf00(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x50b4) != 0) {
    return 0;
  }
  FUN_006217e0();
  iVar2 = FUN_006217e0();
  iVar3 = 0;
  *(int *)(param_1 + 0x50b4) = iVar2;
  if (0 < iVar2) {
    iVar2 = *(int *)(param_1 + 0x50b0) + 0x90;
    do {
      FUN_006216f0(iVar2 + -0x10,0x10);
      FUN_00621900(iVar2);
      uVar1 = FUN_00621860();
      *(undefined2 *)(iVar2 + 0x10) = uVar1;
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0xc0;
    } while (iVar3 < *(int *)(param_1 + 0x50b4));
  }
  return 1;
}

