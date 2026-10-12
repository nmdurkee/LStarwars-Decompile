/* Ghidra pseudocode, not original source.
 * ev_7fb001446c14d370af68fb4a523bbd62db36fda0486cbdd4cf52041e7ba87b14
 * Entry: 0x4de100; label: FUN_004de100
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004de100(int param_1,undefined4 param_2,void *param_3,float param_4)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  float *pfVar7;
  float *unaff_EDI;
  float10 fVar8;
  
  if (DAT_00951b50 == 0) {
    iVar1 = *(int *)(param_1 + 0x2ae8);
    if (iVar1 != 0) {
      iVar6 = 0;
      pfVar7 = *(float **)(iVar1 + 0x1380);
      if (0 < *(int *)(iVar1 + 0x137c)) {
        do {
          if (pfVar7[3] != 0.0) {
            fVar2 = *unaff_EDI - *pfVar7;
            fVar3 = unaff_EDI[2] - pfVar7[2];
            fVar4 = fVar2 * fVar2 + fVar3 * fVar3;
            fVar5 = pfVar7[3] + 1.0;
            if (fVar4 < fVar5 * fVar5) {
              fVar8 = (float10)FUN_005c0240(fVar4);
              *unaff_EDI = fVar2 * (fVar5 / (float)fVar8) + *pfVar7;
              unaff_EDI[2] = (fVar5 / (float)fVar8) * fVar3 + pfVar7[2];
              break;
            }
          }
          iVar6 = iVar6 + 1;
          pfVar7 = pfVar7 + 0x16;
        } while (iVar6 < *(int *)(iVar1 + 0x137c));
      }
    }
    _memset(param_3,0,0x3c);
    if (unaff_EDI[2] * unaff_EDI[2] + *unaff_EDI * *unaff_EDI < param_4 * param_4) {
      fVar8 = (float10)FUN_005506f0(0);
      if ((float)fVar8 != 2e+06) {
        unaff_EDI[1] = (float)fVar8;
      }
      FUN_0052fc80(*(undefined4 *)(param_1 + 0x2ae8));
      if ((*(byte *)((int)param_3 + 0x2e) & 1) != 0) {
        *(float *)((int)param_3 + 0x10) = *unaff_EDI;
        *(float *)((int)param_3 + 0x14) = unaff_EDI[1];
        *(float *)((int)param_3 + 0x18) = unaff_EDI[2];
        *(undefined4 *)((int)param_3 + 0x1c) = param_2;
        return 1;
      }
    }
  }
  return 0;
}

