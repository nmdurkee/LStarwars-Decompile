/* Ghidra analysis pseudocode, not original source.
 * ev_d9778a7e5954a243ecb5357ce6ca10d0e931dd6eaae906e14f50961a2e2268e2
 * Entry: 0x4bcf70; label: FUN_004bcf70
 */

void FUN_004bcf70(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x50b4)) {
    iVar3 = 0;
    do {
      uVar1 = FUN_0067c4f0(*(int *)(param_1 + 0x50b0) + iVar3,5);
      *(undefined2 *)(iVar3 + 0x9c + *(int *)(param_1 + 0x50b0)) = uVar1;
      uVar1 = FUN_0067c4f0(iVar3 + 0x40 + *(int *)(param_1 + 0x50b0),6);
      *(undefined2 *)(iVar3 + 0x9e + *(int *)(param_1 + 0x50b0)) = uVar1;
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0xc0;
    } while (iVar2 < *(int *)(param_1 + 0x50b4));
  }
  return;
}

