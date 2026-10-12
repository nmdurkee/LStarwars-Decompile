/* Ghidra pseudocode, not original source.
 * ev_82e843d85b8a15ad0c2712a3dca0d893aca885ca51044f6184084df2488405d8
 * Entry: 0x475090; label: FUN_00475090
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00475090(int param_1)

{
  ushort uVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  undefined4 uVar6;
  short sVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  float10 extraout_ST0;
  float10 extraout_ST1;
  int local_5c;
  float local_58;
  int local_28 [10];
  
  uVar5 = (uint)*(char *)(DAT_00879588 * 0x130 + 0xa3 + DAT_00951b78);
  if ((DAT_0087b02c == 0) || (*(byte *)(DAT_0087b02c + 0x7c) != uVar5)) {
    sVar7 = DAT_00880898;
    if ((&DAT_0086e0f5)[uVar5 * 0xc] == '\0') {
      sVar7 = DAT_00880884;
    }
    local_28[0] = (int)sVar7;
    uVar1 = *(ushort *)(uVar5 * 0x9c + 0x7a + DAT_00951354);
    local_5c = 1;
    if ((uVar1 & 0x1000) == 0) {
      local_28[1] = (int)DAT_00880888;
      local_5c = 2;
      if ((uVar1 & 0x10) != 0) {
        local_28[2] = (int)DAT_0088074c;
        local_5c = 3;
      }
    }
  }
  else {
    local_28[0] = (int)*(short *)PTR_DAT_007fac0c;
    local_28[1] = (int)*(short *)PTR_DAT_007fac18;
    local_5c = 2;
  }
  iVar8 = 0;
  local_58 = _DAT_007f932c - (float)(local_5c + -1) * -0.2 * 0.5;
  if (local_5c != 0) {
    do {
      if ((param_1 == 0) || (DAT_0087951c != iVar8)) {
        uVar5 = (uint)DAT_00921da9;
        uVar10 = (uint)DAT_0080099a;
        uVar9 = (uint)DAT_0080099b;
      }
      else {
        bVar2 = DAT_008009a1;
        bVar3 = DAT_008009a2;
        bVar4 = DAT_00921dae;
        if (DAT_009213e4 != 0) {
          bVar2 = DAT_00921dad;
          bVar3 = DAT_008009a0;
          bVar4 = DAT_0080099f;
        }
        uVar10 = (uint)bVar4;
        uVar9 = (uint)bVar3;
        uVar5 = (uint)bVar2;
        if (0.0 < _DAT_00921d70) {
          uVar5 = FUN_006e6b90();
          uVar10 = FUN_006e6b90();
          uVar9 = FUN_006e6b90();
        }
      }
      uVar6 = FUN_006e6b90();
      FUN_0050d910(*(undefined4 *)(DAT_00926c20 + local_28[iVar8] * 4),(float)extraout_ST1,local_58,
                   0x3f800000,(float)extraout_ST0,(float)extraout_ST0,(float)extraout_ST0,0,uVar5,
                   uVar10,uVar9,0x3fd9999a,1,0,0,uVar6);
      local_58 = local_58 - 0.2;
      iVar8 = iVar8 + 1;
    } while (iVar8 < local_5c);
  }
  return;
}

