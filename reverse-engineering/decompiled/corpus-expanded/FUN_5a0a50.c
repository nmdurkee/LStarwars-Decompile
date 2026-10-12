/* Ghidra pseudocode, not original source.
 * ev_14412b1be5fe57fadf021e89e905f73790df496cb317f965435f7dd4228acdda
 * Entry: 0x5a0a50; label: FUN_005a0a50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a0a50(float param_1,float param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_1 != 0.0) {
    for (puVar1 = *(undefined4 **)((int)param_1 + 0x18); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      iVar2 = puVar1[4];
      if (iVar2 != 0) {
        if ((float)puVar1[6] <= (float)puVar1[7]) {
          param_1 = 1.0;
        }
        else {
          param_1 = -1.0;
        }
        if (*(float *)(iVar2 + 0x54) == 0.0) {
          *(float *)(iVar2 + 0x40) = param_1 * param_2;
        }
        else {
          *(float *)(iVar2 + 0x40) = *(float *)(iVar2 + 0x54) * param_2 * param_1;
        }
      }
    }
  }
  return;
}

