/* Ghidra pseudocode, not original source.
 * ev_9398ef22b4c43c044c1b187060a2935e0b1d1dc3bbb9f543c9cb1dd758ae788c
 * Entry: 0x553570; label: FUN_00553570
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00553570(undefined4 *param_1,short *param_2,float param_3,undefined1 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  float10 fVar3;
  undefined1 local_c [12];
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[7] = 0;
    if ((param_2 != (short *)0x0) && (1 < *param_2)) {
      *param_1 = param_2;
      *(undefined1 *)((int)param_1 + 6) = param_4;
      puVar1 = *(undefined4 **)(param_2 + 4);
      fVar3 = (float10)FUN_005becc0((int)param_2[1] + (int)puVar1,puVar1,local_c);
      param_1[3] = (float)fVar3;
      if (0.0 < param_3) {
        FUN_005518a0(param_1,param_3);
        return;
      }
      param_1[4] = *puVar1;
      param_1[5] = puVar1[1];
      uVar2 = puVar1[2];
      param_1[7] = 0;
      param_1[6] = uVar2;
    }
  }
  return;
}

