/* Ghidra analysis pseudocode, not original source.
 * ev_074dd20869da91b1b05b19bd1efa0509a9d09e9660d7c7c0c7ca47d053bd121c
 * Entry: 0x4ccad0; label: FUN_004ccad0
 */

int FUN_004ccad0(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar1 = *(int *)(param_1 + 0x6c);
  if (iVar1 == 0) {
    switch(*(undefined1 *)(param_1 + 0x37)) {
    case 0:
      iVar1 = param_1 + 0x3d;
      iVar2 = FUN_00440120(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),iVar1);
      if (iVar2 != 0) {
        *(int *)(param_1 + 0x6c) = iVar2;
        *(undefined1 *)(param_1 + 0x37) = 1;
        return iVar2;
      }
      iVar2 = FUN_0055a020(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),0xffffffff,iVar1);
      if (iVar2 != 0) {
        *(int *)(param_1 + 0x6c) = iVar2;
        *(undefined1 *)(param_1 + 0x37) = 3;
        return iVar2;
      }
      iVar2 = param_1 + 0x60;
      iVar1 = FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),iVar2,iVar1,0);
      if (iVar1 != 0) {
        *(int *)(param_1 + 0x6c) = iVar2;
        *(undefined1 *)(param_1 + 0x37) = 2;
        return iVar2;
      }
      *(undefined1 *)(param_1 + 0x37) = 0;
      *(undefined4 *)(param_1 + 0x6c) = 0;
      iVar1 = 0;
      break;
    case 1:
      iVar1 = FUN_00440120(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),param_1 + 0x3d);
      *(int *)(param_1 + 0x6c) = iVar1;
      if (iVar1 == 0) {
        *(undefined1 *)(param_1 + 0x37) = 0;
        FUN_004cca60(param_1 + 0x3d);
        return 0;
      }
      break;
    case 2:
      *(int *)(param_1 + 0x6c) = param_1 + 0x60;
      iVar1 = FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),param_1 + 0x60,param_1 + 0x3d,0
                          );
      if (iVar1 != 0) {
        return *(int *)(param_1 + 0x6c);
      }
      *(undefined4 *)(param_1 + 0x6c) = 0;
      *(undefined1 *)(param_1 + 0x37) = 0;
      iVar1 = FUN_004cca60(param_1 + 0x3d);
      return iVar1;
    case 3:
      iVar1 = FUN_0055a020(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),0xffffffff,param_1 + 0x3d);
      *(int *)(param_1 + 0x6c) = iVar1;
      if (iVar1 == 0) {
        *(undefined1 *)(param_1 + 0x37) = 0;
        FUN_004cca60(param_1 + 0x3d);
        return 0;
      }
      break;
    default:
      *(undefined1 *)(param_1 + 0x37) = 0;
      FUN_004cca60(0);
      return 0;
    }
  }
  return iVar1;
}

