/* Ghidra pseudocode, not original source.
 * ev_6293e9c45219377b80e3d0963b70152e043cc5400ac7177165af43f16814c89d
 * Entry: 0x442530; label: FUN_00442530
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00442530(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_c [12];
  
  FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),local_c,param_2,1);
  iVar1 = FUN_005cfac0(local_c);
  if (iVar1 != 0) {
    uVar2 = FUN_005d0420(local_c);
    return uVar2;
  }
  return 0;
}

