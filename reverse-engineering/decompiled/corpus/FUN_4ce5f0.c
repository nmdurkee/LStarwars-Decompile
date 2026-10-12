/* Ghidra analysis pseudocode, not original source.
 * ev_074dd20869da91b1b05b19bd1efa0509a9d09e9660d7c7c0c7ca47d053bd121c
 * Entry: 0x4ce5f0; label: FUN_004ce5f0
 */

void FUN_004ce5f0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x4680) != 0) && (iVar2 = 0, 0 < *(int *)(PTR_DAT_00802c54 + 0x4684))) {
    puVar1 = (undefined4 *)(*(int *)(param_1 + 0x4680) + 0x78);
    do {
      *puVar1 = 0;
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 0x3f;
    } while (iVar2 < *(int *)(PTR_DAT_00802c54 + 0x4684));
  }
  return;
}

