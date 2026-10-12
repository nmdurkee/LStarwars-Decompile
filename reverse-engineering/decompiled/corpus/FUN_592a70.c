/* Ghidra analysis pseudocode, not original source.
 * ev_95f339e64e03912db0b4337524e50c5f1fa1cc6c36f27950d42195022949d97c
 * Entry: 0x592a70; label: FUN_00592a70
 */

void FUN_00592a70(int *param_1,short *param_2)

{
  short *psVar1;
  short sVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int local_114;
  int *local_110;
  short *local_10c;
  int local_108;
  undefined1 local_104 [128];
  undefined1 local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_114;
  local_110 = param_1;
  local_10c = param_2;
  if (param_1 != (int *)0x0) {
    DAT_00955874 = 1;
    sVar2 = *param_2;
    while (iVar5 = (int)sVar2, iVar5 != -1) {
      if (iVar5 == (short)param_1[0x1b]) {
        local_114 = 0;
LAB_00592ae6:
        iVar5 = *(short *)(*(int *)(DAT_029130e4 + 0x1c) + iVar5 * 2) * 0x54 +
                *(int *)(DAT_029130e4 + 0x18);
        piVar6 = &DAT_00955630 + local_114 * 0x48;
        local_108 = 0;
        do {
          *piVar6 = 0;
          piVar6[1] = 0;
          piVar6[2] = 0;
          piVar6[3] = 0;
          piVar6[4] = 0;
          piVar6[5] = 0;
          piVar6[6] = 0;
          piVar6[7] = 0;
          if ((*(int *)*param_1 != 0) && (0 < param_1[0x12])) {
            piVar6[7] = iVar5;
            FUN_004f1f10(local_84,*(undefined4 *)
                                   (param_1[9] +
                                   (uint)*(ushort *)
                                          (local_110[0x5d] + (local_108 + local_114 * 0x1c) * 2) *
                                   0x28));
            FUN_004f1f10(local_104,"chars\\weirdo\\");
            FUN_004f1e80(local_104,*(undefined4 *)*param_1);
            FUN_004f1e80(local_104,&DAT_0075a204);
            FUN_004f1e80(local_104,local_84);
            if (*(char *)(*param_1 + 4) == '\0') {
              if (*(char *)(*param_1 + 5) != -1) {
                FUN_004f1e80(local_104,&DAT_0075eac4);
                iVar3 = FUN_005f8d60(local_104,&DAT_00924890,DAT_00924894);
                piVar6[5] = iVar3;
                if (iVar3 != 0) {
                  iVar3 = *(int *)(iVar5 + 4);
                  iVar7 = 0;
                  if (0 < *(int *)(iVar3 + 0x10)) {
                    do {
                      if ((uint)*(byte *)(*(int *)(*(int *)(iVar3 + 0xc) + iVar7 * 4) + 0x9a) ==
                          (int)*(char *)(*param_1 + 5)) {
                        piVar6[6] = iVar7;
                        piVar6[4] = (int)*(short *)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 0xc) +
                                                            iVar7 * 4) + 0x74);
                        *(short *)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 0xc) + iVar7 * 4) + 0x74)
                             = (short)piVar6[5];
                        FUN_005e4b00(*(undefined4 *)
                                      (*(int *)(*(int *)(iVar5 + 4) + 0xc) + iVar7 * 4));
                      }
                      iVar3 = *(int *)(iVar5 + 4);
                      iVar7 = iVar7 + 1;
                    } while (iVar7 < *(int *)(iVar3 + 0x10));
                  }
                }
              }
            }
            else {
              FUN_004f1e80(local_104,&DAT_0075a1fc);
              iVar3 = FUN_005ef7f0(&DAT_00924890,DAT_00924894,local_104);
              *piVar6 = iVar3;
              if (iVar3 != 0) {
                FUN_005cf5b0(iVar3,piVar6 + 1,local_84,1);
              }
            }
          }
          local_108 = local_108 + 1;
          param_1 = param_1 + 1;
          piVar6 = piVar6 + 8;
          piVar4 = local_110;
        } while (local_108 < 9);
      }
      else {
        piVar4 = param_1;
        if (iVar5 == *(short *)((int)param_1 + 0x6e)) {
          local_114 = 1;
          goto LAB_00592ae6;
        }
      }
      psVar1 = local_10c + 2;
      local_10c = local_10c + 2;
      param_1 = piVar4;
      sVar2 = *psVar1;
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_114);
  return;
}

