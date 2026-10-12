/* Ghidra analysis pseudocode, not original source.
 * ev_7aab14e0333828c3f97507d2210eedd59fd790849ff0958821514dbec2d3feea
 * Entry: 0x481e40; label: FUN_00481e40
 */

int FUN_00481e40(float param_1,undefined4 param_2,int param_3,float *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  int local_4;
  
  iVar1 = (int)param_1;
  param_1 = 1e+09;
  iVar3 = *(int *)(iVar1 + 0x50a8);
  iVar4 = 0;
  local_4 = 0;
  iVar2 = 0;
  if (0 < *(int *)(iVar1 + 0x50ac)) {
    do {
      if ((param_3 == 0) ||
         ((((*(byte *)(iVar3 + 0x17) & 2) != 0 && ((*(byte *)(iVar3 + 0x17) & 1) != 0)) &&
          (((*(byte *)(iVar3 + 0x19) & 1) == 0 || (DAT_0087baf0 != 0)))))) {
        fVar5 = (float10)FUN_005b3c50(param_2,iVar3 + 8,0);
        if ((float)fVar5 < param_1) {
          param_1 = (float)fVar5;
          local_4 = iVar3;
        }
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x38;
      iVar2 = local_4;
    } while (iVar4 < *(int *)(iVar1 + 0x50ac));
  }
  if (param_4 != (float *)0x0) {
    *param_4 = param_1;
  }
  return iVar2;
}

