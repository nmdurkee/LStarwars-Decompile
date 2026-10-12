/* Ghidra pseudocode, not original source.
 * ev_dff4057492b6a6aa6b557fdc6c810dc815e99554675c623c5eaef56b669992ab
 * Entry: 0x441d80; label: FUN_00441d80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00441d80(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                    int param_5)

{
  float10 fVar1;
  
  fVar1 = (float10)0;
  if (((param_5 != 0) ||
      (((param_3 != 0 && (*(int **)(param_3 + 0xd0) != (int *)0x0)) &&
       (param_5 = **(int **)(param_3 + 0xd0), param_5 != 0)))) &&
     ((fVar1 < (float10)*(float *)(param_5 + 0x1018) || ((*(byte *)(param_5 + 0xeec) & 1) != 0)))) {
    fVar1 = (float10)1;
  }
  return fVar1;
}

