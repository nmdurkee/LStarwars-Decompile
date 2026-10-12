/* Ghidra pseudocode, not original source.
 * ev_0c39cc066d2b612e886b5e8dc629d567ae8f788bfbc7a0ed81832ee74aa3ece0
 * Entry: 0x402e00; label: FUN_00402e00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00402e00(float param_1,undefined4 param_2,int param_3,float *param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  int local_4;
  
  iVar2 = (int)param_1;
  param_1 = 1e+09;
  iVar4 = *(int *)(iVar2 + 0x5098);
  iVar5 = 0;
  local_4 = 0;
  iVar3 = 0;
  if (0 < *(int *)(iVar2 + 0x509c)) {
    do {
      if (param_3 == 0) {
        iVar3 = iVar4 + 0x10;
LAB_00402e54:
        fVar6 = (float10)FUN_005b3c50(param_2,iVar3,0);
        if ((float)fVar6 < param_1) {
          param_1 = (float)fVar6;
          local_4 = iVar4;
        }
      }
      else {
        bVar1 = *(byte *)(iVar4 + 0x62);
        if ((((bVar1 & 2) != 0) && ((bVar1 & 1) != 0)) && ((bVar1 & 4) == 0)) {
          iVar3 = iVar4 + 100;
          goto LAB_00402e54;
        }
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0x74;
      iVar3 = local_4;
    } while (iVar5 < *(int *)(iVar2 + 0x509c));
  }
  if (param_4 != (float *)0x0) {
    *param_4 = param_1;
  }
  return iVar3;
}

