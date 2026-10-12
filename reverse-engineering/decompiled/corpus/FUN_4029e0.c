/* Ghidra analysis pseudocode, not original source.
 * ev_4eb19e57a9d3b9beba017312b3b21652588e9c732adfcebbbddaeb757a53089f
 * Entry: 0x4029e0; label: FUN_004029e0
 */

void FUN_004029e0(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x509c)) {
    iVar3 = 0;
    do {
      uVar1 = FUN_0067c4f0(iVar3 + 0x1c + *(int *)(param_1 + 0x5098),4);
      *(undefined2 *)(iVar3 + 0x60 + *(int *)(param_1 + 0x5098)) = uVar1;
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x74;
    } while (iVar2 < *(int *)(param_1 + 0x509c));
  }
  return;
}

