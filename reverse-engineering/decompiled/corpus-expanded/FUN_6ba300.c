/* Ghidra pseudocode, not original source.
 * ev_4470474dfe9095336407712c08b1b1234dd43f54b8096ef09bb626cb5952ee3b
 * Entry: 0x6ba300; label: FUN_006ba300
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006ba300(void)

{
  int in_ECX;
  undefined1 local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_84;
  if ((*(int **)(in_ECX + 8))[3] == DAT_02973ac4) {
    (**(code **)(**(int **)(in_ECX + 8) + 4))
              (*(undefined4 *)(in_ECX + 0xc),DAT_02973ac4,local_84,0x80);
  }
  FUN_0061e530(*(undefined4 *)(in_ECX + 4),local_84);
  __security_check_cookie(local_4 ^ (uint)local_84);
  return;
}

