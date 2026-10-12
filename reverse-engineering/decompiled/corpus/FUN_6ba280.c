/* Ghidra analysis pseudocode, not original source.
 * ev_7ed3362792c3ecc1c7f2b3fdd5b033605c88aa142786b47e04128bf45777c493
 * Entry: 0x6ba280; label: FUN_006ba280
 */

void FUN_006ba280(undefined4 param_1)

{
  int in_ECX;
  undefined1 local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_84;
  if (*(int *)(*(int *)(in_ECX + 8) + 0xc) == DAT_02973ac4) {
    FUN_004f1f40(local_84,param_1,*(undefined4 *)(*(int *)(in_ECX + 8) + 0x18));
    (**(code **)(**(int **)(in_ECX + 8) + 8))
              (*(undefined4 *)(in_ECX + 0xc),DAT_02973ac4,local_84,0,0);
  }
  __security_check_cookie(local_4 ^ (uint)local_84);
  return;
}

