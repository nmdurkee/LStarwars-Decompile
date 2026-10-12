/* Ghidra pseudocode, not original source.
 * ev_96df89c4daae28ff35d834560256e783041bc073304993e474c02e03eab098bd
 * Entry: 0x4903f0; label: FUN_004903f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004903f0(int param_1)

{
  float fVar1;
  ushort uVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  float10 fVar11;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float local_f4;
  int local_f0;
  int *local_e8;
  undefined4 local_e4;
  uint local_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  undefined4 local_d0;
  undefined4 local_cc [16];
  undefined1 local_8c [12];
  undefined1 local_80 [64];
  undefined4 local_40 [16];
  
  local_e4 = 0;
  if ((*(char *)(*(int *)(param_1 + 0x2ac0) + 0x1ee) != '\0') &&
     (iVar8 = *(int *)(param_1 + 0x5068), iVar8 != 0)) {
    fVar11 = (float10)FUN_005b7d30(_DAT_0092505c,0x40a00000);
    local_e0 = (int)ROUND((fVar11 / (float10)5.0) * (float10)65536.0) & 0xffff;
    FUN_005b7d30(_DAT_00925064,0x3f000000);
    iVar6 = FUN_006e6b90();
    local_d8 = (float)(&DAT_029899a0)[iVar6 >> 1 & 0x7fff] * 0.2 + 0.8;
    FUN_005b7d30(_DAT_00925064,0x3f000000);
    iVar6 = FUN_006e6b90();
    local_dc = (float)(&DAT_029899a0)[iVar6 >> 1 & 0x7fff] * 0.15 + 0.85;
    FUN_00596920(0);
    if ((DAT_007f39e4 == 0) || (*(char *)(*(int *)(param_1 + 0x2ac0) + 0x1ee) == '\0')) {
      local_e8 = (int *)0x0;
    }
    else {
      local_e8 = (int *)(*(int *)(param_1 + 0x2ac0) + 0x1e0);
      iVar6 = FUN_005d0420(local_e8);
      if ((local_e8 != (int *)0x0) && (iVar6 != 0)) {
        FUN_005ca4b0(*(undefined4 *)
                      (*(int *)(*local_e8 + 0x54) + (uint)*(ushort *)(iVar6 + 0x5c) * 4));
      }
    }
    local_f0 = 0;
    if (0 < *(int *)(param_1 + 0x506c)) {
      do {
        uVar2 = *(ushort *)(iVar8 + 0x94);
        if ((uVar2 & 0x10) != 0) {
          if ((DAT_007f39e4 == 0) || (local_e8 == (int *)0x0)) {
            FUN_005b45f0(local_cc,0);
            FUN_005b4f70(local_cc,*(undefined2 *)(iVar8 + 0x88));
            FUN_005b4900(local_cc,iVar8 + 0x68);
            FUN_005f33b0(*(int *)(param_1 + 0x2ac0) + 0x1e0,local_cc);
          }
          else {
            if (*(float *)(iVar8 + 0x78) <= 0.0) {
              local_f4 = 0.0;
              if (((char)uVar2 < '\0') && ((uVar2 & 3) == 0)) {
                if (*(float *)(iVar8 + 0x74) <= 0.0) {
                  iVar6 = FUN_0054fa60();
                  if (iVar6 < 0x800) {
                    *(undefined4 *)(iVar8 + 0x74) = 0x3e19999a;
                  }
                }
                else {
                  fVar1 = *(float *)(iVar8 + 0x74) - _DAT_00925018;
                  *(float *)(iVar8 + 0x74) = fVar1;
                  if (0.0 <= fVar1) {
                    iVar6 = FUN_006e6b90();
                    local_d4 = ABS((float)(&DAT_029899a0)[iVar6 >> 1 & 0x7fff]);
                    local_f4 = (float)((extraout_ST0 - (float10)local_d4) * (float10)1.5 +
                                      (float10)16.0);
                  }
                  else {
                    *(undefined4 *)(iVar8 + 0x74) = 0;
                  }
                }
              }
            }
            else if (*(float *)(iVar8 + 0x7c) <= 0.0) {
              if ((uVar2 & 0x40) == 0) {
                local_f4 = *(float *)(iVar8 + 0x78) * 31.0 + 1.0;
              }
              else {
                local_f4 = ((0.6 - *(float *)(iVar8 + 0x78)) * 32.0) / 0.6 + 32.0;
              }
            }
            else {
              local_f4 = 32.0;
            }
            FUN_005526c0(local_e8,local_f4,local_cc,0);
            FUN_005c0500(local_cc,local_cc,iVar8);
            FUN_005f33b0(local_e8,local_cc);
          }
          puVar9 = local_cc;
          puVar10 = local_40;
          for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar10 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar10 = puVar10 + 1;
          }
          FUN_005b4670(local_80,*(undefined2 *)(iVar8 + 0x88));
          FUN_005b4900(local_80,iVar8 + 0x68);
          iVar6 = *(short *)(iVar8 + 0x8a) * 0x10 + *(int *)(param_1 + 0x2ac0);
          if (*(char *)(iVar6 + 0xe) != '\0') {
            FUN_005f33b0(iVar6,local_cc);
          }
          if ((*(char *)(*(int *)(param_1 + 0x2ac0) + 0x1fe) != '\0') &&
             ((*(byte *)(iVar8 + 0x95) & 1) == 0)) {
            FUN_005f33b0(*(int *)(param_1 + 0x2ac0) + 0x1f0,iVar8);
          }
          uVar2 = *(ushort *)(iVar8 + 0x94);
          if ((char)uVar2 < '\0') {
            iVar6 = 0x2a;
            fVar1 = *(float *)(iVar8 + 0x78);
            if (NAN(fVar1) || 1.0 < fVar1 == (fVar1 == 1.0)) {
              iVar6 = 0x2b;
            }
            if ((((uVar2 & 0x200) == 0) && (*(float *)(iVar8 + 0x50) != 2e+06)) &&
               (*(char *)(*(int *)(param_1 + 0x2ac0) + 0x55e) != '\0')) {
              bVar3 = true;
            }
            else {
              bVar3 = false;
            }
            if (((uVar2 & 3) == 0) && (*(char *)(*(int *)(param_1 + 0x2ac0) + 0x29e) != '\0')) {
              bVar4 = true;
              FUN_005ff7a0(*(int *)(param_1 + 0x2ac0) + 0x290,local_40,local_dc);
            }
            else {
              bVar4 = false;
            }
            if (((bVar3) || (bVar4)) &&
               (cVar5 = FUN_0055e970(iVar8 + 0x68,&local_e4,&local_d0,0,0), cVar5 != '\0')) {
              iVar7 = FUN_006e6b90();
              fVar1 = (float)((extraout_ST0_00 -
                              (float10)(float)(&DAT_029899a0)[iVar7 >> 1 & 0x7fff]) *
                             (float10)local_d8);
              if ((0.0 < fVar1) && (bVar3)) {
                FUN_004900e0(iVar8,local_8c);
                FUN_005b4670(local_cc,local_e0 & 0xffff);
                if (*(short *)(iVar8 + 0x92) != 0) {
                  FUN_005b5160(local_cc,*(short *)(iVar8 + 0x92));
                }
                if (*(short *)(iVar8 + 0x90) != 0) {
                  FUN_005b4cf0(local_cc,*(short *)(iVar8 + 0x90));
                }
                FUN_005b4ac0(local_cc,0x3f4ccccd);
                FUN_005b4900(local_cc,local_8c);
                FUN_005b4b30(local_cc,*(undefined4 *)(iVar8 + 0x84));
                FUN_005ff7a0(*(int *)(param_1 + 0x2ac0) + 0x550,local_cc,
                             (1.0 - *(float *)(iVar8 + 0x78)) * fVar1);
              }
            }
          }
          else {
            iVar6 = 0x2b;
            if ((*(float *)(iVar8 + 0x78) == 0.0) &&
               (iVar7 = FUN_0062c350(0x3f000000,_DAT_00925018), 0 < iVar7)) {
              FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),0x57,iVar8 + 0x68);
            }
          }
          if ((*(char *)(iVar6 * 0x10 + 0xe + *(int *)(param_1 + 0x2ac0)) != '\0') &&
             ((*(byte *)(iVar8 + 0x95) & 1) == 0)) {
            FUN_005f33b0(iVar6 * 0x10 + *(int *)(param_1 + 0x2ac0),local_80);
          }
        }
        local_f0 = local_f0 + 1;
        iVar8 = iVar8 + 0xa0;
      } while (local_f0 < *(int *)(param_1 + 0x506c));
    }
    thunk_FUN_005d05b0();
  }
  return;
}

