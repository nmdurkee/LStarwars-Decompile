/* Ghidra analysis pseudocode, not original source.
 * ev_51d776bbf7e198208a4486308eec4a97f7acd5ccc3951e1c43c2ae0a52a9ca8f
 * Entry: 0x6c1ca0; label: FUN_006c1ca0
 */

void FUN_006c1ca0(int param_1)

{
  undefined4 uVar1;
  float10 fVar2;
  float local_90;
  float local_8c;
  undefined1 local_88 [4];
  undefined1 local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_90;
  *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 0x20;
  uVar1 = *(undefined4 *)(DAT_02973a48 + 0x40);
  fVar2 = (float10)FUN_004f28e0();
  local_90 = (float)fVar2;
  FUN_0061f840(local_88,&local_8c);
  local_90 = local_90 - local_8c * 100.0;
  fVar2 = (float10)FUN_00619190(uVar1);
  local_8c = (float)fVar2;
  local_90 = local_90 - local_8c;
  FUN_004f2740(local_84,&DAT_0076bd70,(double)local_90);
  FUN_0061e530(param_1,local_84);
  __security_check_cookie(local_4 ^ (uint)&local_90);
  return;
}

