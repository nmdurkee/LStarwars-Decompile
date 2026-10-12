/* Ghidra pseudocode, not original source.
 * ev_14412b1be5fe57fadf021e89e905f73790df496cb317f965435f7dd4228acdda
 * Entry: 0x5a1270; label: FUN_005a1270
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a1270(float param_1,float param_2)

{
  undefined4 *puVar1;
  
  if (param_1 != 0.0) {
    for (puVar1 = *(undefined4 **)((int)param_1 + 0x18); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      if ((puVar1[4] != 0) && (puVar1[5] != 0)) {
        *(uint *)(puVar1[4] + 0x50) = *(uint *)(puVar1[4] + 0x50) & 0xfffffffe;
        *(float *)(puVar1[4] + 0x4c) =
             ((float)puVar1[7] - (float)puVar1[6]) * param_2 + (float)puVar1[6];
        if ((float)puVar1[6] <= (float)puVar1[7]) {
          param_1 = 1.0;
        }
        else {
          param_1 = -1.0;
        }
        if ((float)puVar1[7] * param_1 < param_1 * *(float *)(puVar1[4] + 0x4c)) {
          *(undefined4 *)(puVar1[4] + 0x4c) = puVar1[7];
        }
        if (*(float *)(puVar1[4] + 0x4c) * param_1 < (float)puVar1[6] * param_1) {
          *(undefined4 *)(puVar1[4] + 0x4c) = puVar1[6];
        }
      }
    }
  }
  return;
}

