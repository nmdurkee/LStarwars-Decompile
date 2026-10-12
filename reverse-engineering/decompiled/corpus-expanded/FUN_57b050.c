/* Ghidra pseudocode, not original source.
 * ev_be2e1b76976fde28c062f4f0fb6ba1ce818a6b2c78af6ba8f2a77520ff39bb32
 * Entry: 0x57b050; label: FUN_0057b050
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0057b050(int param_1)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  int iVar6;
  float10 fVar7;
  
  iVar3 = FUN_004f7fb0(param_1);
  if ((iVar3 != 0) &&
     (iVar4 = FUN_00650dc0(*(undefined4 *)(param_1 + 0x510)), iVar3 = DAT_00951c4c, iVar4 != -1)) {
    iVar6 = 0;
    psVar5 = (short *)(DAT_00951c4c + 0x70);
    while (*psVar5 != -1) {
      iVar6 = iVar6 + 1;
      psVar5 = psVar5 + 10;
      if (5 < iVar6) {
        return;
      }
    }
    if (iVar6 < 6) {
      iVar2 = iVar6 * 0x14;
      pbVar1 = (byte *)(iVar2 + 0x72 + DAT_00951c4c);
      *pbVar1 = *pbVar1 & 0xfe;
      *(short *)(iVar2 + 0x70 + iVar3) = (short)iVar4;
      iVar3 = FUN_004f7fb0(param_1);
      while (iVar3 != 0) {
        iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"frame");
        if (iVar3 == 0) {
          fVar7 = (float10)FUN_004f8100(param_1);
          iVar3 = DAT_00951c4c;
          *(float *)(iVar2 + 0x74 + DAT_00951c4c) = (float)fVar7;
          if ((float)fVar7 < 1.0) {
            *(undefined4 *)(iVar2 + 0x74 + iVar3) = 0x3f800000;
          }
        }
        else {
          iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&PTR_DAT_007624f8);
          if ((iVar3 == 0) && (fVar7 = (float10)FUN_004f8100(param_1), fVar7 != (float10)0.0)) {
            fVar7 = (float10)FUN_004f28e0(*(undefined4 *)(param_1 + 0x510));
            *(float *)(DAT_00951c4c + (iVar6 * 5 + 0x1e) * 4) = (float)fVar7;
            fVar7 = (float10)FUN_004f8100(param_1);
            if (fVar7 != (float10)0.0) {
              fVar7 = (float10)FUN_004f28e0(*(undefined4 *)(param_1 + 0x510));
              *(float *)(iVar2 + 0x7c + DAT_00951c4c) = (float)fVar7;
              fVar7 = (float10)FUN_004f8100(param_1);
              if (fVar7 != (float10)0.0) {
                fVar7 = (float10)FUN_004f28e0(*(undefined4 *)(param_1 + 0x510));
                iVar3 = DAT_00951c4c;
                *(float *)(iVar2 + 0x80 + DAT_00951c4c) = (float)fVar7;
                pbVar1 = (byte *)(iVar2 + 0x72 + iVar3);
                *pbVar1 = *pbVar1 | 1;
              }
            }
          }
        }
        iVar3 = FUN_004f7fb0(param_1);
      }
    }
  }
  return;
}

