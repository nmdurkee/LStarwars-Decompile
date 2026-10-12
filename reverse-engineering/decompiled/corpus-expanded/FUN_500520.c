/* Ghidra pseudocode, not original source.
 * ev_e3284882596e4924dd8e2753f6ae25b39d285bc55fae2794478040fb50a7242b
 * Entry: 0x500520; label: FUN_00500520
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00500520(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined1 param_5
            )

{
  byte bVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  piVar2 = *(int **)(param_1 + 0x9c);
  if ((piVar2 != (int *)0x0) &&
     (bVar1 = *(byte *)(piVar2 + 3), bVar1 < *(byte *)((int)piVar2 + 0xb))) {
    puVar3 = (undefined4 *)((uint)bVar1 * 0x10 + *piVar2);
    *(byte *)(piVar2 + 3) = bVar1 + 1;
    puVar3[1] = param_3;
    *puVar3 = param_2;
    puVar3[2] = param_4;
    *(undefined1 *)(puVar3 + 3) = param_5;
    return 1;
  }
  return 0;
}

