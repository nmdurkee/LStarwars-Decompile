/* Ghidra analysis pseudocode, not original source.
 * ev_fb3e2efa05f3fdcad8ac13641a8f1821f73d708273cedf9c40d68478f4bf822c
 * Entry: 0x575920; label: FUN_00575920
 */

int FUN_00575920(float param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  int local_8;
  
  iVar3 = (int)param_1;
  iVar4 = *(int *)((int)param_1 + 0x4698);
  if (iVar4 == 0) {
    return 0;
  }
  piVar1 = (int *)((int)param_1 + 0x469c);
  param_1 = 1e+06;
  local_8 = 0;
  if (0 < *piVar1) {
    iVar5 = 0;
    do {
      if ((((*(byte *)(iVar4 + 0xf5) & 4) == 0) && (sVar2 = *(short *)(iVar4 + 0xf0), sVar2 != -1))
         && (((param_3 != -1 && (sVar2 == param_3)) ||
             ((param_2 != -1 && (*(char *)(sVar2 * 0x130 + 0xa3 + DAT_00951b78) == param_2)))))) {
        if (param_4 == 0) {
          return iVar4;
        }
        fVar6 = (float10)FUN_005b3c50(param_4,iVar4 + 0xd4,0);
        if ((float)fVar6 < param_1) {
          param_1 = (float)fVar6;
          local_8 = iVar4;
        }
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0x128;
    } while (iVar5 < *(int *)(iVar3 + 0x469c));
  }
  return local_8;
}

