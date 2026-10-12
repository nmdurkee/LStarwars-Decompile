/* Ghidra pseudocode, not original source.
 * ev_9931c233bc23f2b366e36cd20edde6ea49582f2b0a176997d8924d6b396dfde7
 * Entry: 0x58e130; label: FUN_0058e130
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0058e130(float param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  
  iVar5 = (int)param_1;
  iVar3 = *(int *)((int)param_1 + 0x794);
  if (iVar3 == 0) {
    if ((*(uint *)(*(int *)(*(int *)((int)param_1 + 0x54) + 0x24) + 0x90) & 0x8000) == 0) {
      return 0;
    }
    iVar3 = *(int *)((int)param_1 + 0x790);
    if (iVar3 == 0) {
      return 0;
    }
    if ((DAT_00802844 == -1) || (*(char *)((int)param_1 + 0x7b5) != DAT_00802844)) {
      if (DAT_00802838 == -1) {
        return 0;
      }
      if (*(char *)((int)param_1 + 0x7b5) != DAT_00802838) {
        return 0;
      }
      if (*(char *)((int)param_1 + 0x7b8) != '\x03') {
        return 0;
      }
    }
    iVar6 = iVar3 + 0x80;
    fVar4 = *(float *)((int)param_1 + 0x1dc) * 2.25 + *(float *)(iVar3 + 0x1dc);
    param_1 = *(float *)((int)param_1 + 0x1dc) * 1.75 + *(float *)(iVar3 + 0x1dc);
  }
  else {
    iVar6 = iVar3 + 0x4c;
    if (((DAT_00802844 == -1) || (*(char *)((int)param_1 + 0x7b5) != DAT_00802844)) &&
       ((DAT_00802838 == -1 ||
        ((*(char *)((int)param_1 + 0x7b5) != DAT_00802838 ||
         (*(char *)((int)param_1 + 0x7b8) != '\x03')))))) {
      fVar4 = *(float *)((int)param_1 + 0xac) * 1.25 + *(float *)(iVar3 + 0xa8);
      param_1 = *(float *)((int)param_1 + 0xac) * 0.75 + *(float *)(iVar3 + 0xa8);
    }
    else {
      fVar4 = *(float *)((int)param_1 + 0xac) * 2.25 + *(float *)(iVar3 + 0xa8);
      param_1 = *(float *)((int)param_1 + 0xac) * 1.75 + *(float *)(iVar3 + 0xa8);
    }
  }
  if (iVar6 != 0) {
    fVar7 = (float10)FUN_0062f1c0(*(undefined4 *)(iVar5 + 0x50),(int)*(short *)(iVar5 + 0x7aa));
    fVar1 = (float)fVar7;
    if (fVar1 != 0.0) {
      fVar7 = (float10)FUN_005b3cf0(iVar5 + 0x80,iVar6,0);
      fVar2 = (float)fVar7;
      if (fVar2 < fVar4 * fVar4) {
        if (param_1 * param_1 < fVar2) {
          fVar7 = (float10)FUN_005c0240(fVar2);
          fVar7 = (float10)1 - (fVar7 - (float10)param_1) / ((float10)fVar4 - (float10)param_1);
        }
        else {
          fVar7 = (float10)1;
        }
        fVar1 = (-fVar1 - fVar1) * (float)fVar7 + fVar1;
        *(float *)(iVar5 + 0xf18) = fVar1 * (float)(&DAT_029899a0)[*(ushort *)(iVar5 + 0x5a) >> 1];
        *(float *)(iVar5 + 0xf20) =
             fVar1 * (float)(&DAT_029899a0)[(int)(*(ushort *)(iVar5 + 0x5a) + 0x4000) >> 1 & 0x7fff]
        ;
        return 1;
      }
    }
  }
  return 0;
}

