/* Ghidra analysis pseudocode, not original source.
 * ev_ca54e982c9f1bc50e375bb5e2806226defe8bc9769d9e20e94a8e2507c387560
 * Entry: 0x466840; label: FUN_00466840
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

