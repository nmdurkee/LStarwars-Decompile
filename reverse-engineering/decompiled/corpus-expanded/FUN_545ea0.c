/* Ghidra pseudocode, not original source.
 * ev_67e04bb194beb06fa3ce238b04e3098eb4f9bf275f7ff551e45745ee5a93428c
 * Entry: 0x545ea0; label: FUN_00545ea0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined2 *
FUN_00545ea0(undefined4 *param_1,float param_2,short param_3,undefined4 param_4,undefined4 param_5,
            undefined2 param_6,float param_7,float param_8)

{
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined2 *puVar5;
  int iVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  float10 fVar11;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar6 = (int)param_2;
  puVar5 = (undefined2 *)FUN_00545e50();
  if (puVar5 != (undefined2 *)0x0) {
    if (param_2 != 0.0) {
      *(float *)(puVar5 + 6) = param_2;
      *(undefined4 *)(puVar5 + 2) = *param_1;
      uVar1 = param_1[2];
      *(undefined4 *)(puVar5 + 0x10) = param_4;
      *(undefined4 *)(puVar5 + 0x12) = param_5;
      *(undefined4 *)(puVar5 + 4) = uVar1;
      *(float *)(puVar5 + 0x18) = param_7;
      puVar5[1] = param_6;
      iVar8 = (int)param_3;
      *(float *)(puVar5 + 0x1a) = param_8;
      iVar9 = 0;
      puVar5[0xf] = param_3;
      *(float *)(puVar5 + 0x1c) = param_8 * param_8;
      *(float *)(puVar5 + 0x1e) = param_8 - param_7;
      *(undefined4 *)(puVar5 + 0x24) = 0x3e4ccccd;
      *(undefined4 *)(puVar5 + 0x20) = 0x3ccccccd;
      *(undefined4 *)(puVar5 + 0x22) = 0x3a23d70b;
      local_4 = 1e+07;
      param_2 = 1e+07;
      local_14 = 1e+07;
      local_8 = -1e+07;
      local_c = -1e+07;
      local_10 = -1e+07;
      if (3 < iVar8) {
        iVar10 = (iVar8 - 4U >> 2) + 1;
        iVar9 = iVar10 * 4;
        do {
          if (*(float *)(iVar6 + 0x30) < local_14) {
            local_14 = *(float *)(iVar6 + 0x30);
          }
          if (*(float *)(iVar6 + 0x34) < param_2) {
            param_2 = *(float *)(iVar6 + 0x34);
          }
          if (*(float *)(iVar6 + 0x38) < local_4) {
            local_4 = *(float *)(iVar6 + 0x38);
          }
          if (local_10 < *(float *)(iVar6 + 0x30)) {
            local_10 = *(float *)(iVar6 + 0x30);
          }
          if ((local_c < *(float *)(iVar6 + 0x34)) && (*(float *)(iVar6 + 0x34) < 2e+06)) {
            local_c = *(float *)(iVar6 + 0x34);
          }
          if (local_8 < *(float *)(iVar6 + 0x38)) {
            local_8 = *(float *)(iVar6 + 0x38);
          }
          if (*(float *)(iVar6 + 0x70) < local_14) {
            local_14 = *(float *)(iVar6 + 0x70);
          }
          if (*(float *)(iVar6 + 0x74) < param_2) {
            param_2 = *(float *)(iVar6 + 0x74);
          }
          if (*(float *)(iVar6 + 0x78) < local_4) {
            local_4 = *(float *)(iVar6 + 0x78);
          }
          if (local_10 < *(float *)(iVar6 + 0x70)) {
            local_10 = *(float *)(iVar6 + 0x70);
          }
          if ((local_c < *(float *)(iVar6 + 0x74)) && (*(float *)(iVar6 + 0x74) < 2e+06)) {
            local_c = *(float *)(iVar6 + 0x74);
          }
          if (local_8 < *(float *)(iVar6 + 0x78)) {
            local_8 = *(float *)(iVar6 + 0x78);
          }
          if (*(float *)(iVar6 + 0xb0) < local_14) {
            local_14 = *(float *)(iVar6 + 0xb0);
          }
          if (*(float *)(iVar6 + 0xb4) < param_2) {
            param_2 = *(float *)(iVar6 + 0xb4);
          }
          if (*(float *)(iVar6 + 0xb8) < local_4) {
            local_4 = *(float *)(iVar6 + 0xb8);
          }
          if (local_10 < *(float *)(iVar6 + 0xb0)) {
            local_10 = *(float *)(iVar6 + 0xb0);
          }
          if ((local_c < *(float *)(iVar6 + 0xb4)) && (*(float *)(iVar6 + 0xb4) < 2e+06)) {
            local_c = *(float *)(iVar6 + 0xb4);
          }
          if (local_8 < *(float *)(iVar6 + 0xb8)) {
            local_8 = *(float *)(iVar6 + 0xb8);
          }
          if (*(float *)(iVar6 + 0xf0) < local_14) {
            local_14 = *(float *)(iVar6 + 0xf0);
          }
          if (*(float *)(iVar6 + 0xf4) < param_2) {
            param_2 = *(float *)(iVar6 + 0xf4);
          }
          if (*(float *)(iVar6 + 0xf8) < local_4) {
            local_4 = *(float *)(iVar6 + 0xf8);
          }
          if (local_10 < *(float *)(iVar6 + 0xf0)) {
            local_10 = *(float *)(iVar6 + 0xf0);
          }
          if ((local_c < *(float *)(iVar6 + 0xf4)) && (*(float *)(iVar6 + 0xf4) < 2e+06)) {
            local_c = *(float *)(iVar6 + 0xf4);
          }
          if (local_8 < *(float *)(iVar6 + 0xf8)) {
            local_8 = *(float *)(iVar6 + 0xf8);
          }
          iVar6 = iVar6 + 0x100;
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
      }
      if (iVar9 < iVar8) {
        pfVar7 = (float *)(iVar6 + 0x34);
        iVar8 = iVar8 - iVar9;
        do {
          if (pfVar7[-1] < local_14) {
            local_14 = pfVar7[-1];
          }
          if (*pfVar7 < param_2) {
            param_2 = *pfVar7;
          }
          if (pfVar7[1] < local_4) {
            local_4 = pfVar7[1];
          }
          if (local_10 < pfVar7[-1]) {
            local_10 = pfVar7[-1];
          }
          if ((local_c < *pfVar7) && (*pfVar7 < 2e+06)) {
            local_c = *pfVar7;
          }
          if (local_8 < pfVar7[1]) {
            local_8 = pfVar7[1];
          }
          pfVar7 = pfVar7 + 0x10;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
      *(float *)(puVar5 + 8) = (local_10 + local_14) * 0.5;
      *(float *)(puVar5 + 10) = (local_c + param_2) * 0.5;
      *(float *)(puVar5 + 0xc) = (local_4 + local_8) * 0.5;
      fVar4 = (local_c - param_2) * 0.5;
      fVar2 = (local_10 - local_14) * 0.5;
      fVar3 = (local_8 - local_4) * 0.5;
      fVar2 = fVar3 * fVar3 + fVar2 * fVar2 + fVar4 * fVar4 + 1.5;
      *(float *)(puVar5 + 0x14) = fVar2;
      *(float *)(puVar5 + 0x1c) = fVar2 + param_8 * param_8;
      fVar11 = (float10)FUN_005c0240(fVar2);
      *(float *)(puVar5 + 0x16) = (float)fVar11;
      return puVar5;
    }
    *puVar5 = 0;
  }
  return (undefined2 *)0x0;
}

