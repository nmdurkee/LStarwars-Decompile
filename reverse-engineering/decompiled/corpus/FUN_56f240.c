/* Ghidra analysis pseudocode, not original source.
 * ev_c11631b0b0a1045a7d98640a93ba67d08ac61cae21ea073376eab243577db9e4
 * Entry: 0x56f240; label: FUN_0056f240
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0056f240(int param_1)

{
  char *pcVar1;
  float fVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  int in_EAX;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int in_ECX;
  char *pcVar9;
  int local_5c;
  undefined4 local_4c;
  float local_48;
  undefined4 local_44;
  undefined1 local_40 [64];
  
  if ((in_ECX != 0) && (iVar6 = FUN_0058aab0(DAT_009553d4), iVar6 == 0)) {
    FUN_005b7d30(_DAT_00925064,0x3f000000);
    fVar2 = *(float *)(*(int *)(param_1 + 0x50b8) + 0x14);
    fVar4 = *(float *)(*(int *)(param_1 + 0x50b8) + 0x14) * 0.5;
    if (0 < in_EAX) {
      pcVar9 = (char *)(in_ECX + 0x24);
      local_5c = in_EAX;
      do {
        bVar3 = pcVar9[-0xd];
        if (((((bVar3 & 1) != 0) && (pcVar9[-0xd] = bVar3 & 0xef, (bVar3 & 4) != 0)) &&
            ((bVar3 & 8) == 0)) &&
           (((bVar3 & 0x20) != 0 &&
            ((*pcVar9 < '\0' || (*(char *)((int)*pcVar9 + *(int *)(param_1 + 0x2a94)) != '\0'))))))
        {
          if (((bVar3 & 0x40) == 0) || (PTR_PTR_008033b0[0xc] == -1)) {
            iVar6 = *(int *)PTR_PTR_008033b0 + (uint)(byte)pcVar9[1] * 0x38;
          }
          else {
            iVar6 = *(int *)PTR_PTR_008033b0 + (char)PTR_PTR_008033b0[0xc] * 0x38;
          }
          if (*(char *)(iVar6 + 0xf) == '\0') {
            pcVar1 = pcVar9 + -0x1c;
            fVar5 = (*(float *)(pcVar9 + -0x1c) - *(float *)(PTR_DAT_008021b4 + 0x11c)) *
                    (*(float *)(pcVar9 + -0x1c) - *(float *)(PTR_DAT_008021b4 + 0x11c)) +
                    (*(float *)(pcVar9 + -0x14) - *(float *)(PTR_DAT_008021b4 + 0x124)) *
                    (*(float *)(pcVar9 + -0x14) - *(float *)(PTR_DAT_008021b4 + 0x124));
            if (fVar5 <= fVar2 * fVar2) {
              iVar7 = ((uint)(byte)pcVar9[-0xe] + (int)*(short *)(iVar6 + 0x10)) * 0x10;
              if (*(char *)(*(int *)(param_1 + 0x2ac0) + 0xe + iVar7) != '\0') {
                if ((*(byte *)(iVar6 + 0xe) & 1) == 0) {
                  if ((*(byte *)(iVar6 + 0xe) & 2) == 0) {
                    FUN_005b4500(local_40,pcVar1);
                  }
                  else {
                    uVar8 = FUN_0056eff0();
                    FUN_005b4900(uVar8,pcVar1);
                  }
                }
                else {
                  FUN_006e6b90();
                  FUN_0056ef50();
                  uVar8 = FUN_0056f0a0();
                  FUN_005b4900(uVar8,pcVar1);
                }
                if (DAT_00950f60 != 1.0) {
                  FUN_005b4b30(local_40,DAT_00950f60);
                }
                if ((pcVar9[-0xf] & 8U) != 0) {
                  thunk_FUN_005d05b0();
                }
                iVar7 = FUN_005f33b0(*(int *)(param_1 + 0x2ac0) + iVar7,local_40);
                pcVar9[-0xd] = pcVar9[-0xd] ^ ((iVar7 != 0) << 4 ^ pcVar9[-0xd]) & 0x10U;
                if ((((pcVar9[-0xd] & 0x10U) != 0) && (*(short *)(iVar6 + 0x2e) != -1)) &&
                   (*(char *)(*(short *)(iVar6 + 0x2e) * 0x10 + 0xe + *(int *)(param_1 + 0x2ac0)) !=
                    '\0')) {
                  thunk_FUN_005d05b0();
                  FUN_005f33b0(*(short *)(iVar6 + 0x2e) * 0x10 + *(int *)(param_1 + 0x2ac0),local_40
                              );
                  FUN_00596920(0);
                }
                if ((pcVar9[-0xf] & 8U) != 0) {
                  FUN_00596920(0);
                }
              }
              if (((DAT_00951288 == 0) && (*(float *)(pcVar9 + -8) != 2e+06)) &&
                 (fVar5 < fVar4 * fVar4)) {
                local_4c = *(undefined4 *)pcVar1;
                local_48 = *(float *)(pcVar9 + -8) + 0.005;
                local_44 = *(undefined4 *)(pcVar9 + -0x14);
                uVar8 = FUN_006e6b90(*(undefined2 *)(pcVar9 + -4),0,*(undefined2 *)(pcVar9 + -2));
                FUN_005fee80(&local_4c,*(undefined4 *)(iVar6 + 0x14),uVar8);
              }
            }
          }
        }
        pcVar9 = pcVar9 + 0x2c;
        local_5c = local_5c + -1;
      } while (local_5c != 0);
    }
  }
  return;
}

