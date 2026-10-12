/* Ghidra analysis pseudocode, not original source.
 * ev_ecc8ce98e599e83956a160512bc3e9e95348504114ce7e145bc7e138d08a4c20
 * Entry: 0x5a0f10; label: FUN_005a0f10
 */

undefined4 FUN_005a0f10(float param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 != 0.0) {
    piVar2 = *(int **)((int)param_1 + 0x18);
    iVar3 = 0;
    iVar4 = 0;
    if (piVar2 != (int *)0x0) {
      do {
        iVar1 = piVar2[4];
        if (iVar1 != 0) {
          iVar3 = iVar3 + 1;
          if ((*(uint *)(iVar1 + 0x50) & 8) == 0) {
            if ((*(uint *)(iVar1 + 0x50) & 1) != 0) {
              return 0;
            }
            if ((float)piVar2[6] <= (float)piVar2[7]) {
              param_1 = 1.0;
            }
            else {
              param_1 = -1.0;
            }
            if (param_1 * (float)piVar2[6] < param_1 * *(float *)(iVar1 + 0x4c)) {
              return 0;
            }
          }
          else {
            iVar4 = iVar4 + 1;
          }
        }
        piVar2 = (int *)*piVar2;
      } while (piVar2 != (int *)0x0);
      if ((0 < iVar3) && (iVar4 == iVar3)) {
        return 0;
      }
    }
  }
  return 1;
}

