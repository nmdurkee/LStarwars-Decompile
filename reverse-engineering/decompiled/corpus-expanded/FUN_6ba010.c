/* Ghidra pseudocode, not original source.
 * ev_4470474dfe9095336407712c08b1b1234dd43f54b8096ef09bb626cb5952ee3b
 * Entry: 0x6ba010; label: FUN_006ba010
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006ba010(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  
  piVar2 = *(int **)(in_ECX + 0x10);
  iVar1 = *piVar2;
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = FUN_004f8b10(iVar1,param_1);
    if (iVar1 != 0) break;
    iVar1 = piVar2[2];
    piVar2 = piVar2 + 2;
  }
  return piVar2[1];
}

