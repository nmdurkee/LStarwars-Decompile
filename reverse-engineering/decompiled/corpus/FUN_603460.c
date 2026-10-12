/* Ghidra analysis pseudocode, not original source.
 * ev_f0df202184b9720525c4247b3bb30bed7ac4e9212116aa7e13e8156c499e8a94
 * Entry: 0x603460; label: FUN_00603460
 */

void FUN_00603460(undefined1 *param_1,undefined4 param_2)

{
  *param_1 = 0x80;
  *(undefined4 *)(param_1 + 4) = param_2;
  param_1[1] = 3;
  return;
}

