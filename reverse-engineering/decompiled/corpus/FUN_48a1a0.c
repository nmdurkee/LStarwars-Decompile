/* Ghidra analysis pseudocode, not original source.
 * ev_8191aeb1a3da19da8f7480131ae46b5e7aabe132901fddc0002d6d5d4eb98622
 * Entry: 0x48a1a0; label: FUN_0048a1a0
 */

void FUN_0048a1a0(uint *param_1)

{
  DAT_0087b2cc = *param_1 + 0xf & 0xfffffff0;
  *param_1 = DAT_0087b2cc;
  *param_1 = *param_1 + 0x229e0;
  return;
}

