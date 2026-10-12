/* Ghidra pseudocode, not original source.
 * ev_ea1530849940888f284d0032d7a98207406f19684b2cf3146fa9fb18feca4f87
 * Entry: 0x467b40; label: FUN_00467b40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00467b40(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  iVar1 = *param_1;
  uVar2 = *(uint *)(iVar1 + 0xa0);
  if (((((uVar2 & 2) != 0) || (*(short *)(iVar1 + 0x88) != -1)) && ((uVar2 & 1) != 0)) ||
     (param_3 != 0)) {
    switch(param_2) {
    case 0:
      if ((*(int *)(iVar1 + 0x28) != 0) && (*(int *)(*(int *)(iVar1 + 0x28) + 0xc) == 2)) {
        return 1;
      }
      break;
    case 1:
      if ((*(int *)(iVar1 + 0x28) != 0) && (*(int *)(*(int *)(iVar1 + 0x28) + 0xc) != 0)) {
        return 1;
      }
      break;
    case 2:
      if ((*(int *)(iVar1 + 0x28) != 0) && (*(int *)(*(int *)(iVar1 + 0x28) + 0xc) == 0)) {
        return 1;
      }
      break;
    case 3:
      if ((*(int *)(iVar1 + 0x40) != 0) && ((*(byte *)(*(int *)(iVar1 + 0x40) + 0x24) & 2) != 0)) {
        return 1;
      }
      break;
    case 4:
      if ((*(int *)(iVar1 + 0x40) != 0) && ((*(byte *)(*(int *)(iVar1 + 0x40) + 0x24) & 4) != 0)) {
        return 1;
      }
      break;
    case 5:
      if ((uVar2 & 0x10000) != 0) {
        return 1;
      }
      break;
    case 6:
      uVar3 = FUN_00467890(iVar1);
      return uVar3;
    case 7:
      if ((uVar2 & 0x200000) != 0) {
        return 1;
      }
    }
  }
  return 0;
}

