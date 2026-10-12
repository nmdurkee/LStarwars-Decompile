/* Ghidra pseudocode, not original source.
 * ev_dff4057492b6a6aa6b557fdc6c810dc815e99554675c623c5eaef56b669992ab
 * Entry: 0x441ea0; label: FUN_00441ea0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00441ea0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if (((param_3 != 0) && (iVar1 = *(int *)(param_3 + 0xd0), iVar1 != 0)) &&
     (*(int *)(iVar1 + 0x1f0) != 0 || *(int *)(iVar1 + 500) != 0)) {
    return (float10)1;
  }
  return (float10)0;
}

