/* Ghidra pseudocode, not original source.
 * ev_3cc3478cfa8c26bd4fafca5bd3c3e065fb7e5c3537b7c6265584e6b0ffbf613e
 * Entry: 0x6379f0; label: FUN_006379f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_006379f0(byte *param_1)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  int iVar7;
  byte *unaff_EDI;
  
  uVar6 = 0xc;
  pbVar1 = unaff_EDI;
  pbVar5 = param_1;
  do {
    if (*(int *)pbVar5 != *(int *)pbVar1) goto LAB_00637a18;
    uVar6 = uVar6 - 4;
    pbVar1 = pbVar1 + 4;
    pbVar5 = pbVar5 + 4;
  } while (3 < uVar6);
  if (uVar6 == 0) {
LAB_00637a75:
    uVar6 = 0;
  }
  else {
LAB_00637a18:
    iVar7 = (uint)*pbVar5 - (uint)*pbVar1;
    if (iVar7 == 0) {
      if (uVar6 == 1) goto LAB_00637a75;
      iVar7 = (uint)pbVar5[1] - (uint)pbVar1[1];
      if (iVar7 == 0) {
        if (uVar6 == 2) goto LAB_00637a75;
        iVar7 = (uint)pbVar5[2] - (uint)pbVar1[2];
        if (iVar7 == 0) {
          if ((uVar6 == 3) || (iVar7 = (uint)pbVar5[3] - (uint)pbVar1[3], iVar7 == 0))
          goto LAB_00637a75;
        }
      }
    }
    uVar6 = 1;
    if (iVar7 < 1) {
      uVar6 = 0xffffffff;
    }
  }
  uVar2 = 0xc;
  pbVar1 = unaff_EDI + 0xc;
  pbVar5 = param_1 + 0xc;
  do {
    if (*(int *)pbVar5 != *(int *)pbVar1) goto LAB_00637a9e;
    uVar2 = uVar2 - 4;
    pbVar1 = pbVar1 + 4;
    pbVar5 = pbVar5 + 4;
  } while (3 < uVar2);
  if (uVar2 == 0) {
LAB_00637afb:
    uVar2 = 0;
  }
  else {
LAB_00637a9e:
    iVar7 = (uint)*pbVar5 - (uint)*pbVar1;
    if (iVar7 == 0) {
      if (uVar2 == 1) goto LAB_00637afb;
      iVar7 = (uint)pbVar5[1] - (uint)pbVar1[1];
      if (iVar7 == 0) {
        if (uVar2 == 2) goto LAB_00637afb;
        iVar7 = (uint)pbVar5[2] - (uint)pbVar1[2];
        if (iVar7 == 0) {
          if ((uVar2 == 3) || (iVar7 = (uint)pbVar5[3] - (uint)pbVar1[3], iVar7 == 0))
          goto LAB_00637afb;
        }
      }
    }
    uVar2 = 1;
    if (iVar7 < 1) {
      uVar2 = 0xffffffff;
    }
  }
  uVar3 = 0xc;
  pbVar1 = unaff_EDI + 0x24;
  pbVar5 = param_1 + 0x24;
  do {
    if (*(int *)pbVar5 != *(int *)pbVar1) goto LAB_00637b28;
    uVar3 = uVar3 - 4;
    pbVar1 = pbVar1 + 4;
    pbVar5 = pbVar5 + 4;
  } while (3 < uVar3);
  if (uVar3 == 0) {
LAB_00637b85:
    uVar3 = 0;
  }
  else {
LAB_00637b28:
    iVar7 = (uint)*pbVar5 - (uint)*pbVar1;
    if (iVar7 == 0) {
      if (uVar3 == 1) goto LAB_00637b85;
      iVar7 = (uint)pbVar5[1] - (uint)pbVar1[1];
      if (iVar7 == 0) {
        if (uVar3 == 2) goto LAB_00637b85;
        iVar7 = (uint)pbVar5[2] - (uint)pbVar1[2];
        if (iVar7 == 0) {
          if ((uVar3 == 3) || (iVar7 = (uint)pbVar5[3] - (uint)pbVar1[3], iVar7 == 0))
          goto LAB_00637b85;
        }
      }
    }
    uVar3 = 1;
    if (iVar7 < 1) {
      uVar3 = 0xffffffff;
    }
  }
  uVar4 = 0xc;
  pbVar1 = unaff_EDI + 0x30;
  pbVar5 = param_1 + 0x30;
  do {
    if (*(int *)pbVar5 != *(int *)pbVar1) goto LAB_00637bae;
    uVar4 = uVar4 - 4;
    pbVar1 = pbVar1 + 4;
    pbVar5 = pbVar5 + 4;
  } while (3 < uVar4);
  if (uVar4 == 0) {
LAB_00637c0b:
    uVar4 = 0;
  }
  else {
LAB_00637bae:
    iVar7 = (uint)*pbVar5 - (uint)*pbVar1;
    if (iVar7 == 0) {
      if (uVar4 == 1) goto LAB_00637c0b;
      iVar7 = (uint)pbVar5[1] - (uint)pbVar1[1];
      if (iVar7 == 0) {
        if (uVar4 == 2) goto LAB_00637c0b;
        iVar7 = (uint)pbVar5[2] - (uint)pbVar1[2];
        if (iVar7 == 0) {
          if ((uVar4 == 3) || (iVar7 = (uint)pbVar5[3] - (uint)pbVar1[3], iVar7 == 0))
          goto LAB_00637c0b;
        }
      }
    }
    uVar4 = 1;
    if (iVar7 < 1) {
      uVar4 = 0xffffffff;
    }
  }
  uVar6 = uVar6 | uVar2 | uVar3 | uVar4 |
          (uint)(*(float *)(unaff_EDI + 0x3c) != *(float *)(param_1 + 0x3c)) |
          (uint)(*(float *)(unaff_EDI + 0x40) != *(float *)(param_1 + 0x40)) |
          (uint)(*(float *)(unaff_EDI + 0x44) != *(float *)(param_1 + 0x44)) |
          (uint)(*(float *)(unaff_EDI + 0x48) != *(float *)(param_1 + 0x48)) |
          (uint)(*(float *)(unaff_EDI + 0x4c) != *(float *)(param_1 + 0x4c)) |
          (param_1[0x59] ^ unaff_EDI[0x59]) & 1 |
          (uint)(*(short *)(param_1 + 0x68) != *(short *)(unaff_EDI + 0x68)) |
          (uint)(*(short *)(param_1 + 0x60) != *(short *)(unaff_EDI + 0x60)) |
          (uint)(*(short *)(param_1 + 0x5e) != *(short *)(unaff_EDI + 0x5e)) |
          (uint)(*(short *)(param_1 + 0x5c) != *(short *)(unaff_EDI + 0x5c)) |
          (uint)(*(short *)(param_1 + 0x5a) != *(short *)(unaff_EDI + 0x5a)) |
          (uint)(param_1[0x58] != unaff_EDI[0x58]) |
          (uint)(*(float *)(unaff_EDI + 0x50) != *(float *)(param_1 + 0x50));
  if (*(float *)(unaff_EDI + 0x6c) == *(float *)(param_1 + 0x6c)) {
    return uVar6;
  }
  return uVar6 | 1;
}

