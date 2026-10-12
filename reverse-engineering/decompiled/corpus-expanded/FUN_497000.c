/* Ghidra pseudocode, not original source.
 * ev_c8c236b59c094db138f75ad711126508fb50275f6e5d8f12ab0ad6308e4435ce
 * Entry: 0x497000; label: FUN_00497000
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00497000(void)

{
  float fVar1;
  float fVar2;
  short sVar3;
  short sVar4;
  float fVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined2 in_FPUControlWord;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  undefined1 local_84 [64];
  undefined1 local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_94;
  if (DAT_00921d24 == 0) {
    local_8c = _DAT_00921d5c;
    uVar6 = FUN_006e6b90();
    FUN_0050d910(*(undefined4 *)
                  (DAT_00926c20 + *(short *)(*DAT_009553d4 + 4 + DAT_0087b884 * 0x18) * 4),0,
                 _DAT_007faff8,0x3f800000,_DAT_007faffc,_DAT_007faffc,_DAT_007faffc,0,0xff,0xbf,0,
                 0x3fd9999a,1,0,0,uVar6);
    uVar6 = FUN_006e6b90();
    FUN_0050d910(*(undefined4 *)(DAT_00926c20 + DAT_00880ff0 * 4),0,0x3f066666,0x3f800000,
                 _DAT_007faffc,_DAT_007faffc,_DAT_007faffc,0,0xff,0xff,0xff,0x3fa00000,1,0,0,uVar6);
    if (((&DAT_0086e5ac)[DAT_0087b884] != '\0') &&
       (local_94 = _DAT_0087b880 * local_8c, 0.0 < local_94)) {
      local_90 = _DAT_007f92e4 + 0.1;
      FUN_00478d20(0xd3,_DAT_007fb000,local_90,local_94,0xffffffff,0xffffffff);
      FUN_0054bbc0(*(undefined4 *)(&DAT_0086e55c + DAT_0087b884 * 4),0,1,1,local_84);
      FUN_004f2740(local_44,"~0(~2%s~0)",local_84);
      fVar2 = local_94 * 128.0;
      local_94 = (float)CONCAT22(local_94._2_2_,in_FPUControlWord);
      local_90 = (float)(int)ROUND(fVar2);
      FUN_0050c780(local_44,_DAT_007fb004,_DAT_007fb008,0x3f800000,_DAT_007fb00c,_DAT_007fb00c,
                   _DAT_007fb00c,0,0,0xff,0,(uint)local_90 & 0xff);
    }
    iVar11 = 0;
    if ((char)DAT_009553d4[7] != '\0') {
      iVar12 = 0;
      piVar8 = DAT_009553d4;
      do {
        fVar2 = 1.0;
        local_94 = ((float)(&DAT_0087b790)[iVar11] * 0.3 + 0.7) * local_8c;
        local_90 = (float)(&DAT_0087b7e0)[iVar11] - 0.0;
        local_88 = ABS(local_90);
        if (local_88 <= 1.0) {
          if (0.5 < local_88) {
            local_94 = (1.0 - ((local_88 - 0.5) + (local_88 - 0.5))) * local_94;
          }
          fVar5 = local_94;
          if (0.0 < local_94) {
            if ((iVar11 == DAT_0087b884) && (DAT_009213e4 != 0)) {
              fVar2 = 0.7;
            }
            fVar1 = fVar2 * local_94;
            local_90 = _DAT_007fafe4 +
                       (float)(&DAT_0087b790)[iVar11] * (_DAT_007fafe8 - _DAT_007fafe4);
            local_94 = fVar2;
            FUN_0055b830((int)*(short *)(*piVar8 + iVar12),(&DAT_0087b7e0)[iVar11],_DAT_007faff4,0,
                         local_90,((&DAT_0086e5ac)[iVar11] != '\0') + 0xa7,fVar5,fVar1,1,0);
            piVar8 = DAT_009553d4;
          }
        }
        iVar11 = iVar11 + 1;
        iVar12 = iVar12 + 0x18;
      } while (iVar11 < (int)(uint)*(byte *)(piVar8 + 7));
    }
    local_94 = 1.0;
    if (DAT_0087b6c8 == '\0') {
      local_94 = _DAT_007fc2d8;
    }
    FUN_0055b830((int)DAT_0087b6c4,-_DAT_007fc31c,_DAT_007fc310,0,_DAT_007fc318,0xa6,local_94,
                 local_94,1,0);
    local_94 = _DAT_007fc2d8;
    if (DAT_0087b6c9 != '\0') {
      local_94 = 1.0;
    }
    FUN_0055b830((int)DAT_0087b6c6,_DAT_007fc31c,_DAT_007fc310,0,_DAT_007fc318,0xa5,local_94,
                 local_94,1,0);
    if ((DAT_0087b6c8 == '\0') || (DAT_0087b6c9 == '\0')) {
      iVar7 = (int)DAT_00880868;
      iVar9 = (int)DAT_00880824;
      iVar10 = (int)DAT_00880e8c;
      iVar11 = iVar10;
      iVar12 = iVar7;
      iVar13 = iVar9;
    }
    else {
      if (DAT_0087b6cc == '\0') {
        iVar12 = (int)DAT_00880868;
        sVar3 = DAT_00880824;
        sVar4 = DAT_00880e8c;
      }
      else {
        iVar12 = -1;
        sVar3 = DAT_00880870;
        sVar4 = DAT_00880e90;
      }
      iVar11 = (int)sVar4;
      iVar13 = (int)sVar3;
      if (DAT_0087b6cd == '\0') {
        iVar7 = (int)DAT_00880868;
        iVar9 = (int)DAT_00880824;
        iVar10 = (int)DAT_00880e8c;
      }
      else {
        iVar10 = (int)DAT_00880e90;
        iVar7 = -1;
        iVar9 = (int)DAT_00880870;
      }
    }
    FUN_004b79a0(DAT_0087b6c8,iVar12,0x3f800000,0xffffffff,iVar13,0xffffffff,iVar11,DAT_0087b6c9,
                 iVar7,0x3f800000,0xffffffff,iVar9,0xffffffff,iVar10);
  }
  __security_check_cookie(local_4 ^ (uint)&local_94);
  return;
}

