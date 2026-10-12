/* Ghidra analysis pseudocode, not original source.
 * ev_f0df202184b9720525c4247b3bb30bed7ac4e9212116aa7e13e8156c499e8a94
 * Entry: 0x603530; label: FUN_00603530
 */

void FUN_00603530(int param_1,int param_2)

{
  uint *puVar1;
  
  *DAT_009736e0 = *DAT_009736e0 + 0xf & 0xfffffff0;
  puVar1 = DAT_009736e0;
  *(uint *)(*(int *)(param_1 + 0x14) + 4) = *DAT_009736e0;
  *(uint *)(param_1 + 0x24) = *puVar1;
  *puVar1 = *puVar1 + param_2 * 0x10;
  *(undefined1 *)*puVar1 = 0x8d;
  *(undefined1 *)(*puVar1 + 1) = 1;
  *(int *)(*puVar1 + 4) = *(int *)(param_1 + 0x18) + 0x10;
  *(uint *)(param_1 + 0x14) = *puVar1;
  *puVar1 = *puVar1 + 0x10;
  return;
}

