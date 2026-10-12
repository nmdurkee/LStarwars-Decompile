/* Ghidra analysis pseudocode, not original source.
 * ev_3de2cf7b8df928d729538760151df11dfb76bb55f80af3b4d4d063063f9aa6a2
 * Entry: 0x57ae80; label: FUN_0057ae80
 */

void FUN_0057ae80(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"level");
    if (iVar1 == 0) {
      *(uint *)(DAT_00951c4c + 0x50) = *(uint *)(DAT_00951c4c + 0x50) | 8;
      return;
    }
    *(uint *)(DAT_00951c4c + 0x50) = *(uint *)(DAT_00951c4c + 0x50) & 0xfffffff7;
  }
  return;
}

