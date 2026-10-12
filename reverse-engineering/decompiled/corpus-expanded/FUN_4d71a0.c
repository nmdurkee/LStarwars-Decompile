/* Ghidra pseudocode, not original source.
 * ev_7cce3243898a12dda79e95a496780a4d79cb1010b8a976b902fd46336e9989b6
 * Entry: 0x4d71a0; label: FUN_004d71a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d71a0(int param_1)

{
  byte bVar1;
  ushort uVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int local_5c;
  undefined4 local_58;
  char local_54 [4];
  char local_50 [4];
  undefined1 local_4c [12];
  undefined1 local_40 [64];
  
  if ((param_1 != 0) && (iVar5 = *(int *)(param_1 + 0x4688), iVar5 != 0)) {
    FUN_005b7d30(_DAT_0092505c,0x40a00000);
    FUN_005b7d30(_DAT_00925064,0x3f000000);
    iVar4 = FUN_006e6b90();
    local_5c = 0;
    fVar3 = (float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff] * 0.2 + 0.8;
    if (0 < *(int *)(param_1 + 0x468c)) {
      do {
        uVar2 = *(ushort *)(iVar5 + 0x68);
        if (((uVar2 & 0x40) != 0) && ((char)uVar2 < '\0')) {
          if ((uVar2 & 0x20) == 0) {
            if (((uVar2 & 0x10) != 0) && (*(char *)(*(int *)(param_1 + 0x2ac0) + 0x53e) != '\0')) {
              FUN_00596920(0);
              FUN_005b45f0(local_40,*(undefined2 *)(iVar5 + 0x34));
              FUN_005b4f70(local_40,*(undefined2 *)(iVar5 + 0x36));
              FUN_005b4900(local_40,iVar5 + 0x1c);
              FUN_005f33b0(*(int *)(param_1 + 0x2ac0) + 0x530,local_40);
              thunk_FUN_005d05b0();
            }
            if (((DAT_00881c38 != 0) && ((*(byte *)(iVar5 + 0x68) & 2) != 0)) &&
               (*(char *)(*(int *)(param_1 + 0x2ac0) + 0xe5e) != '\0')) {
              FUN_005b4500(local_40,iVar5 + 0x10);
              FUN_005ff7a0(*(int *)(param_1 + 0x2ac0) + 0xe50,local_40,0x3f800000);
              if ((*(byte *)(iVar5 + 0x68) & 8) != 0) {
                FUN_005b4500(local_40,iVar5 + 0x28);
                FUN_005ff7a0(*(int *)(param_1 + 0x2ac0) + 0xe50,local_40,0x3f800000);
              }
              if ((*(byte *)(iVar5 + 0x68) & 4) != 0) {
                FUN_004d70f0(param_1,fVar3);
                bVar1 = *(byte *)(iVar5 + 0x68);
                goto joined_r0x004d74a2;
              }
            }
          }
          else {
            if (*(char *)(*(int *)(param_1 + 0x2ac0) + 0x53e) != '\0') {
              local_58 = 0;
              local_54[0] = s_>_Cl___W_Active_007ffc2f[5];
              local_54[1] = s_>_Cl___W_Active_007ffc2f[6];
              local_54[2] = s_>_Cl___W_Active_007ffc2f[7];
              local_54[3] = s_>_Cl___W_Active_007ffc2f[8];
              local_50[0] = s_>_Cl___W_Active_007ffc2f[1];
              local_50[1] = s_>_Cl___W_Active_007ffc2f[2];
              local_50[2] = s_>_Cl___W_Active_007ffc2f[3];
              local_50[3] = s_>_Cl___W_Active_007ffc2f[4];
              FUN_005b3620(&local_58,&local_58,*(undefined2 *)(iVar5 + 100));
              FUN_005b37d0(local_4c,iVar5 + 0x10,&local_58);
              FUN_005b4500(local_40,local_4c);
              FUN_005f33b0(*(int *)(param_1 + 0x2ac0) + 0x530,local_40);
              if ((*(byte *)(iVar5 + 0x68) & 8) != 0) {
                FUN_005b3620(&local_58,&local_58,0x8000);
                FUN_005b37d0(local_4c,iVar5 + 0x28,&local_58);
                FUN_005b4500(local_40,local_4c);
                FUN_005f33b0(*(int *)(param_1 + 0x2ac0) + 0x530,local_40);
              }
            }
            FUN_004d70f0(param_1,fVar3);
            bVar1 = *(byte *)(iVar5 + 0x68);
joined_r0x004d74a2:
            if ((bVar1 & 8) != 0) {
              FUN_004d70f0(param_1,fVar3);
            }
          }
        }
        local_5c = local_5c + 1;
        iVar5 = iVar5 + 0x7c;
      } while (local_5c < *(int *)(param_1 + 0x468c));
    }
  }
  return;
}

