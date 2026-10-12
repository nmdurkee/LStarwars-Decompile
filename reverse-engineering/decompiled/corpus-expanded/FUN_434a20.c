/* Ghidra pseudocode, not original source.
 * ev_a581b26cc49c1240ca9fc8201471236b1c0a2571dfff42173a4e3442f2e0fd27
 * Entry: 0x434a20; label: FUN_00434a20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00434a20(int param_1)

{
  undefined1 uVar1;
  short sVar2;
  float fVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  undefined1 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  int iVar13;
  int *piVar14;
  float **ppfVar15;
  undefined2 in_FPUControlWord;
  float10 fVar16;
  int *local_108;
  float local_104;
  uint uStack_100;
  float local_fc;
  int local_f8;
  float fStack_f4;
  float fStack_f0;
  float fStack_ec;
  int aiStack_e8 [2];
  float *apfStack_e0 [5];
  undefined1 uStack_cc;
  undefined1 uStack_cb;
  undefined1 uStack_ca;
  undefined1 uStack_c9;
  undefined4 uStack_c8;
  undefined1 uStack_91;
  undefined1 local_90 [12];
  float afStack_84 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_108;
  _DAT_00879b08 = 0;
  _DAT_00879b04 = 0;
  local_f8 = param_1;
  FUN_0055e410();
  _DAT_007f6714 = 1.0;
  DAT_00889614 = 0;
  iVar5 = FUN_0056e160(0x2c);
  fVar3 = 2.0;
  if (iVar5 != 0) {
    if (PTR_DAT_007f3a14[DAT_00856c0c * 4 + 3] == '\x01') {
      fVar3 = 0.5;
    }
    else if (PTR_DAT_007f3a14[DAT_00856c0c * 4 + 3] != -1) goto LAB_00434ab1;
    _DAT_007f6714 = _DAT_007f6714 * fVar3;
  }
LAB_00434ab1:
  local_104 = _DAT_00925018 * 2.0;
  iVar5 = FUN_0054fa60(local_104);
  local_104 = (float)iVar5 * 1.5259022e-05 * 0.5 + 0.75;
  fVar16 = (float10)FUN_0054fad0(_DAT_00805030,local_104);
  _DAT_00805030 = (float)fVar16;
  if (_DAT_00805034 == _DAT_00805030) {
    local_104 = (float)FUN_0054fa60();
    _DAT_00805034 = (float)(int)local_104 * 1.5259022e-05 * 0.5 + 0.75;
  }
  local_fc = 0.0;
  iVar5 = DAT_0093d504;
  if (0 < DAT_0093d500) {
    do {
      if (((*(uint *)(iVar5 + 0x1fc) & 1) != 0) && ((*(uint *)(iVar5 + 0x1fc) & 0x1000) != 0)) {
        if ((*(uint *)(iVar5 + 0xef4) & 8) != 0) {
          *(undefined4 *)(iVar5 + 0x10b8) = 0;
        }
        local_108 = (int *)0x1;
        *(float *)(iVar5 + 0x10b8) = *(float *)(iVar5 + 0x10b8) + _DAT_00925018;
        if ((DAT_007f6588 == 0) || ((*(uint *)(iVar5 + 0x1f8) & 0x400) == 0)) {
LAB_00434d36:
          *(uint *)(iVar5 + 0xef4) = *(uint *)(iVar5 + 0xef4) | 0x10;
        }
        else if ((((*(uint *)(iVar5 + 0xeec) & 0x8000000) == 0) &&
                 ((((*(uint *)(iVar5 + 0xef4) & 0x20) == 0 &&
                   ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(iVar5 + 0x7b5) * 0x10 + 8) & 0x200) == 0
                   )) && (*(short *)(iVar5 + 0x27e) == -1)))) &&
                ((*(int *)(iVar5 + 0xcd0) == 0 || (*(char *)(iVar5 + 0x7b5) != ';')))) {
          iVar8 = FUN_004cca90(iVar5);
          if (iVar8 == 0) {
            if ((*(int *)(iVar5 + 0x10d4) == 0) ||
               ((*(byte *)(*(int *)(iVar5 + 0x10d4) + 0x210) & 2) == 0)) {
              if ((*(int *)(iVar5 + 0x40c) == 0) ||
                 ((*(byte *)(*(int *)(iVar5 + 0x40c) + 0x50) & 8) == 0)) {
                if ((*(char *)((int)*(short *)(iVar5 + 0x106a) + *(int *)(local_f8 + 0x2a94)) ==
                     '\0') || (*(char *)(iVar5 + 0x288) == '\0')) {
                  local_108 = (int *)0xa;
LAB_00434d52:
                  *(uint *)(iVar5 + 0xef4) = *(uint *)(iVar5 + 0xef4) & 0xffffffef;
                }
                else {
                  if (*(char *)(iVar5 + 0x281) != '\0') {
                    fVar16 = (float10)FUN_005b3c50(iVar5 + 0x80,PTR_DAT_008021b4 + 0x11c,local_90);
                    local_104 = (float)fVar16;
                    iVar8 = *(int *)(*(int *)(iVar5 + 0x54) + 0x24);
                    iVar6 = 0;
                    iVar13 = 0xbc;
                    pcVar9 = (char *)(iVar8 + 0xcc);
                    do {
                      if (*pcVar9 == '\0') break;
                      if (*(float *)(iVar13 + iVar8) * *(float *)(iVar13 + iVar8) < local_104) {
                        local_108 = (int *)(uint)*(byte *)(iVar8 + 0xcc + iVar6);
                        if (local_108 != (int *)0x1) goto LAB_00434d52;
                        break;
                      }
                      iVar13 = iVar13 + 4;
                      iVar6 = iVar6 + 1;
                      pcVar9 = pcVar9 + 1;
                    } while (iVar13 < 0xcc);
                    goto LAB_00434d36;
                  }
                  *(uint *)(iVar5 + 0xef4) = *(uint *)(iVar5 + 0xef4) | 0x10;
                  local_108 = (int *)0x1;
                }
              }
              else {
                *(uint *)(iVar5 + 0xef4) = *(uint *)(iVar5 + 0xef4) | 0x10;
                local_108 = (int *)0x1;
              }
            }
            else {
              *(uint *)(iVar5 + 0xef4) = *(uint *)(iVar5 + 0xef4) | 0x10;
              local_108 = (int *)0x1;
            }
          }
          else {
            *(uint *)(iVar5 + 0xef4) = *(uint *)(iVar5 + 0xef4) | 0x10;
            local_108 = (int *)0x1;
          }
        }
        else {
          *(uint *)(iVar5 + 0xef4) = *(uint *)(iVar5 + 0xef4) | 0x10;
          local_108 = (int *)0x1;
        }
        if (((uint)*(byte *)(iVar5 + 0x28d) + DAT_00925068) % (uint)local_108 == 0) {
          *(uint *)(iVar5 + 0xef4) = *(uint *)(iVar5 + 0xef4) | 8;
          if (((*(uint *)(iVar5 + 0x1f8) & 0x400) != 0) &&
             ((*(uint *)(iVar5 + 0x1f8) & 0x40000) == 0)) {
            *(undefined4 *)(iVar5 + 0x5c) = *(undefined4 *)(iVar5 + 0x10bc);
            *(undefined4 *)(iVar5 + 0x60) = *(undefined4 *)(iVar5 + 0x10c0);
            *(undefined4 *)(iVar5 + 100) = *(undefined4 *)(iVar5 + 0x10c4);
          }
        }
        else {
          *(uint *)(iVar5 + 0xef4) = *(uint *)(iVar5 + 0xef4) & 0xfffffff7;
        }
      }
      local_fc = (float)((int)local_fc + 1);
      iVar5 = iVar5 + 0x10d8;
    } while ((int)local_fc < DAT_0093d500);
  }
  iVar5 = local_f8;
  FUN_0059ab00(*(undefined4 *)(local_f8 + 0x510c));
  FUN_0043e530();
  iVar13 = 0;
  iVar8 = DAT_0093d504;
  if (0 < DAT_0093d500) {
    do {
      uVar7 = *(uint *)(iVar8 + 0x1fc);
      if ((((uVar7 & 1) != 0) && ((uVar7 & 0x1000) != 0)) &&
         ((*(uint *)(iVar8 + 0x1f8) & 0x400) != 0)) {
        *(uint *)(iVar8 + 0x1fc) =
             ((uint)(*(char *)(iVar8 + 0x7b5) == '\0') << 0xe ^ uVar7) & 0x4000 ^ uVar7;
        local_104 = *(float *)(iVar8 + 0x1018) - _DAT_00925018;
        *(float *)(iVar8 + 0x1018) = local_104;
        if (local_104 < -1.0) {
          FUN_00414ab0(iVar8,0);
        }
        if (0.0 < *(float *)(iVar8 + 0xd34)) {
          *(float *)(iVar8 + 0xd34) = *(float *)(iVar8 + 0xd34) - _DAT_00925018;
        }
        if (0.0 < *(float *)(iVar8 + 0xd54)) {
          *(float *)(iVar8 + 0xd54) = *(float *)(iVar8 + 0xd54) - _DAT_00925018;
        }
        if ((*(uint *)(iVar8 + 0x1f8) & 0x40000) == 0) {
          if ((*(byte *)(iVar8 + 0xef4) & 8) != 0) {
            local_fc = _DAT_00925018;
            _DAT_00925018 = *(float *)(iVar8 + 0x10b8);
            *(uint *)(iVar8 + 0xe20) = *(uint *)(iVar8 + 0xe20) & 0xffffffdf;
            if (0.0 < *(float *)(iVar8 + 0x1000)) {
              *(float *)(iVar8 + 0x1000) = *(float *)(iVar8 + 0x1000) - _DAT_00925018;
            }
            *(undefined4 *)(iVar8 + 0xdec) = 0;
            if (*(code **)(iVar8 + 0x10b0) == (code *)0x0) {
              if (*(int *)(iVar8 + 0xe64) == 0) {
                FUN_00416190(iVar8);
              }
              else {
                FUN_00415c60();
              }
            }
            else {
              (**(code **)(iVar8 + 0x10b0))();
            }
            if ((((*(uint *)(iVar8 + 0xeec) & 0x400000) != 0) &&
                ((*(byte *)(iVar8 + 0x1fc) & 4) == 0)) &&
               ((*(undefined2 *)(iVar8 + 0x106a) = 0xffff,
                (*(uint *)(iVar8 + 0xeec) & 0x800000) != 0 && (*(int *)(local_f8 + 0x13c) != 0)))) {
              uVar4 = FUN_005d92b0(*(int *)(local_f8 + 0x13c),iVar8 + 0x80);
              *(undefined2 *)(iVar8 + 0x106a) = uVar4;
            }
            _DAT_00925018 = local_fc;
          }
        }
        else {
          FUN_004b6bf0(iVar8);
        }
        if (*(char *)(*(int *)(*(int *)(iVar8 + 0x54) + 0x24) + 0x116) == '\n') {
          if (*(char *)(iVar8 + 0x288) == '\0') {
            if (((*(uint *)(iVar8 + 0xef4) & 0x100) != 0) && (_DAT_00876834 <= 0.0)) {
              FUN_00681f40("veh_tie_by",iVar8 + 0x80);
              local_104 = (float)FUN_0054fa60();
              _DAT_00876834 = (float)(int)local_104 * 1.5259022e-05 * 0.5 + 0.5;
            }
          }
          else if (((*(uint *)(iVar8 + 0xef4) & 0x100) == 0) && (_DAT_00876830 <= 0.0)) {
            FUN_00681f40("veh_tie_by",iVar8 + 0x80);
            local_104 = (float)FUN_0054fa60();
            _DAT_00876830 = (float)(int)local_104 * 1.5259022e-05 * 0.5 + 0.5;
          }
        }
      }
      iVar13 = iVar13 + 1;
      iVar5 = local_f8;
      iVar8 = iVar8 + 0x10d8;
    } while (iVar13 < DAT_0093d500);
  }
  piVar14 = &DAT_0093d7f0;
  do {
    iVar8 = *piVar14;
    if (iVar8 != 0) {
      uVar7 = *(uint *)(iVar8 + 0x1fc);
      if (((uVar7 & 1) != 0) && ((uVar7 & 0x1000) != 0)) {
        if ((DAT_00951288 == 0) ||
           (((*(char *)(iVar8 + 0x280) != '\0' && (*(char *)(iVar8 + 0x280) != '\x01')) ||
            ((char)uVar7 < '\0')))) {
          iVar13 = 0;
        }
        else {
          iVar13 = 1;
        }
        *(uint *)(iVar8 + 0xe20) =
             *(uint *)(iVar8 + 0xe20) ^ (iVar13 << 5 ^ *(uint *)(iVar8 + 0xe20)) & 0x20;
        if (0.0 < *(float *)(iVar8 + 0xd60)) {
          *(float *)(iVar8 + 0xd60) = *(float *)(iVar8 + 0xd60) - _DAT_00925018;
        }
        if (0.0 < *(float *)(iVar8 + 0x7c0)) {
          *(float *)(iVar8 + 0x7c0) = *(float *)(iVar8 + 0x7c0) - _DAT_00925018;
        }
        if (0.0 < *(float *)(iVar8 + 0x1000)) {
          *(float *)(iVar8 + 0x1000) = *(float *)(iVar8 + 0x1000) - _DAT_00925018;
        }
        FUN_0046ac80(iVar8);
        if (((*(byte *)(iVar8 + 0x1fc) & 0x80) != 0) &&
           ((iVar13 = FUN_0056e0f0(0x1000), iVar13 != 0 || (0.0 < *(float *)(iVar8 + 0xdec))))) {
          FUN_0058b770(iVar8);
        }
        *(uint *)(iVar8 + 0xef4) = *(uint *)(iVar8 + 0xef4) & 0xefffffff;
        local_108 = (int *)0x3f800000;
        if (((0.0 < *(float *)(iVar8 + 0x1018)) && ((*(byte *)(iVar8 + 0x1fc) & 0x80) != 0)) &&
           (iVar13 = FUN_0056e160(0x2c), iVar13 != 0)) {
          if (PTR_DAT_007f3a14[DAT_00856c0c * 4 + 2] == '\x01') {
            local_108 = (int *)0x40000000;
          }
          else if (PTR_DAT_007f3a14[DAT_00856c0c * 4 + 2] == -1) {
            local_108 = (int *)0x3f000000;
          }
        }
        local_104 = *(float *)(iVar8 + 0x1018) - _DAT_00925018 * (float)local_108;
        *(float *)(iVar8 + 0x1018) = local_104;
        if (local_104 < -1.0) {
          FUN_00414ab0(iVar8,0);
        }
        if (0.0 < *(float *)(iVar8 + 0xd34)) {
          *(float *)(iVar8 + 0xd34) = *(float *)(iVar8 + 0xd34) - _DAT_00925018;
        }
        if (0.0 < *(float *)(iVar8 + 0xd54)) {
          *(float *)(iVar8 + 0xd54) = *(float *)(iVar8 + 0xd54) - _DAT_00925018;
        }
        *(uint *)(iVar8 + 0x1fc) =
             *(uint *)(iVar8 + 0x1fc) ^
             ((uint)(*(char *)(iVar8 + 0x7b5) == '\0') << 0xe ^ *(uint *)(iVar8 + 0x1fc)) & 0x4000;
        if ((*(uint *)(iVar8 + 0x1f8) & 0x40000) == 0) {
          if ((char)*(undefined4 *)(iVar8 + 0x1fc) < '\0') {
            if (**(int **)(iVar8 + 0xca4) != 0) {
              FUN_0054a810(*(int **)(iVar8 + 0xca4) + 0x10);
              FUN_0055eaa0(iVar8,0,1);
            }
          }
          else if (DAT_0093b2a4 != 0) {
            FUN_0055eaa0(iVar8,0,0);
          }
          if (*(code **)(iVar8 + 0x10b0) == (code *)0x0) {
            if (*(int *)(iVar8 + 0xe64) == 0) {
              FUN_00416190(iVar8);
            }
            else {
              FUN_00415c60();
            }
          }
          else {
            (**(code **)(iVar8 + 0x10b0))();
          }
        }
        else {
          FUN_004b6bf0(iVar8);
        }
        if (((((*(uint *)(iVar8 + 0xeec) & 0x400000) != 0) && ((*(byte *)(iVar8 + 0x1fc) & 4) == 0))
            && (*(undefined2 *)(iVar8 + 0x106a) = 0xffff, (*(uint *)(iVar8 + 0xeec) & 0x800000) != 0
               )) && (*(int *)(iVar5 + 0x13c) != 0)) {
          uVar4 = FUN_005d92b0(*(int *)(iVar5 + 0x13c),iVar8 + 0x80);
          *(undefined2 *)(iVar8 + 0x106a) = uVar4;
        }
      }
    }
    piVar14 = piVar14 + 1;
  } while ((int)piVar14 < 0x93d810);
  _DAT_0087b8e8 = -1000.0;
  FUN_00499b60();
  iVar13 = 0;
  iVar8 = DAT_0093d504;
  if (0 < DAT_0093d500) {
    do {
      if ((((*(uint *)(iVar8 + 0x1fc) & 1) != 0) && ((*(uint *)(iVar8 + 0x1fc) & 0x1000) != 0)) &&
         ((*(uint *)(iVar8 + 0x1f8) & 0x400) != 0)) {
        if ((*(byte *)(iVar8 + 0xef4) & 8) == 0) {
          FUN_00498a40(iVar8);
          FUN_004b6b80(iVar8);
          if ((*(uint *)(iVar8 + 0x1f8) & 0x40000) == 0) {
            *(float *)(iVar8 + 0x5c) =
                 *(float *)(iVar8 + 0x68) * _DAT_00925018 + *(float *)(iVar8 + 0x5c);
            *(float *)(iVar8 + 0x60) =
                 *(float *)(iVar8 + 0x10c8) * _DAT_00925018 + *(float *)(iVar8 + 0x60);
            *(float *)(iVar8 + 100) =
                 *(float *)(iVar8 + 0x70) * _DAT_00925018 + *(float *)(iVar8 + 100);
          }
          else {
            FUN_0055d2b0(iVar8);
          }
        }
        else {
          local_fc = _DAT_00925018;
          _DAT_00925018 = *(float *)(iVar8 + 0x10b8);
          FUN_00416d60();
          local_104 = *(float *)(iVar8 + 0x60) - *(float *)(iVar8 + 0x90);
          *(undefined4 *)(iVar8 + 0x10bc) = *(undefined4 *)(iVar8 + 0x5c);
          *(undefined4 *)(iVar8 + 0x10c0) = *(undefined4 *)(iVar8 + 0x60);
          *(undefined4 *)(iVar8 + 0x10c4) = *(undefined4 *)(iVar8 + 100);
          local_108 = (int *)0x0;
          if ((local_104 != 0.0) && (*(float *)(iVar8 + 0x10b8) != 0.0)) {
            local_108 = (int *)(local_104 / *(float *)(iVar8 + 0x10b8));
          }
          *(int **)(iVar8 + 0x10c8) = local_108;
          _DAT_00925018 = local_fc;
        }
        FUN_00418ca0(iVar8);
        *(undefined4 *)(iVar8 + 0xeac) = 0;
        if ((*(int *)(iVar5 + 0x2988) == 0) || ((*(uint *)(iVar8 + 0xeec) & 0x4000) == 0)) {
          *(undefined2 *)(iVar8 + 0x672) = 0xffff;
          *(undefined1 *)(iVar8 + 0x671) = 0xff;
        }
        else {
          FUN_00541bc0(*(int *)(iVar5 + 0x2988),iVar8 + 0x5c,(int)*(char *)(iVar8 + 0x671),
                       (int)*(short *)(iVar8 + 0x672),iVar8 + 0x670);
          FUN_0053f380(iVar8 + 0x7cc);
        }
        if ((((*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b234) || (DAT_009253a4 != 0)) ||
            (*(short *)(iVar8 + 0x1064) != DAT_007f1948)) || (*(char *)(iVar8 + 0x28b) == '\0')) {
          FUN_0055d8c0(iVar8);
        }
        if (*(char *)(iVar8 + 0x28b) == '\x01') {
          fVar3 = 1.0 - *(float *)(iVar8 + 0x1008) / *(float *)(iVar8 + 0x100c);
        }
        else {
          fVar3 = 1.0;
        }
        *(float *)(iVar8 + 0xff8) = fVar3;
        if (*(float *)(iVar8 + 0x102c) != 1e+09) {
          *(undefined4 *)(iVar8 + 0xff8) = *(undefined4 *)(iVar8 + 0x102c);
        }
        *(float *)(iVar8 + 0xa8) =
             *(float *)(*(int *)(iVar8 + 0x54) + 0x3c) * *(float *)(iVar8 + 0xff8);
        FUN_0055ccd0(iVar8);
        FUN_0055cc40(iVar8);
        FUN_0042fcf0(iVar8);
        if (*(char *)(iVar8 + 0x1079) != -1) {
          *(char *)(iVar8 + 0x1079) = *(char *)(iVar8 + 0x1079) + '\x01';
        }
        FUN_005d6430(iVar8 + 0xc5c,iVar8 + 0x80,1,0);
        FUN_00432860(iVar8);
      }
      *(uint *)(iVar8 + 0xeec) = *(uint *)(iVar8 + 0xeec) & 0xfffffffe;
      if (0.0 < *(float *)(iVar8 + 0xecc)) {
        *(float *)(iVar8 + 0xecc) = *(float *)(iVar8 + 0xecc) - _DAT_00925018;
      }
      iVar13 = iVar13 + 1;
      iVar8 = iVar8 + 0x10d8;
    } while (iVar13 < DAT_0093d500);
  }
  _DAT_007fc024 = 0.0;
  local_108 = &DAT_0093d7f0;
  do {
    iVar5 = *local_108;
    if (((iVar5 != 0) && ((*(uint *)(iVar5 + 0x1fc) & 1) != 0)) &&
       ((*(uint *)(iVar5 + 0x1fc) & 0x1000) != 0)) {
      if ((DAT_00951288 != 0) || ((*(uint *)(*(int *)(iVar5 + 0x54) + 4) & 0x2000) != 0)) {
        *(undefined4 *)(iVar5 + 0xdf8) = *(undefined4 *)(iVar5 + 0x68);
        *(undefined4 *)(iVar5 + 0xdfc) = *(undefined4 *)(iVar5 + 0x6c);
        *(undefined4 *)(iVar5 + 0xe00) = *(undefined4 *)(iVar5 + 0x70);
        local_104 = *(float *)(iVar5 + 0xe00) * *(float *)(iVar5 + 0xe00) +
                    *(float *)(iVar5 + 0xdf8) * *(float *)(iVar5 + 0xdf8) +
                    *(float *)(iVar5 + 0xdfc) * *(float *)(iVar5 + 0xdfc);
        fVar16 = (float10)FUN_005c0240(local_104);
        *(float *)(iVar5 + 0xdf0) = (float)fVar16;
      }
      FUN_00416d60(iVar5);
      local_104 = *(float *)(iVar5 + 0x60) - *(float *)(iVar5 + 0x90);
      *(undefined4 *)(iVar5 + 0x10bc) = *(undefined4 *)(iVar5 + 0x5c);
      *(undefined4 *)(iVar5 + 0x10c0) = *(undefined4 *)(iVar5 + 0x60);
      local_fc = 0.0;
      *(undefined4 *)(iVar5 + 0x10c4) = *(undefined4 *)(iVar5 + 100);
      if ((local_104 != 0.0) && (*(float *)(iVar5 + 0x10b8) != 0.0)) {
        local_fc = local_104 / *(float *)(iVar5 + 0x10b8);
      }
      *(float *)(iVar5 + 0x10c8) = local_fc;
      FUN_00418ca0(iVar5);
      *(undefined4 *)(iVar5 + 0xeac) = 0;
      if ((DAT_00951288 != 0) || ((*(uint *)(*(int *)(iVar5 + 0x54) + 4) & 0x2000) != 0)) {
        local_104 = *(float *)(iVar5 + 0x70) * *(float *)(iVar5 + 0x70) +
                    *(float *)(iVar5 + 0x68) * *(float *)(iVar5 + 0x68) +
                    *(float *)(iVar5 + 0x6c) * *(float *)(iVar5 + 0x6c);
        fVar16 = (float10)FUN_005c0240(local_104);
        *(float *)(iVar5 + 0xdf4) = (float)fVar16;
      }
      if (*(undefined4 **)(iVar5 + 0xca8) != (undefined4 *)0x0) {
        puVar12 = (undefined4 *)(iVar5 + 0x670);
        puVar11 = *(undefined4 **)(iVar5 + 0xca8);
        for (iVar8 = 0xe; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar11 = *puVar12;
          puVar12 = puVar12 + 1;
          puVar11 = puVar11 + 1;
        }
      }
      if ((*(int *)(local_f8 + 0x2988) == 0) ||
         ((((*(byte *)(iVar5 + 0x1fc) & 0x80) == 0 && (DAT_00951288 == 0)) &&
          (*(int *)(local_f8 + 0x128) != DAT_0087b2a8)))) {
        *(undefined2 *)(iVar5 + 0x672) = 0xffff;
        *(undefined1 *)(iVar5 + 0x671) = 0xff;
        if (*(int *)(iVar5 + 0xca8) != 0) {
          *(undefined2 *)(*(int *)(iVar5 + 0xca8) + 2) = 0xffff;
          *(undefined1 *)(*(int *)(iVar5 + 0xca8) + 1) = 0xff;
        }
      }
      else {
        FUN_00541bc0(*(int *)(local_f8 + 0x2988),(undefined4 *)(iVar5 + 0x5c),
                     (int)*(char *)(iVar5 + 0x671),(int)*(short *)(iVar5 + 0x672),iVar5 + 0x670);
        FUN_0053f380(iVar5 + 0x7cc);
      }
      if (iVar5 == DAT_0093d7f0) {
        if (*(char *)(iVar5 + 0x671) != -1) {
          _DAT_007fc024 =
               *(float *)(*(char *)(iVar5 + 0x671) * 0x13c + 0x70 + **(int **)(local_f8 + 0x2988));
        }
        _DAT_007fc028 = _DAT_007fc024;
        if (_DAT_0087b8e8 != -1000.0) {
          _DAT_007fc024 = _DAT_0087b8e8;
        }
      }
      FUN_0055d8c0(iVar5);
      if (*(char *)(iVar5 + 0x671) == -1) {
        _DAT_0093d620 = *(undefined4 *)(iVar5 + 0x5c);
        DAT_0093d624 = *(undefined4 *)(iVar5 + 0x60);
        DAT_0093d628 = *(undefined4 *)(iVar5 + 100);
      }
      else {
        _DAT_0093d620 = *(undefined4 *)(iVar5 + 0x8c);
        DAT_0093d624 = *(undefined4 *)(iVar5 + 0x90);
        DAT_0093d628 = *(undefined4 *)(iVar5 + 0x94);
        puVar12 = *(undefined4 **)(iVar5 + 0xca8);
        if ((puVar12 != (undefined4 *)0x0) && (*(char *)((int)puVar12 + 1) == -1)) {
          puVar11 = (undefined4 *)(iVar5 + 0x670);
          for (iVar8 = 0xe; iVar8 != 0; iVar8 = iVar8 + -1) {
            *puVar12 = *puVar11;
            puVar11 = puVar11 + 1;
            puVar12 = puVar12 + 1;
          }
        }
      }
      FUN_00415770(iVar5);
      iVar8 = local_f8;
      FUN_00575f50(local_f8,iVar5);
      if (*(char *)(iVar5 + 0x28b) == '\x01') {
        fVar3 = 1.0 - *(float *)(iVar5 + 0x1008) / *(float *)(iVar5 + 0x100c);
      }
      else {
        fVar3 = 1.0;
      }
      *(float *)(iVar5 + 0xff8) = fVar3;
      if (((DAT_0093b2a4 != 0) && (*(int *)(PTR_DAT_00802c54 + 300) != 0)) &&
         ((*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087af5c &&
          (((sVar2 = *(short *)(iVar5 + 0x1064), sVar2 != DAT_007f1b2c && (sVar2 != DAT_007f1b30))
           && (sVar2 != DAT_007f1b1c)))))) {
        *(float *)(iVar5 + 0xff8) = *(float *)(iVar5 + 0xff8) * 0.55;
      }
      if (*(float *)(iVar5 + 0x102c) != 1e+09) {
        *(undefined4 *)(iVar5 + 0xff8) = *(undefined4 *)(iVar5 + 0x102c);
      }
      *(float *)(iVar5 + 0xa8) =
           *(float *)(*(int *)(iVar5 + 0x54) + 0x3c) * *(float *)(iVar5 + 0xff8);
      FUN_0055ccd0(iVar5);
      FUN_0055cc40(iVar5);
      if ((((*(byte *)(iVar5 + 0x1fc) & 0x80) != 0) && (_DAT_00950780 == 0.0)) &&
         (iVar13 = FUN_004b8fc0(iVar5), iVar13 != 0)) {
        DAT_0087b924 = DAT_0087b924 | 1 << (*(byte *)(iVar5 + 0x280) & 0x1f);
      }
      FUN_00570a80(*(undefined4 *)(iVar5 + 0x7fc),*(uint *)(iVar5 + 0x1fc) >> 7 & 1,
                   (int)*(char *)(iVar5 + 0x280));
      if ((((*(byte *)(iVar5 + 0x1fc) & 0x80) == 0) || (*(char *)(iVar5 + 0x28b) != '\0')) ||
         ((*(char *)(iVar5 + 0x7b5) == '+' ||
          ((*(char *)(iVar5 + 0x7b5) == '\x0f' && (*(char *)(iVar5 + 0x7b3) == '\x01')))))) {
        FUN_00570a60(*(undefined4 *)(iVar5 + 0x7fc));
      }
      else {
        FUN_005705b0(iVar8,iVar5,1);
      }
      FUN_0042fcf0(iVar5);
      if (((((*(uint *)(*(int *)(iVar5 + 0x54) + 4) & 0x2000) != 0) &&
           (*(char *)(iVar5 + 0x28b) == '\0')) && (*(char *)(iVar5 + 0x288) != '\0')) &&
         ((*(byte *)(iVar5 + 0xe20) & 0x20) == 0)) {
        FUN_0042f5e0(iVar5);
      }
      if (*(char *)(iVar5 + 0x1079) != -1) {
        *(char *)(iVar5 + 0x1079) = *(char *)(iVar5 + 0x1079) + '\x01';
      }
      FUN_005d6430(iVar5 + 0xc5c,iVar5 + 0x80,1,0);
      FUN_00432860(iVar5);
    }
    iVar5 = DAT_0093d504;
    local_108 = local_108 + 1;
  } while ((int)local_108 < 0x93d810);
  if (DAT_0092503b == -1) {
    local_104 = 0.0;
  }
  else {
    local_104 = (float)((DAT_0092503b * DAT_0093d500) / 3);
  }
  aiStack_e8[0] = FUN_0055ce20((int)DAT_007f198c,0,1,1,0);
  iVar13 = 0;
  iVar8 = local_f8;
  if (0 < DAT_0093d500) {
    do {
      if (((*(char *)((int)*(short *)(iVar5 + 0x106a) + *(int *)(iVar8 + 0x2a94)) != '\0') &&
          ((*(uint *)(iVar5 + 0x1fc) & 1) != 0)) && ((*(uint *)(iVar5 + 0x1fc) & 0x1000) != 0)) {
        iVar6 = 0;
        if (DAT_007f39e4 != 0) {
          iVar6 = FUN_004e8380(iVar5,aiStack_e8[0],local_90);
        }
        if ((*(uint *)(iVar5 + 0xe20) & 0x80000000) == 0) {
          if (iVar6 == 0) {
            local_108 = (int *)0x0;
          }
          else {
            local_108 = (int *)0x3f800000;
          }
        }
        else {
          local_108 = (int *)0x3f800000;
        }
        local_fc = _DAT_00925018 + _DAT_00925018;
        fVar16 = (float10)FUN_0054fad0(*(undefined4 *)(iVar5 + 0xdd4),local_108,local_fc);
        *(float *)(iVar5 + 0xdd4) = (float)fVar16;
        if (*(char *)(iVar5 + 0x288) != '\0') {
          if (((int)local_104 <= iVar13) && (iVar13 < DAT_0093d500)) {
            FUN_00595af0(iVar5,*(undefined4 *)(iVar8 + 0x2ab4));
          }
          if (0.0 < *(float *)(iVar5 + 0xdd4)) {
            iVar8 = (int)*(char *)(*(int *)(*(int *)(iVar5 + 0x54) + 0x24) + 0x113);
            if ((iVar8 == -1) || (*(int *)(*(int *)(iVar5 + 0x50) + 0x14 + iVar8 * 4) == 0)) {
              fStack_f4 = *(float *)(iVar5 + 400);
              fStack_f0 = *(float *)(iVar5 + 0x194);
              fStack_ec = *(float *)(iVar5 + 0x198);
            }
            else {
              fStack_f4 = *(float *)(iVar8 * 0x40 + 0x834 + iVar5);
              iVar8 = iVar8 * 0x40 + 0x834 + iVar5;
              fStack_f0 = *(float *)(iVar8 + 4);
              fStack_ec = *(float *)(iVar8 + 8);
            }
            local_fc = *(float *)(iVar5 + 0x1e0) * 0.5;
            if (local_fc < 0.21) {
              local_fc = 0.21;
            }
            fStack_f0 = fStack_f0 + local_fc;
            local_fc = *(float *)(iVar5 + 0x1dc) * 0.05;
            uVar7 = (uint)(ushort)((ushort)(*(byte *)(iVar5 + 0x28d) & 7) << 0xd);
            fVar16 = (float10)FUN_005b7d30(_DAT_0092505c,0x3fc00000);
            uStack_100 = (uint)ROUND((fVar16 / (float10)1.5) * (float10)65536.0);
            fStack_f4 = (float)(&DAT_029899a0)[(int)((uStack_100 & 0xffff) + uVar7) >> 1 & 0x7fff] *
                        local_fc + fStack_f4;
            fVar16 = (float10)FUN_005b7d30(_DAT_0092505c,0x3f9645a2);
            uStack_100 = (uint)ROUND((fVar16 / (float10)1.1740000247955322) * (float10)65536.0);
            fStack_f0 = local_fc * 0.75 *
                        (float)(&DAT_029899a0)[(int)((uStack_100 & 0xffff) + uVar7) >> 1 & 0x7fff] +
                        fStack_f0;
            fVar16 = (float10)FUN_005b7d30(_DAT_0092505c,0x3fa126e9);
            uStack_100 = (uint)ROUND((fVar16 / (float10)1.2589999437332153) * (float10)65536.0);
            fStack_ec = (float)(&DAT_029899a0)[(int)((uStack_100 & 0xffff) + uVar7) >> 1 & 0x7fff] *
                        local_fc + fStack_ec;
            FUN_004f1f10(afStack_84,PTR_DAT_007f3a1c);
            puVar12 = &DAT_00802cd8;
            ppfVar15 = apfStack_e0;
            for (iVar8 = 0x14; iVar8 != 0; iVar8 = iVar8 + -1) {
              *ppfVar15 = (float *)*puVar12;
              puVar12 = puVar12 + 1;
              ppfVar15 = ppfVar15 + 1;
            }
            apfStack_e0[3] = (float *)_DAT_007f6590;
            apfStack_e0[0] = afStack_84;
            apfStack_e0[1] = &fStack_f4;
            fVar16 = (float10)FUN_005b7d30(_DAT_00925064,0x3f000000);
            local_108 = (int *)CONCAT22(local_108._2_2_,in_FPUControlWord);
            uStack_c8 = 0x1083;
            uStack_91 = 4;
            uStack_100 = (uint)ROUND(((float)(&DAT_029899a0)
                                             [(uint)(int)ROUND((fVar16 + fVar16) * (float10)65536.0)
                                              >> 1 & 0x7fff] * 24.0 + 104.0) *
                                     *(float *)(iVar5 + 0xdd4));
            uStack_c9 = (undefined1)uStack_100;
            FUN_00560b60(apfStack_e0);
            iVar8 = local_f8;
          }
        }
      }
      iVar13 = iVar13 + 1;
      iVar5 = iVar5 + 0x10d8;
    } while (iVar13 < DAT_0093d500);
  }
  FUN_00431210(iVar8);
  if (DAT_0087a7d4 == 0) {
    if ((0.0 < _DAT_0087a7d0) &&
       ((((_DAT_0087a7d0 = _DAT_0087a7d0 - _DAT_00925018, _DAT_0087a7d0 < 0.0 || (DAT_0087a7c8 == 0)
          ) || (DAT_0087a7cc == 0)) ||
        ((((((*(uint *)(DAT_0087a7c8 + 0x1fc) & 1) == 0 ||
            ((*(uint *)(DAT_0087a7c8 + 0x1fc) & 0x1000) == 0)) ||
           ((*(char *)(DAT_0087a7c8 + 0x28b) != '\0' ||
            (((*(byte *)(DAT_0087a7c8 + 0x7c5) & 2) != 0 ||
             ((*(uint *)(DAT_0087a7cc + 0x1fc) & 1) == 0)))))) ||
          ((*(uint *)(DAT_0087a7cc + 0x1fc) & 0x1000) == 0)) ||
         ((*(char *)(DAT_0087a7cc + 0x28b) != '\0' || ((*(byte *)(DAT_0087a7cc + 0x7c5) & 2) != 0)))
         ))))) {
      _DAT_0087a7d0 = 0.0;
      DAT_0087a7c8 = 0;
      DAT_0087a7cc = 0;
      DAT_0087a7d4 = 0;
    }
  }
  else {
    if ((((DAT_0087a7c8 != 0) && (DAT_0087a7cc != 0)) && (DAT_0087a7c8 != DAT_0087a7cc)) &&
       (((((*(uint *)(DAT_0087a7c8 + 0x1fc) & 1) != 0 &&
          ((*(uint *)(DAT_0087a7c8 + 0x1fc) & 0x1000) != 0)) &&
         ((*(char *)(DAT_0087a7c8 + 0x28b) == '\0' &&
          (((*(byte *)(DAT_0087a7c8 + 0x7c5) & 2) == 0 &&
           ((*(uint *)(DAT_0087a7cc + 0x1fc) & 1) != 0)))))) &&
        (((*(uint *)(DAT_0087a7cc + 0x1fc) & 0x1000) != 0 &&
         ((*(char *)(DAT_0087a7cc + 0x28b) == '\0' && ((*(byte *)(DAT_0087a7cc + 0x7c5) & 2) == 0)))
         ))))) {
      iVar5 = FUN_004876a0(DAT_0087a7c8,DAT_0087a7cc,0,0,1);
      if (iVar5 == 1) {
        FUN_00547930(0x22,DAT_0087a7c8 + 0x80,0,0);
        FUN_0054a3e0(PTR_DAT_008021b4,0x3f000000,0,1);
        if (DAT_0093d7f4 == 0) {
          iVar5 = -1;
        }
        else {
          iVar5 = (int)*(short *)(DAT_0093d7f4 + 0x1064);
        }
        if (DAT_0093d7f0 == 0) {
          iVar8 = -1;
        }
        else {
          iVar8 = (int)*(short *)(DAT_0093d7f0 + 0x1064);
        }
        FUN_0055e1b0(0,iVar8,iVar5);
        *(undefined4 *)(DAT_0087a7c8 + 0xd60) = 0x40000000;
        *(undefined4 *)(DAT_0087a7cc + 0xd60) = 0x40000000;
      }
      else if (iVar5 == 2) goto LAB_0043614c;
    }
    DAT_0087a7c8 = 0;
    _DAT_0087a7d0 = 0.0;
    DAT_0087a7cc = 0;
    DAT_0087a7d4 = 0;
  }
LAB_0043614c:
  aiStack_e8[1] = 0;
  aiStack_e8[0] = 0;
  if (((DAT_00951288 == 0) &&
      ((*(int *)(PTR_DAT_00802c54 + 300) == 0 ||
       ((*(byte *)(*(int *)(PTR_DAT_00802c54 + 300) + 0x7a) & 4 | 0x100) != 4)))) &&
     ((*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b234 || (DAT_009253a4 != 0)))) {
LAB_004361df:
    if ((((DAT_0093d7f0 != 0) && ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) != 0)) &&
        (((*(byte *)(DAT_0093d7f0 + 0xe24) & 8) != 0 && (*(int *)(DAT_0093d7f0 + 0xcd0) != 0)))) &&
       (((sVar2 = *(short *)(DAT_0093d7f0 + 0x1064), sVar2 == DAT_007f18f4 ||
         (sVar2 == DAT_007f18f8)) || (sVar2 == DAT_007f1914)))) {
      aiStack_e8[0] = 2;
    }
  }
  else if (DAT_0093d7f0 != 0) {
    if ((((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) != 0) && (DAT_0093d7f4 != 0)) &&
       ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) != 0)) {
      aiStack_e8[1] = 1;
      aiStack_e8[0] = 1;
      goto LAB_0043625f;
    }
    goto LAB_004361df;
  }
  if (((((DAT_0093d7f4 != 0) && ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) != 0)) &&
       ((*(byte *)(DAT_0093d7f4 + 0xe24) & 8) != 0)) && (*(int *)(DAT_0093d7f4 + 0xcd0) != 0)) &&
     (((sVar2 = *(short *)(DAT_0093d7f4 + 0x1064), sVar2 == DAT_007f18f4 || (sVar2 == DAT_007f18f8))
      || (sVar2 == DAT_007f1914)))) {
    aiStack_e8[1] = 2;
  }
LAB_0043625f:
  puVar10 = &DAT_00802be1;
  iVar5 = 0;
  do {
    iVar8 = *(int *)((int)&DAT_0093d7f0 + iVar5);
    if (((iVar8 != 0) && (*(int *)((int)aiStack_e8 + iVar5) != 0)) &&
       ((*(char *)(iVar8 + 0x28b) == '\0' &&
        ((*(float *)(iVar8 + 0xd60) <= 0.0 || (DAT_00951288 != 0)))))) {
      if (*(int *)((int)aiStack_e8 + iVar5) == 2) {
        iVar13 = (int)*(char *)(*(int *)(*(int *)(iVar8 + 0x54) + 0x24) + 0x113);
        if ((iVar13 == -1) || (*(int *)(*(int *)(iVar8 + 0x50) + 0x14 + iVar13 * 4) == 0)) {
          fStack_f4 = *(float *)(iVar8 + 400);
          fStack_f0 = *(float *)(iVar8 + 0x194);
          fStack_ec = *(float *)(iVar8 + 0x198);
        }
        else {
          fStack_f4 = *(float *)(iVar13 * 0x40 + 0x834 + iVar8);
          iVar13 = iVar13 * 0x40 + 0x834 + iVar8;
          fStack_f0 = *(float *)(iVar13 + 4);
          fStack_ec = *(float *)(iVar13 + 8);
        }
        fStack_f0 = *(float *)(iVar8 + 0x1e0) * 0.5 + fStack_f0;
      }
      else if (*(int *)(local_f8 + 0x128) == DAT_0087b0f8) {
        fStack_f4 = 0.0;
        fStack_f0 = *(float *)(iVar8 + 0xff4) * *(float *)(iVar8 + 0xa8);
        fStack_ec = 0.0;
        FUN_005b3200(&fStack_f4,&fStack_f4,iVar8 + 0xc04);
        FUN_005b37d0(&fStack_f4,&fStack_f4,iVar8 + 0x5c);
      }
      else {
        fStack_f4 = *(float *)(iVar8 + 0x80);
        fStack_f0 = *(float *)(iVar8 + 0x1e0) * 1.5 + *(float *)(iVar8 + 0x84);
        fStack_ec = *(float *)(iVar8 + 0x88);
      }
      uVar1 = puVar10[-1];
      puVar12 = &DAT_00802cd8;
      ppfVar15 = apfStack_e0;
      for (iVar8 = 0x14; iVar8 != 0; iVar8 = iVar8 + -1) {
        *ppfVar15 = (float *)*puVar12;
        puVar12 = puVar12 + 1;
        ppfVar15 = ppfVar15 + 1;
      }
      apfStack_e0[3] = (float *)0x3f2a7efa;
      apfStack_e0[1] = &fStack_f4;
      uStack_ca = puVar10[1];
      apfStack_e0[0] = (float *)PTR_DAT_007f3a1c;
      uStack_cb = *puVar10;
      uStack_cc = uVar1;
      fVar16 = (float10)FUN_005b7d30(_DAT_00925064,0x3f000000);
      uStack_c8 = 0x83;
      uStack_91 = 4;
      local_108 = (int *)CONCAT22(local_108._2_2_,in_FPUControlWord);
      uStack_100 = (uint)ROUND((float)(&DAT_029899a0)
                                      [(uint)(int)ROUND((fVar16 + fVar16) * (float10)65536.0) >> 1 &
                                       0x7fff] * 48.0 + 80.0);
      uStack_c9 = (undefined1)uStack_100;
      FUN_00560b60(apfStack_e0);
    }
    puVar10 = puVar10 + 3;
    iVar5 = iVar5 + 4;
  } while ((int)puVar10 < 0x802be7);
  if (((DAT_009553d4 != 0) && (iVar5 = FUN_0058a900(DAT_009553d4), iVar5 != 0)) &&
     (*(int *)(DAT_009553d4 + 4) != 0)) {
    FUN_004977f0(DAT_009553d4);
  }
  __security_check_cookie(local_4 ^ (uint)&local_108);
  return;
}

