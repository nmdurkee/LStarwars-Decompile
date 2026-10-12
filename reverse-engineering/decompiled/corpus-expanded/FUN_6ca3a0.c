/* Ghidra pseudocode, not original source.
 * ev_78df0822e84eed863df7f286a1c553c9b84caeaa7e7dd857dd35c61ca827b7f8
 * Entry: 0x6ca3a0; label: FUN_006ca3a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006ca3a0(float *param_1,float *param_2)

{
  float fVar1;
  int iVar2;
  int *in_ECX;
  float *pfVar3;
  int iVar4;
  float *pfVar5;
  float10 fVar6;
  int *local_528;
  int local_524;
  float local_510 [64];
  float local_410 [259];
  
  local_528 = (int *)*in_ECX;
  *param_1 = 0.0;
  param_1[1] = 0.0;
  param_1[2] = 0.0;
  local_524 = 0;
  param_1[3] = 1.0;
  iVar2 = 0;
  if (local_528 != (int *)0x0) {
    pfVar3 = local_510;
    pfVar5 = local_410;
    do {
      if (0x3f < local_524) break;
      iVar2 = FUN_006c8760(8,DAT_02973ab8,pfVar5,0);
      if (iVar2 != 0) {
        *param_1 = *pfVar5 + *param_1;
        param_1[1] = pfVar5[1] + param_1[1];
        param_1[2] = pfVar5[2] + param_1[2];
        *pfVar3 = 1.0;
        FUN_006c8760(0x40,DAT_02973ab4,pfVar3,0);
        local_524 = local_524 + 1;
        pfVar5 = pfVar5 + 4;
        pfVar3 = pfVar3 + 1;
      }
      local_528 = (int *)*local_528;
    } while (local_528 != (int *)0x0);
    iVar2 = local_524;
    if (0 < local_524) {
      iVar4 = 0;
      fVar1 = 1.0 / (float)local_524;
      *param_1 = fVar1 * *param_1;
      param_1[1] = param_1[1] * fVar1;
      param_1[2] = fVar1 * param_1[2];
      *param_2 = 0.0;
      if (0 < local_524) {
        pfVar3 = local_410 + 2;
        do {
          fVar6 = (float10)FUN_005c0240((param_1[2] - *pfVar3) * (param_1[2] - *pfVar3) +
                                        (param_1[1] - pfVar3[-1]) * (param_1[1] - pfVar3[-1]) +
                                        (*param_1 - pfVar3[-2]) * (*param_1 - pfVar3[-2]));
          if (*param_2 < local_510[iVar4] + (float)fVar6) {
            *param_2 = local_510[iVar4] + (float)fVar6;
          }
          iVar4 = iVar4 + 1;
          pfVar3 = pfVar3 + 4;
        } while (iVar4 < local_524);
      }
    }
  }
  return iVar2;
}

