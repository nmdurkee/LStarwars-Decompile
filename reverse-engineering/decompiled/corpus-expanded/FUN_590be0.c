/* Ghidra pseudocode, not original source.
 * ev_b142addbfc413d4476e6a560937bb6deb0d869285f4b587c6bb2379626f1bfc8
 * Entry: 0x590be0; label: FUN_00590be0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00590be0(int param_1,int param_2)

{
  float10 fVar1;
  
  *(undefined4 *)(param_1 + 0x48) = 0x3e99999a;
  if (param_2 != 0) {
    fVar1 = (float10)FUN_0058fe80(param_2);
    *(float *)(param_1 + 0x48) = (float)((float10)0.30000001192092896 / fVar1);
  }
  *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(param_1 + 0x48);
  return;
}

