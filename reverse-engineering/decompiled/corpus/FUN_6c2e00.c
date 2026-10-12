/* Ghidra analysis pseudocode, not original source.
 * ev_51d776bbf7e198208a4486308eec4a97f7acd5ccc3951e1c43c2ae0a52a9ca8f
 * Entry: 0x6c2e00; label: FUN_006c2e00
 */

void FUN_006c2e00(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x38);
  *(uint *)(param_1 + 0x38) = (~uVar1 & 4 ^ uVar1) & 4 ^ uVar1;
  *(byte *)(param_2 + 0x11) = *(byte *)(param_2 + 0x11) ^ 1;
  if ((*(byte *)(param_1 + 0x38) & 4) != 0) {
    FUN_006279f0(param_1);
    DAT_02973a80 = param_1;
    return;
  }
  FUN_006279f0(param_1);
  FUN_00624220(param_1);
  if (param_1 == DAT_02973a7c) {
    DAT_02973a7c = 0;
  }
  DAT_02973a80 = 0;
  return;
}

