/* Ghidra pseudocode, not original source.
 * ev_bb04fbbbd27a84d29838025e356b4a832b57e1ec23fb072545eb7050db0a5426
 * Entry: 0x5ec590; label: FUN_005ec590
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ec590(float *param_1,float *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  float *pfVar2;
  float *pfVar3;
  float local_8;
  float local_4;
  
  FUN_005ec3d0(&local_8,&local_4,param_3,param_4);
  pfVar2 = param_2;
  pfVar3 = param_1;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar3 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar3 = pfVar3 + 1;
  }
  param_1[4] = param_2[4] + local_8 * *param_2 + local_4 * param_2[8];
  param_1[5] = param_2[9] * local_4 + param_2[1] * local_8 + param_2[5];
  param_1[6] = param_2[10] * local_4 + param_2[2] * local_8 + param_2[6];
  param_1[7] = local_8 * param_2[3] + param_2[7] + param_2[0xb] * local_4;
  return;
}

