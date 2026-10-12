/* Ghidra pseudocode, not original source.
 * ev_8be83d5a314ed06484cc1a00e0611cd4a1346ac66c548b102291ab30b68096a0
 * Entry: 0x4ccc60; label: FUN_004ccc60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ccc60(int param_1,float param_2)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  
  iVar5 = (int)param_2;
  if (param_2 != 0.0) {
    if (((*(byte *)((int)param_2 + 0x1fc) & 0x80) == 0) &&
       (*(char *)((int)param_2 + 0xf00) == '\x02')) {
      param_2 = 1.0;
      goto LAB_004ccce2;
    }
    bVar1 = *(byte *)(param_1 + 0x36);
    if ((bVar1 & 1) == 0) {
      if ((bVar1 & 2) != 0) {
        param_2 = *(float *)(*(int *)((int)param_2 + 0xca4) + 0x3c);
        goto LAB_004ccce2;
      }
      if ((bVar1 & 4) != 0) {
        param_2 = *(float *)(*(int *)((int)param_2 + 0xca4) + 0x30);
        goto LAB_004ccce2;
      }
      if ((bVar1 & 8) != 0) {
        param_2 = *(float *)(*(int *)((int)param_2 + 0xca4) + 0x2c);
        goto LAB_004ccce2;
      }
    }
    else if ((*(byte *)(*(int *)((int)param_2 + 0xca4) + 0x5a) & 8) != 0) {
      param_2 = 1.0;
      goto LAB_004ccce2;
    }
  }
  param_2 = 0.0;
LAB_004ccce2:
  if (((*(byte *)(param_1 + 0x38) & 1) != 0) && (param_2 < 0.0)) {
    param_2 = 0.0;
  }
  if (*(int *)(param_1 + 0x6c) == 0) {
    FUN_004ccad0(param_1);
  }
  if (*(char *)(param_1 + 0x37) != '\x02') {
    if ((*(char *)(param_1 + 0x37) == '\x03') &&
       (iVar6 = FUN_004f8b10((uint)*(byte *)(*(int *)(param_1 + 0x6c) + 6) * 0x9c +
                             *(int *)(DAT_0093b268 + 8),"GIZOBSTACLE"), iVar6 == 0)) {
      uVar3 = **(undefined4 **)(param_1 + 0x6c);
      if ((((*(byte *)(param_1 + 0x36) & 2) == 0) || (iVar5 == 0)) ||
         ((cVar2 = *(char *)(iVar5 + 0x280), cVar2 != '\0' && (cVar2 != '\x01')))) {
        FUN_00558510(uVar3,param_2);
        return;
      }
      if (*(float *)(*(int *)(iVar5 + 0xca4) + 0x3c) == 0.0) {
        fVar4 = _DAT_00925018 + _DAT_00925018;
      }
      else {
        fVar4 = _DAT_00925018 * 3.0;
      }
      fVar7 = (float10)FUN_0054fad0(*(undefined4 *)(&DAT_00880584 + cVar2 * 4),param_2,fVar4);
      *(float *)(&DAT_00880584 + *(char *)(iVar5 + 0x280) * 4) = (float)fVar7;
      FUN_00558510(uVar3,*(undefined4 *)(&DAT_00880584 + *(char *)(iVar5 + 0x280) * 4));
    }
    return;
  }
  FUN_004cca60();
  return;
}

