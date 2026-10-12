/* Ghidra analysis pseudocode, not original source.
 * ev_656543c8328aa29e7546f4f9ed4e60ad4c1e465caa45a29e90694e112f58dfef
 * Entry: 0x46ddf0; label: FUN_0046ddf0
 */

int FUN_0046ddf0(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((param_1 != 0) && (piVar1 = *(int **)(param_1 + 0x5070), piVar1 != (int *)0x0)) {
    iVar3 = 0;
    iVar4 = piVar1[1];
    if (0 < *piVar1) {
      do {
        iVar2 = FUN_004f8b10(iVar4 + 0x40,param_2);
        if (iVar2 == 0) {
          return iVar4;
        }
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 0x90;
      } while (iVar3 < **(int **)(param_1 + 0x5070));
    }
    return 0;
  }
  return 0;
}

