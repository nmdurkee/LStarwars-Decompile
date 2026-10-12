/* Ghidra analysis pseudocode, not original source.
 * ev_074dd20869da91b1b05b19bd1efa0509a9d09e9660d7c7c0c7ca47d053bd121c
 * Entry: 0x4ce590; label: FUN_004ce590
 */

void FUN_004ce590(int param_1)

{
  undefined2 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  
  if ((*(int *)(param_1 + 0x4680) != 0) && (iVar4 = 0, 0 < *(int *)(PTR_DAT_00802c54 + 0x4684))) {
    puVar2 = (undefined1 *)(*(int *)(param_1 + 0x4680) + 0x4e);
    do {
      puVar2[1] = 0;
      *puVar2 = 1;
      puVar1 = (undefined2 *)(puVar2 + 0x26);
      iVar3 = 2;
      do {
        puVar1[2] = 0;
        *puVar1 = 0;
        puVar1 = puVar1 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      iVar4 = iVar4 + 1;
      puVar2 = puVar2 + 0xfc;
    } while (iVar4 < *(int *)(PTR_DAT_00802c54 + 0x4684));
  }
  return;
}

