/* Ghidra pseudocode, not original source.
 * ev_ca5ea7f3b5788154105ce78c12a6b4d3dd45520787e3b427f0542ab309566885
 * Entry: 0x62a6d0; label: FUN_0062a6d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0062a6d0(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = DAT_029130e4;
  puVar1 = (undefined1 *)register0x00000010;
  do {
    if (((iVar4 != 0) && (iVar2 = param_1 * 0x4c + *(int *)(iVar4 + 0x20), iVar2 != 0)) &&
       (piVar3 = *(int **)(iVar2 + 0x10), piVar3 != (int *)0x0)) {
      iVar2 = *piVar3;
      while (iVar2 != 0) {
        piVar3[1] = piVar3[1] | 0x8000;
        piVar3 = piVar3 + 0x13;
        iVar4 = DAT_029130e4;
        iVar2 = *piVar3;
      }
    }
    param_1 = *(int *)(puVar1 + 8);
    puVar1 = puVar1 + 4;
  } while (param_1 != -1);
  return;
}

