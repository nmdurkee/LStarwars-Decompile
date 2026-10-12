/* Ghidra pseudocode, not original source.
 * ev_994c8ab95260a4a020e9117574c628d5ef7b33cde61134a1d0677698b3534ab7
 * Entry: 0x4b79a0; label: FUN_004b79a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b79a0(undefined4 param_1,int param_2,float param_3,undefined4 param_4,undefined4 param_5
                 ,int param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
                 undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13)

{
  int iVar1;
  float fVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  bool bVar8;
  bool bVar9;
  char cVar10;
  undefined2 in_FPUControlWord;
  undefined *puVar11;
  float local_158;
  float local_154;
  float local_150;
  float local_14c;
  undefined4 local_148;
  undefined4 local_144;
  int local_140 [4];
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  float local_11c [2];
  int local_114 [4];
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_158;
  if (_DAT_00950780 == 0.0) {
    local_11c[0] = param_3;
    local_114[2] = param_1;
    local_11c[1] = (float)param_10;
    local_114[3] = param_8;
    local_114[0] = param_2;
    local_114[1] = param_9;
    local_140[2] = param_4;
    local_140[3] = param_11;
    local_130 = param_5;
    local_12c = param_12;
    local_140[0] = param_6;
    local_140[1] = param_13;
    FUN_00574e20();
    local_144 = _DAT_007fc360;
    local_128 = 0xffffffff;
    local_14c = _DAT_007fc354;
    local_124 = 0xffffffff;
    local_120 = FUN_006d6350();
    iVar6 = 0;
    do {
      uVar3 = FUN_004f48e0(iVar6);
      FUN_006d67f0(uVar3);
      FUN_006d6340(iVar6);
      iVar1 = local_114[iVar6];
      local_158 = 0.7;
      cVar10 = iVar1 != -1;
      if (local_140[iVar6 + 2] != -1) {
        cVar10 = cVar10 + '\x01';
      }
      if (local_140[iVar6 + 4] != -1) {
        cVar10 = cVar10 + '\x01';
      }
      if (local_140[iVar6] != -1) {
        cVar10 = cVar10 + '\x01';
      }
      if (local_140[iVar6 + 6] != -1) {
        cVar10 = cVar10 + '\x01';
      }
      if (cVar10 == '\x05') {
        fVar2 = 3.5;
LAB_004b7b08:
        local_158 = fVar2 * local_14c + 0.7;
      }
      else {
        if (cVar10 == '\x04') {
          fVar2 = 2.5;
          goto LAB_004b7b08;
        }
        if (cVar10 == '\x03') {
          fVar2 = 1.5;
          goto LAB_004b7b08;
        }
        if (cVar10 == '\x02') {
          fVar2 = 0.5;
          goto LAB_004b7b08;
        }
      }
      if (iVar6 == 0) {
        local_150 = -_DAT_007fc350;
        uVar3 = 2;
      }
      else {
        uVar3 = 8;
        local_150 = _DAT_007fc350;
      }
      if (local_114[iVar6 + 2] != 0) {
        local_158 = local_158 + local_14c;
        if (iVar1 != -1) {
          local_158 = local_158 - local_14c;
          bVar8 = DAT_009213e4 != 0;
          FUN_004f1f10(local_104,"[[accept]]");
          FUN_00511560(local_104,local_150,local_158,0x3f800000,0x3e8ccccd,0x3e8ccccd,0x3e8ccccd,
                       uVar3,0xff,0xff,0xff,0x3f19999a,2);
          local_148 = CONCAT22(local_148._2_2_,in_FPUControlWord);
          local_158 = local_158 - (_DAT_007fc358 - 0.01);
          local_154 = (float)(int)ROUND(local_11c[iVar6] * 128.0);
          FUN_0050d910(*(undefined4 *)(DAT_00926c20 + iVar1 * 4),local_150,local_158,0x3f800000,
                       0x3eb33333,0x3e800000,0x3ecccccd,uVar3,0,(-(uint)bVar8 & 0xffffffc0) + 0xff,0
                       ,local_144,1,0,0,(uint)local_154 & 0xff);
        }
        if (local_140[iVar6] != -1) {
          local_158 = local_158 - local_14c;
          if (DAT_009213e4 == 0) {
            local_148 = DAT_007fc338;
            uVar5 = DAT_007fc33c;
            uVar7 = DAT_007fc340;
          }
          else {
            local_148 = DAT_007fc344;
            uVar5 = DAT_007fc348;
            uVar7 = DAT_007fc34c;
          }
          if (local_140[iVar6] == (int)DAT_00880760) {
            puVar11 = &DAT_00751620;
          }
          else {
            puVar11 = &DAT_007515e8;
          }
          FUN_004015e0(puVar11,local_104);
          FUN_00511560(local_104,local_150,local_158,0x3f800000,0x3e8ccccd,0x3e8ccccd,0x3e8ccccd,
                       uVar3,0xff,0xff,0xff,0x3f19999a,2);
          local_158 = local_158 - (_DAT_007fc358 - 0.01);
          FUN_0050d910(*(undefined4 *)(DAT_00926c20 + local_140[iVar6] * 4),local_150,local_158,
                       0x3f800000,0x3ecccccd,0x3e800000,0x3ecccccd,uVar3,local_148,uVar5,uVar7,
                       local_144,1,0,0,0x80);
        }
        if (local_140[iVar6 + 2] != -1) {
          local_158 = local_158 - local_14c;
          bVar8 = DAT_009213e4 != 0;
          bVar9 = DAT_009213e4 != 0;
          FUN_004015e0(&DAT_00751604,local_104);
          FUN_00511560(local_104,local_150,local_158,0x3f800000,0x3e8ccccd,0x3e8ccccd,0x3e8ccccd,
                       uVar3,0xff,0xff,0xff,0x3f19999a,2);
          local_148 = CONCAT22(local_148._2_2_,in_FPUControlWord);
          local_158 = local_158 - (_DAT_007fc358 - 0.01);
          local_154 = (float)(int)ROUND(local_11c[iVar6] * 128.0);
          FUN_0050d910(*(undefined4 *)(DAT_00926c20 + local_140[iVar6 + 2] * 4),local_150,local_158,
                       0x3f800000,0x3ecccccd,0x3e800000,0x3ecccccd,uVar3,
                       (-(uint)bVar8 & 0xffffffc1) + 0xff,(-(uint)bVar9 & 0xffffffd0) + 0xbf,0,
                       local_144,1,0,0,(uint)local_154 & 0xff);
        }
        iVar1 = local_140[iVar6 + 4];
        if (iVar1 != -1) {
          local_158 = local_158 - local_14c;
          bVar8 = DAT_009213e4 != 0;
          FUN_004f1f10(local_104,"[[back]]");
          FUN_00511560(local_104,local_150,local_158,0x3f800000,0x3e8ccccd,0x3e8ccccd,0x3e8ccccd,
                       uVar3,0xff,0xff,0xff,0x3f19999a,2);
          local_158 = local_158 - (_DAT_007fc358 - 0.01);
          FUN_0050d910(*(undefined4 *)(DAT_00926c20 + iVar1 * 4),local_150,local_158,0x3f800000,
                       0x3eb33333,0x3e800000,0x3ecccccd,uVar3,(-(uint)bVar8 & 0xffffffc0) + 0xff,0,0
                       ,local_144,1,0,0,0x80);
        }
        if (local_140[iVar6 + 6] != -1) {
          uVar4 = CONCAT31((int3)((uint)-DAT_009213e4 >> 8),-(DAT_009213e4 != 0)) & 0xffffffc5;
          uVar5 = CONCAT31((int3)(uVar4 >> 8),(char)uVar4 + -1);
          local_154 = (local_158 - local_14c) - (_DAT_007fc358 - 0.01);
          FUN_0050d910(*(undefined4 *)(DAT_00926c20 + local_140[iVar6 + 6] * 4),local_150,local_154,
                       0x3f800000,0x3ecccccd,0x3e800000,0x3ecccccd,uVar3,uVar5,0,uVar5,local_144,1,0
                       ,0,0x80);
        }
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 2);
    FUN_006d6340(local_120);
  }
  __security_check_cookie(local_4 ^ (uint)&local_158);
  return;
}

