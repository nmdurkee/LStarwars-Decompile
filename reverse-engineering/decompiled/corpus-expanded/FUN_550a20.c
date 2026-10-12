/* Ghidra pseudocode, not original source.
 * ev_9af94503fce638d48c98755f8a4ba03de7c5cdf51e6dce151974c12e75b3fd49
 * Entry: 0x550a20; label: FUN_00550a20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x00550b43) */

void FUN_00550a20(short *param_1,float param_2,float *param_3,short *param_4,short *param_5,
                 int param_6)

{
  float *pfVar1;
  float *pfVar2;
  ulonglong uVar3;
  float fVar4;
  short *psVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  ushort in_FPUControlWord;
  undefined6 uVar9;
  uint local_c;
  ulonglong local_8;
  
  psVar5 = param_5;
  if (param_4 != (short *)0x0) {
    *param_4 = 0;
  }
  if (param_5 != (short *)0x0) {
    *param_5 = 0;
  }
  if (param_1 != (short *)0x0) {
    if (param_2 <= 1.0) {
      if (param_2 < 0.0) {
        param_2 = 0.0;
      }
    }
    else {
      param_2 = 1.0;
    }
    iVar7 = (int)*param_1;
    if (param_6 == 0) {
      iVar7 = iVar7 + -1;
    }
    fVar4 = (float)(iVar7 << 0x10);
    if (iVar7 << 0x10 < 0) {
      fVar4 = fVar4 + 4.2949673e+09;
    }
    local_c = in_FPUControlWord | 0xc00;
    uVar3 = (ulonglong)ROUND(fVar4 * param_2);
    local_8._0_4_ = (uint)uVar3;
    uVar6 = (uint)local_8;
    uVar8 = (uint)local_8 >> 0x10;
    pfVar1 = (float *)(*(int *)(param_1 + 4) + uVar8 * 0xc);
    *param_3 = *pfVar1;
    param_3[1] = pfVar1[1];
    param_3[2] = pfVar1[2];
    local_8 = uVar3;
    FUN_005508f0(param_6,param_5,param_4);
    iVar7 = uVar8 + 1;
    if (*param_1 <= iVar7) {
      if (param_6 == 0) {
        return;
      }
      iVar7 = 0;
    }
    if ((uVar3 & 0xffff) != 0) {
      pfVar2 = (float *)(*(int *)(param_1 + 4) + iVar7 * 0xc);
      fVar4 = (float)(uVar6 & 0xffff) * 1.5258789e-05;
      *param_3 = *param_3 + fVar4 * (*pfVar2 - *pfVar1);
      param_3[1] = (pfVar2[1] - pfVar1[1]) * fVar4 + param_3[1];
      param_3[2] = (pfVar2[2] - pfVar1[2]) * fVar4 + param_3[2];
      FUN_005508f0(param_6,-(uint)(param_5 != (short *)0x0) & (uint)&local_8,
                   -(uint)(param_4 != (short *)0x0) & (uint)&local_c);
      if (param_4 != (short *)0x0) {
        uVar9 = FUN_00550040(*param_4,local_c);
        param_5._0_2_ = (short)(int)ROUND((float)(int)uVar9 * fVar4);
        *param_4 = (short)param_5 + (short)((uint6)uVar9 >> 0x20);
      }
      if (psVar5 != (short *)0x0) {
        uVar9 = FUN_00550040(*psVar5,(uint)local_8);
        param_5._0_2_ = (short)(int)ROUND((float)(int)uVar9 * fVar4);
        *psVar5 = (short)param_5 + (short)((uint6)uVar9 >> 0x20);
      }
    }
  }
  return;
}

