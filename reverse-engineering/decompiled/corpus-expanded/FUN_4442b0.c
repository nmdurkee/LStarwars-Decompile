/* Ghidra pseudocode, not original source.
 * ev_20f8c411b4261e575accf39560ead20e25095f356798bee204490bf31a6f5756
 * Entry: 0x4442b0; label: FUN_004442b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_004442b0(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5
            ,int param_6)

{
  int iVar1;
  int iVar2;
  
  if (((param_6 != 0) && (iVar1 = **(int **)(param_3 + 0xd0), iVar1 != 0)) &&
     (iVar2 = *(int *)(iVar1 + 0xea4), iVar2 != 0)) {
    *(undefined4 *)(iVar1 + 0xea4) = 0;
    *(undefined4 *)(iVar2 + 0xea4) = 0;
  }
  return 1;
}

