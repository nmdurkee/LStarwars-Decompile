/* Ghidra pseudocode, not original source.
 * ev_da30da9df459bd28e82b339ffdc0f4cd1266c83ded903d656831cff2a8a86063
 * Entry: 0x46e290; label: FUN_0046e290
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046e290(int param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  float fVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined4 *puVar11;
  float10 fVar12;
  int local_120;
  int local_11c;
  int local_118;
  int local_114;
  undefined4 local_110;
  int local_108;
  int local_104;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  uint local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  float local_e4;
  int local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  float local_d4;
  float local_d0;
  undefined4 local_cc [16];
  undefined1 local_8c [48];
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined1 local_4c [12];
  undefined4 local_40 [16];
  
  if (((param_1 != 0) && (piVar2 = *(int **)(param_1 + 0x5070), piVar2 != (int *)0x0)) &&
     (*piVar2 != 0)) {
    fVar12 = (float10)FUN_005b7d30(_DAT_0092505c,0x40a00000);
    local_f0 = (int)ROUND((fVar12 / (float10)5.0) * (float10)65536.0) & 0xffff;
    FUN_005b7d30(_DAT_00925064,0x3f000000);
    iVar5 = FUN_006e6b90();
    local_114 = 0;
    local_d0 = (float)(&DAT_029899a0)[iVar5 >> 1 & 0x7fff] * 0.2 + 0.8;
    if (0 < *piVar2) {
      local_104 = 0;
      do {
        iVar5 = piVar2[1] + local_104;
        if (((*(byte *)(iVar5 + 0x62) & 4) == 0) && (DAT_0087b4d8 == 0)) goto LAB_0046ea59;
        if ((*(byte *)(iVar5 + 99) & 2) == 0) {
          FUN_00596920(0);
        }
        else {
          thunk_FUN_005d05b0();
        }
        switch(*(undefined1 *)(iVar5 + 0x61)) {
        case 0:
          uVar7 = *(byte *)(iVar5 + 99) & 1 | 0x106;
          uVar6 = *(byte *)(iVar5 + 0x62) >> 7 | 0x108;
          local_120 = 0x10a;
          iVar10 = 0x10b;
          local_11c = 0x10c;
          local_118 = 0x55;
          break;
        case 1:
          local_120 = 0x103;
          iVar10 = 0x104;
          local_11c = 0x105;
          local_118 = 0x55;
          uVar7 = (-(uint)((*(byte *)(iVar5 + 99) & 1) != 0) & 7) + 0x100;
          uVar6 = ((*(byte *)(iVar5 + 0x62) & 0x80) != 0) + 0x101;
          break;
        case 2:
          uVar7 = 0x10d;
          local_110 = 0x3e7ae148;
          uVar6 = 0x10e;
          uVar3 = 0xbe428f5c;
          local_120 = 0x10f;
          iVar10 = 0x110;
          local_11c = 0x111;
          local_108 = 0x112;
          local_118 = 0x113;
          goto LAB_0046e4e1;
        case 3:
          uVar7 = 0x114;
          local_110 = 0x3eae147b;
          uVar6 = 0x115;
          uVar3 = 0xbe2e147b;
          local_120 = 0x116;
          iVar10 = 0x117;
          local_11c = 0x118;
          local_108 = 0x119;
          local_118 = 0x11a;
          goto LAB_0046e4e1;
        default:
          uVar7 = 0xffffffff;
          uVar6 = 0xffffffff;
          local_120 = -1;
          iVar10 = -1;
          local_11c = -1;
          local_118 = -1;
        }
        local_108 = -1;
        uVar3 = 0;
        local_110 = 0;
LAB_0046e4e1:
        FUN_005b4670(local_cc,*(undefined2 *)(iVar5 + 0x5c));
        local_e0 = iVar5 + 0x50;
        FUN_005b4900(local_cc,local_e0);
        if ((((*(byte *)(iVar5 + 0x62) & 0x20) == 0) && (uVar7 != 0xffffffff)) &&
           (iVar8 = uVar7 * 0x10 + *(int *)(param_1 + 0x2ac0), *(char *)(iVar8 + 0xe) != '\0')) {
          FUN_005f33b0(iVar8,local_cc);
        }
        if ((*(byte *)(iVar5 + 0x62) & 0x20) == 0) {
          if ((*(byte *)(iVar5 + 0x62) & 2) == 0) {
            if (local_11c != -1) {
              iVar10 = local_11c * 0x10 + *(int *)(param_1 + 0x2ac0);
              cVar1 = *(char *)(iVar10 + 0xe);
              goto joined_r0x0046e589;
            }
          }
          else if (iVar10 != -1) {
            iVar10 = iVar10 * 0x10 + *(int *)(param_1 + 0x2ac0);
            cVar1 = *(char *)(iVar10 + 0xe);
joined_r0x0046e589:
            if (cVar1 != '\0') {
              FUN_005f33b0(iVar10,local_cc);
            }
          }
        }
        if (((*(byte *)(iVar5 + 0x62) & 0x20) == 0) &&
           ((0.0 < *(float *)(iVar5 + 0x88) || (DAT_0087b4d8 != 0)))) {
          local_dc = 0;
          local_d8 = _DAT_007f90c8;
          local_d4 = _DAT_007f90c4;
          local_ec = 0;
          local_e8 = _DAT_007f90c8;
          local_e4 = _DAT_007f90c4 - 0.0005;
          FUN_005b3620(&local_dc,&local_dc,*(undefined2 *)(iVar5 + 0x5c));
          FUN_005b3620(&local_ec,&local_ec,*(undefined2 *)(iVar5 + 0x5c));
          puVar9 = local_cc;
          puVar11 = local_40;
          for (iVar10 = 0x10; iVar10 != 0; iVar10 = iVar10 + -1) {
            *puVar11 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar11 = puVar11 + 1;
          }
          FUN_005b4900(local_cc,&local_dc);
          FUN_005b4900(local_40,&local_ec);
          if ((1.2 <= *(float *)(iVar5 + 0x88)) || (DAT_0087b4d8 != 0)) {
            FUN_005526c0(*(int *)(param_1 + 0x2ac0) + uVar6 * 0x10,
                         (*(float *)(iVar5 + 0x88) / 0.8) * 24.0 + 1.0,local_8c,0);
            local_54 = 0;
            local_58 = 0;
            local_5c = 0;
            FUN_005c0500(local_8c,local_8c,local_cc);
            FUN_005ff7a0(*(int *)(param_1 + 0x2ac0) + uVar6 * 0x10,local_8c,0x3f800000);
          }
          else {
            fVar4 = *(float *)(iVar5 + 0x88) / 1.2;
            FUN_005526c0(*(int *)(param_1 + 0x2ac0) + local_120 * 0x10,fVar4 * 23.0 + 1.0,local_8c,0
                        );
            local_54 = 0;
            local_58 = 0;
            local_5c = 0;
            FUN_005c0500(local_8c,local_8c,local_40);
            FUN_005ff7a0(*(int *)(param_1 + 0x2ac0) + local_120 * 0x10,local_8c,1.0 - fVar4);
            FUN_005526c0(*(int *)(param_1 + 0x2ac0) + uVar6 * 0x10,
                         (*(float *)(iVar5 + 0x88) / 0.8) * 24.0 + 1.0,local_8c,0);
            local_54 = 0;
            local_58 = 0;
            local_5c = 0;
            FUN_005c0500(local_8c,local_8c,local_cc);
            FUN_005ff7a0(*(int *)(param_1 + 0x2ac0) + uVar6 * 0x10,local_8c,0x3f800000);
          }
        }
        if (((((*(byte *)(iVar5 + 0x62) & 0x40) == 0) && ((*(byte *)(iVar5 + 0x62) & 8) != 0)) &&
            (*(float *)(iVar5 + 0x74) != 2e+06)) &&
           ((local_118 != -1 &&
            (*(char *)(local_118 * 0x10 + 0xe + *(int *)(param_1 + 0x2ac0)) != '\0')))) {
          FUN_0046dc10(iVar5,local_4c,0);
          FUN_005b4670(local_cc,local_f0 & 0xffff);
          if (*(short *)(iVar5 + 0x84) != 0) {
            FUN_005b5160(local_cc,*(short *)(iVar5 + 0x84));
          }
          if (*(short *)(iVar5 + 0x82) != 0) {
            FUN_005b4cf0(local_cc,*(short *)(iVar5 + 0x82));
          }
          FUN_005b4900(local_cc,local_4c);
          FUN_005b4b30(local_cc,*(undefined4 *)(iVar5 + 0x8c));
          fVar4 = local_d0;
          if ((*(byte *)(iVar5 + 0x62) & 1) != 0) {
            fVar4 = 0.0;
          }
          FUN_005ff7a0(*(int *)(param_1 + 0x2ac0) + local_118 * 0x10,local_cc,fVar4);
        }
        if ((((*(byte *)(iVar5 + 0x62) & 0x20) == 0) && (local_108 != -1)) &&
           (*(char *)(local_108 * 0x10 + 0xe + *(int *)(param_1 + 0x2ac0)) != '\0')) {
          local_fc = 0;
          local_f8 = local_110;
          local_f4 = uVar3;
          FUN_005b35a0(&local_fc,&local_fc,*(undefined2 *)(iVar5 + 0x80));
          FUN_005b3620(&local_fc,&local_fc,*(undefined2 *)(iVar5 + 0x5c));
          FUN_005b45f0(local_cc,*(undefined2 *)(iVar5 + 0x80));
          FUN_005b4f70(local_cc,*(undefined2 *)(iVar5 + 0x5c));
          FUN_005b4dd0(local_cc,*(undefined2 *)(iVar5 + 0x7c));
          FUN_005b4f70(local_cc,*(undefined2 *)(iVar5 + 0x7e));
          FUN_005b4900(local_cc,local_e0);
          FUN_005b4900(local_cc,&local_fc);
          FUN_005f33b0(*(int *)(param_1 + 0x2ac0) + local_108 * 0x10,local_cc);
        }
LAB_0046ea59:
        local_104 = local_104 + 0x90;
        local_114 = local_114 + 1;
      } while (local_114 < *piVar2);
    }
    thunk_FUN_005d05b0();
  }
  return;
}

