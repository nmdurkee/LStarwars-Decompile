/* Ghidra analysis pseudocode, not original source.
 * ev_2b6ca283a8ac7011eb105309a135b5adaaf9bfbb0074228736b4018ed27e76f8
 * Entry: 0x599a10; label: FUN_00599a10
 */

void FUN_00599a10(uint *param_1)

{
  DAT_00956048 = *param_1 + 3 & 0xfffffffc;
  *param_1 = DAT_00956048;
  *param_1 = *param_1 + DAT_0093b278 * 4;
  return;
}

