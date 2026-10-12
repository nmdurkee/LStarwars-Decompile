/* Ghidra pseudocode, not original source.
 * ev_8b33ce688355ba097f8d2f702831fda396d81ac3370e92e38da24fe76235d9ff
 * Entry: 0x466840; label: FUN_00466840
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00466840(undefined4 param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = *(int **)(in_EAX + 0x46ac);
  if (piVar1 != (int *)0x0) {
    iVar5 = *piVar1;
    iVar4 = 0;
    if (*(short *)((int)piVar1 + 0xe) != 0) {
      do {
        if (*(int *)(iVar5 + 0x28) != 0) {
          for (puVar2 = *(undefined4 **)(*(int *)(iVar5 + 0x28) + 0x18); puVar2 != (undefined4 *)0x0
              ; puVar2 = (undefined4 *)*puVar2) {
            iVar3 = FUN_005cfa50(puVar2 + 1);
            if ((iVar3 != 0) && (iVar3 = FUN_004f8b10(param_1,iVar3), iVar3 == 0)) {
              return iVar5;
            }
          }
        }
        iVar4 = iVar4 + 1;
        iVar5 = iVar5 + 0xa4;
      } while (iVar4 < (int)(uint)*(ushort *)((int)piVar1 + 0xe));
    }
  }
  return 0;
}

