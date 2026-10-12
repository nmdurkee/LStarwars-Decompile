/* Ghidra pseudocode, not original source.
 * ev_dff4057492b6a6aa6b557fdc6c810dc815e99554675c623c5eaef56b669992ab
 * Entry: 0x441e60; label: FUN_00441e60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00441e60(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if ((((param_3 != 0) && (iVar1 = *(int *)(param_3 + 0xe4), iVar1 != 0)) &&
      (iVar2 = *(int *)(param_3 + 0xd0), iVar2 != 0)) &&
     ((*(uint *)(iVar2 + 0x1f0) & *(uint *)(iVar1 + 0x1e8)) != 0 ||
      (*(uint *)(iVar2 + 500) & *(uint *)(iVar1 + 0x1ec)) != 0)) {
    return (float10)1;
  }
  return (float10)0;
}

