/* Ghidra analysis pseudocode, not original source.
 * ev_28935bb75220519b9cd6c8dd2893feffbabc6fed0a1828833445fdd6a861260d
 * Entry: 0x685340; label: FUN_00685340
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00685340(int param_1,float param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  if (param_2 < 0.0) {
    return;
  }
  if (param_1 == -1) {
    return;
  }
  iVar8 = param_1 * 0x330 + DAT_029620a4;
  iVar3 = *(int *)(DAT_0296209c + *(short *)(iVar8 + 0x182) * 4);
  if ((double)(int)*(short *)(iVar3 + 0x16) != 0.0) {
    if (param_2 == 0.0) {
      param_2 = *(float *)(iVar3 + 0xa4);
    }
    fVar2 = _DAT_0296205c;
    if (*(char *)(iVar3 + 0x2f1) == '\x04') {
      fVar2 = _DAT_02962060;
    }
    fVar4 = fVar2 + _DAT_008108e4;
    fVar2 = fVar2 - param_2;
    if (*(short *)(iVar8 + 0x18c) == 0) {
      uVar5 = FUN_006e6b90();
      FUN_00683e90(iVar8,uVar5);
    }
    *(undefined1 *)(iVar8 + 0x184) = 1;
    if (0 < *(short *)(iVar8 + 0x180)) {
      iVar7 = 0;
      if (DAT_029620b8 == 0) {
        fVar1 = _DAT_00810908;
        if (*(float *)(iVar3 + 0x2f4) < _DAT_00810908) {
          fVar1 = *(float *)(iVar3 + 0x2f4);
        }
        fVar1 = (float)(int)*(short *)(iVar3 + 0x16) / fVar1;
      }
      else {
        fVar1 = (float)(int)*(short *)(iVar3 + 0x16) / _DAT_00810908;
      }
      *(float *)(iVar8 + 0x324) = fVar2;
      while ((fVar2 = fVar2 + 1.0 / fVar1, fVar2 < fVar4 && (iVar7 = iVar7 + 1, iVar7 < 1000))) {
        iVar6 = (**(code **)(iVar8 + 0x1c0))(iVar8,iVar3,fVar2);
        if ((*(char *)(iVar3 + 0x2f0) != '\0') && (iVar6 != 0)) {
          FUN_00656080(iVar6,fVar2,iVar3,iVar8,0);
        }
        fVar2 = *(float *)(iVar8 + 0x324);
      }
      return;
    }
  }
  return;
}

