/* Ghidra analysis pseudocode, not original source.
 * ev_0c8ba0b3b7b14392dbbecf96693a80f9f750c2c118e50ed36c877e83d8a87913
 * Entry: 0x5ea800; label: FUN_005ea800
 */

void FUN_005ea800(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int *param_5)

{
  uint *puVar1;
  short *psVar2;
  int iVar3;
  undefined4 local_20c;
  undefined4 local_208;
  undefined4 local_1f8;
  undefined4 local_1e8;
  uint local_d0;
  uint local_54;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_20c;
  iVar3 = FUN_005e4b20(0);
  *(int *)(param_1 + 0x40) = iVar3;
  *(undefined4 *)(iVar3 + 0x54) = 0x3f800000;
  *(undefined4 *)(*(int *)(param_1 + 0x40) + 0x58) = 0x3f800000;
  *(undefined4 *)(*(int *)(param_1 + 0x40) + 0x5c) = 0x3f800000;
  *(uint *)(*(int *)(param_1 + 0x40) + 0x40) =
       *(uint *)(*(int *)(param_1 + 0x40) + 0x40) & 0xffffefff | 0x2000;
  puVar1 = (uint *)(*(int *)(param_1 + 0x40) + 0x40);
  *puVar1 = *puVar1 | 0xc000;
  *(undefined4 *)(*(int *)(param_1 + 0x40) + 0x70) = 0x3f800000;
  *(uint *)(*(int *)(param_1 + 0x40) + 0x40) =
       *(uint *)(*(int *)(param_1 + 0x40) + 0x40) & 0xfffffff1 | 1;
  puVar1 = (uint *)(*(int *)(param_1 + 0x40) + 0x40);
  *puVar1 = *puVar1 | 0x40000;
  *(short *)(*(int *)(param_1 + 0x40) + 0x74) = (short)param_2;
  *(uint *)(*(int *)(param_1 + 0x40) + 0x40) =
       *(uint *)(*(int *)(param_1 + 0x40) + 0x40) & 0xfffffdff | 0x100;
  *(uint *)(*(int *)(param_1 + 0x40) + 0x40) =
       *(uint *)(*(int *)(param_1 + 0x40) + 0x40) & 0xfffff7ff | 0x400;
  _memset(&local_20c,0,0x208);
  local_1e8 = 0x3f800000;
  local_54 = local_54 | 0x1000;
  local_20c = 0x1000;
  local_d0 = local_d0 & 0xffffcfff | 0x40901;
  local_208 = param_2;
  local_1f8 = 0xffffffff;
  FUN_00601230(*(undefined4 *)(param_1 + 0x40),&local_20c);
  iVar3 = *(int *)(param_1 + 0x40);
  FUN_00601030(iVar3);
  psVar2 = (short *)(iVar3 + 0x2c0);
  *psVar2 = *psVar2 + 1;
  *(uint *)(param_1 + 0x48) = *param_5 + 0xfU & 0xfffffff0;
  *param_5 = (*param_5 + 0xfU & 0xfffffff0) + 0x58;
  iVar3 = *(int *)(param_1 + 0x48);
  *(int *)(param_1 + 0x2c) = iVar3 + 0x50;
  *(int *)(param_1 + 0x44) = iVar3;
  *(int *)(param_1 + 0x30) = iVar3 + 0x54;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  __security_check_cookie(local_4 ^ (uint)&local_20c);
  return;
}

