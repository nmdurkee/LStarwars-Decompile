/* Ghidra pseudocode, not original source.
 * ev_14412b1be5fe57fadf021e89e905f73790df496cb317f965435f7dd4228acdda
 * Entry: 0x5a1500; label: FUN_005a1500
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005a1500(int param_1)

{
  undefined4 *puVar1;
  float10 fVar2;
  float10 fVar3;
  
  fVar2 = (float10)0;
  if (param_1 != 0) {
    for (puVar1 = *(undefined4 **)(param_1 + 0x18); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      if (puVar1[4] != 0) {
        if ((float)puVar1[7] == (float)puVar1[6]) {
          return (float10)1.0;
        }
        fVar3 = (float10)((*(float *)(puVar1[4] + 0x4c) - (float)puVar1[6]) /
                         ((float)puVar1[7] - (float)puVar1[6]));
        if (fVar3 <= (float10)1) {
          if (fVar2 <= fVar3) {
            return fVar3;
          }
          return (float10)(float)fVar2;
        }
        return (float10)(float)(float10)1;
      }
    }
  }
  return (float10)(float)fVar2;
}

