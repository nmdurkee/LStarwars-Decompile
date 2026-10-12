/* Ghidra analysis pseudocode, not original source.
 * ev_967bc49bfb89c9289ebafb6996ca9c72d569b4a48639dbecd20a21d28d62ec51
 * Entry: 0x4505d0; label: FUN_004505d0
 */

undefined4
FUN_004505d0(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,int param_6)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  uVar4 = 0;
  local_10 = 0;
  local_4 = 1;
  local_18 = 0;
  local_c = 0;
  local_8 = 0;
  if ((((param_1 != 0) && (*(char **)(param_1 + 0x10) != (char *)0x0)) &&
      (**(char **)(param_1 + 0x10) != '\0')) && ((param_6 != 0 && (iVar5 = 0, 0 < param_5)))) {
    do {
      iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),&DAT_00757f40);
      if (iVar2 == 0) {
        iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),&DAT_00757d6c);
        if (iVar2 == 0) {
          uVar3 = FUN_0044d870();
          if (uVar3 == 0) {
            iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"bothways");
            if (iVar2 == 0) {
              local_10 = 1;
            }
            else {
              iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"FALSE");
              if (iVar2 == 0) {
                local_4 = 0;
              }
            }
          }
          else {
            uVar4 = uVar4 | uVar3;
            if (uVar3 == DAT_00950d74) {
              local_18 = local_18 | DAT_00950d78;
            }
            else if (uVar3 == DAT_00950d78) {
              local_18 = local_18 | DAT_00950d74;
            }
            else if (uVar3 == 0x20000000) {
              local_10 = 1;
            }
          }
        }
        else {
          local_8 = iVar2 + 3;
        }
      }
      else {
        local_c = iVar2 + 5;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_5);
    if (((local_c != 0) && (local_8 != 0)) &&
       (iVar5 = FUN_0051adf0(param_1,*(undefined4 *)(*(int *)(param_1 + 0x10) + 8),local_c,local_8,
                             &local_14), iVar5 != 0)) {
      if (local_4 == 0) {
        puVar1 = (uint *)(iVar5 + local_14 * 4);
        *puVar1 = *puVar1 & ~uVar4;
      }
      else {
        puVar1 = (uint *)(iVar5 + local_14 * 4);
        *puVar1 = *puVar1 | uVar4;
        puVar1 = (uint *)(iVar5 + local_14 * 4);
        *puVar1 = *puVar1 & ~local_18;
      }
      if (local_10 != 0) {
        if (local_4 != 0) {
          puVar1 = (uint *)(iVar5 + (uint)(local_14 == 0) * 4);
          *puVar1 = *puVar1 | uVar4;
          puVar1 = (uint *)(iVar5 + (uint)(local_14 == 0) * 4);
          *puVar1 = *puVar1 & ~local_18;
          return 1;
        }
        puVar1 = (uint *)(iVar5 + (uint)(local_14 == 0) * 4);
        *puVar1 = *puVar1 & ~uVar4;
      }
    }
  }
  return 1;
}

