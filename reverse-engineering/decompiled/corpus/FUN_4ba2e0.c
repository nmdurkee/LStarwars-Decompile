/* Ghidra analysis pseudocode, not original source.
 * ev_d9778a7e5954a243ecb5357ce6ca10d0e931dd6eaae906e14f50961a2e2268e2
 * Entry: 0x4ba2e0; label: FUN_004ba2e0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ba2e0(int param_1,int param_2,uint param_3)

{
  float fVar1;
  undefined4 uVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  float10 extraout_ST0;
  float10 fVar7;
  float10 fVar8;
  float10 fVar9;
  float10 fVar10;
  float local_1c;
  float local_18;
  
  fVar4 = _DAT_0087b928;
  fVar3 = _DAT_007fc3b0;
  uVar2 = _DAT_007fc3a4;
  if ((_DAT_00950780 == 0.0) && (0 < (int)param_3)) {
    iVar5 = (int)(param_3 + 1) / 2;
    iVar6 = FUN_006e6b90();
    fVar9 = (float10)1;
    fVar7 = (float10)0.5;
    fVar10 = ((float10)(float)(&DAT_029899a0)[iVar6 >> 1 & 0x7fff] + fVar9) * fVar7;
    if ((param_3 & 1) == 0) {
      fVar9 = ((float10)0.4000000059604645 - (float10)iVar5 * (float10)0.05000000074505806) *
              (fVar9 - fVar10);
      fVar8 = (float10)(float)(-extraout_ST0 * fVar7) - fVar9;
      fVar9 = fVar9 + (float10)(float)(fVar7 * extraout_ST0);
    }
    else {
      fVar10 = fVar9 - fVar10;
      fVar8 = (float10)0 -
              ((fVar7 * extraout_ST0 + (float10)0.4000000059604645) -
              (float10)iVar5 * (float10)0.05000000074505806) * fVar10;
      fVar9 = (((float10)0.4000000059604645 - fVar7 * extraout_ST0) -
              (float10)(float)((float10)iVar5 - fVar9) * (float10)0.05000000074505806) * fVar10 +
              extraout_ST0;
    }
    local_1c = (float)fVar8;
    local_18 = (float)fVar9;
    fVar9 = (float10)FUN_00457ec0();
    iVar6 = 0;
    if (0 < (int)param_3) {
      do {
        if (*(char *)(iVar6 + param_2) == '\0') {
          fVar1 = 1.0;
        }
        else {
          fVar1 = 0.25;
        }
        fVar1 = fVar1 * (float)(((float10)1 - fVar9) * (float10)fVar4);
        if (iVar6 < iVar5) {
          FUN_0055b830((int)*(short *)(param_1 + iVar6 * 2),local_1c,_DAT_00805260,0,uVar2,0xa7,
                       fVar1,fVar1,1,0);
          local_1c = local_1c - fVar3;
        }
        else {
          FUN_0055b830((int)*(short *)(param_1 + iVar6 * 2),local_18,_DAT_00805260,0,uVar2,0xa7,
                       fVar1,fVar1,1,0);
          local_18 = local_18 + fVar3;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < (int)param_3);
    }
  }
  return;
}

