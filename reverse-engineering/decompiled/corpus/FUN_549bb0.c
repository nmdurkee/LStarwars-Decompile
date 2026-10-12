/* Ghidra analysis pseudocode, not original source.
 * ev_5937183d084659f3cd2a7a2e71fd5c7a233dbdbc790437ca60456b8bfcc76022
 * Entry: 0x549bb0; label: FUN_00549bb0
 */

void FUN_00549bb0(undefined *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_1 == (undefined *)0x0) {
    param_1 = PTR_DAT_008021b4;
  }
  *(undefined4 *)(param_1 + 0x1d4) = param_2;
  *(undefined4 *)(param_1 + 0x1d8) = param_3;
  *(undefined4 *)(param_1 + 0x1dc) = param_4;
  return;
}

