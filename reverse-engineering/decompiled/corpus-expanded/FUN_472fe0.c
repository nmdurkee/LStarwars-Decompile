/* Ghidra pseudocode, not original source.
 * ev_f56492005d3db2572965d416e35be25a43fb24333701b400d47d471ee6ec09ab
 * Entry: 0x472fe0; label: FUN_00472fe0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00472fe0(int param_1)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  float10 fVar8;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float10 extraout_ST0_03;
  float10 extraout_ST0_04;
  float10 extraout_ST0_05;
  float10 extraout_ST0_06;
  float10 extraout_ST0_07;
  float10 extraout_ST0_08;
  float10 fVar9;
  float10 extraout_ST0_09;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float local_b8;
  float local_b4;
  undefined4 local_b0;
  float local_ac;
  float local_a8;
  uint local_a4;
  float local_a0;
  int local_9c;
  int *local_98;
  undefined1 local_94 [48];
  undefined4 local_64;
  undefined4 local_5c;
  float local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  float local_44;
  uint local_40;
  int local_3c [4];
  float local_2c [4];
  int local_1c [4];
  undefined1 local_c [12];
  
  if (((param_1 != 0) && (piVar2 = *(int **)(param_1 + 0x5074), piVar2 != (int *)0x0)) &&
     (*piVar2 != 0)) {
    local_98 = piVar2;
    fVar8 = (float10)FUN_005b7d30(_DAT_0092505c,0x40a00000);
    local_a0 = (float)(int)ROUND((fVar8 / (float10)5.0) * (float10)65536.0);
    local_40 = (uint)local_a0 & 0xffff;
    FUN_005b7d30(_DAT_00925064,0x3f000000);
    iVar3 = FUN_006e6b90();
    local_44 = (float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff] * 0.2 + 0.8;
    FUN_005b7d30(_DAT_00925064,0x3f000000);
    iVar3 = FUN_006e6b90();
    local_a0 = (float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff] * 0.15 + 0.85;
    FUN_00596920(0);
    if (DAT_007f39e4 != 0) {
      iVar3 = 0;
      do {
        iVar4 = *(int *)(param_1 + 0x2ac0) + *(int *)((int)&DAT_00758f64 + iVar3) * 0x10;
        *(int *)((int)local_3c + iVar3) = iVar4;
        iVar4 = FUN_005d0420(iVar4);
        *(int *)((int)local_1c + iVar3) = iVar4;
        if ((*(int **)((int)local_3c + iVar3) != (int *)0x0) && (iVar4 != 0)) {
          fVar8 = (float10)FUN_005ca4b0(*(undefined4 *)
                                         (*(int *)(**(int **)((int)local_3c + iVar3) + 0x54) +
                                         (uint)*(ushort *)(iVar4 + 0x5c) * 4));
          *(float *)((int)local_2c + iVar3) = (float)fVar8;
        }
        iVar3 = iVar3 + 4;
      } while (iVar3 < 0x10);
    }
    local_9c = 0;
    if (0 < *piVar2) {
      do {
        iVar3 = local_9c * 0xa0 + local_98[3];
        if (((*(byte *)(iVar3 + 99) & 4) == 0) && (DAT_0087b4d8 == 0))
        goto switchD_00473cac_caseD_4;
        local_b8 = *(float *)(iVar3 + 0x8c);
        if (local_b8 < 0.0) {
          local_b8 = 0.0;
        }
        if (*(char *)(*(int *)(param_1 + 0x2ac0) + 0x11be) != '\0') {
          FUN_005f33b0(*(int *)(param_1 + 0x2ac0) + 0x11b0,iVar3);
        }
        iVar4 = *(int *)(param_1 + 0x2ac0);
        if ((*(byte *)(iVar3 + 99) & 8) == 0) {
          if (*(char *)(iVar4 + 0x11fe) != '\0') {
            iVar4 = iVar4 + 0x11f0;
            goto LAB_00473224;
          }
        }
        else if (*(char *)(iVar4 + 0x11ee) != '\0') {
          iVar4 = iVar4 + 0x11e0;
LAB_00473224:
          FUN_005f33b0(iVar4,iVar3);
        }
        if ((((*(byte *)(iVar3 + 99) & 0x20) == 0) && (*(float *)(iVar3 + 0x74) != 2e+06)) &&
           (*(char *)(*(int *)(param_1 + 0x2ac0) + 0x55e) != '\0')) {
          FUN_00472800(iVar3,local_c);
          FUN_005b4670(local_94,local_40 & 0xffff);
          if (*(short *)(iVar3 + 0x7e) != 0) {
            FUN_005b5160(local_94,*(short *)(iVar3 + 0x7e));
          }
          if (*(short *)(iVar3 + 0x7c) != 0) {
            FUN_005b4cf0(local_94,*(short *)(iVar3 + 0x7c));
          }
          FUN_005b4ac0(local_94,0x3f4ccccd);
          FUN_005b4900(local_94,local_c);
          FUN_005b4b30(local_94,*(undefined4 *)(iVar3 + 0x90));
          fVar1 = local_44;
          if ((*(byte *)(iVar3 + 99) & 1) != 0) {
            fVar1 = 0.0;
          }
          FUN_005ff7a0(*(int *)(param_1 + 0x2ac0) + 0x550,local_94,fVar1);
        }
        iVar4 = local_3c[0];
        if (DAT_007f39e4 != 0) {
          if ((local_3c[0] != 0) && (local_1c[0] != 0)) {
            if (*(char *)(iVar3 + 0x60) < '\x01') {
              *(undefined4 *)(iVar3 + 0x94) = 0;
              local_b8 = 0.0;
              if (((*(byte *)(iVar3 + 99) & 8) != 0) && ((*(byte *)(iVar3 + 99) & 3) == 0)) {
                if (*(float *)(iVar3 + 0x98) <= 0.0) {
                  iVar5 = FUN_0054fa60();
                  if (iVar5 < 0x800) {
                    *(undefined4 *)(iVar3 + 0x98) = 0x3e19999a;
                  }
                }
                else {
                  fVar1 = *(float *)(iVar3 + 0x98) - _DAT_00925018;
                  *(float *)(iVar3 + 0x98) = fVar1;
                  if (0.0 <= fVar1) {
                    iVar5 = FUN_006e6b90();
                    local_54 = ABS((float)(&DAT_029899a0)[iVar5 >> 1 & 0x7fff]);
                    local_b8 = (float)((extraout_ST0 - (float10)local_54) * (float10)1.5 +
                                      (float10)16.0);
                  }
                  else {
                    *(undefined4 *)(iVar3 + 0x98) = 0;
                  }
                }
              }
            }
            else {
              fVar1 = *(float *)(iVar3 + 0x94) + _DAT_00925018;
              *(float *)(iVar3 + 0x94) = fVar1;
              if ((*(char *)(iVar3 + 0x60) < '\x04') && (3.0 <= fVar1)) {
                *(undefined1 *)(iVar3 + 0x60) = 4;
                *(undefined4 *)(iVar3 + 0x8c) = 0;
                *(undefined4 *)(iVar3 + 0x88) = 0x40000000;
              }
              local_b8 = *(float *)(local_1c[0] + 0x40) * *(float *)(iVar3 + 0x94) * 60.0;
              if (local_2c[0] < local_b8 != (local_2c[0] == local_b8)) {
                local_b8 = local_2c[0];
              }
            }
            FUN_005526c0(iVar4,local_b8,local_94,0);
            FUN_005c0500(local_94,local_94,iVar3);
            FUN_005f33b0(iVar4,local_94);
            iVar4 = *(int *)(param_1 + 0x2ac0) + *(char *)(iVar3 + 0x62) * 0x10;
            if (*(char *)(iVar4 + 0xe) != '\0') {
              FUN_005f33b0(iVar4,local_94);
            }
            if ((((*(byte *)(iVar3 + 99) & 8) != 0) && ((*(byte *)(iVar3 + 99) & 3) == 0)) &&
               (*(char *)(*(int *)(param_1 + 0x2ac0) + 0x29e) != '\0')) {
              FUN_005ff7a0(*(int *)(param_1 + 0x2ac0) + 0x290,local_94,local_a0);
            }
          }
          local_50 = *(undefined4 *)(iVar3 + 0x50);
          local_4c = *(undefined4 *)(iVar3 + 0x54);
          local_48 = *(undefined4 *)(iVar3 + 0x58);
          iVar4 = 1;
          do {
            iVar5 = local_3c[iVar4];
            if ((iVar5 != 0) && (local_1c[iVar4] != 0)) {
              local_b8 = *(float *)(iVar3 + 0x94) * *(float *)(local_1c[0] + 0x40) * 60.0;
              if (local_2c[iVar4] < local_b8 != (local_2c[iVar4] == local_b8)) {
                local_b8 = local_2c[iVar4];
              }
              FUN_005526c0(iVar5,local_b8,local_94,0);
              FUN_005c0500(local_94,local_94,iVar3);
              FUN_005f33b0(iVar5,local_94);
              if (iVar4 == 1) {
                local_50 = local_64;
                local_48 = local_5c;
              }
            }
            iVar4 = iVar4 + 1;
          } while (iVar4 < 4);
          if ((((*(byte *)(iVar3 + 99) & 8) == 0) || (*(byte *)(iVar3 + 0x5f) == 0)) ||
             (*(char *)((uint)*(byte *)(iVar3 + 0x5f) * 0x10 + 0xf9e + *(int *)(param_1 + 0x2ac0))
              == '\0')) goto switchD_00473cac_caseD_4;
          local_a8 = DAT_007f9278;
          local_b0 = DAT_007f9270;
          local_ac = DAT_007f9274;
          fVar1 = *(float *)(iVar3 + 0x94);
          if (!NAN(fVar1) && 2.35 < fVar1 != (fVar1 == 2.35)) goto switchD_00473cac_caseD_4;
          iVar4 = FUN_006e6b90();
          local_b4 = (float)(extraout_ST0_00 -
                            (extraout_ST0_00 -
                            ((float10)(float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff] + extraout_ST0_00)
                            * (float10)0.5));
          local_ac = (float)((extraout_ST0_00 - (float10)local_b4) * (float10)0.10000000149011612 +
                            (float10)DAT_007f9274);
          if (*(char *)(iVar3 + 0x60) < '\x03') {
            fVar8 = (float10)FUN_004727a0(local_b8,0x42480000);
            local_b8 = (float)fVar8;
            if (1.0 < local_b8) {
              local_b8 = 1.0;
            }
            iVar4 = FUN_006e6b90();
            local_ac = (float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff] * (1.0 - local_b8) * 0.01 +
                       local_ac;
          }
          FUN_005b3620(&local_b0,&local_b0,*(undefined2 *)(iVar3 + 0x5c));
          FUN_005b4670(local_94,*(ushort *)(iVar3 + 0x5c) + 0x8000);
          puVar6 = &local_50;
          goto LAB_0047377c;
        }
        if (*(char *)(*(int *)(param_1 + 0x2ac0) + 0x1ee) != '\0') {
          FUN_005b4670(local_94,*(undefined2 *)(iVar3 + 0x5c));
          switch(*(undefined1 *)(iVar3 + 0x60)) {
          case 1:
            local_a4 = (uint)ROUND((local_b8 / *(float *)(iVar3 + 0x88)) * -32768.0);
            uVar7 = local_a4 & 0xffff;
            break;
          case 2:
          case 3:
          case 4:
          case 5:
            uVar7 = 0x8000;
            break;
          case 6:
            local_a4 = (uint)ROUND((1.0 - local_b8 / *(float *)(iVar3 + 0x88)) * -32768.0);
            uVar7 = local_a4 & 0xffff;
            break;
          default:
            goto switchD_00473810_default;
          }
          FUN_005b4dd0(local_94,uVar7);
switchD_00473810_default:
          FUN_005b4900(local_94,iVar3 + 0x50);
          FUN_005f33b0(*(int *)(param_1 + 0x2ac0) + 0x1e0,local_94);
          iVar4 = *(char *)(iVar3 + 0x62) * 0x10 + *(int *)(param_1 + 0x2ac0);
          if (*(char *)(iVar4 + 0xe) != '\0') {
            FUN_005f33b0(iVar4,local_94);
          }
          if ((((*(byte *)(iVar3 + 99) & 8) != 0) && ((*(byte *)(iVar3 + 99) & 3) == 0)) &&
             (*(char *)(*(int *)(param_1 + 0x2ac0) + 0x29e) != '\0')) {
            FUN_005ff7a0(*(int *)(param_1 + 0x2ac0) + 0x290,local_94,local_a0);
          }
        }
        if (*(char *)(*(int *)(param_1 + 0x2ac0) + 0x11de) != '\0') {
          local_b0 = DAT_0093b0cc;
          local_ac = DAT_0093b0d0;
          local_a8 = DAT_0093b0d4;
          switch(*(undefined1 *)(iVar3 + 0x60)) {
          case 2:
            iVar4 = FUN_006e6b90();
            local_a8 = (float)((extraout_ST0_01 +
                               (float10)(float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff]) *
                              (float10)-0.14409999549388885);
            break;
          case 3:
            local_a8 = -0.1441;
            iVar4 = FUN_006e6b90();
            local_ac = (float)((extraout_ST0_02 +
                               (float10)(float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff]) *
                              (float10)-0.3499999940395355);
            break;
          case 4:
            local_a8 = -0.1441;
            iVar4 = FUN_006e6b90();
            local_ac = (float)((extraout_ST0_03 -
                               ((float10)(float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff] +
                               extraout_ST0_03)) * (float10)-0.3499999940395355);
            break;
          case 5:
            iVar4 = FUN_006e6b90();
            local_a8 = (float)((extraout_ST0_04 -
                               (float10)(float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff]) *
                              (float10)-0.14409999549388885);
          }
          FUN_005b3620(&local_b0,&local_b0,*(undefined2 *)(iVar3 + 0x5c));
          FUN_005b4670(local_94,*(undefined2 *)(iVar3 + 0x5c));
          FUN_005b4900(local_94,iVar3 + 0x50);
          FUN_005b4900(local_94,&local_b0);
          FUN_005f33b0(*(int *)(param_1 + 0x2ac0) + 0x11d0,local_94);
        }
        if (*(char *)(*(int *)(param_1 + 0x2ac0) + 0x11ce) != '\0') {
          local_b0 = DAT_0093b0cc;
          local_ac = DAT_0093b0d0;
          local_a8 = DAT_0093b0d4;
          switch(*(undefined1 *)(iVar3 + 0x60)) {
          case 2:
            iVar4 = FUN_006e6b90();
            local_a8 = (float)((extraout_ST0_05 +
                               (float10)(float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff]) *
                              (float10)-0.14409999549388885);
            break;
          case 3:
            local_a8 = -0.1441;
            iVar4 = FUN_006e6b90();
            local_ac = (float)((extraout_ST0_06 +
                               (float10)(float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff]) *
                              (float10)-0.3499999940395355);
            break;
          case 4:
            local_a8 = -0.1441;
            iVar4 = FUN_006e6b90();
            local_ac = (float)((extraout_ST0_07 -
                               ((float10)(float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff] +
                               extraout_ST0_07)) * (float10)-0.3499999940395355);
            break;
          case 5:
            iVar4 = FUN_006e6b90();
            local_a8 = (float)((extraout_ST0_08 -
                               (float10)(float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff]) *
                              (float10)-0.14409999549388885);
          }
          FUN_005b3620(&local_b0,&local_b0,*(undefined2 *)(iVar3 + 0x5c));
          FUN_005b4670(local_94,*(undefined2 *)(iVar3 + 0x5c));
          FUN_005b4900(local_94,iVar3 + 0x50);
          FUN_005b4900(local_94,&local_b0);
          FUN_005f33b0(*(int *)(param_1 + 0x2ac0) + 0x11c0,local_94);
        }
        fVar8 = (float10)16384.0;
        if ((((*(byte *)(iVar3 + 99) & 8) == 0) || (*(byte *)(iVar3 + 0x5f) == 0)) ||
           (*(char *)((uint)*(byte *)(iVar3 + 0x5f) * 0x10 + 0xf9e + *(int *)(param_1 + 0x2ac0)) ==
            '\0')) goto switchD_00473cac_caseD_4;
        local_a8 = DAT_007f9278;
        local_b0 = DAT_007f9270;
        local_ac = DAT_007f9274;
        switch(*(undefined1 *)(iVar3 + 0x60)) {
        case 2:
          iVar4 = FUN_006e6b90();
          local_a8 = (float)(extraout_ST1 -
                            ((float10)(float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff] + fVar8) *
                            (float10)0.14409999549388885);
        default:
switchD_00473cac_default:
          iVar4 = FUN_006e6b90();
          local_b4 = (float)(extraout_ST0_09 -
                            (extraout_ST0_09 -
                            ((float10)(float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff] + extraout_ST0_09)
                            * (float10)0.5));
          local_ac = (float)((extraout_ST0_09 - (float10)local_b4) * (float10)0.10000000149011612 +
                            (float10)local_ac);
          FUN_005b3620(&local_b0,&local_b0,*(undefined2 *)(iVar3 + 0x5c));
          FUN_005b4670(local_94,*(ushort *)(iVar3 + 0x5c) + 0x8000);
          puVar6 = (undefined4 *)(iVar3 + 0x50);
LAB_0047377c:
          FUN_005b4900(local_94,puVar6);
          FUN_005b4900(local_94,&local_b0);
          FUN_005b4b30(local_94,local_b4);
          FUN_005f33b0((*(byte *)(iVar3 + 0x5f) + 0xf9) * 0x10 + *(int *)(param_1 + 0x2ac0),local_94
                      );
          break;
        case 3:
          fVar9 = (float10)local_b8;
          if (fVar9 / (float10)*(float *)(iVar3 + 0x88) < (float10)0.8500000238418579) {
            local_a8 = DAT_007f9278 - 0.1441;
            iVar4 = FUN_006e6b90();
            local_ac = (float)(extraout_ST1_00 -
                              ((float10)(float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff] + fVar8) *
                              (float10)0.3499999940395355);
            iVar4 = FUN_006e6b90();
            local_ac = (float)(((float10)(float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff] + fVar9) *
                               (float10)0.125 + (float10)local_ac);
            goto switchD_00473cac_default;
          }
          break;
        case 4:
        case 5:
          break;
        }
switchD_00473cac_caseD_4:
        local_9c = local_9c + 1;
      } while (local_9c < *local_98);
    }
    thunk_FUN_005d05b0();
  }
  return;
}

