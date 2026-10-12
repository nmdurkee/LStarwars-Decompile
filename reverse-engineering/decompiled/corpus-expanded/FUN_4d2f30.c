/* Ghidra pseudocode, not original source.
 * ev_dd26b1472d11f86911997a5210ef83804c7265178bcab9b4c8b40141cd7b855f
 * Entry: 0x4d2f30; label: FUN_004d2f30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004d2f30(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((((param_1 != 0) && (*(int *)(param_1 + 4) != 0)) &&
      (iVar1 = *(int *)(*(int *)(param_1 + 4) + 0xcc4), iVar1 != 0)) &&
     (*(int *)(iVar1 + 0x84) != 0)) {
    if (4 < *(byte *)(iVar1 + 2)) {
      *(byte *)(iVar1 + 1) = *(byte *)(iVar1 + 1) | 0x10;
      return;
    }
    *(byte *)(iVar1 + 1) = *(byte *)(iVar1 + 1) | 8;
    *(undefined4 *)(iVar1 + 0x78) = *param_2;
    *(undefined4 *)(iVar1 + 0x7c) = param_2[1];
    uVar2 = param_2[2];
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 0x80) = uVar2;
    *(byte *)(iVar1 + 2) = *(byte *)(iVar1 + 2) + 1;
  }
  return;
}

