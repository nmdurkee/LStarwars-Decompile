/* Ghidra pseudocode, not original source.
 * ev_0c39cc066d2b612e886b5e8dc629d567ae8f788bfbc7a0ed81832ee74aa3ece0
 * Entry: 0x402eb0; label: FUN_00402eb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00402eb0(int param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  undefined4 *puVar9;
  float10 fVar10;
  float10 extraout_ST0;
  undefined4 local_50;
  undefined4 local_4c;
  float local_48;
  float local_44;
  undefined4 local_40 [16];
  
  iVar2 = param_1;
  local_50 = 0;
  if ((*(char *)(*(int *)(param_1 + 0x2ac0) + 0x48e) != '\0') &&
     (iVar6 = *(int *)(param_1 + 0x5098), iVar6 != 0)) {
    fVar10 = (float10)FUN_005b7d30(_DAT_0092505c,0x40a00000);
    FUN_005b7d30(_DAT_00925064,0x3f000000);
    iVar5 = FUN_006e6b90();
    piVar1 = (int *)(param_1 + 0x509c);
    param_1 = 0;
    local_48 = (float)(&DAT_029899a0)[iVar5 >> 1 & 0x7fff] * 0.2 + 0.8;
    if (0 < *piVar1) {
      pbVar7 = (byte *)(iVar6 + 0x62);
      do {
        *pbVar7 = *pbVar7 & 0xf7;
        if ((*pbVar7 & 2) != 0) {
          pbVar8 = pbVar7 + -0x46;
          puVar9 = local_40;
          for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar9 = *(undefined4 *)pbVar8;
            pbVar8 = pbVar8 + 4;
            puVar9 = puVar9 + 1;
          }
          cVar3 = FUN_005f33b0(*(int *)(iVar2 + 0x2ac0) + 0x480,local_40);
          bVar4 = (cVar3 << 3 ^ *pbVar7) & 8 ^ *pbVar7;
          *pbVar7 = bVar4;
          if ((((bVar4 & 4) == 0) && ((bVar4 & 1) != 0)) &&
             (*(char *)(*(int *)(iVar2 + 0x2ac0) + 0x55e) != '\0')) {
            FUN_005b4670(local_40,(int)ROUND((fVar10 / (float10)5.0) * (float10)65536.0) & 0xffff);
            if (*(short *)(pbVar7 + 0x10) != 0) {
              FUN_005b5160(local_40,*(short *)(pbVar7 + 0x10));
            }
            if (*(short *)(pbVar7 + 0xe) != 0) {
              FUN_005b4cf0(local_40,*(short *)(pbVar7 + 0xe));
            }
            FUN_005b4900(local_40,pbVar7 + 2);
            cVar3 = FUN_0055e970(pbVar7 + -0x52,&local_50,&local_4c,0,0);
            if (cVar3 != '\0') {
              iVar6 = FUN_006e6b90();
              local_44 = (float)(extraout_ST0 - (float10)(float)(&DAT_029899a0)[iVar6 >> 1 & 0x7fff]
                                );
              FUN_005ff7a0(*(int *)(iVar2 + 0x2ac0) + 0x550,local_40,local_44);
            }
          }
        }
        param_1 = param_1 + 1;
        pbVar7 = pbVar7 + 0x74;
      } while (param_1 < *(int *)(iVar2 + 0x509c));
    }
  }
  return;
}

