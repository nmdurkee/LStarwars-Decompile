/* Ghidra pseudocode, not original source.
 * ev_65926145281a5167c739b8e4818ebc57eef5737a43bcd750b332aefff6a63eb2
 * Entry: 0x441020; label: FUN_00441020
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00441020(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                    undefined4 param_5)

{
  int iVar1;
  
  iVar1 = FUN_004678f0(**(undefined4 **)(param_3 + 0xd0),param_5);
  if (iVar1 != 0) {
    return (float10)1;
  }
  return (float10)0;
}

