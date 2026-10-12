/* Ghidra pseudocode, not original source.
 * ev_a37d45c54d4922ce68f22ac83ec0c43bcdcd42a61686a123418b5247712e53b1
 * Entry: 0x59cc90; label: FUN_0059cc90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0059cc90(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = FUN_004f1ff0();
  if (iVar1 != 0) {
    uVar2 = FUN_00552670(param_1,param_2,iVar1 + 1);
    FUN_004f1f10(uVar2);
  }
  return uVar2;
}

