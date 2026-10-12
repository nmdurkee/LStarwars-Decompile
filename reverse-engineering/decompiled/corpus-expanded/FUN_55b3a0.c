/* Ghidra pseudocode, not original source.
 * ev_8c943698e03161dcf7a1afd17c02789bd1a03bc5c571948a550cbb172219f06a
 * Entry: 0x55b3a0; label: FUN_0055b3a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0055b3a0(int param_1)

{
  int iVar1;
  int iVar2;
  int local_4;
  
  iVar2 = 0;
  iVar1 = 0;
  if (0 < DAT_0093b278) {
    local_4 = 0;
    do {
      *(undefined4 *)(iVar2 + *(int *)(param_1 + 0x2980)) = 0;
      if ((((DAT_0093b27c == 0) || (*(int *)(iVar2 + DAT_0093b27c) == 0)) &&
          ((*(byte *)(local_4 + 0x40 + DAT_0093b274) & 1) != 0)) &&
         ((*(int *)(param_1 + 0x2ab0) != 0 &&
          ((*(uint *)(*(int *)(*(int *)(param_1 + 0x2ab0) + 8) +
                     ((int)(iVar1 + (iVar1 >> 0x1f & 0x1fU)) >> 5) * 4) & 1 << ((byte)iVar1 & 0x1f))
           != 0)))) {
        FUN_0055b300(param_1 + 0x104,*(undefined4 *)(param_1 + 0x108));
      }
      local_4 = local_4 + 0x4c;
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x10;
    } while (iVar1 < DAT_0093b278);
  }
  return;
}

