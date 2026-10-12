/* Ghidra pseudocode, not original source.
 * ev_2606baf984ee455df312fc83a5be5e2bd228e340f9dbc5529ae9524aab57b603
 * Entry: 0x47dce0; label: FUN_0047dce0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0047dce0(void)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  float fVar4;
  byte bVar5;
  undefined4 uVar6;
  char *pcVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  float10 fVar14;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float local_130;
  float local_12c;
  float local_128;
  float local_124;
  int local_120;
  int local_11c;
  int local_118;
  int local_114;
  int local_110;
  int local_10c;
  int local_108;
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_130;
  fVar14 = (float10)0.8;
  iVar13 = 0;
  if ((DAT_0087b738 == 0) || (_DAT_0087b73c < 2.0)) goto LAB_0047de24;
  if (2.5 <= _DAT_0087b73c) {
    if (7.5 <= _DAT_0087b73c) {
      if (8.0 <= _DAT_0087b73c) goto LAB_0047de24;
      local_12c = 1.0 - ((_DAT_0087b73c - 7.5) + (_DAT_0087b73c - 7.5));
      goto LAB_0047de06;
    }
    local_12c = 1.0;
  }
  else {
    local_12c = (_DAT_0087b73c - 2.0) * 2.0;
LAB_0047de06:
    if (local_12c <= 0.0) goto LAB_0047de24;
  }
  uVar6 = FUN_006e6b90();
  local_124 = (_DAT_007f92ec + _DAT_007f92e4) * 0.5;
  FUN_0050d910(*(undefined4 *)(DAT_00926c20 + DAT_008806d8 * 4),(float)extraout_ST0,local_124,
               (float)fVar14,(float)extraout_ST1,(float)extraout_ST1,(float)extraout_ST1,0,
               DAT_007f92f4,DAT_007f92f8,DAT_00879b1c,0x3fd9999a,1,0,0,uVar6);
LAB_0047de24:
  FUN_004c6c50();
  iVar9 = DAT_00879554;
  if ((DAT_00879554 != -1) && (0.0 < _DAT_00879574)) {
    local_124 = (float)FUN_006e6b90();
    if (iVar9 == 6) {
      iVar11 = 0;
      iVar9 = 0;
      local_10c = 0;
      local_128 = 0.0;
      local_110 = 0;
      local_118 = 0;
      local_12c = 0.0;
      local_114 = 0;
      local_11c = 0;
      local_108 = 0;
      local_120 = 0;
      if (0 < DAT_00956294) {
        do {
          FUN_0059b840(iVar9,0xffffffff,&DAT_0086e0f4);
          local_10c = local_10c + DAT_00956250;
          local_128 = (float)((int)local_128 + DAT_00956284);
          local_110 = local_110 + DAT_00956288;
          iVar11 = iVar11 + DAT_00956268;
          iVar13 = iVar13 + DAT_00956274;
          if (DAT_0093b314 != 0) {
            local_118 = local_118 + DAT_00956278;
            local_12c = (float)((int)local_12c + DAT_00956270);
            local_114 = local_114 + DAT_00956280;
            local_11c = local_11c + DAT_00956260;
          }
          local_108 = local_108 + DAT_0095626c;
          local_120 = local_120 + DAT_0095627c;
          iVar9 = iVar9 + 1;
        } while (iVar9 < DAT_00956294);
      }
      _DAT_007f930c = 0.8;
      iVar9 = FUN_006e6b90(0x3f800000,0x3f800000,0);
      local_130 = (_DAT_00805270 + _DAT_007f92ec) - _DAT_00805278;
      if (DAT_0093b314 == 0) {
        FUN_004b86f0(*(undefined4 *)(PTR_DAT_007fa200 + 4),local_130,100,100,
                     (&DAT_029899a0)[iVar9 >> 1 & 0x7fff]);
        _sprintf(local_104,"%i/%i",iVar11,iVar13);
        local_130 = _DAT_00805274 * _DAT_007f930c;
        FUN_0050c780(local_104,*(undefined4 *)(PTR_DAT_007fa200 + 4),_DAT_007f92ec,0x3f800000,
                     local_130,_DAT_00805274,_DAT_00805274,0,0xff,0,0x7f,local_124);
      }
      else {
        FUN_004b86f0(*(undefined4 *)(PTR_DAT_007fa200 + 4),local_130,100,100,
                     (&DAT_029899a0)[iVar9 >> 1 & 0x7fff]);
        _sprintf(local_104,"%i/%i",local_118,local_12c);
        fVar4 = local_124;
        local_130 = _DAT_00805274 * _DAT_007f930c;
        FUN_0050c780(local_104,*(undefined4 *)(PTR_DAT_007fa200 + 4),_DAT_007f92ec,0x3f800000,
                     local_130,_DAT_00805274,_DAT_00805274,0,0xff,0,0x7f,local_124);
        uVar6 = FUN_006e6b90();
        local_130 = _DAT_007f9310 + _DAT_007f92ec;
        FUN_0050d910(*(undefined4 *)(DAT_00926c20 + DAT_00880884 * 4),
                     *(undefined4 *)(PTR_DAT_007fa200 + 4),local_130,0x3f800000,_DAT_007f9314,
                     _DAT_007f9314,_DAT_007f9314,0,DAT_007f931c,DAT_007f9320,DAT_007f9324,
                     _DAT_007f9318,1,0,0,uVar6);
        iVar13 = FUN_006e6b90(0x3f800000,0x3f800000,0);
        local_130 = (_DAT_00805270 + _DAT_007f92ec) - _DAT_00805278;
        FUN_004b86f0(*(undefined4 *)(PTR_DAT_007fa200 + 0x10),local_130,100,100,
                     (&DAT_029899a0)[iVar13 >> 1 & 0x7fff]);
        _sprintf(local_104,"%i/%i",local_114,local_11c);
        local_130 = _DAT_00805274 * _DAT_007f930c;
        FUN_0050c780(local_104,*(undefined4 *)(PTR_DAT_007fa200 + 0x10),_DAT_007f92ec,0x3f800000,
                     local_130,_DAT_00805274,_DAT_00805274,0,0xff,0,0x7f,fVar4);
        uVar6 = FUN_006e6b90();
        local_130 = _DAT_007f9310 + _DAT_007f92ec;
        FUN_0050d910(*(undefined4 *)(DAT_00926c20 + DAT_00880888 * 4),
                     *(undefined4 *)(PTR_DAT_007fa200 + 0x10),local_130,0x3f800000,_DAT_007f9314,
                     _DAT_007f9314,_DAT_007f9314,0,DAT_007f931c,DAT_007f9320,DAT_007f9324,
                     _DAT_007f9318,1,0,0,uVar6);
      }
      FUN_00478b00(*(undefined4 *)PTR_DAT_007fa200,_DAT_007f92ec,local_10c,_DAT_00879574);
      FUN_00478d20(0xd2,*(undefined4 *)(PTR_DAT_007fa200 + 8),_DAT_007f92ec,_DAT_00879574,local_108,
                   local_120);
      FUN_00478d20(0xd3,*(undefined4 *)(PTR_DAT_007fa200 + 0xc),_DAT_007f92ec,_DAT_00879574,
                   DAT_0086e4e2,DAT_0093b30c);
      DAT_00879b70 = 1;
      FUN_00478b00(*(undefined4 *)(PTR_DAT_007fa200 + 0x14),_DAT_007f92ec,local_110,_DAT_00879574);
      _DAT_007f930c = 1.0;
    }
    else if (iVar9 == 7) {
      if (DAT_009553d4 != 0) {
        uVar6 = FUN_0058a9b0(DAT_009553d4,&DAT_0086e55c,0,*(undefined1 *)(DAT_009553d4 + 0x1c));
        FUN_00478d20(0xd3,0,_DAT_007f92ec,_DAT_00879574,uVar6);
      }
    }
    else if (iVar9 == 8) {
      iVar13 = 0;
      iVar9 = 0;
      if (0 < DAT_00951360) {
        pcVar7 = &DAT_0086e0f5;
        iVar11 = DAT_00951354;
        iVar10 = DAT_00951360;
        iVar12 = iVar13;
        do {
          iVar13 = iVar12;
          if ((((iVar11 != DAT_00951364) &&
               (uVar2 = *(ushort *)(iVar11 + 0x7a), (uVar2 & 0x22) == 0)) &&
              (*(char *)(iVar11 + 0x86) == -1)) &&
             (((uVar2 & 0x10) == 0 && ((uVar2 & 0x2000) == 0)))) {
            if ((uVar2 & 0x100) == 0) {
              if ((uVar2 & 4) == 0) {
                if ((uVar2 & 0x800) == 0) goto LAB_0047e497;
              }
              else {
                local_130 = (float)(uint)*(ushort *)(iVar11 + 0x84);
                iVar13 = iVar12 + 1;
                if (*(float *)(pcVar7 + 7) < (float)(int)local_130) goto LAB_0047e49f;
              }
            }
            else if (DAT_0093b318 != 0) {
LAB_0047e497:
              iVar13 = iVar12 + 1;
              if (*pcVar7 != '\0') {
LAB_0047e49f:
                iVar9 = iVar9 + 1;
                iVar13 = iVar12 + 1;
              }
            }
          }
          pcVar7 = pcVar7 + 0xc;
          iVar11 = iVar11 + 0x9c;
          iVar10 = iVar10 + -1;
          iVar12 = iVar13;
        } while (iVar10 != 0);
      }
      local_128 = (float)extraout_ST1_00;
      fVar14 = extraout_ST0_00;
      if (DAT_0086e4e5 != '\0') {
        local_130 = _DAT_007f92e4 - 0.225;
        FUN_00478d20(0xfb,0x3dcccccd,local_130,(float)extraout_ST0_00,0xffffffff,0xffffffff);
        local_128 = -0.1;
        fVar14 = (float10)_DAT_00879574;
      }
      FUN_00478d20(0xd3,local_128,_DAT_007f92e4,(float)fVar14,iVar9,iVar13);
      FUN_0050d910(*(undefined4 *)(DAT_00926c20 + DAT_008807c4 * 4),0,_DAT_007f92ec,0x3f800000,
                   _DAT_007f92f0,_DAT_007f92f0,_DAT_007f92f0,0,DAT_007f92f4,DAT_007f92f8,
                   DAT_00879b1c,0x3fd9999a,1,0,0,local_124);
    }
    else if ((-1 < iVar9) && (iVar9 < DAT_00956294)) {
      FUN_0047a2d0((float)extraout_ST0_00);
    }
  }
  if ((DAT_00879b00 != 0xffffffff) && (0.0 < _DAT_00879508)) {
    uVar2 = *(ushort *)(DAT_00879b00 * 0x9c + DAT_00951354 + 0x7a);
    if ((uVar2 & 0x100) == 0) {
      if ((uVar2 & 4) == 0) {
        FUN_00478f30(_DAT_00879508,DAT_00879b00,0xffffffff);
      }
      else if ((DAT_0087b030 == 0) || (DAT_00879b00 != *(byte *)(DAT_0087b030 + 0x7c))) {
        FUN_0047ab00(_DAT_00879508,DAT_00879b00,0xffffffff);
      }
      else {
        FUN_00475890(_DAT_00879508);
      }
    }
    else {
      FUN_0047af70(_DAT_00879508);
    }
  }
  iVar13 = FUN_00574e20();
  if (iVar13 == 0xe) {
    FUN_00479710(_DAT_00879b38);
  }
  if ((DAT_00879558 != -1) && (0.0 < _DAT_00879594)) {
    if (DAT_00879558 == 999) {
      uVar3 = (uint)*(byte *)(DAT_0087a7e0 + 0x6c) * 2;
      uVar8 = (uint)DAT_0086e4e2;
      if (uVar3 < DAT_0086e4e2) {
        uVar8 = uVar3;
      }
      FUN_00478d20(0xd3,0,_DAT_007f92ec,_DAT_00879594,uVar8,uVar3);
      __security_check_cookie(local_4 ^ (uint)&local_130);
      return;
    }
    if ((int *)(&DAT_007f939c)[DAT_00879558 * 0xf] != (int *)0x0) {
      bVar1 = *(byte *)(*(int *)(&DAT_007f939c)[DAT_00879558 * 0xf] + 0x6c);
      bVar5 = DAT_0086e4e2;
      if (bVar1 < DAT_0086e4e2) {
        bVar5 = bVar1;
      }
      FUN_00478d20(0xd3,0,_DAT_007f92ec,_DAT_00879594,bVar5,bVar1);
      __security_check_cookie(local_4 ^ (uint)&local_130);
      return;
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_130);
  return;
}

