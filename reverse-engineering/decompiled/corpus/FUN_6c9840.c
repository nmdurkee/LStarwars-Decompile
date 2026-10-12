/* Ghidra analysis pseudocode, not original source.
 * ev_e0849b30759777b1ea42e04473fa04c4a6f69ff919b3575aa742b133a483e34a
 * Entry: 0x6c9840; label: FUN_006c9840
 */

void FUN_006c9840(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  int in_ECX;
  code *pcVar3;
  undefined1 auStack_134 [8];
  undefined4 local_12c;
  int *local_128;
  undefined1 *puStack_124;
  undefined1 local_120 [48];
  undefined1 auStack_f0 [88];
  undefined1 local_98 [132];
  uint local_14;
  
  local_14 = DAT_00829570 ^ (uint)auStack_134;
  iVar1 = FUN_006c6a10(&local_12c,*(undefined4 *)(param_1 + 4),2,1);
  if (iVar1 != 0) {
    if ((*(byte *)(local_128 + 7) & 2) != 0) {
      (**(code **)(*local_128 + 4))(local_12c,DAT_02973ac4,local_98,0x80);
    }
    FUN_006c9760(local_98,local_120,0x80);
    puStack_124 = local_120;
    if ((*(byte *)(local_128 + 7) & 2) != 0) {
      (**(code **)(*local_128 + 8))(local_12c,DAT_02973ac4,puStack_124,0,0);
    }
  }
  iVar1 = FUN_006c6a10(&local_12c,*(undefined4 *)(param_1 + 4),8,1);
  if (iVar1 != 0) {
    puVar2 = (undefined1 *)(*(int *)(in_ECX + 0x20) + 0x60);
    puStack_124 = puVar2;
    if ((*(byte *)(local_128 + 7) & 8) != 0) {
      if (local_128[3] == DAT_02973abc) {
        (**(code **)(*local_128 + 4))(local_12c,DAT_02973abc,local_120,0);
        FUN_004ef660(auStack_f0,puStack_124,0x10);
        pcVar3 = *(code **)(*local_128 + 8);
        puVar2 = local_120;
        iVar1 = DAT_02973abc;
      }
      else {
        pcVar3 = *(code **)(*local_128 + 8);
        iVar1 = DAT_02973ab8;
      }
      (*pcVar3)(local_12c,iVar1,puVar2,0,0);
    }
  }
  __security_check_cookie(local_14 ^ (uint)auStack_134);
  return;
}

