/* Ghidra analysis pseudocode, not original source.
 * ev_95f339e64e03912db0b4337524e50c5f1fa1cc6c36f27950d42195022949d97c
 * Entry: 0x5934d0; label: FUN_005934d0
 */

void FUN_005934d0(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  
  if (param_1 != 0) {
    piVar3 = (int *)(param_2 + 0x5144);
    piVar2 = (int *)(param_1 + 0x48);
    param_1 = 9;
    do {
      piVar4 = (int *)piVar3[-9];
      if (piVar4 != (int *)0x0) {
        iVar5 = 0;
        if (0 < *piVar2) {
          do {
            iVar1 = *piVar4;
            if (iVar1 == 0) {
              if (piVar4[5] != 0) {
                FUN_005e5630(piVar4[5]);
              }
            }
            else {
              if (iVar1 != *piVar3) {
                FUN_005ef880(iVar1);
              }
              *piVar4 = 0;
            }
            iVar5 = iVar5 + 1;
            piVar4 = piVar4 + 8;
          } while (iVar5 < *piVar2);
        }
        if (*piVar3 != 0) {
          FUN_005ef880(*piVar3);
          *piVar3 = 0;
        }
      }
      piVar2 = piVar2 + 1;
      piVar3 = piVar3 + 1;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}

