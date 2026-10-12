/* Ghidra pseudocode, not original source.
 * ev_586220d7ac6b37fe8b0c159ff03e90627c1db9a143c695a82bf037091d09cd88
 * Entry: 0x45cac0; label: FUN_0045cac0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045cac0(int param_1,undefined4 param_2,float param_3)

{
  float fVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  float10 fVar6;
  float10 fVar7;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float10 extraout_ST0_03;
  float10 extraout_ST0_04;
  float10 fVar8;
  float10 extraout_ST0_05;
  float10 extraout_ST0_06;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  float10 extraout_ST1_02;
  float10 extraout_ST1_03;
  float10 extraout_ST1_04;
  float10 fVar9;
  float fVar10;
  float local_c;
  
  fVar10 = _DAT_007f85e0;
  if (param_3 != 0.0) {
    switch(*(undefined4 *)(param_1 + 0x14)) {
    case 1:
      iVar5 = 0;
      if (-1 < DAT_00876dc0) {
        do {
          fVar6 = (float10)10.0;
          fVar7 = (float10)0;
          uVar4 = 1 << ((byte)iVar5 & 0x1f) & DAT_00876dac;
          iVar2 = iVar5;
          if (iVar5 == DAT_00876dc0) {
            fVar10 = *(float *)(param_1 + 0x18) / *(float *)(param_1 + 0x1c);
            iVar3 = FUN_006e6b90();
            fVar1 = (float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff];
            fVar7 = (float10)_DAT_007f85e0;
            iVar3 = FUN_006e6b90();
            local_c = (float)(fVar7 * (fVar6 - ((float10)fVar1 + fVar6) * (float10)0.5)) *
                      (float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff];
            iVar3 = FUN_006e6b90();
            fVar7 = (float10)(float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff] * extraout_ST1;
            if (uVar4 == 0) {
              iVar2 = -1;
            }
            fVar1 = fVar10 * 0.3;
            fVar6 = extraout_ST0;
          }
          else {
            iVar3 = FUN_006e6b90();
            local_c = _DAT_007f85e0 * (float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff];
            iVar3 = FUN_006e6b90();
            fVar7 = (float10)(float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff] * fVar7;
            if (uVar4 == 0) {
              iVar2 = -1;
            }
            fVar10 = (float)extraout_ST1_00;
            fVar1 = 0.3;
            fVar6 = extraout_ST0_00;
          }
          param_3 = (float)fVar7;
          FUN_0055b830(iVar2,local_c,param_3,(float)fVar6,fVar1,0xa7,fVar10,fVar10,1,0);
          iVar5 = iVar5 + 1;
        } while (iVar5 <= DAT_00876dc0);
        return;
      }
      break;
    case 2:
      iVar2 = 0;
      iVar5 = DAT_00876dc0;
      do {
        uVar4 = 1 << ((byte)iVar2 & 0x1f) & DAT_00876dac;
        iVar3 = FUN_006e6b90();
        fVar1 = (float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff];
        iVar3 = FUN_006e6b90();
        if ((iVar2 != iVar5) ||
           (fVar7 = extraout_ST0_01, (float10)*(float *)(param_1 + 0x18) < extraout_ST0_01)) {
          iVar5 = iVar2;
          if (uVar4 == 0) {
            iVar5 = -1;
          }
          FUN_0055b830(iVar5,fVar1 * fVar10,(float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff] * fVar10,
                       (float)extraout_ST1_01,0x3e99999a,0xa7,(float)extraout_ST0_01,
                       (float)extraout_ST0_01,1,0);
          fVar7 = (float10)1;
          iVar5 = DAT_00876dc0;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < 10);
      if (*(float *)(param_1 + 0x18) < 0.5) {
        fVar10 = *(float *)(param_1 + 0x18);
        iVar2 = FUN_006e6b90();
        FUN_0055b830(iVar5,(float)extraout_ST0_02,(float)extraout_ST0_02,(float)extraout_ST0_02,
                     (fVar10 + fVar10) * 0.3,0xa7,(float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff] + 1.0,
                     (float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff] + 1.0,1,0);
        param_3 = 1.0 - *(float *)(param_1 + 0x18) / 0.8333334;
        if (param_3 < 0.0) {
          param_3 = 0.0;
        }
        FUN_0050d910(*(undefined4 *)
                      (DAT_00926c20 + *(short *)(&PTR_DAT_007fcfc0)[DAT_00876dc0 * 6] * 4),0,
                     _DAT_007f8238,0x3f800000,_DAT_007f823c,_DAT_007f823c,_DAT_007f823c,0,
                     DAT_007fa4c8,DAT_007fa4cc,DAT_0087a774,0x3fd9999a,1,0,0,
                     (int)ROUND(param_3 * 128.0) & 0xffff);
        return;
      }
      if (fVar7 <= (float10)*(float *)(param_1 + 0x18)) {
        iVar2 = FUN_006e6b90();
        fVar8 = (float10)_DAT_007f85e0;
        fVar9 = fVar8 * (float10)(float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff];
        iVar2 = FUN_006e6b90();
        fVar10 = (float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff];
        iVar2 = FUN_006e6b90();
        fVar1 = (float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff];
        fVar7 = extraout_ST1_04;
        fVar6 = extraout_ST0_05;
        if (DAT_00876dc4 == 0) {
          FUN_00681f40("Char_Icon_App",0);
          fVar6 = (float10)0;
          fVar7 = (float10)1;
          DAT_00876dc4 = 1;
          iVar5 = DAT_00876dc0;
        }
        FUN_0055b830(iVar5,(float)fVar9,(float)((float10)fVar10 * extraout_ST1_03),(float)fVar6,
                     (float)(fVar8 - (float10)ABS(fVar1)) * 0.1 + 0.3,0xa7,(float)fVar7,(float)fVar7
                     ,1,0);
        return;
      }
      iVar2 = FUN_006e6b90();
      fVar10 = (float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff];
      fVar6 = (float10)_DAT_007f85e0;
      iVar2 = FUN_006e6b90((float)fVar7,0x3e99999a,0xa7,(float)extraout_ST1_02,
                           (float)extraout_ST1_02,1,0);
      iVar2 = FUN_006e6b90((float)(((float10)1 - ((float10)fVar10 + (float10)1) * extraout_ST0_03) *
                                  fVar6) * (float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff]);
      FUN_0055b830(iVar5,(float)(extraout_ST0_04 *
                                (float10)(float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff]));
      param_3 = 1.0 - *(float *)(param_1 + 0x18) / 0.8333334;
      if (param_3 < 0.0) {
        param_3 = 0.0;
      }
      FUN_0050d910(*(undefined4 *)
                    (DAT_00926c20 + *(short *)(&PTR_DAT_007fcfc0)[DAT_00876dc0 * 6] * 4),0,
                   _DAT_007f8238,0x3f800000,_DAT_007f823c,_DAT_007f823c,_DAT_007f823c,0,DAT_007fa4c8
                   ,DAT_007fa4cc,DAT_0087a774,0x3fd9999a,1,0,0,(int)ROUND(param_3 * 128.0) & 0xffff)
      ;
      if (DAT_00876dc8 == 0) {
        FUN_00681f40("Char_Icon_Slide",0);
        DAT_00876dc8 = 1;
        return;
      }
      break;
    case 3:
      iVar5 = 0;
      do {
        fVar10 = 1.0 - *(float *)(param_1 + 0x18) / *(float *)(param_1 + 0x1c);
        iVar2 = FUN_006e6b90();
        fVar1 = _DAT_007f85e0 * (float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff];
        iVar3 = FUN_006e6b90();
        iVar2 = iVar5;
        if ((DAT_00876dac & 1 << ((byte)iVar5 & 0x1f)) == 0) {
          iVar2 = -1;
        }
        FUN_0055b830(iVar2,fVar1,
                     (float)(extraout_ST0_06 * (float10)(float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff])
                     ,0,0x3e99999a,0xa7,fVar10,fVar10,1,0);
        iVar5 = iVar5 + 1;
      } while (iVar5 < 10);
      break;
    case 0xffffffff:
    case 0:
      break;
    default:
      goto switchD_0045cae5_default;
    }
  }
switchD_0045cae5_default:
  return;
}

