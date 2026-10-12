/* Ghidra analysis pseudocode, not original source.
 * ev_04eba8a6041128e42a5942cb543eca22153343fab03a80410cc8a046c9872535
 * Entry: 0x51af40; label: FUN_0051af40
 */

void FUN_0051af40(undefined4 param_1,int param_2,int param_3)

{
  float *pfVar1;
  byte *pbVar2;
  char cVar3;
  uint *puVar4;
  uint uVar5;
  undefined2 uVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  float10 fVar11;
  float *pfVar12;
  float *pfVar13;
  undefined4 local_18 [2];
  undefined4 local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar10 = param_3;
  if (*(char *)(param_3 + 0x2a) != '\0') {
    uVar5 = (param_3 - *(int *)(param_2 + 0x7c)) / 0x5c;
    uVar9 = uVar5 & 0x80000007;
    if ((int)uVar9 < 0) {
      uVar9 = (uVar9 - 1 | 0xfffffff8) + 1;
    }
    iVar7 = (int)(uVar5 + ((int)uVar5 >> 0x1f & 7U)) >> 3;
    pbVar2 = (byte *)(iVar7 + 0x18 + param_2);
    if ((*(byte *)(iVar7 + 0x18 + param_2) & (byte)(1 << ((byte)uVar9 & 0x1f))) == 0) {
      *pbVar2 = *pbVar2 | '\x01' << ((byte)uVar9 & 0x1f);
      if ((*(byte *)(param_3 + 0x2b) & 4) == 0) {
        iVar7 = FUN_005cfd60(param_3 + 0x40);
        if ((iVar7 == 0) &&
           ((DAT_009238d8 == (code *)0x0 ||
            (iVar7 = (*DAT_009238d8)(param_1,param_3 + 0x40), iVar7 == 0)))) {
          *(byte *)(param_3 + 0x2b) = *(byte *)(param_3 + 0x2b) | 4;
          iVar10 = 0;
          if (*(char *)(param_3 + 0x28) == '\0') {
            return;
          }
          do {
            puVar4 = *(uint **)(*(int *)(param_3 + 0x34) + iVar10 * 4);
            *puVar4 = *puVar4 | 0x10000000;
            puVar4[1] = puVar4[1] | 0x10000000;
            iVar10 = iVar10 + 1;
          } while (iVar10 < (int)(uint)*(byte *)(param_3 + 0x28));
          return;
        }
      }
      else {
        iVar7 = FUN_005cfd60(param_3 + 0x40);
        if (iVar7 == 0) {
          return;
        }
        *(byte *)(param_3 + 0x2b) = *(byte *)(param_3 + 0x2b) & 0xfb;
        iVar7 = 0;
        if (*(char *)(param_3 + 0x28) != '\0') {
          do {
            puVar4 = *(uint **)(*(int *)(param_3 + 0x34) + iVar7 * 4);
            uVar9 = (uint)(byte)puVar4[4];
            if (uVar9 == uVar5) {
              uVar9 = (uint)*(byte *)((int)puVar4 + 0x11);
            }
            if ((*(byte *)(uVar9 * 0x5c + *(int *)(param_2 + 0x7c) + 0x2b) & 4) == 0) {
              *puVar4 = *puVar4 & 0xefffffff;
              puVar4[1] = puVar4[1] & 0xefffffff;
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 < (int)(uint)*(byte *)(param_3 + 0x28));
        }
      }
      local_4 = *(float *)(param_3 + 0xc);
      local_c = *(float *)(param_3 + 4);
      local_8 = *(float *)(param_3 + 8);
      pfVar1 = (float *)(param_3 + 4);
      uVar8 = FUN_005d0330(param_3 + 0x40);
      FUN_005b30a0(pfVar1,param_3 + 0x4c,uVar8);
      pfVar13 = (float *)(param_3 + 0x1c);
      pfVar12 = (float *)(param_3 + 8);
      cVar3 = *(char *)(param_3 + 0x28);
      param_3 = 0;
      *(float *)(iVar10 + 0x18) = *pfVar13 + *pfVar12;
      *(float *)(iVar10 + 0x20) = *(float *)(iVar10 + 0x24) + *(float *)(iVar10 + 8);
      if (cVar3 != '\0') {
        do {
          puVar4 = *(uint **)(*(int *)(iVar10 + 0x34) + param_3 * 4);
          if ((byte)puVar4[4] == uVar5) {
            iVar7 = (uint)*(byte *)((int)puVar4 + 0x11) * 0x5c + *(int *)(param_2 + 0x7c);
            pfVar12 = (float *)(iVar7 + 4);
            pfVar13 = pfVar1;
          }
          else {
            iVar7 = (uint)(byte)puVar4[4] * 0x5c + *(int *)(param_2 + 0x7c);
            pfVar13 = (float *)(iVar7 + 4);
            pfVar12 = pfVar1;
          }
          fVar11 = (float10)FUN_005bed80(pfVar12,pfVar13,local_18);
          puVar4[7] = (uint)(float)fVar11;
          FUN_005bfe00(local_18[0],local_10);
          uVar6 = FUN_006e6b90();
          *(undefined2 *)((int)puVar4 + 0x12) = uVar6;
          if ((float)puVar4[8] != 0.0) {
            if ((float)puVar4[7] <=
                *(float *)(iVar10 + 0x10) + (float)puVar4[8] + *(float *)(iVar7 + 0x10)) {
              *puVar4 = *puVar4 & 0xf7ffffff;
              puVar4[1] = puVar4[1] & 0xf7ffffff;
            }
            else {
              *puVar4 = *puVar4 | 0x8000000;
              puVar4[1] = puVar4[1] | 0x8000000;
            }
          }
          param_3 = param_3 + 1;
        } while (param_3 < (int)(uint)*(byte *)(iVar10 + 0x28));
      }
      if ((((local_c == *pfVar1) && (local_8 == *(float *)(iVar10 + 8))) &&
          (local_4 == *(float *)(iVar10 + 0xc))) &&
         (((iVar7 = FUN_005d0420(iVar10 + 0x40), iVar7 == 0 || ((*(byte *)(iVar7 + 0x50) & 1) == 0))
          || (*(float *)(iVar7 + 0x40) == 0.0)))) {
        *(byte *)(iVar10 + 0x2b) = *(byte *)(iVar10 + 0x2b) & 0xfd;
        return;
      }
      *(byte *)(iVar10 + 0x2b) = *(byte *)(iVar10 + 0x2b) | 2;
    }
  }
  return;
}

