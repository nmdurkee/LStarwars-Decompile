/* Ghidra pseudocode, not original source.
 * ev_4470474dfe9095336407712c08b1b1234dd43f54b8096ef09bb626cb5952ee3b
 * Entry: 0x6b9fe0; label: FUN_006b9fe0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

char * FUN_006b9fe0(int param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  piVar2 = *(int **)(in_ECX + 0x10);
  iVar1 = *piVar2;
  while( true ) {
    if (iVar1 == 0) {
      return "Unknown";
    }
    if (piVar2[1] == param_1) break;
    piVar2 = piVar2 + 2;
    iVar1 = *piVar2;
  }
  return (char *)*piVar2;
}

