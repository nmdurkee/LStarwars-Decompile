/* Ghidra pseudocode, not original source.
 * ev_554bacc3f16b6ba5ba2e9bdc745347cbc06d0daeabfbc4224973a16c83b60b9e
 * Entry: 0x4c06a0; label: FUN_004c06a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004c06a0(float param_1,undefined4 param_2,int param_3,float *param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  
  iVar2 = (int)param_1;
  param_1 = 1e+09;
  iVar4 = *(int *)(iVar2 + 0x5090);
  iVar5 = 0;
  iVar3 = 0;
  if (0 < *(int *)(iVar2 + 0x5094)) {
    do {
      if ((param_3 == 0) ||
         (((bVar1 = *(byte *)(iVar4 + 0x3c), (bVar1 & 1) != 0 && ((bVar1 & 2) != 0)) &&
          ((bVar1 & 0xc) == 0)))) {
        fVar6 = (float10)FUN_005b3c50(param_2,iVar4 + 0x1c,0);
        if ((float)fVar6 < param_1) {
          iVar3 = iVar4;
          param_1 = (float)fVar6;
        }
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0x54;
    } while (iVar5 < *(int *)(iVar2 + 0x5094));
  }
  if (param_4 != (float *)0x0) {
    *param_4 = param_1;
  }
  return iVar3;
}

