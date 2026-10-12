/* Ghidra pseudocode, not original source.
 * ev_608779b64e90f57b93ecbf13df65bed39f2d483d8cb24d2405739ebf49354e95
 * Entry: 0x57cdd0; label: FUN_0057cdd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_0057cdd0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar2 = FUN_0055f450();
  puVar1 = *(undefined4 **)(iVar2 + 0x2ab0);
  if ((puVar1 != (undefined4 *)0x0) && (param_1 != 0)) {
    iVar2 = -1;
    iVar4 = 0;
    if (0 < (int)puVar1[1]) {
      piVar3 = (int *)*puVar1;
      do {
        if (*piVar3 == param_1) {
          iVar2 = iVar4;
        }
        iVar4 = iVar4 + 1;
        piVar3 = piVar3 + 1;
      } while (iVar4 < (int)puVar1[1]);
      if (iVar2 != -1) {
        iVar4 = FUN_0055f450();
        return (*(uint *)(*(int *)(iVar4 + 0x130) + 0x2820) & 1 << ((byte)iVar2 & 0x1f)) != 0;
      }
    }
  }
  return false;
}

