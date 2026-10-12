/* Ghidra pseudocode, not original source.
 * ev_80517fb4f192ecd2851e0fd4e2a7dbbf5e68bec5ed1b7e7e17e8e9bcd800f2e9
 * Entry: 0x748b90; label: FUN_00748b90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00748b90(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_007e9300;
  in_ECX[0x81] = 0;
  in_ECX[0x82] = 0;
  FUN_00746db0(param_1,param_2);
  FUN_00748460(param_1,0x2d000);
  FUN_00740f50(param_1,0x32000);
  *(undefined1 *)(in_ECX + 1) = 0;
  return;
}

