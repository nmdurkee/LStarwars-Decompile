/* Ghidra pseudocode, not original source.
 * ev_647b85ee0a7e8e41d889ce710347a98583a3d140d8a364c007ecae69f59044b8
 * Entry: 0x6c6420; label: FUN_006c6420
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c6420(uint param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  int *unaff_ESI;
  int *piVar3;
  int iVar4;
  undefined4 unaff_retaddr;
  
  piVar3 = (int *)*in_ECX;
  if (piVar3 != (int *)0x0) {
    do {
      (**(code **)(**(int **)(piVar3[2] + 0x14) + 0x24))(piVar3[3]);
      if ((param_1 & 2) == 0) {
        iVar1 = piVar3[2];
        iVar2 = piVar3[3];
        iVar4 = 0;
        in_ECX = unaff_ESI;
        if (0 < DAT_02973bbc) {
          do {
            (**(code **)(**(int **)(DAT_02973b98 + iVar4 * 4) + 0xc))(iVar2,iVar1,unaff_retaddr);
            iVar4 = iVar4 + 1;
          } while (iVar4 < DAT_02973bbc);
        }
      }
      if (*piVar3 == 0) {
        in_ECX[1] = piVar3[1];
      }
      else {
        *(int *)(*piVar3 + 4) = piVar3[1];
      }
      if ((int *)piVar3[1] == (int *)0x0) {
        *in_ECX = *piVar3;
      }
      else {
        *(int *)piVar3[1] = *piVar3;
      }
      *piVar3 = 0;
      piVar3[1] = 0;
      in_ECX[2] = in_ECX[2] + -1;
      FUN_006e85b0(piVar3);
      piVar3 = (int *)*in_ECX;
    } while (piVar3 != (int *)0x0);
  }
  return;
}

