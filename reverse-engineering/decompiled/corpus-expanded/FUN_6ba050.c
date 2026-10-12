/* Ghidra pseudocode, not original source.
 * ev_4470474dfe9095336407712c08b1b1234dd43f54b8096ef09bb626cb5952ee3b
 * Entry: 0x6ba050; label: FUN_006ba050
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006ba050(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  int iVar3;
  undefined1 local_4 [4];
  
  iVar3 = DAT_02973ab0;
  (**(code **)(**(int **)(in_ECX + 8) + 4))(*(undefined4 *)(in_ECX + 0xc),DAT_02973ab0,local_4,0);
  piVar2 = *(int **)(in_ECX + 0x10);
  iVar1 = *piVar2;
  while( true ) {
    if (iVar1 == 0) {
      FUN_0061e530(*(undefined4 *)(in_ECX + 4),"Unknown");
      return;
    }
    if (piVar2[1] == iVar3) break;
    piVar2 = piVar2 + 2;
    iVar1 = *piVar2;
  }
  FUN_0061e530(*(undefined4 *)(in_ECX + 4),*piVar2);
  return;
}

