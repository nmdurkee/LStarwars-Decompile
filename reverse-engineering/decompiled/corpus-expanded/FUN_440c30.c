/* Ghidra pseudocode, not original source.
 * ev_65926145281a5167c739b8e4818ebc57eef5737a43bcd750b332aefff6a63eb2
 * Entry: 0x440c30; label: FUN_00440c30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00440c30(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                    int param_5)

{
  int iVar1;
  
  if (((param_5 != -1) && (param_3 != 0)) && (*(undefined4 **)(param_3 + 0xd0) != (undefined4 *)0x0)
     ) {
    iVar1 = FUN_0055bc80(**(undefined4 **)(param_3 + 0xd0),param_5);
    if (iVar1 != 0) {
      return (float10)1;
    }
  }
  return (float10)0;
}

