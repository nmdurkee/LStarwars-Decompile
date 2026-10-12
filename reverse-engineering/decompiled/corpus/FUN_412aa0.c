/* Ghidra analysis pseudocode, not original source.
 * ev_67a1dd79f1152a4a8dc944803f9da200f64b6e45b6a6754633c37085e261482d
 * Entry: 0x412aa0; label: FUN_00412aa0
 */

undefined4 FUN_00412aa0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_38;
  
  if (((*(int *)(PTR_DAT_00802c54 + 0x5118) != 0) &&
      (iVar4 = *(int *)(PTR_DAT_00802c54 + 0x511c), iVar4 != 0)) &&
     ((*(byte *)(param_1 + 0xf0) & 3) != 0)) {
    local_38 = 0;
    iVar2 = iVar4 + 0xe0;
    do {
      if (*(int *)(iVar2 + 0x628) != 0) {
        iVar5 = 0;
        iVar3 = iVar2;
        do {
          if ((*(int *)(iVar3 + 0x110) != 0) && (iVar1 = FUN_00412760(param_1), iVar1 != 0)) {
            return 1;
          }
          iVar5 = iVar5 + 1;
          iVar3 = iVar3 + 0x130;
        } while (iVar5 < 5);
      }
      local_38 = local_38 + 1;
      iVar2 = iVar2 + 0x680;
    } while (local_38 < 8);
    iVar2 = 0;
    iVar4 = iVar4 + 0x564d0;
    do {
      if ((*(int *)(iVar4 + 0x110) != 0) && (iVar3 = FUN_00412760(param_1), iVar3 != 0)) {
        return 1;
      }
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + 0x130;
    } while (iVar2 < 0x60);
  }
  return 0;
}

