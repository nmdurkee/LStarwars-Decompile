/* Ghidra pseudocode, not original source.
 * ev_8d7f18048ef2880fb529f575b466097bafe0da5dbea7c232731940988e33188f
 * Entry: 0x597380; label: FUN_00597380
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00597380(int param_1)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  short sVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  float10 fVar9;
  undefined4 local_18;
  float local_14;
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  float local_4;
  
  if ((param_1 != 0) && (iVar3 = *(int *)(param_1 + 0x10ac), iVar3 != 0)) {
    local_18 = *(undefined4 *)(param_1 + 0x19c);
    *(undefined4 *)(param_1 + 0xff8) = *(undefined4 *)(iVar3 + 0x108);
    local_10 = *(undefined4 *)(param_1 + 0x1a4);
    iVar8 = 0;
    local_14 = *(float *)(iVar3 + 0x108) * _DAT_00805138 + *(float *)(param_1 + 0x1a0);
    if (*(short *)(iVar3 + 0x10c) != 0) {
      do {
        iVar3 = iVar8 * 0x18;
        puVar5 = (undefined4 *)(*(int *)(param_1 + 0x10ac) + iVar3);
        *puVar5 = local_18;
        puVar5[1] = local_14;
        puVar5[2] = local_10;
        if (iVar8 == 0) {
          uVar6 = (uint)*(ushort *)(param_1 + 0x27a);
        }
        else {
          uVar6 = *(uint *)(iVar3 + -8 + *(int *)(param_1 + 0x10ac));
        }
        uVar6 = FUN_00550070(*(undefined2 *)(iVar3 + 0x10 + *(int *)(param_1 + 0x10ac)),uVar6,
                             _DAT_0080513c);
        *(uint *)(iVar3 + 0x10 + *(int *)(param_1 + 0x10ac)) = uVar6 & 0xffff;
        *(undefined4 *)(iVar3 + 0x14 + *(int *)(param_1 + 0x10ac)) = 0;
        local_c = 0;
        local_8 = 0.0;
        local_4 = -(*(float *)(*(int *)(param_1 + 0x10ac) + 0x108) * _DAT_00805134);
        FUN_005b3620(&local_c,&local_c,*(undefined4 *)(iVar3 + 0x10 + *(int *)(param_1 + 0x10ac)));
        FUN_005b37d0(&local_18,*(int *)(param_1 + 0x10ac) + iVar3,&local_c);
        fVar9 = (float10)FUN_005506f0(0,&local_18,0x40a00000,0x1f);
        fVar2 = (float)fVar9;
        if (fVar2 == 2e+06) {
          fVar2 = *(float *)(iVar3 + 4 + *(int *)(param_1 + 0x10ac));
        }
        pfVar1 = (float *)(iVar3 + 0xc + *(int *)(param_1 + 0x10ac));
        if (*(float *)(iVar3 + 0xc + *(int *)(param_1 + 0x10ac)) == 1e+09) {
          *pfVar1 = fVar2;
        }
        else {
          fVar9 = (float10)FUN_0054fb40(*pfVar1,fVar2,0x41200000);
          *(float *)(iVar3 + 0xc + *(int *)(param_1 + 0x10ac)) = (float)fVar9;
        }
        iVar7 = *(int *)(param_1 + 0x10ac) + iVar3;
        if (*(float *)(*(int *)(param_1 + 0x10ac) + 0xc + iVar3) != 2e+06) {
          local_14 = *(float *)(iVar7 + 0xc);
          fVar9 = (float10)FUN_005becc0(&local_18,iVar7,&local_c);
          FUN_005b3830(&local_c,&local_c,
                       (*(float *)(*(int *)(param_1 + 0x10ac) + 0x108) * _DAT_00805134) /
                       (float)fVar9);
          FUN_005b37d0(&local_18,*(int *)(param_1 + 0x10ac) + iVar3,&local_c);
          sVar4 = FUN_005970d0(-local_8 /
                               (*(float *)(*(int *)(param_1 + 0x10ac) + 0x108) * _DAT_00805134));
          *(int *)(iVar3 + 0x14 + *(int *)(param_1 + 0x10ac)) = (int)sVar4;
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < (int)(uint)*(ushort *)(*(int *)(param_1 + 0x10ac) + 0x10c));
    }
  }
  return;
}

