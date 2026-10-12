/* Ghidra pseudocode, not original source.
 * ev_d279921681329594f701fe8f20a56ba9d177d693157112987774dc2af4761a09
 * Entry: 0x55e970; label: FUN_0055e970
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_0055e970(undefined4 param_1,int *param_2,float *param_3,char param_4,uint param_5)

{
  int iVar1;
  int *piVar2;
  float10 fVar3;
  
  *param_2 = 0;
  *param_3 = 0.0;
  piVar2 = &DAT_0093d7f0;
  do {
    iVar1 = *piVar2;
    if ((iVar1 != 0) && ((*(byte *)(iVar1 + 0x1fc) & 0x80) != 0)) {
      fVar3 = (float10)FUN_005b3c50(iVar1 + 0x5c,param_1,0);
      if ((((float)fVar3 < *param_3) || (*param_2 == 0)) &&
         ((param_4 == '\0' ||
          ((*(uint *)(*(int *)(*(int *)(*piVar2 + 0x54) + 0x24) + 0x90) & param_5) != 0)))) {
        *param_3 = (float)fVar3;
        *param_2 = *piVar2;
      }
    }
    piVar2 = piVar2 + 1;
  } while ((int)piVar2 < 0x93d810);
  return *param_2 != 0;
}

