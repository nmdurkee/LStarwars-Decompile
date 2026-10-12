/* Ghidra pseudocode, not original source.
 * ev_7610d2e5ecab5d7a95653def000f5e9425ca0c842a62593dc010feaabdcb80b1
 * Entry: 0x5186a0; label: FUN_005186a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005186a0(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,float param_4,
                 float param_5)

{
  undefined4 uVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    uVar1 = param_2[2];
    param_1[3] = param_3;
    param_1[2] = uVar1;
    param_1[4] = (float)param_1[1] - param_4;
    param_1[6] = (float)param_1[1] + param_5;
  }
  return;
}

