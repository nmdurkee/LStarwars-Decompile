/* Ghidra analysis pseudocode, not original source.
 * ev_e0849b30759777b1ea42e04473fa04c4a6f69ff919b3575aa742b133a483e34a
 * Entry: 0x6c9af0; label: FUN_006c9af0
 */

void FUN_006c9af0(void)

{
  undefined4 uVar1;
  int iVar2;
  float local_8c;
  float local_88;
  undefined1 local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_8c;
  FUN_004f1f10(local_84,"Destroy Selected Objects");
  FUN_0061f7e0(&local_8c,&local_88);
  local_8c = local_8c * 640.0;
  local_88 = local_88 * 448.0;
  uVar1 = FUN_006e6b90(300,0x32,DAT_02973a78,FUN_006b9520,local_84);
  uVar1 = FUN_006e6b90(uVar1);
  iVar2 = FUN_00619250(uVar1);
  if (iVar2 != 0) {
    uVar1 = FUN_00627a80(1,&DAT_0081f9a0,0,0,&LAB_006c9a90,&PTR_DAT_0075f2d4);
    FUN_00618e10(iVar2,uVar1);
    uVar1 = FUN_00627a80(0,&DAT_0081f9a0,0,0,&LAB_006c9a90,&DAT_0075f2d0);
    FUN_00618e10(iVar2,uVar1);
    FUN_006242b0(iVar2,5);
    FUN_00627930(iVar2,1);
    DAT_02973a84 = iVar2;
  }
  __security_check_cookie(local_4 ^ (uint)&local_8c);
  return;
}

