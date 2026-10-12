/* Ghidra pseudocode, not original source.
 * ev_d9512b1cdbab5300ab403012014fa5708c5416e00a513842278be36b13b8a77c
 * Entry: 0x46fbe0; label: FUN_0046fbe0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046fbe0(int param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  int local_48;
  int local_44;
  undefined1 local_40 [64];
  
  if ((((param_1 != 0) && (piVar4 = *(int **)(param_1 + 0x5100), piVar4 != (int *)0x0)) &&
      (piVar4[1] != 0)) &&
     ((*(char *)(*(int *)(param_1 + 0x2ac0) + 0x122e) != '\0' &&
      (*(char *)(*(int *)(param_1 + 0x2ac0) + 0x123e) != '\0')))) {
    FUN_00596920(0);
    local_44 = 0;
    if (0 < piVar4[1]) {
      local_48 = 0;
      do {
        iVar7 = *piVar4 + local_48;
        if (((*(byte *)(iVar7 + 0x2b) & 2) != 0) || (DAT_0087b4d8 != 0)) {
          FUN_005b4670(local_40,*(undefined2 *)(iVar7 + 0x20));
          iVar1 = iVar7 + 0x10;
          FUN_005b4900(local_40,iVar1);
          FUN_005b4b30(local_40,piVar4[2]);
          bVar5 = *(byte *)(iVar7 + 0x2b) >> 2 & 1;
          if ((bVar5 == 0) && (*(char *)(*(int *)(param_1 + 0x2ac0) + 0x122e) != '\0')) {
            iVar6 = *(int *)(param_1 + 0x2ac0) + 0x1220;
LAB_0046fcd6:
            FUN_005f33b0(iVar6,local_40);
          }
          else if ((bVar5 == 1) && (*(char *)(*(int *)(param_1 + 0x2ac0) + 0x123e) != '\0')) {
            iVar6 = *(int *)(param_1 + 0x2ac0) + 0x1230;
            goto LAB_0046fcd6;
          }
          if ((((*(byte *)(iVar7 + 0x2b) & 1) != 0) && (0.0 < *(float *)(iVar7 + 0x1c))) &&
             (0.3 <= *(float *)(iVar7 + 0x1c) + *(float *)(iVar7 + 0x1c))) {
            iVar7 = FUN_006e6b90();
            fVar2 = (float)(&DAT_029899a0)[iVar7 >> 1 & 0x7fff];
            fVar3 = *(float *)(*(int *)(PTR_DAT_00802c54 + 0x5100) + 8);
            FUN_005b7d30(_DAT_00925064,0x3e4ccccd);
            iVar7 = FUN_006e6b90();
            fVar2 = ((float)(&DAT_029899a0)[iVar7 >> 1 & 0x7fff] * 0.1 + 1.0) * fVar3 * 4.0 * fVar2;
            FUN_00552ad0(param_1,0x79,iVar1,0,0,0,fVar2,fVar2,fVar2,2);
            FUN_00552ad0(param_1,0x7b,iVar1,0,0,0,fVar2,fVar2,fVar2,2);
          }
        }
        local_48 = local_48 + 0x2c;
        local_44 = local_44 + 1;
      } while (local_44 < piVar4[1]);
    }
    thunk_FUN_005d05b0();
  }
  return;
}

