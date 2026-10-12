/* Ghidra pseudocode, not original source.
 * ev_b978e2ca46034d20a029bc1dc30b8253616b522a4771dca24a925efe269276a9
 * Entry: 0x568a80; label: FUN_00568a80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00568a80(int param_1)

{
  uint *puVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  char cVar4;
  undefined2 uVar5;
  short sVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  int iVar10;
  float *pfVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  bool bVar17;
  float10 fVar18;
  int local_548;
  int local_544;
  undefined4 *local_540;
  int local_53c;
  undefined4 *local_538;
  float local_534;
  float local_530;
  float local_52c;
  int local_528;
  undefined4 local_524;
  undefined4 local_520;
  undefined4 local_51c;
  undefined4 local_518 [12];
  int local_4e8 [3];
  undefined1 local_4dc [12];
  undefined1 local_4d0 [12];
  undefined4 local_4c4;
  undefined4 local_4c0;
  undefined4 local_4bc;
  float local_4a0;
  undefined4 local_49c;
  undefined4 local_498;
  float local_494;
  float local_490;
  float local_48c;
  float local_484;
  float local_480;
  float local_47c;
  undefined4 local_478;
  undefined4 local_474;
  undefined4 local_470;
  undefined2 local_46c;
  undefined4 local_46a;
  undefined1 local_464 [36];
  undefined1 local_440 [32];
  undefined1 local_420;
  undefined1 local_41f;
  undefined1 local_41e;
  undefined1 local_41d;
  undefined4 local_418 [28];
  float local_3a8;
  float local_3a4;
  float local_3a0;
  float local_39c;
  float local_398;
  float local_394;
  float local_390;
  float local_38c;
  float local_388;
  uint local_380;
  uint local_37c;
  undefined4 local_378;
  int local_374;
  float local_36c;
  float local_368;
  float local_360;
  float local_358;
  float local_354;
  float local_350;
  float local_348;
  float local_344;
  undefined2 local_33c;
  undefined2 local_33a;
  undefined2 local_338;
  undefined2 local_336;
  undefined2 local_334;
  undefined2 local_332;
  undefined2 local_330;
  undefined2 local_32e;
  undefined2 local_32c;
  undefined2 local_32a;
  undefined2 local_328;
  undefined1 local_326 [16];
  undefined1 local_316;
  undefined1 local_30c;
  undefined1 local_30b;
  undefined1 local_309;
  undefined1 local_308;
  undefined1 local_307;
  undefined4 local_304;
  undefined4 local_300;
  undefined4 local_2fc;
  undefined4 local_2f8;
  undefined1 local_2f4;
  undefined1 local_204 [256];
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_548;
  iVar14 = 0;
  local_538 = (undefined4 *)0x0;
  local_544 = 0;
  if (((*(void **)(param_1 + 0x50c4) == (void *)0x0) || (*(int *)(param_1 + 0x50c8) == 0)) ||
     (_memset(*(void **)(param_1 + 0x50c4),0,
              (uint)*(ushort *)(*(int *)(param_1 + 0x128) + 0xdc) << 8),
     *(int *)(param_1 + 0x50c0) != 0)) {
    __security_check_cookie(local_4 ^ (uint)&local_548);
    return;
  }
  iVar7 = FUN_006217e0();
  if (1 < iVar7) {
    iVar14 = FUN_006217e0();
  }
  local_528 = FUN_006217e0();
  if (1 < iVar7) {
    local_540 = *(undefined4 **)(param_1 + 0x50c4);
    if (0 < iVar14) {
      do {
        local_548 = iVar14;
        local_53c = 0;
        _memset(local_518,0,0x100);
        cVar4 = FUN_006218c0();
        FUN_006216f0(&local_304,(int)cVar4);
        FUN_004f1f10(local_440,&local_304);
        cVar4 = FUN_006218c0();
        FUN_006216f0(&local_304,(int)cVar4);
        FUN_0055acd0(*(undefined4 *)(param_1 + 0x13c),local_4e8,&local_304,1,
                     *(undefined4 *)(param_1 + 0x2ac8),"BlowUp",local_440);
        iVar14 = FUN_005cfac0(local_4e8);
        if (iVar14 == 0) {
          local_53c = 1;
        }
        local_478 = 0xffffffff;
        if (iVar7 < 0x11) {
          if (iVar7 < 5) {
            uVar5 = FUN_00621860();
          }
          else {
            cVar4 = FUN_006218c0();
            if (cVar4 < '\x01') goto LAB_00568c79;
            FUN_006216f0(local_104,(int)cVar4);
            uVar5 = FUN_0064afd0(local_104);
          }
          local_478 = CONCAT22(local_478._2_2_,uVar5);
        }
        else {
          iVar14 = 0;
          do {
            cVar4 = FUN_006218c0();
            if ('\0' < cVar4) {
              FUN_006216f0(local_104,(int)cVar4);
              uVar3 = *(undefined4 *)(param_1 + 0x2a9c);
              *(undefined2 *)((int)&local_478 + iVar14 * 2) = 0xffff;
              uVar5 = FUN_0064b020(local_104,uVar3);
              *(undefined2 *)((int)&local_478 + iVar14 * 2) = uVar5;
            }
            iVar14 = iVar14 + 1;
          } while (iVar14 < 2);
        }
LAB_00568c79:
        local_470 = 0xffffffff;
        local_46c = 0xffff;
        local_474 = 0xffffffff;
        local_46a = 0xffffffff;
        if (3 < iVar7) {
          iVar14 = 0;
          do {
            cVar4 = FUN_006218c0();
            if ('\0' < cVar4) {
              FUN_006216f0(local_204,(int)cVar4);
              uVar2 = *(undefined1 *)(param_1 + 0x2a98);
              *(undefined2 *)((int)&local_470 + iVar14 * 2) = 0xffff;
              uVar5 = FUN_00658490(local_204,uVar2);
              *(undefined2 *)((int)&local_470 + iVar14 * 2) = uVar5;
            }
            iVar14 = iVar14 + 1;
          } while (iVar14 < 3);
        }
        if (0x19 < iVar7) {
          iVar14 = 0;
          do {
            cVar4 = FUN_006218c0();
            if ('\0' < cVar4) {
              FUN_006216f0(local_204,(int)cVar4);
              *(undefined2 *)((int)&local_474 + iVar14 * 2) = 0xffff;
              uVar5 = FUN_00658570(local_204);
              *(undefined2 *)((int)&local_474 + iVar14 * 2) = uVar5;
            }
            iVar14 = iVar14 + 1;
          } while (iVar14 < 2);
        }
        if (0x1a < iVar7) {
          iVar14 = 0;
          do {
            cVar4 = FUN_006218c0();
            if ('\0' < cVar4) {
              FUN_006216f0(local_204,(int)cVar4);
              *(undefined2 *)((int)&local_46a + iVar14 * 2) = 0xffff;
              uVar5 = FUN_00658570(local_204);
              *(undefined2 *)((int)&local_46a + iVar14 * 2) = uVar5;
            }
            iVar14 = iVar14 + 1;
          } while (iVar14 < 2);
        }
        local_49c = FUN_006217e0();
        if (iVar7 < 7) {
          local_498 = 100;
          local_41d = 1;
        }
        else {
          local_498 = FUN_006217e0();
          local_41d = FUN_006218c0();
        }
        if (iVar7 < 8) {
          fVar18 = (float10)0;
        }
        else {
          fVar18 = (float10)FUN_006217a0();
        }
        local_4a0 = (float)fVar18;
        if (8 < iVar7) {
          _memset(&local_304,0,0x100);
          cVar4 = FUN_006218c0();
          if ('\0' < cVar4) {
            FUN_006216f0(&local_304,(int)cVar4);
            FUN_0055acd0(*(undefined4 *)(param_1 + 0x13c),local_4dc,&local_304,1,
                         *(undefined4 *)(param_1 + 0x2ac8),"BlowUpDecal",local_440);
          }
        }
        if (iVar7 < 0xe) {
          local_490 = 1.0;
          iVar14 = FUN_005d0420(local_4e8);
          if (iVar14 == 0) {
            fVar18 = (float10)1;
          }
          else {
            fVar18 = (float10)FUN_005ca4b0(*(undefined4 *)
                                            (*(int *)(local_4e8[0] + 0x54) +
                                            (uint)*(ushort *)(iVar14 + 0x5c) * 4));
          }
        }
        else {
          fVar18 = (float10)FUN_006217a0();
          local_490 = (float)fVar18;
          fVar18 = (float10)FUN_006217a0();
        }
        local_48c = (float)fVar18;
        if (iVar7 < 0xf) {
          local_420 = 0;
          local_41f = 0;
        }
        else {
          local_420 = FUN_006218c0();
          local_41f = FUN_006218c0();
        }
        if (iVar7 < 0x10) {
          iVar14 = FUN_005cfac0(local_4e8);
          if (iVar14 != 0) {
            FUN_0059ae10(local_464,local_4e8);
          }
        }
        else {
          FUN_0059af60(local_464);
        }
        if (iVar7 < 0x16) {
          if (iVar7 < 0x12) {
            local_41e = 0;
            local_484 = -10.0;
            fVar18 = (float10)1;
          }
          else {
            _memset(&local_304,0,0x100);
            cVar4 = FUN_006218c0();
            if ('\0' < cVar4) {
              FUN_006216f0(&local_304,(int)cVar4);
              FUN_0055acd0(*(undefined4 *)(param_1 + 0x13c),local_518,&local_304,1,
                           *(undefined4 *)(param_1 + 0x2ac8),"BlowUpEmitObj",local_440);
            }
            local_41e = FUN_006218c0();
            fVar18 = (float10)FUN_006217a0();
            local_484 = (float)fVar18;
            fVar18 = (float10)FUN_006217a0();
          }
        }
        else {
          puVar15 = local_518;
          iVar14 = 4;
          do {
            _memset(&local_304,0,0x100);
            cVar4 = FUN_006218c0();
            if ('\0' < cVar4) {
              FUN_006216f0(&local_304,(int)cVar4);
              FUN_0055acd0(*(undefined4 *)(param_1 + 0x13c),puVar15,&local_304,1,
                           *(undefined4 *)(param_1 + 0x2ac8),"BlowUpEmitObj",local_440);
            }
            puVar15 = puVar15 + 3;
            iVar14 = iVar14 + -1;
          } while (iVar14 != 0);
          local_41e = FUN_006218c0();
          fVar18 = (float10)FUN_006217a0();
          local_484 = (float)fVar18;
          fVar18 = (float10)FUN_006217a0();
        }
        local_480 = (float)fVar18;
        if (0x12 < iVar7) {
          local_304 = 0;
          local_300 = 0;
          local_2fc = 0;
          local_2f8 = 0;
          cVar4 = FUN_006218c0();
          if ('\0' < cVar4) {
            FUN_006216f0(&local_304,(int)cVar4);
            local_2f4 = 0;
            FUN_0055acd0(*(undefined4 *)(param_1 + 0x13c),local_4d0,&local_304,1,
                         *(undefined4 *)(param_1 + 0x2ac8),"BlowUpShadow",local_440);
          }
        }
        if (0x13 < iVar7) {
          local_304 = 0;
          local_300 = 0;
          local_2fc = 0;
          local_2f8 = 0;
          local_4c4 = 0;
          local_4c0 = 0;
          local_4bc = 0;
          cVar4 = FUN_006218c0();
          if ('\0' < cVar4) {
            FUN_006216f0(&local_304,(int)cVar4);
            FUN_0055acd0(*(undefined4 *)(param_1 + 0x13c),&local_4c4,&local_304,1,
                         *(undefined4 *)(param_1 + 0x2ac8),"BlowUpSwap",local_440);
          }
        }
        if (0x16 < iVar7) {
          fVar18 = (float10)FUN_006217a0();
          local_47c = (float)fVar18;
        }
        if (0x17 < iVar7) {
          fVar18 = (float10)FUN_006217a0();
          local_494 = (float)fVar18;
        }
        if (local_53c == 0) {
          local_544 = local_544 + 1;
          puVar8 = local_540 + 0x40;
          puVar15 = local_518;
          puVar16 = local_540;
          for (iVar14 = 0x40; local_540 = puVar8, iVar14 != 0; iVar14 = iVar14 + -1) {
            *puVar16 = *puVar15;
            puVar15 = puVar15 + 1;
            puVar16 = puVar16 + 1;
          }
        }
        local_548 = local_548 + -1;
        iVar14 = local_548;
      } while (local_548 != 0);
    }
    *(int *)(param_1 + 0x50bc) = local_544;
  }
  if (0 < local_528) {
    local_548 = local_528;
    do {
      _memset(local_418,0,0x114);
      cVar4 = FUN_006218c0();
      FUN_006216f0(&local_304,(int)cVar4);
      if (1 < iVar7) {
        cVar4 = FUN_006218c0();
        FUN_006216f0(local_326,(int)cVar4);
        local_316 = 0;
      }
      iVar14 = FUN_005689f0(&local_304,param_1);
      if (iVar14 != 0) {
        local_538 = (undefined4 *)(*(int *)(param_1 + 0x50c0) * 0x114 + *(int *)(param_1 + 0x50c8));
        *(int *)(param_1 + 0x50c0) = *(int *)(param_1 + 0x50c0) + 1;
        local_374 = iVar14;
      }
      FUN_00621900(&local_524);
      local_330 = FUN_00621860();
      local_32e = FUN_00621860();
      local_32c = FUN_00621860();
      local_378 = 0;
      local_30b = 1;
      local_30c = 0;
      if (1 < iVar7) {
        if (iVar7 < 0x14) {
          local_380 = 0;
          sVar6 = FUN_00621860();
          uVar9 = (uint)sVar6;
        }
        else if ((iVar7 < 0x1c) || (0x1c < iVar7)) {
          local_380 = 0;
          uVar9 = FUN_006217e0();
        }
        else {
          local_380 = 0;
          uVar9 = FUN_006217e0();
          FUN_006217e0();
        }
        local_37c = 0;
        if (iVar7 < 0x1e) {
          bVar17 = (uVar9 & 0x100) != 0;
          if (bVar17) {
            uVar9 = uVar9 & 0xfffffeff;
          }
          local_37c = (uint)bVar17;
          local_380 = uVar9;
          if ((uVar9 & 0x40000000) != 0) {
            local_37c = local_37c | 4;
            local_380 = uVar9 & 0xbfffffff;
          }
        }
        else {
          local_380 = uVar9;
          local_37c = FUN_006217e0();
        }
        if (iVar7 == 2) {
          local_380 = local_380 | 5;
        }
        local_378 = FUN_006217e0();
        local_30b = FUN_006218c0();
        local_30c = FUN_006218c0();
      }
      local_309 = 0;
      if (3 < iVar7) {
        local_309 = FUN_006218c0();
      }
      local_36c = 0.0;
      if (5 < iVar7) {
        fVar18 = (float10)FUN_006217a0();
        local_36c = (float)fVar18;
      }
      if (iVar7 < 8) {
        fVar18 = (float10)0;
        local_368 = (float)fVar18;
      }
      else {
        fVar18 = (float10)FUN_006217a0();
        local_368 = (float)fVar18;
        fVar18 = (float10)FUN_006217a0();
      }
      local_360 = (float)fVar18;
      if (8 < iVar7) {
        local_33c = FUN_00621860();
        local_33a = FUN_00621860();
        local_338 = FUN_00621860();
        fVar18 = (float10)FUN_006217a0();
        local_3a8 = (float)fVar18;
        fVar18 = (float10)FUN_006217a0();
        local_3a4 = (float)fVar18;
        fVar18 = (float10)FUN_006217a0();
        local_3a0 = (float)fVar18;
      }
      if (iVar7 < 10) {
        fVar18 = (float10)1;
      }
      else {
        fVar18 = (float10)FUN_006217a0();
      }
      local_358 = (float)fVar18;
      if (iVar7 < 0xb) {
        fVar18 = (float10)0;
        local_39c = (float)fVar18;
        local_398 = (float)fVar18;
      }
      else {
        fVar18 = (float10)FUN_006217a0();
        local_39c = (float)fVar18;
        fVar18 = (float10)FUN_006217a0();
        local_398 = (float)fVar18;
        fVar18 = (float10)FUN_006217a0();
      }
      local_394 = (float)fVar18;
      if (iVar7 < 0xc) {
        local_307 = 1;
        local_308 = 1;
      }
      else {
        local_307 = FUN_006218c0();
        local_308 = local_307;
      }
      local_308 = local_307;
      if (iVar7 < 0xd) {
        local_32a = 0;
        local_328 = 0;
      }
      else {
        local_32a = FUN_00621860();
        local_328 = FUN_00621860();
      }
      if (0x12 < iVar7) {
        local_336 = FUN_00621860();
        local_334 = FUN_00621860();
        local_332 = FUN_00621860();
        fVar18 = (float10)FUN_006217a0();
        local_390 = (float)fVar18;
        fVar18 = (float10)FUN_006217a0();
        local_38c = (float)fVar18;
        fVar18 = (float10)FUN_006217a0();
        local_388 = (float)fVar18;
        fVar18 = (float10)FUN_006217a0();
        local_354 = (float)fVar18;
      }
      local_350 = 0.0;
      if (0x14 < iVar7) {
        fVar18 = (float10)FUN_006217a0();
        local_350 = (float)fVar18;
      }
      if (0x16 < iVar7) {
        fVar18 = (float10)FUN_006217a0();
        local_348 = (float)fVar18;
      }
      if (0x1e < iVar7) {
        fVar18 = (float10)FUN_006217a0();
        local_344 = (float)fVar18;
      }
      if (iVar14 != 0) {
        puVar15 = local_418;
        puVar16 = local_538;
        for (iVar14 = 0x45; iVar14 != 0; iVar14 = iVar14 + -1) {
          *puVar16 = *puVar15;
          puVar15 = puVar15 + 1;
          puVar16 = puVar16 + 1;
        }
        local_538[0xc] = local_524;
        local_538[0xd] = local_520;
        local_538[0xe] = local_51c;
      }
      local_548 = local_548 + -1;
    } while (local_548 != 0);
  }
  iVar14 = 0;
  if (0 < *(int *)(param_1 + 0x50bc)) {
    iVar7 = 0;
    do {
      iVar10 = *(int *)(param_1 + 0x50c4) + iVar7;
      iVar12 = 0;
      *(undefined2 *)(iVar10 + 0xb2) = 0;
      if (0 < *(int *)(param_1 + 0x50c0)) {
        iVar13 = 0;
        do {
          if (*(int *)(iVar13 + 0xa4 + *(int *)(param_1 + 0x50c8)) == iVar10) {
            *(short *)(iVar10 + 0xb2) = *(short *)(iVar10 + 0xb2) + 1;
          }
          iVar12 = iVar12 + 1;
          iVar13 = iVar13 + 0x114;
        } while (iVar12 < *(int *)(param_1 + 0x50c0));
      }
      iVar14 = iVar14 + 1;
      iVar7 = iVar7 + 0x100;
    } while (iVar14 < *(int *)(param_1 + 0x50bc));
  }
  iVar14 = 0;
  if (0 < *(int *)(param_1 + 0x50c0)) {
    iVar7 = 0;
    do {
      iVar10 = *(int *)(param_1 + 0x50c8) + iVar7;
      pfVar11 = (float *)FUN_005cf9e0(*(int *)(*(int *)(param_1 + 0x50c8) + 0xa4 + iVar7) + 0x30);
      local_534 = *pfVar11;
      local_530 = pfVar11[1];
      local_52c = pfVar11[2];
      if (((local_534 == *(float *)(iVar10 + 0x30)) && (local_530 == *(float *)(iVar10 + 0x34))) &&
         (local_52c == *(float *)(iVar10 + 0x38))) {
        puVar1 = (uint *)(*(int *)(iVar10 + 0xa4) + 0x7c);
        *puVar1 = *puVar1 | 0x2000;
      }
      *(undefined2 *)(iVar10 + 0x102) = 0xffff;
      *(undefined2 *)(iVar10 + 0x104) = 0xffff;
      if ((*(uint *)(iVar10 + 0x98) & 0x40000000) == 0) {
        *(undefined4 *)(iVar10 + 0xd4) = 0;
      }
      iVar14 = iVar14 + 1;
      iVar7 = iVar7 + 0x114;
    } while (iVar14 < *(int *)(param_1 + 0x50c0));
  }
  __security_check_cookie(local_4 ^ (uint)&local_548);
  return;
}

