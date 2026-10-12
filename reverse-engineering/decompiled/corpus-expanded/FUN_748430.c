/* Ghidra pseudocode, not original source.
 * ev_bef7beff20bbab7c70650c6f9f545113d8e67786c96c5ee03f6ff15c7c5049ec
 * Entry: 0x748430; label: FUN_00748430
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00748430(undefined4 param_1,undefined1 param_2)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  uVar1 = FUN_006ea018(param_1);
  *in_ECX = uVar1;
  in_ECX[2] = param_1;
  *(undefined1 *)(in_ECX + 3) = param_2;
  in_ECX[1] = 0;
  return;
}

