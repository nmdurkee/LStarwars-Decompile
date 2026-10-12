/* Ghidra pseudocode, not original source.
 * ev_0733f146760cc31006e6190a74f2cd28d34a83dcf7f13916827ecd624512e4e0
 * Entry: 0x5f26d0; label: FUN_005f26d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f26d0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 *in_ECX;
  
  if (param_1 != 0) {
    FUN_005e7f40(param_1,param_2,param_3);
    FUN_005e7f40(param_1,param_2,param_3);
    *(undefined4 *)(in_ECX + 0x158) = 0x3e99999a;
    *(undefined1 **)(in_ECX + 0x150) = in_ECX + 0x10;
    *(undefined1 **)(in_ECX + 0x154) = in_ECX + 0xb0;
    *(undefined4 *)(in_ECX + 0x15c) = 0xbf800000;
    *in_ECX = 1;
    in_ECX[1] = 1;
  }
  return;
}

