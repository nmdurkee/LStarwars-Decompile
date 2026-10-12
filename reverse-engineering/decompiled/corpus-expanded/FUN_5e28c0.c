/* Ghidra pseudocode, not original source.
 * ev_a87fd181e19a595ed696a9e48a76c3177ea695d31392ba84c3867c15109a72c3
 * Entry: 0x5e28c0; label: FUN_005e28c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e28c0(int *param_1)

{
  uint uVar1;
  
  DAT_00963f94 = *param_1 + 3U & 0xfffffffc;
  uVar1 = *param_1 + 3U & 0xfffffffc;
  *param_1 = uVar1 + 0x36b00;
  DAT_00963f88 = uVar1 + 0x36b00;
  uVar1 = *param_1 + 3U & 0xfffffffc;
  *param_1 = uVar1 + 2000;
  DAT_0096e568 = uVar1 + 2000;
  *param_1 = (*param_1 + 3U & 0xfffffffc) + 2000;
  return;
}

