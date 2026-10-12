/* Ghidra pseudocode, not original source.
 * ev_12b000564e8cba1f3519ff70f1088df218803466ba65b3333f742de5377565cf
 * Entry: 0x41fe90; label: FUN_0041fe90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0041fe90(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int local_c;
  int local_8;
  int local_4;
  
  if ((((DAT_0087b504 == 0) && (iVar1 = FUN_0058a900(0), iVar1 == 0)) && (DAT_00951b50 == 0)) &&
     (param_1 != 0)) {
    local_c = 0;
    if (0 < *(int *)(param_1 + 0x14)) {
      local_8 = 0;
      do {
        iVar1 = 0;
        iVar4 = *(int *)(param_1 + 0x18) + local_8;
        local_4 = 0;
        if (*(char *)(iVar4 + 0x50) != '\0') {
          do {
            uVar2 = __allshl();
            if ((((uVar2 & *(uint *)(iVar4 + 0x58)) != 0) &&
                (uVar2 = (uint)*(short *)(iVar4 + 0x4e), uVar2 < 0x154)) &&
               ((*(short *)(*(int *)(DAT_029130e4 + 0x1c) + uVar2 * 2) != -1 &&
                (iVar3 = FUN_0055c9f0(), iVar3 != 0)))) {
              FUN_0041c7c0(iVar3,uVar2,1);
              *(uint *)(iVar3 + 0x1f8) = *(uint *)(iVar3 + 0x1f8) | 0x400;
              *(uint *)(iVar3 + 0x1fc) = *(uint *)(iVar3 + 0x1fc) & 0xffffefff;
              uVar2 = *(uint *)(*(short *)(iVar4 + 0x4e) * 0x4c + 4 + *(int *)(DAT_029130e4 + 0x20))
              ;
              if ((uVar2 & 0x200) == 0) {
                if ((uVar2 & 4) != 0) {
                  uVar2 = *(uint *)(iVar3 + 0x1f8) | 1;
                  goto LAB_0041ff96;
                }
              }
              else {
                uVar2 = *(uint *)(iVar3 + 0x1f8) | 4;
LAB_0041ff96:
                *(uint *)(iVar3 + 0x1f8) = uVar2;
              }
              *(uint *)(iVar3 + 0x1044) = *(uint *)(iVar3 + 0x1044) | 1;
              if ((*(uint *)(*(short *)(iVar4 + 0x4e) * 0x4c + 4 + *(int *)(DAT_029130e4 + 0x20)) &
                  0x1000) != 0) {
                *(uint *)(iVar3 + 0x1044) = *(uint *)(iVar3 + 0x1044) | 4;
              }
              *(undefined1 *)(iVar3 + 0x400) = (undefined1)local_c;
              if (((iVar1 == 0) && (1 < *(byte *)(iVar4 + 0x50))) &&
                 (*(float *)(iVar4 + 0x90) == 0.0)) {
                local_4 = FUN_00517fd0(param_1,*(undefined1 *)(iVar4 + 0x51),
                                       *(undefined4 *)(iVar4 + 0x5c),*(undefined4 *)(iVar4 + 0x60),
                                       *(undefined4 *)
                                        (*(int *)(*(int *)(iVar3 + 0x54) + 0x24) + 0x1c));
              }
              if (local_4 != 0) {
                FUN_00518040(local_4,iVar3);
              }
              *(undefined4 *)(iVar3 + 0x368) = *(undefined4 *)(iVar4 + 0x78);
              *(undefined4 *)(iVar3 + 0x36c) = *(undefined4 *)(iVar4 + 0x7c);
              *(undefined4 *)(iVar3 + 0x478) = *(undefined4 *)(iVar4 + 0x80);
              *(undefined1 *)(iVar3 + 0x378) = *(undefined1 *)(iVar4 + 0x4c);
            }
            iVar1 = iVar1 + 1;
          } while (iVar1 < (int)(uint)*(byte *)(iVar4 + 0x50));
        }
        local_8 = local_8 + 0xa4;
        local_c = local_c + 1;
      } while (local_c < *(int *)(param_1 + 0x14));
    }
    *(ushort *)(param_1 + 0x1386) = *(ushort *)(param_1 + 0x1386) & 0xfffe;
  }
  return;
}

