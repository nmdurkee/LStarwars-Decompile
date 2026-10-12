/* Ghidra pseudocode, not original source.
 * ev_6e12a0fbf5898bf57966e4401ca56b9d94fa9ac9209c3805722876eb5ad577ae
 * Entry: 0x4ff130; label: FUN_004ff130
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004ff130(int param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 local_208;
  undefined1 local_204 [512];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_208;
  iVar3 = param_1 + 0x34;
  local_208 = param_2;
  uVar1 = FUN_004f1ff0(iVar3);
  iVar2 = FUN_004f20a0(param_3,&DAT_0075c044);
  if (iVar2 == 0) {
    iVar2 = FUN_004f8b80(param_3,iVar3,uVar1);
    if (iVar2 == 0) {
      iVar3 = FUN_004f1ff0(iVar3);
      if ((*(char *)(iVar3 + param_3) == '\\') || (*(char *)(iVar3 + param_3) == '/'))
      goto LAB_004ff17e;
      FUN_004f1f10(local_204,param_1 + 0x4c);
      FUN_004f1e80(local_204,param_1 + 0xac);
      param_3 = iVar3 + param_3;
    }
    else {
      FUN_004f1f10(local_204,param_1 + 0x4c);
      FUN_004f1e80(local_204,param_1 + 0xac);
    }
    FUN_004f1e80(local_204,param_3);
  }
  else {
LAB_004ff17e:
    FUN_004f1f10(local_204,param_3);
  }
  iVar3 = FUN_004f1ff0(param_1 + 0x4c);
  FUN_004efdf0(param_1,local_204 + iVar3);
  FUN_004efec0(param_1,local_204);
  iVar3 = FUN_004f1ff0(local_204);
  if (iVar3 < param_4) {
    FUN_004f1f10(local_208,local_204);
    __security_check_cookie(local_4 ^ (uint)&local_208);
    return;
  }
  __security_check_cookie(local_4 ^ (uint)&local_208);
  return;
}

