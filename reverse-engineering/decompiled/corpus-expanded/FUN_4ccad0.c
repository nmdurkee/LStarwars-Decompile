/* Ghidra pseudocode, not original source.
 * ev_8be83d5a314ed06484cc1a00e0611cd4a1346ac66c548b102291ab30b68096a0
 * Entry: 0x4ccad0; label: FUN_004ccad0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

