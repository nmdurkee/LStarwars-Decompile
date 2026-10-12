/* Ghidra pseudocode, not original source.
 * ev_ec63a0996326cf703ee2b3a6fc0e0cae7d47cd208787877e90138bc554ba8dc2
 * Entry: 0x4bcf70; label: FUN_004bcf70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

