/* Ghidra pseudocode, not original source.
 * ev_12b000564e8cba1f3519ff70f1088df218803466ba65b3333f742de5377565cf
 * Entry: 0x41d350; label: FUN_0041d350
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0041d350(void)

{
  byte bVar1;
  char cVar2;
  short sVar3;
  float fVar4;
  undefined1 uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  float10 fVar10;
  float local_128;
  float local_124;
  float local_120;
  undefined4 local_11c;
  float local_118;
  undefined4 local_114;
  int local_110;
  undefined4 local_10c [12];
  undefined1 local_dc [4];
  float local_d8;
  undefined1 local_cc [12];
  undefined1 local_c0 [64];
  undefined4 local_80 [12];
  undefined4 local_50;
  float local_4c;
  undefined4 local_48;
  undefined4 local_40 [16];
  
  local_110 = 0;
  iVar7 = DAT_0093d504;
  if (0 < DAT_0093d500) {
    do {
      *(uint *)(iVar7 + 0x1f8) = *(uint *)(iVar7 + 0x1f8) | 0x800;
      if (((*(uint *)(iVar7 + 0x1fc) & 1) == 0) || ((*(uint *)(iVar7 + 0x1fc) & 0x1000) == 0))
      goto LAB_0041da87;
      bVar1 = *(byte *)(iVar7 + 0x28c);
      *(uint *)(iVar7 + 0xe24) = *(uint *)(iVar7 + 0xe24) & 0xfffffff7;
      *(undefined1 *)(iVar7 + 0x28c) = 0;
      *(uint *)(iVar7 + 0xe20) =
           *(uint *)(iVar7 + 0xe20) ^ ((uint)bVar1 << 0x1b ^ *(uint *)(iVar7 + 0xe20)) & 0x8000000;
      if (((*(char *)(iVar7 + 0x28b) != '\0') &&
          ((0.0 < *(float *)(iVar7 + 0x1010) || (*(float *)(iVar7 + 0x100c) == 0.0)))) ||
         ((((*(byte *)(iVar7 + 0xe20) & 0x20) != 0 &&
           ((*(char *)(iVar7 + 0x7b5) != '#' && (*(char *)(iVar7 + 0x7b5) != '$')))) ||
          (((cVar2 = *(char *)(iVar7 + 0x7b5), cVar2 == '\x0f' &&
            (((*(char *)(iVar7 + 0x7b3) == '\x01' && (*(int *)(iVar7 + 0x798) != 0)) &&
             ((*(byte *)(*(int *)(iVar7 + 0x798) + 0x4c) & 4) == 0)))) ||
           ((cVar2 == ';' || (cVar2 == '9')))))))) goto LAB_0041da87;
      local_11c = *(undefined4 *)(iVar7 + 0x5c);
      local_118 = *(float *)(iVar7 + 0x60);
      if ((*(uint *)(iVar7 + 0x1f8) & 0x100) != 0) {
        local_118 = *(float *)(iVar7 + 0xff0) * *(float *)(iVar7 + 0xa8) + local_118;
      }
      local_114 = *(undefined4 *)(iVar7 + 100);
      FUN_005b37d0(&local_11c,&local_11c,iVar7 + 0xe94);
      local_128 = *(float *)(iVar7 + 0xa8);
      bVar1 = *(byte *)(iVar7 + 0x288);
      *(undefined1 *)(iVar7 + 0x288) = 1;
      *(uint *)(iVar7 + 0xef4) =
           *(uint *)(iVar7 + 0xef4) ^ ((uint)bVar1 << 8 ^ *(uint *)(iVar7 + 0xef4)) & 0x100;
      fVar10 = (float10)FUN_00427ad0(iVar7);
      local_128 = (float)fVar10 * local_128;
      local_124 = local_128;
      local_120 = local_128;
      FUN_005b45a0(local_10c,&local_128);
      switch(*(undefined1 *)(iVar7 + 0x107a)) {
      case 0:
        FUN_00413fe0();
        if (*(short *)(iVar7 + 0x278) != 0) {
          FUN_00414090();
        }
        if (*(short *)(iVar7 + 0x27a) != 0) {
          FUN_00414170();
        }
        if (*(short *)(iVar7 + 0x27c) != 0) {
          FUN_00414250();
        }
        FUN_005c0500(local_10c,local_10c,local_c0);
        break;
      case 1:
        FUN_00413fe0();
        if (*(short *)(iVar7 + 0x278) != 0) {
          FUN_00414090();
        }
        if (*(short *)(iVar7 + 0x27c) != 0) {
          FUN_00414250();
        }
        goto LAB_0041d724;
      default:
        FUN_00413fe0();
        if (*(short *)(iVar7 + 0x27c) != 0) {
          FUN_00414250();
        }
        if (*(short *)(iVar7 + 0x278) != 0) {
          FUN_00414090();
        }
LAB_0041d724:
        FUN_005c0500(local_10c,local_10c,local_c0);
        break;
      case 3:
        FUN_00413fe0();
        if (*(short *)(iVar7 + 0x27c) != 0) {
          FUN_00414250();
        }
        if (*(short *)(iVar7 + 0x278) != 0) {
          FUN_00414090();
        }
        if (*(short *)(iVar7 + 0x27a) != 0) {
          FUN_00414170();
        }
        FUN_005c0500(local_10c,local_10c,local_c0);
        break;
      case 4:
        puVar8 = (undefined4 *)(iVar7 + 0xc04);
        puVar9 = local_10c;
        for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar9 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar9 = puVar9 + 1;
        }
        FUN_005b4c30(local_10c,&local_128);
        FUN_005b5060(local_10c,0x8000);
        FUN_005b4900(local_10c,&local_11c);
        goto LAB_0041d74b;
      case 5:
        puVar8 = (undefined4 *)(iVar7 + 0xc04);
        puVar9 = local_10c;
        for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar9 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar9 = puVar9 + 1;
        }
        FUN_005b4c30(local_10c,&local_128);
        FUN_005b5060(local_10c,0x8000);
        goto LAB_0041d74b;
      }
      FUN_005b4900(local_10c,&local_11c);
LAB_0041d74b:
      if (*(short *)(iVar7 + 0xe18) != 0) {
        iVar6 = (int)*(short *)(iVar7 + 0xe18);
        if ((DAT_0087af5c != 0) && (*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087af5c)) {
          FUN_004dbb80(iVar7);
          iVar6 = FUN_006e6b90();
        }
        FUN_005b5240(local_10c,iVar6);
      }
      if (*(short *)(iVar7 + 0xe1a) != 0) {
        FUN_005b4dd0(local_10c,(int)*(short *)(iVar7 + 0xe1a));
      }
      if (*(short *)(iVar7 + 0xe1c) != 0) {
        FUN_005b5060(local_10c,(int)*(short *)(iVar7 + 0xe1c));
      }
      FUN_0049b7f0(iVar7,local_10c);
      if ((*(char *)(iVar7 + 0x107a) != '\x04') &&
         ((cVar2 = *(char *)(iVar7 + 0x7b5), cVar2 == '#' || (cVar2 == '$')))) {
        fVar4 = (1.0 - (float)fVar10) *
                *(float *)(*(int *)(iVar7 + 0x54) + 0x3c) *
                *(float *)(*(int *)(iVar7 + 0x54) + 0x30) * 7.5;
        if (cVar2 != '#') {
          fVar4 = -fVar4;
        }
        FUN_005c11d0(local_cc,&DAT_0080250c,local_c0);
        FUN_005b3830(local_cc,local_cc,fVar4);
        FUN_005b37d0(local_dc,local_dc,local_cc);
      }
      if ((*(byte *)(iVar7 + 0x1079) < 2) &&
         (((sVar3 = *(short *)(iVar7 + 0x1064), sVar3 == DAT_007f18f4 || (sVar3 == DAT_007f18f8)) ||
          (sVar3 == DAT_007f1914)))) {
        local_d8 = *(float *)(iVar7 + 0xff0) * *(float *)(iVar7 + 0xa8) + local_d8;
      }
      puVar8 = local_10c;
      puVar9 = (undefined4 *)(iVar7 + 0xb8);
      for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar9 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar9 = puVar9 + 1;
      }
      if (((local_128 == 0.0) && (local_124 == 0.0)) && (local_120 == 0.0)) {
        *(undefined1 *)(iVar7 + 0x288) = 0;
      }
      else {
        *(uint *)(iVar7 + 0x1f8) = *(uint *)(iVar7 + 0x1f8) ^ 0x800;
        *(uint *)(iVar7 + 0xef0) = *(uint *)(iVar7 + 0xef0) & 0xfffdffff;
        *(undefined1 *)(iVar7 + 0x107c) = 0;
        if (((*(char *)(iVar7 + 0x107b) != '\0') && (*(float *)(iVar7 + 0x1014) != 2e+06)) &&
           (*(float *)(iVar7 + 0x101c) < (float)*(byte *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xcd)
           )) {
          uVar5 = FUN_00550490(local_10c,*(char *)(iVar7 + 0x107b),*(undefined4 *)(iVar7 + 0x1014),
                               *(undefined4 *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xc0),local_40);
          *(undefined1 *)(iVar7 + 0x107c) = uVar5;
          puVar8 = local_40;
          puVar9 = (undefined4 *)(iVar7 + 0x138);
          for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar9 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar9 = puVar9 + 1;
          }
        }
        if ((((*(char *)(iVar7 + 0x28b) == '\0') && (*(float *)(iVar7 + 0x21c) != 2e+06)) &&
            ((*(byte *)(iVar7 + 0x1f8) & 0x40) != 0)) &&
           (*(short *)(*(int *)(*(int *)(iVar7 + 0x54) + 0x24) + 0xf0) == 0)) {
          FUN_00413f80();
          FUN_00414170();
          if (*(short *)(iVar7 + 0x1054) != 0) {
            FUN_00414250();
          }
          if (*(short *)(iVar7 + 0x1052) != 0) {
            FUN_00414090();
          }
          *(uint *)(iVar7 + 0xef0) = *(uint *)(iVar7 + 0xef0) | 0x20000;
          local_50 = *(undefined4 *)(iVar7 + 0x5c);
          local_4c = *(float *)(iVar7 + 0x21c) + 0.005;
          local_48 = *(undefined4 *)(iVar7 + 100);
          puVar8 = local_80;
          puVar9 = (undefined4 *)(iVar7 + 0xf8);
          for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar9 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar9 = puVar9 + 1;
          }
        }
      }
LAB_0041da87:
      local_110 = local_110 + 1;
      iVar7 = iVar7 + 0x10d8;
    } while (local_110 < DAT_0093d500);
  }
  return 0;
}

