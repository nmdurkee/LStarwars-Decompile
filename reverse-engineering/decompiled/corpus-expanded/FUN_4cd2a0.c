/* Ghidra pseudocode, not original source.
 * ev_8be83d5a314ed06484cc1a00e0611cd4a1346ac66c548b102291ab30b68096a0
 * Entry: 0x4cd2a0; label: FUN_004cd2a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004cd2a0(int param_1)

{
  float fVar1;
  int iVar2;
  short *psVar3;
  undefined *puVar4;
  int iVar5;
  undefined2 *puVar6;
  float10 fVar7;
  int local_48;
  undefined1 local_40 [48];
  undefined1 local_10 [16];
  
  if (((DAT_007fd11e != -1) &&
      (*(char *)(DAT_007fd11e * 0x10 + 0xe + *(int *)(param_1 + 0x2ac0)) != '\0')) &&
     (iVar5 = *(int *)(param_1 + 0x5078), iVar5 != 0)) {
    fVar7 = (float10)FUN_005b7d30(_DAT_0092505c,0x40a00000);
    FUN_005b7d30(_DAT_00925064,0x3f000000);
    iVar2 = FUN_006e6b90();
    local_48 = 0;
    fVar1 = (float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff] * 0.2 + 0.8;
    if (0 < *(int *)(param_1 + 0x507c)) {
      puVar6 = (undefined2 *)(iVar5 + 0x30);
      do {
        if ((*(byte *)(puVar6 + 6) & 2) != 0) {
          psVar3 = &DAT_007fd11e;
          puVar4 = &DAT_007fd124;
          do {
            if (*psVar3 != -1) {
              FUN_005b4500(local_40,puVar4);
              FUN_005b4f70(local_40,*puVar6);
              FUN_005b4900(local_40,puVar6 + -0x10);
              FUN_005f33b0(*psVar3 * 0x10 + *(int *)(param_1 + 0x2ac0),local_40);
            }
            puVar4 = puVar4 + 0xc;
            psVar3 = psVar3 + 1;
          } while ((int)puVar4 < 0x7fd148);
          iVar5 = 0;
          do {
            if (*(char *)((short)(&DAT_007fd148)[iVar5] * 0x10 + 0xe + *(int *)(param_1 + 0x2ac0))
                != '\0') {
              FUN_006e6b90();
              iVar2 = FUN_006e6b90();
              if (iVar5 != 0) {
                iVar2 = -iVar2;
              }
              FUN_005b4670(local_40,iVar2);
              FUN_005b4900(local_40,&DAT_007fd14c + iVar5 * 0xc);
              FUN_005b4f70(local_40,*puVar6);
              FUN_005b37d0(local_10,local_10,puVar6 + -0x10);
              FUN_005f33b0((short)(&DAT_007fd148)[iVar5] * 0x10 + *(int *)(param_1 + 0x2ac0),
                           local_40);
            }
            iVar5 = iVar5 + 1;
          } while (iVar5 < 2);
          if ((((*(byte *)(puVar6 + 6) & 1) != 0) && (*(float *)(puVar6 + -8) != 2e+06)) &&
             ((*(char *)(DAT_007fd11c * 0x10 + 0xe + *(int *)(param_1 + 0x2ac0)) != '\0' &&
              (0.0 < fVar1)))) {
            FUN_005b4670(local_40,(int)ROUND((fVar7 / (float10)5.0) * (float10)65536.0) & 0xffff);
            if (puVar6[2] != 0) {
              FUN_005b5160(local_40,puVar6[2]);
            }
            if (puVar6[1] != 0) {
              FUN_005b4cf0(local_40,puVar6[1]);
            }
            FUN_005b4900(local_40,puVar6 + -10);
            FUN_005ff7a0(DAT_007fd11c * 0x10 + *(int *)(param_1 + 0x2ac0),local_40,fVar1);
          }
        }
        local_48 = local_48 + 1;
        puVar6 = puVar6 + 0x38;
      } while (local_48 < *(int *)(param_1 + 0x507c));
    }
  }
  return;
}

