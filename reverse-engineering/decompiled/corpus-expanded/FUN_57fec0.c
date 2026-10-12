/* Ghidra pseudocode, not original source.
 * ev_148a09dc694c3f4e6090ec8593a8f5c40e6398f75b0d17d245a3886ccb65c6ec
 * Entry: 0x57fec0; label: FUN_0057fec0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_0057fec0(int param_1,int param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  float10 fVar7;
  int *local_14;
  float local_c;
  int local_8;
  
  if (*(float *)(param_1 + 0x1e0) <= *(float *)(param_1 + 0x1dc)) {
    fVar1 = *(float *)(param_1 + 0x1dc);
  }
  else {
    fVar1 = *(float *)(param_1 + 0x1e0);
  }
  piVar6 = (int *)0x0;
  local_14 = (int *)0x0;
  piVar5 = &DAT_00951cec;
  local_8 = 0x20;
  local_c = 1e+08;
  do {
    if (((char)piVar5[0x3f] != '\0') &&
       (((((param_2 == 0 || (iVar4 = *piVar5, iVar4 == 0)) || ((*(uint *)(iVar4 + 0x1fc) & 1) == 0))
         || (((*(uint *)(iVar4 + 0x1fc) & 0x1000) == 0 || (*(char *)(iVar4 + 0x28b) != '\0')))) ||
        (*(char *)(iVar4 + 0x280) == -1)))) {
      fVar2 = (float)piVar5[0x32];
      fVar7 = (float10)FUN_005b3c50(piVar5 + 0x21,param_1 + 0x80,0);
      fVar3 = (float)fVar7;
      piVar6 = local_14;
      if (((fVar3 < fVar2 * 0.5 * fVar2 * 0.5) &&
          (iVar4 = FUN_00551730(piVar5 + 0x21,piVar5 + 0x2a,param_1 + 0x80,fVar1 * fVar1,0),
          iVar4 != 0)) && (fVar3 < local_c)) {
        local_14 = piVar5 + -1;
        piVar6 = local_14;
        local_c = fVar3;
      }
    }
    piVar5 = piVar5 + 0x4e;
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  if ((piVar6 != (int *)0x0) && (param_3 != 0)) {
    fVar1 = *(float *)(param_1 + 0x1dc) * 0.75;
    iVar4 = FUN_00551800(piVar6 + 0x22,piVar6 + 0x2b,param_1 + 0x80,fVar1 * fVar1);
    if (iVar4 != 0) {
      *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) | 0x2000;
      return piVar6;
    }
  }
  return piVar6;
}

