/* Ghidra pseudocode, not original source.
 * ev_49c5de326560f696c25fe7c48a171edc0aeca1661cc4385396c06e099fff9572
 * Entry: 0x443b90; label: FUN_00443b90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00443b90(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    uVar1 = FUN_0059f7a0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2acc),param_2);
    return uVar1;
  }
  return 0;
}

