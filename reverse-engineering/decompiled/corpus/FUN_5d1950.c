/* Ghidra analysis pseudocode, not original source.
 * ev_7d8e2999f2f8a3752dbaff0aac6d4e5497e59d04af9d3c1072d39c32106cee2b
 * Entry: 0x5d1950; label: FUN_005d1950
 */

void FUN_005d1950(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_1 != 0) {
    puVar1 = (undefined4 *)(param_1 + 0x28);
    iVar2 = 0x20;
    do {
      puVar1[0x20] = 0xffffffff;
      *puVar1 = 0xffffffff;
      puVar1 = puVar1 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    *(ushort *)(param_1 + 0x1b6) = *(ushort *)(param_1 + 0x1b6) & 0xfffe;
    *(undefined2 *)(param_1 + 0x1b4) = 0;
    *(undefined4 *)(param_1 + 0x128) = 0;
    *(undefined4 *)(param_1 + 300) = 0;
    *(undefined1 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x1b0) = 0;
    *(undefined2 *)(param_1 + 0x1b8) = 1;
  }
  return;
}

