/* Ghidra analysis pseudocode, not original source.
 * ev_411dd83ba30300d5831318e5e0d5db9024421d970d639e52cbaaaf14146f88dc
 * Entry: 0x6a6670; label: FUN_006a6670
 */

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Type propagation algorithm not settling */

void FUN_006a6670(int *param_1,int param_2,float *param_3)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  float *pfVar5;
  int iVar6;
  undefined4 in_ECX;
  float *pfVar7;
  int iVar8;
  int aiStack_40 [6];
  undefined4 uStack_28;
  int local_10;
  
  iVar2 = *param_1;
  uStack_28 = 0x6a668d;
  iVar3 = iVar2 * -4;
  aiStack_40[6 - iVar2] = 0xffffffff;
  aiStack_40[5 - iVar2] = in_ECX;
  aiStack_40[5 - iVar2] = 0x430c0000;
  iVar8 = param_1[6];
  aiStack_40[4 - iVar2] = (int)param_3;
  aiStack_40[3 - iVar2] = param_2;
  aiStack_40[2 - iVar2] = iVar8;
  aiStack_40[1 - iVar2] = iVar2;
  aiStack_40[-iVar2] = 0x6a66b1;
  FUN_006a5a20();
  iVar8 = 0;
  if (3 < iVar2) {
    pfVar5 = param_3 + 1;
    pfVar7 = (float *)(&stack0xffffffe4 + iVar3);
    do {
      iVar6 = iVar8 * 4;
      iVar8 = iVar8 + 4;
      pfVar4 = pfVar5 + 4;
      pfVar7[-2] = *(float *)(param_2 + iVar6) - pfVar5[-1];
      *(float *)((int)aiStack_40 + (iVar3 - (int)param_3) + 0xc + (int)pfVar4) =
           *(float *)((param_2 - (int)param_3) + -0x10 + (int)pfVar4) - *pfVar5;
      *pfVar7 = *(float *)((param_2 - (int)(&stack0xffffffdc + iVar3)) + -0x10 + (int)(pfVar7 + 4))
                - pfVar5[1];
      pfVar7[1] = *(float *)(param_2 + -4 + iVar8 * 4) - pfVar5[2];
      pfVar5 = pfVar4;
      pfVar7 = pfVar7 + 4;
    } while (iVar8 < iVar2 + -3);
  }
  if (iVar8 < iVar2) {
    pfVar5 = param_3 + iVar8;
    iVar8 = iVar2 - iVar8;
    do {
      pfVar7 = (float *)((param_2 - (int)param_3) + (int)pfVar5);
      fVar1 = *pfVar5;
      pfVar5 = pfVar5 + 1;
      iVar8 = iVar8 + -1;
      *(float *)((int)aiStack_40 + (iVar3 - (int)param_3) + 0x18 + (int)pfVar5) = *pfVar7 - fVar1;
    } while (iVar8 != 0);
  }
  iVar8 = param_1[1];
  aiStack_40[6 - iVar2] = *(undefined4 *)(iVar8 + 0x80);
  iVar6 = param_1[6];
  aiStack_40[5 - iVar2] = iVar8;
  aiStack_40[5 - iVar2] = 0;
  aiStack_40[4 - iVar2] = (int)param_3;
  aiStack_40[3 - iVar2] = (int)(&stack0xffffffdc + iVar3);
  aiStack_40[2 - iVar2] = iVar6;
  aiStack_40[1 - iVar2] = iVar2;
  aiStack_40[-iVar2] = 0x6a6775;
  FUN_006a5a20();
  local_10 = 0;
  if (3 < iVar2) {
    iVar8 = (iVar2 - 4U >> 2) + 1;
    local_10 = iVar8 * 4;
    pfVar5 = (float *)(&stack0xffffffe0 + iVar3);
    pfVar7 = (float *)(param_2 + 0xc);
    do {
      iVar8 = iVar8 + -1;
      pfVar5[-1] = pfVar7[-3] - pfVar5[-1];
      *pfVar5 = *(float *)((param_2 - (int)(&stack0xffffffdc + iVar3)) + -0x10 + (int)(pfVar5 + 4))
                - *pfVar5;
      pfVar5[1] = pfVar7[-1] - pfVar5[1];
      pfVar5[2] = *pfVar7 - pfVar5[2];
      pfVar5 = pfVar5 + 4;
      pfVar7 = pfVar7 + 4;
    } while (iVar8 != 0);
  }
  if (local_10 < iVar2) {
    iVar8 = iVar2 - local_10;
    pfVar5 = (float *)(&stack0xffffffdc + local_10 * 4 + iVar3);
    do {
      iVar8 = iVar8 + -1;
      *pfVar5 = *(float *)((param_2 - (int)(&stack0xffffffdc + iVar3)) + (int)pfVar5) - *pfVar5;
      pfVar5 = pfVar5 + 1;
    } while (iVar8 != 0);
  }
  if (0 < iVar2) {
    pfVar5 = param_3;
    iVar8 = iVar2;
    do {
      aiStack_40[6 - iVar2] = 0x6a681f;
      iVar6 = FUN_006e6b90();
      if (iVar6 < 0x28) {
        if (iVar6 < 0) {
          iVar6 = 0;
        }
      }
      else {
        iVar6 = 0x27;
      }
      iVar8 = iVar8 + -1;
      *pfVar5 = *(float *)(param_1[1] + 0x150 + iVar6 * 4) +
                *(float *)((int)aiStack_40 + (iVar3 - (int)param_3) + 0x18 + (int)(pfVar5 + 1));
      pfVar5 = pfVar5 + 1;
    } while (iVar8 != 0);
  }
  return;
}

