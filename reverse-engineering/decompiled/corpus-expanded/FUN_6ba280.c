/* Ghidra pseudocode, not original source.
 * ev_4470474dfe9095336407712c08b1b1234dd43f54b8096ef09bb626cb5952ee3b
 * Entry: 0x6ba280; label: FUN_006ba280
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

