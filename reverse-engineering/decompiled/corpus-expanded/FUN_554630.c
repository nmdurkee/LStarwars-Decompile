/* Ghidra pseudocode, not original source.
 * ev_23fe0c900a66283c3d20cf72d3e92d7068463e5c92bfb1d0cb56e731534c3cac
 * Entry: 0x554630; label: FUN_00554630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00554630(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_4c;
  int local_48;
  undefined1 local_40 [64];
  
  if ((*(int *)(param_1 + 0x46e0) != 0) &&
     (local_48 = 0, *(char *)(*(int *)(param_1 + 0x128) + 0xf2) != '\0')) {
    local_4c = 0;
    do {
      FUN_00596920(0);
      iVar4 = *(int *)(param_1 + 0x46e0) + local_4c;
      if (((*(byte *)(iVar4 + 0xac) & 1) != 0) &&
         (((*(byte *)(iVar4 + 0xac) & 4) == 0 || (DAT_0087b4d8 != 0)))) {
        iVar2 = iVar4 + 0x50;
        iVar1 = FUN_005cfac0(iVar2);
        if ((iVar1 != 0) &&
           ((((FUN_005f33b0(iVar2,iVar4), *(char *)(iVar4 + 0x8b) != '\0' &&
              (iVar1 = FUN_005d0450(iVar2,&DAT_0093b118), iVar1 != 0)) &&
             (iVar1 = FUN_005cfac0(&DAT_0093b10c), iVar1 != 0)) &&
            (iVar1 = 0, *(char *)(iVar4 + 0x8b) != '\0')))) {
          iVar3 = iVar4 + 0xb4;
          do {
            FUN_005f33b0(&DAT_0093b10c,iVar3);
            iVar1 = iVar1 + 1;
            iVar3 = iVar3 + 0x44;
          } while (iVar1 < (int)(uint)*(byte *)(iVar4 + 0x8b));
        }
        thunk_FUN_005d05b0();
        if ((((*(uint *)(iVar4 + 0x84) & 0x800) != 0) && (iVar1 = FUN_005cfac0(iVar2), iVar1 != 0))
           && ((iVar1 = FUN_005cfd60(iVar2), iVar1 != 0 &&
               (iVar1 = FUN_005505a0(iVar4,*(undefined4 *)(iVar4 + 0xa0),
                                     *(undefined4 *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xc0),
                                     local_40), iVar1 != 0)))) {
          FUN_005d4690(0);
          FUN_005f33b0(iVar2,local_40);
          if (((*(char *)(iVar4 + 0x8b) != '\0') &&
              (iVar2 = FUN_005d0450(iVar2,&DAT_0093b118), iVar2 != 0)) &&
             ((iVar2 = FUN_005cfac0(&DAT_0093b10c), iVar2 != 0 &&
              (iVar2 = 0, *(char *)(iVar4 + 0x8b) != '\0')))) {
            iVar1 = iVar4 + 0xb4;
            do {
              FUN_005f33b0(&DAT_0093b10c,iVar1);
              iVar2 = iVar2 + 1;
              iVar1 = iVar1 + 0x44;
            } while (iVar2 < (int)(uint)*(byte *)(iVar4 + 0x8b));
          }
          FUN_005d46b0();
        }
      }
      local_4c = local_4c + 0x304;
      local_48 = local_48 + 1;
    } while (local_48 < (int)(uint)*(byte *)(*(int *)(param_1 + 0x128) + 0xf2));
  }
  return;
}

