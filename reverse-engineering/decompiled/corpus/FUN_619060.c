/* Ghidra analysis pseudocode, not original source.
 * ev_142c6a8c6383f125e012f2efba2eadfa5dbe8b6e60e30e9e06bfa3e419522019
 * Entry: 0x619060; label: FUN_00619060
 */

void FUN_00619060(int *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  bool bVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  
  piVar4 = param_1;
  param_1 = (int *)*param_1;
  if (param_1 != (int *)0x0) {
    do {
      bVar3 = true;
      piVar6 = param_1;
      if (*param_1 == 0) {
        return;
      }
      do {
        if (piVar6[9] == 0) break;
        iVar5 = *(int *)(*piVar6 + 0x24);
        if (iVar5 == 0) break;
        if ((piVar6[2] == 0x14) ||
           ((*(int *)(*piVar6 + 8) != 0x14 && (iVar5 = FUN_004f8b10(piVar6[9],iVar5), iVar5 < 1))))
        {
          piVar6 = (int *)*piVar6;
        }
        else {
          if (piVar6 != (int *)piVar4[1]) {
            piVar1 = (int *)*piVar6;
            puVar2 = (undefined4 *)piVar6[1];
            piVar6[1] = (int)piVar1;
            iVar5 = *piVar1;
            *piVar6 = iVar5;
            if (iVar5 == 0) {
              piVar4[1] = (int)piVar6;
            }
            else {
              *(int **)(iVar5 + 4) = piVar6;
            }
            if (puVar2 == (undefined4 *)0x0) {
              *piVar4 = (int)piVar1;
            }
            else {
              *puVar2 = piVar1;
            }
            piVar1[1] = (int)puVar2;
            *piVar1 = (int)piVar6;
            piVar4[3] = *piVar4;
            piVar4[4] = 0;
          }
          if (piVar6 == param_1) {
            param_1 = (int *)piVar6[1];
          }
          bVar3 = false;
        }
      } while (*piVar6 != 0);
    } while (!bVar3);
  }
  return;
}

