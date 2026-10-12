/* Ghidra pseudocode, not original source.
 * ev_4470474dfe9095336407712c08b1b1234dd43f54b8096ef09bb626cb5952ee3b
 * Entry: 0x6ba250; label: FUN_006ba250
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006ba250(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  if ((*(int **)(in_ECX + 8))[3] == DAT_02973ac4) {
    (**(code **)(**(int **)(in_ECX + 8) + 4))
              (*(undefined4 *)(in_ECX + 0xc),DAT_02973ac4,param_1,param_2);
  }
  return;
}

