/* Ghidra pseudocode, not original source.
 * ev_a581b26cc49c1240ca9fc8201471236b1c0a2571dfff42173a4e3442f2e0fd27
 * Entry: 0x4329c0; label: FUN_004329c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004329c0(undefined4 *param_1)

{
  undefined4 uVar1;
  
  *param_1 = 0;
  param_1[1] = 0x3f800000;
  param_1[2] = 0;
  uVar1 = FUN_0054fa60();
  FUN_005b3690(param_1,param_1,uVar1);
  uVar1 = FUN_0054fa60();
  FUN_005b35a0(param_1,param_1,uVar1);
  return;
}

