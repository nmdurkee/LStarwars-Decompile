/* Ghidra analysis pseudocode, not original source.
 * ev_7afb5199773593ea980580d1c3e319946e9fb0192a7e36f1658c723ed800643d
 * Entry: 0x748430; label: FUN_00748430
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

