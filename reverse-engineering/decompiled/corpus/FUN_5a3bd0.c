/* Ghidra analysis pseudocode, not original source.
 * ev_0b4f3bc8b4a39fc427a7fcc8ed3e1304ee3926d0e45102a57071cb05acfa7baa
 * Entry: 0x5a3bd0; label: FUN_005a3bd0
 */

void FUN_005a3bd0(float param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  float fVar4;
  int *piVar5;
  
  piVar1 = DAT_0095da40;
  if (param_1 != 0.0) {
    while (piVar5 = piVar1, piVar5 != (int *)0x0) {
      piVar1 = (int *)*piVar5;
      if (((piVar5[4] == 0) && (puVar2 = (undefined4 *)piVar5[5], puVar2 != (undefined4 *)0x0)) &&
         ((int *)*puVar2 == piVar5)) {
        *puVar2 = 0;
        piVar5[5] = 0;
      }
      piVar3 = (int *)piVar5[2];
      piVar5[4] = 0;
      for (; piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
        fVar4 = (float)piVar3[0x39] - param_1;
        piVar3[0x39] = (int)fVar4;
        if ((fVar4 < 0.0 != (fVar4 == 0.0)) && (*piVar3 == 0)) {
          if ((int *)piVar3[1] == (int *)0x0) {
            piVar5[2] = *piVar3;
          }
          else {
            *(int *)piVar3[1] = *piVar3;
          }
          if (*piVar3 != 0) {
            *(int *)(*piVar3 + 4) = piVar3[1];
          }
          *piVar3 = (int)DAT_0095da38;
          DAT_0095da38 = piVar3;
          break;
        }
      }
      if (piVar5[2] == 0) {
        if ((int *)piVar5[1] == (int *)0x0) {
          DAT_0095da40 = (int *)*piVar5;
        }
        else {
          *(int *)piVar5[1] = *piVar5;
        }
        if (*piVar5 != 0) {
          *(int *)(*piVar5 + 4) = piVar5[1];
        }
        *piVar5 = (int)DAT_0095da3c;
        DAT_0095da3c = piVar5;
      }
    }
  }
  return;
}

