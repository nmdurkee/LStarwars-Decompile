/* Ghidra pseudocode, not original source.
 * ev_51f4537ed7c57c9a0fa7f304a7a0f3427cc608dfecd65a4b8280241ed2e1f797
 * Entry: 0x5acde0; label: FUN_005acde0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005acde0(void)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  float10 fVar4;
  
  iVar2 = FUN_0055f450();
  piVar1 = *(int **)(iVar2 + 0x46b8);
  if (((*(int *)(iVar2 + 300) == 0) || (*(int *)(iVar2 + 300) != DAT_00951364)) &&
     (DAT_00951288 == 0)) {
    if (piVar1 != (int *)0x0) {
      iVar2 = 0;
      if ((short)piVar1[2] != 0) {
        puVar3 = (uint *)(*piVar1 + 0x108);
        do {
          if ((((*(ushort *)((int)puVar3 + 0x32) & 2) != 0) &&
              ((*(ushort *)((int)puVar3 + 0x32) & 4) != 0)) &&
             (((*puVar3 & 0x4000) != 0 && (((*puVar3 & 0x10) == 0 && (puVar3[-9] != 0)))))) {
            fVar4 = (float10)FUN_005b3c50(PTR_DAT_008021b4 + 0x11c,puVar3 + -0x39,0);
            if (fVar4 < (float10)36.0) {
              return 1;
            }
          }
          iVar2 = iVar2 + 1;
          puVar3 = puVar3 + 0x4f;
        } while (iVar2 < (int)(uint)*(ushort *)(piVar1 + 2));
      }
    }
    return 0;
  }
  return 0;
}

