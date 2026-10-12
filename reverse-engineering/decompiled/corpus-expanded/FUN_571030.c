/* Ghidra pseudocode, not original source.
 * ev_565248e81838fc57af25e3b2c05c11c2e8daf24aacbb3d036db872a2a4b2fd33
 * Entry: 0x571030; label: FUN_00571030
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00571030(int param_1)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  float10 fVar9;
  int local_58;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40 [4];
  undefined1 local_30 [16];
  undefined1 local_20 [32];
  
  local_4c = DAT_00950f60;
  local_48 = DAT_00950f60;
  local_44 = DAT_00950f60;
  if (((*(int *)(param_1 + 0x5054) != 0) && (PTR_PTR_008033b0[0xb] != -1)) &&
     (*(char *)(*(int *)PTR_PTR_008033b0 + 0xf + (char)PTR_PTR_008033b0[0xb] * 0x38) == '\0')) {
    fVar9 = (float10)FUN_005b7d30(_DAT_0092505c,0x40800000);
    uVar2 = (int)ROUND(fVar9 * (float10)0.25 * (float10)65536.0) & 0xffff;
    fVar1 = (float)(&DAT_029899a0)[(int)(uVar2 * 2) >> 1 & 0x7fff];
    iVar7 = **(int **)(param_1 + 0x5054);
    local_58 = 0;
    if (0 < (*(int **)(param_1 + 0x5054))[1]) {
      do {
        if ((*(byte *)(iVar7 + 0x38) & 0x20) == 0) {
          iVar3 = FUN_005cfd60(iVar7);
          if ((iVar3 != 0) &&
             (((((uVar5 = *(uint *)(iVar7 + 0x38), (uVar5 & 1) != 0 ||
                 (iVar3 = *(int *)(iVar7 + 0xc), iVar3 == 0)) || (*(int *)(iVar7 + 0x10) == 0)) ||
               ((((uVar5 & 2) != 0 && ((*(byte *)(iVar3 + 0x50) & 8) == 0)) &&
                (*(float *)(iVar3 + 0x4c) <= 1.0)))) ||
              (((((uVar5 & 8) != 0 && ((*(byte *)(iVar3 + 0x50) & 8) == 0)) &&
                (*(float *)(iVar7 + 0x14) < *(float *)(iVar3 + 0x4c) !=
                 (*(float *)(iVar7 + 0x14) == *(float *)(iVar3 + 0x4c)))) ||
               (((uVar5 & 4) != 0 && ((*(byte *)(iVar3 + 0x50) & 1) != 0)))))))) {
            iVar3 = FUN_005cf9e0(iVar7);
            puVar4 = (undefined4 *)FUN_005d0330(iVar7);
            puVar8 = local_40;
            for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
              *puVar8 = *puVar4;
              puVar4 = puVar4 + 1;
              puVar8 = puVar8 + 1;
            }
            FUN_005b3b30(local_40,local_40);
            FUN_005b3b30(local_30,local_30);
            FUN_005b3b30(local_20,local_20);
            FUN_005b4c30(local_40,&local_4c);
            goto LAB_0057126a;
          }
        }
        else if (((*(int *)(iVar7 + 0x30) != 0) &&
                 (iVar3 = FUN_0055a320(*(undefined4 *)(param_1 + 0x2ac8),*(int *)(iVar7 + 0x30)),
                 iVar3 != 0)) &&
                (iVar3 = FUN_0055a360(*(undefined4 *)(param_1 + 0x2ac8),
                                      *(undefined4 *)(iVar7 + 0x30)), iVar3 != 0)) {
          FUN_005b45a0(local_40,&local_4c);
          FUN_005b4900(local_40,iVar3);
LAB_0057126a:
          if (*(int **)(iVar7 + 0x34) != (int *)0x0) {
            iVar6 = **(int **)(iVar7 + 0x34);
            if (((*(byte *)(iVar6 + 0x17) & 0x40) == 0) || (PTR_PTR_008033b0[0xc] == -1)) {
              uVar5 = (uint)*(byte *)(iVar6 + 0x25);
            }
            else {
              uVar5 = (uint)(char)PTR_PTR_008033b0[0xc];
            }
            iVar6 = *(int *)PTR_PTR_008033b0 + uVar5 * 0x38;
            if (iVar6 != 0) {
              if ((*(byte *)(iVar7 + 0x38) & 0x10) == 0) {
                FUN_005b45a0(local_40,&local_4c);
                FUN_005b4f70(local_40,uVar2);
                FUN_005b4cf0(local_40,(int)ROUND(fVar1 * 1820.0) & 0xffff);
                FUN_005b4900(local_40,iVar3);
              }
              FUN_005f33b0(*(short *)(iVar6 + 0x10) * 0x10 + *(int *)(param_1 + 0x2ac0),local_40);
            }
          }
        }
        local_58 = local_58 + 1;
        iVar7 = iVar7 + 0x3c;
      } while (local_58 < *(int *)(*(int *)(param_1 + 0x5054) + 4));
    }
  }
  return;
}

