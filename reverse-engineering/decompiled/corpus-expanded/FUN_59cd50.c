/* Ghidra pseudocode, not original source.
 * ev_57e4595202f6848139a561b6e4253d561eb3ad03e2f9632ed29ba9ff4f0bafc7
 * Entry: 0x59cd50; label: FUN_0059cd50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0059cd50(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  float fVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char cVar8;
  int iVar9;
  int iVar10;
  float10 fVar11;
  float local_118;
  undefined4 local_114;
  undefined4 local_110;
  int local_10c;
  float local_108;
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_118;
  _DAT_009562ac = 0.0;
  _DAT_00805434 = 120.0;
  local_114 = param_2;
  local_110 = param_3;
  cVar8 = '\0';
  puVar3 = &DAT_00805444;
  do {
    puVar3[4] = *puVar3;
    puVar3[5] = puVar3[1];
    puVar3[6] = puVar3[2];
    puVar3[0xb] = cVar8;
    puVar3[7] = puVar3[3];
    puVar3 = puVar3 + 0x18;
    cVar8 = cVar8 + '\x01';
  } while ((int)puVar3 < 0x8054bc);
  FUN_004f1f10(local_104,"stuff\\text\\");
  FUN_004f1e80(local_104,"english");
  FUN_004f1e80(local_104,"_credits.txt");
  iVar4 = FUN_00552670(param_2,param_3,24000);
  iVar10 = 0;
  DAT_009562a4 = 0;
  local_10c = 0;
  DAT_009562a0 = iVar4;
  if ((iVar4 != 0) && (iVar5 = FUN_004fc860(local_104), iVar5 != 0)) {
    local_118 = 0.0;
    iVar6 = FUN_004fc5b0(iVar5);
    while (iVar6 != 0) {
      iVar6 = FUN_004f7fb0(iVar5);
      iVar9 = iVar4;
      if (iVar6 == 0) goto LAB_0059d1a5;
      iVar6 = FUN_004f8b10(*(undefined4 *)(iVar5 + 0x510),"duration");
      if (iVar6 == 0) {
        iVar4 = FUN_004f7fb0(iVar5);
        if ((iVar4 != 0) && (_DAT_00805434 == 120.0)) {
          fVar11 = (float10)FUN_004f28e0(*(undefined4 *)(iVar5 + 0x510));
          local_108 = (float)fVar11;
          if (0.0 < local_108) {
            _DAT_00805434 = local_108;
          }
        }
        goto LAB_0059d1a5;
      }
      iVar6 = FUN_0059cb90(*(undefined4 *)(iVar5 + 0x510));
      if ((iVar6 == 0) || (iVar7 = FUN_004f7fb0(iVar5), iVar7 == 0)) goto LAB_0059d1a5;
      iVar7 = FUN_004f8b10(*(undefined4 *)(iVar5 + 0x510),"colour");
      if (iVar7 == 0) {
        FUN_0059cbe0(iVar6 + 0x10,0xff);
        FUN_0059cbe0(iVar6 + 0x11,0xff);
        FUN_0059cbe0(iVar6 + 0x12,0xff);
        FUN_0059cbe0(iVar6 + 0x13,0x80);
        iVar10 = local_10c;
        goto LAB_0059d1a5;
      }
      if (999 < DAT_009562a4) goto LAB_0059d1a5;
      uVar1 = *(undefined1 *)(iVar6 + 0x17);
      *(undefined1 *)(iVar4 + 0x15) = uVar1;
      switch(uVar1) {
      case 0:
        if ((iVar10 == 0) || (*(char *)(iVar10 + 0x15) != '\x01')) {
          local_118 = (_DAT_0080543c / _DAT_00805454) * 0.2 + local_118;
        }
        FUN_0059ccd0(*(undefined4 *)(iVar5 + 0x510),0,local_118,*(undefined4 *)(iVar6 + 4),
                     *(undefined1 *)(iVar6 + 0x10),*(undefined1 *)(iVar6 + 0x11),
                     *(undefined1 *)(iVar6 + 0x12),*(undefined1 *)(iVar6 + 0x13),1,local_114,
                     local_110);
        local_108 = (_DAT_0080543c / _DAT_00805454) * 0.2 + local_118;
        local_118 = local_108 + 0.1;
        break;
      case 1:
        if ((iVar10 != 0) && (*(char *)(iVar10 + 0x15) != '\0')) {
          local_118 = (_DAT_00805454 / _DAT_00805454) * 0.2 + local_118;
        }
        FUN_0059ccd0(*(undefined4 *)(iVar5 + 0x510),0,local_118,*(undefined4 *)(iVar6 + 4),
                     *(undefined1 *)(iVar6 + 0x10),*(undefined1 *)(iVar6 + 0x11),
                     *(undefined1 *)(iVar6 + 0x12),*(undefined1 *)(iVar6 + 0x13),1,local_114,
                     local_110);
        fVar2 = _DAT_00805454 / _DAT_00805454;
        goto LAB_0059d17e;
      case 2:
        FUN_0059ccd0(*(undefined4 *)(iVar5 + 0x510),0xbc75c28f,local_118,*(undefined4 *)(iVar6 + 4),
                     *(undefined1 *)(iVar6 + 0x10),*(undefined1 *)(iVar6 + 0x11),
                     *(undefined1 *)(iVar6 + 0x12),*(undefined1 *)(iVar6 + 0x13),9,local_114,
                     local_110);
        break;
      case 3:
        FUN_0059ccd0(*(undefined4 *)(iVar5 + 0x510),0x3c75c28f,local_118,*(undefined4 *)(iVar6 + 4),
                     *(undefined1 *)(iVar6 + 0x10),*(undefined1 *)(iVar6 + 0x11),
                     *(undefined1 *)(iVar6 + 0x12),*(undefined1 *)(iVar6 + 0x13),3,local_114,
                     local_110);
        fVar2 = _DAT_00805484;
        goto LAB_0059d178;
      case 4:
        FUN_0059ccd0(*(undefined4 *)(iVar5 + 0x510),0,local_118,*(undefined4 *)(iVar6 + 4),
                     *(undefined1 *)(iVar6 + 0x10),*(undefined1 *)(iVar6 + 0x11),
                     *(undefined1 *)(iVar6 + 0x12),*(undefined1 *)(iVar6 + 0x13),1,local_114,
                     local_110);
        fVar2 = _DAT_0080549c;
LAB_0059d178:
        fVar2 = fVar2 / _DAT_00805454;
LAB_0059d17e:
        local_118 = fVar2 * 0.2 + local_118;
      }
      DAT_009562a4 = DAT_009562a4 + 1;
      iVar9 = iVar4 + 0x18;
      iVar10 = iVar4;
      local_10c = iVar4;
LAB_0059d1a5:
      _DAT_009562ac = local_118 + 2.2;
      iVar6 = FUN_004fc5b0(iVar5);
      iVar4 = iVar9;
    }
    FUN_004fa300(iVar5);
  }
  __security_check_cookie(local_4 ^ (uint)&local_118);
  return;
}

