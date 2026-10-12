/* Ghidra pseudocode, not original source.
 * ev_20f8c411b4261e575accf39560ead20e25095f356798bee204490bf31a6f5756
 * Entry: 0x443bf0; label: FUN_00443bf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00443bf0(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (param_2 != 0) {
    iVar1 = FUN_004f8b10(param_2,"player1");
    if (iVar1 == 0) {
      return 1;
    }
  }
  return 0xffffffff;
}

