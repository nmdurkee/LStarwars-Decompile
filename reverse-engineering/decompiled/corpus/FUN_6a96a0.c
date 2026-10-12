/* Ghidra analysis pseudocode, not original source.
 * ev_411dd83ba30300d5831318e5e0d5db9024421d970d639e52cbaaaf14146f88dc
 * Entry: 0x6a96a0; label: FUN_006a96a0
 */

undefined4 FUN_006a96a0(int param_1,int param_2,undefined4 param_3)

{
  if (-1 < param_2) {
    if (param_2 < *(int *)(*(int *)(param_1 + 0xc) + 4)) {
      FUN_006a3570(param_3,*(undefined4 *)(*(int *)(param_1 + 0x14) + param_2 * 4),
                   *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xc) + 8) + param_2 * 4));
      return *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xc) + 8) + param_2 * 4);
    }
  }
  return 0;
}

