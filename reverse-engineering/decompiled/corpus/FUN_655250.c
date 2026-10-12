/* Ghidra analysis pseudocode, not original source.
 * ev_537f31f6d7a7ebc324951952e862ea8d16fa2be695db959927eb9326274a35d3
 * Entry: 0x655250; label: FUN_00655250
 */

void FUN_00655250(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  
  piVar6 = &DAT_0292fbfc;
  do {
    piVar2 = (int *)*piVar6;
    while (piVar5 = piVar2, piVar5 != (int *)0x0) {
      piVar2 = (int *)piVar5[4];
      if (*piVar5 == param_1) {
        iVar3 = *piVar6;
        piVar1 = piVar6;
        while (iVar3 != 0) {
          piVar4 = (int *)*piVar1;
          if (piVar4 == piVar5) {
            *piVar1 = (int)piVar2;
            break;
          }
          piVar1 = piVar4 + 4;
          iVar3 = piVar4[4];
        }
        piVar5[4] = 0;
        DAT_02947b70 = DAT_02947b70 + -1;
        *(int **)(DAT_02923198 + DAT_02947b70 * 4) = piVar5;
        *piVar5 = 0;
      }
    }
    piVar6 = piVar6 + 1;
    if (0x292fc03 < (int)piVar6) {
      return;
    }
  } while( true );
}

