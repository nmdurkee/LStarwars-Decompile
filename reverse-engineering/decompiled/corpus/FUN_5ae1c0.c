/* Ghidra analysis pseudocode, not original source.
 * ev_82de32114f0a758998fb1b139028178946084d97602e6dd81f3d90db1eb3e6aa
 * Entry: 0x5ae1c0; label: FUN_005ae1c0
 */

void FUN_005ae1c0(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 local_30 [12];
  undefined1 local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_30;
  iVar2 = FUN_0055f460();
  if ((iVar2 != 0) && (param_2 != 0)) {
    FUN_005cf5b0(*(undefined4 *)(iVar2 + 0x13c),local_30,param_2,0);
    FUN_004f1f10(local_24,&DAT_00805eb4);
    iVar3 = FUN_004f1ff0(&DAT_00805eb4);
    FUN_004f1ec0(local_24,param_2,0x20 - iVar3);
    iVar3 = FUN_005cfac0(local_30);
    if ((iVar3 != 0) &&
       ((iVar3 = FUN_0055a020(*(undefined4 *)(iVar2 + 0x2ac8),DAT_00805ebc,local_24), iVar3 == 0 &&
        (piVar1 = *(int **)(iVar2 + 0x5108),
        piVar1[1] < (int)(uint)*(byte *)(*(int *)(iVar2 + 0x128) + 0xf5))))) {
      iVar3 = *piVar1 + piVar1[1] * 0x28;
      FUN_005a0810(*(undefined4 *)(iVar3 + 0x20),local_30,0x3f800000,0x4e6e6b28,0);
      piVar1 = (int *)(*(int *)(iVar2 + 0x5108) + 4);
      *piVar1 = *piVar1 + 1;
      FUN_004f1f10(iVar3,&DAT_00805eb4);
      iVar4 = FUN_004f1ff0(&DAT_00805eb4);
      FUN_004f1ec0(iVar3,param_2,0x20 - iVar4);
      FUN_00559ee0(*(undefined4 *)(iVar2 + 0x2ac8),DAT_00805ebc,0,iVar3);
      __security_check_cookie(local_4 ^ (uint)local_30);
      return;
    }
  }
  __security_check_cookie(local_4 ^ (uint)local_30);
  return;
}

