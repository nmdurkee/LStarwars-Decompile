/* Ghidra pseudocode, not original source.
 * ev_ca5ea7f3b5788154105ce78c12a6b4d3dd45520787e3b427f0542ab309566885
 * Entry: 0x62a720; label: FUN_0062a720
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0062a720(int param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  
  if ((DAT_029130e4 == 0) || (iVar2 = param_1 * 0x4c + *(int *)(DAT_029130e4 + 0x20), iVar2 == 0)) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = *(int **)(iVar2 + 0x10);
  }
  if (param_2 != 0xffffffff) {
    puVar4 = &param_2;
    do {
      if (*piVar5 != 0) {
        puVar3 = (uint *)(piVar5 + 1);
        do {
          if (*(byte *)((int)puVar3 + 6) == param_2) {
            *puVar3 = *puVar3 & 0xffff7fff;
          }
          puVar1 = puVar3 + 0x12;
          puVar3 = puVar3 + 0x13;
        } while (*puVar1 != 0);
      }
      param_2 = puVar4[1];
      puVar4 = puVar4 + 1;
    } while (param_2 != 0xffffffff);
  }
  return;
}

