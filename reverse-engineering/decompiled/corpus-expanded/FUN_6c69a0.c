/* Ghidra pseudocode, not original source.
 * ev_3e1dd6b2d4f666d2001b5d4d68499aac60c4283e1c30ebf06a77c3cfaf088012
 * Entry: 0x6c69a0; label: FUN_006c69a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006c69a0(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 8);
  do {
    if (iVar1 == 0) {
      return 0;
    }
    if ((int)*(uint *)(iVar1 + 0x1c) < 0) {
      if ((param_2 != 0) && (iVar2 = FUN_006c69a0(param_1,1), iVar2 != 0)) {
        return iVar2;
      }
    }
    else if ((param_1 & *(uint *)(iVar1 + 0x1c)) != 0) {
      return iVar1;
    }
    iVar1 = *(int *)(iVar1 + 4);
  } while( true );
}

