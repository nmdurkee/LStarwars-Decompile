/* Ghidra analysis pseudocode, not original source.
 * ev_0b4f3bc8b4a39fc427a7fcc8ed3e1304ee3926d0e45102a57071cb05acfa7baa
 * Entry: 0x5a4540; label: FUN_005a4540
 */

void FUN_005a4540(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *local_4c;
  int local_48;
  int local_44;
  undefined1 local_40 [48];
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if ((*(int *)(param_1 + 0x46bc) != 0) && (local_44 = 0, 0 < *(int *)(param_1 + 0x46c0))) {
    local_4c = (undefined4 *)(param_2 + 0xcc);
    iVar6 = *(int *)(param_1 + 0x46bc) + 0x24;
    do {
      if ((param_2 != 0) && (local_44 < 0x10)) {
        iVar7 = (int)(local_44 + (local_44 >> 0x1f & 0x1fU)) >> 5;
        uVar3 = 1 << ((byte)local_44 & 0x1f);
        *(uint *)(iVar6 + 0xa4) =
             *(uint *)(iVar6 + 0xa4) ^
             ((uint)((*(uint *)(param_2 + 4 + iVar7 * 4) & uVar3) != 0) * 0x2000000 ^
             *(uint *)(iVar6 + 0xa4)) & 0x2000000;
        uVar1 = ((uint)((*(uint *)(param_2 + iVar7 * 4) & uVar3) != 0) * 0x40000 ^
                *(uint *)(iVar6 + 0xa4)) & 0x40000 ^ *(uint *)(iVar6 + 0xa4);
        *(uint *)(iVar6 + 0xa4) = uVar1;
        if ((uVar1 & 0x40000) == 0) {
          FUN_005cfc00(iVar6,0);
          *(uint *)(iVar6 + 0xa4) = *(uint *)(iVar6 + 0xa4) & 0xfffbffff;
          iVar5 = 0;
          if (*(char *)(iVar6 + 0xad) != '\0') {
            local_48 = iVar6 + 0x38;
            do {
              FUN_005cfc00(local_48,0);
              local_48 = local_48 + 0xc;
              iVar5 = iVar5 + 1;
            } while (iVar5 < (int)(uint)*(byte *)(iVar6 + 0xad));
          }
        }
        if ((*(uint *)(param_2 + 8 + iVar7 * 4) & uVar3) != 0) {
          iVar7 = FUN_005d0420(iVar6);
          if (((*(uint *)(iVar6 + 0xa4) & 0x40000) == 0) && (iVar7 != 0)) {
            iVar7 = FUN_005d0370(iVar6);
            FUN_005526c0(iVar6,0x3f800000,local_40,0);
            *(undefined4 *)(iVar7 + 0x30) = local_10;
            *(undefined4 *)(iVar7 + 0x34) = local_c;
            *(undefined4 *)(iVar7 + 0x38) = local_8;
            FUN_005ea660(iVar6);
            iVar7 = 0;
            if (*(char *)(iVar6 + 0xad) != '\0') {
              iVar5 = iVar6 + 0x38;
              do {
                if (iVar5 != 0) {
                  iVar2 = FUN_005d0370(iVar5);
                  FUN_005526c0(iVar5,0x3f800000,local_40,0);
                  *(undefined4 *)(iVar2 + 0x30) = local_10;
                  *(undefined4 *)(iVar2 + 0x34) = local_c;
                  *(undefined4 *)(iVar2 + 0x38) = local_8;
                  FUN_005ea660(iVar5);
                }
                iVar7 = iVar7 + 1;
                iVar5 = iVar5 + 0xc;
              } while (iVar7 < (int)(uint)*(byte *)(iVar6 + 0xad));
            }
          }
          else {
            iVar7 = FUN_005d0370(iVar6);
            *(undefined4 *)(iVar7 + 0x30) = local_4c[-0x30];
            *(undefined4 *)(iVar7 + 0x34) = local_4c[-0x2f];
            *(undefined4 *)(iVar7 + 0x38) = local_4c[-0x2e];
            FUN_005ea660(iVar6);
            iVar7 = 0;
            if (*(char *)(iVar6 + 0xad) != '\0') {
              iVar5 = iVar6 + 0x38;
              puVar4 = local_4c;
              do {
                if (iVar5 != 0) {
                  iVar2 = FUN_005d0370(iVar5);
                  *(undefined4 *)(iVar2 + 0x30) = *puVar4;
                  *(undefined4 *)(iVar2 + 0x34) = puVar4[1];
                  *(undefined4 *)(iVar2 + 0x38) = puVar4[2];
                  FUN_005ea660(iVar5);
                }
                iVar7 = iVar7 + 1;
                iVar5 = iVar5 + 0xc;
                puVar4 = puVar4 + 0x30;
              } while (iVar7 < (int)(uint)*(byte *)(iVar6 + 0xad));
            }
          }
        }
      }
      local_4c = local_4c + 3;
      local_44 = local_44 + 1;
      iVar6 = iVar6 + 0xd4;
    } while (local_44 < *(int *)(param_1 + 0x46c0));
  }
  return;
}

