/* Ghidra pseudocode, not original source.
 * ev_65926145281a5167c739b8e4818ebc57eef5737a43bcd750b332aefff6a63eb2
 * Entry: 0x440c00; label: FUN_00440c00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00440c00(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (((param_2 != 0) && (param_1 != 0)) && (DAT_0093b280 != 0)) {
    uVar1 = FUN_0055bc20(param_2);
    return uVar1;
  }
  return 0xffffffff;
}

