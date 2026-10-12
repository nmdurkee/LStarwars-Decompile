/* Ghidra pseudocode, not original source.
 * ev_dff4057492b6a6aa6b557fdc6c810dc815e99554675c623c5eaef56b669992ab
 * Entry: 0x441ca0; label: FUN_00441ca0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00441ca0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                    int param_5)

{
  int iVar1;
  
  if ((param_5 != 0) || (param_5 = *(int *)(param_2 + 0xa4), param_5 != 0)) {
    iVar1 = FUN_005d6620(param_5 + 0x10,0,&DAT_00806680);
    if (iVar1 == 0) {
      return (float10)1;
    }
  }
  return (float10)0;
}

