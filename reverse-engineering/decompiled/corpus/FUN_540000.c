/* Ghidra analysis pseudocode, not original source.
 * ev_3c859e02b972a8e60701cf54913e5d4895bfb87c225b3b379a359b744e8ff688
 * Entry: 0x540000; label: FUN_00540000
 */

void FUN_00540000(int param_1)

{
  uint *puVar1;
  int iVar2;
  
  iVar2 = FUN_004f7fb0(param_1);
  while (iVar2 != 0) {
    iVar2 = FUN_004f29a0(*(undefined4 *)(param_1 + 0x510));
    puVar1 = (uint *)(DAT_029838fc + 0xdc + ((int)(iVar2 + (iVar2 >> 0x1f & 0x1fU)) >> 5) * 4);
    *puVar1 = *puVar1 | 1 << ((byte)iVar2 & 0x1f);
    iVar2 = FUN_004f7fb0(param_1);
  }
  return;
}

