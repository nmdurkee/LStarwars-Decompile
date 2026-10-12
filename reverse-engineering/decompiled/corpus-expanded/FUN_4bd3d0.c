/* Ghidra pseudocode, not original source.
 * ev_ec63a0996326cf703ee2b3a6fc0e0cae7d47cd208787877e90138bc554ba8dc2
 * Entry: 0x4bd3d0; label: FUN_004bd3d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004bd3d0(float param_1,undefined4 param_2,int param_3,float *param_4)

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
  iVar4 = *(int *)(iVar2 + 0x50b0);
  iVar5 = 0;
  local_4 = 0;
  iVar3 = 0;
  if (0 < *(int *)(iVar2 + 0x50b4)) {
    do {
      if (param_3 == 0) {
        iVar3 = iVar4 + 0x90;
LAB_004bd448:
        fVar6 = (float10)FUN_005b3c50(param_2,iVar3,0);
        if ((float)fVar6 < param_1) {
          param_1 = (float)fVar6;
          local_4 = iVar4;
        }
      }
      else {
        bVar1 = *(byte *)(iVar4 + 0xa2);
        if (((((bVar1 & 2) != 0) && ((bVar1 & 1) != 0)) && ((bVar1 & 4) == 0)) &&
           ((*(char *)(iVar4 + 0xa3) == '\0' && (*(float *)(iVar4 + 0xb4) == 0.0)))) {
          iVar3 = iVar4 + 0xa4;
          goto LAB_004bd448;
        }
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0xc0;
      iVar3 = local_4;
    } while (iVar5 < *(int *)(iVar2 + 0x50b4));
  }
  if (param_4 != (float *)0x0) {
    *param_4 = param_1;
  }
  return iVar3;
}

