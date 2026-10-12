/* Ghidra pseudocode, not original source.
 * ev_50944669d30d55cc8660bd39a1540d3c58ad2d352d01610283ebac90eef0b416
 * Entry: 0x4f0d60; label: FUN_004f0d60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004f0d60(int param_1,int param_2,int param_3)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined1 *puVar5;
  
  puVar3 = &DAT_0090fba8;
  while ((puVar3[0xe] != '\x04' || ((char)puVar3[0xd] != param_3))) {
    puVar3 = puVar3 + 0x10;
    if (puVar3 == (undefined1 *)0x0) {
      return 0;
    }
  }
  iVar4 = (int)(char)puVar3[0xf];
  iVar2 = 0;
  if (param_2 < iVar4) {
    return 0;
  }
  puVar5 = puVar3 + iVar4;
  if (0 < iVar4) {
    do {
      puVar1 = puVar5 + -1;
      puVar5 = puVar5 + -1;
      *(undefined1 *)(iVar2 + param_1) = *puVar1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < (char)puVar3[0xf]);
  }
  *(undefined1 *)(iVar2 + param_1) = 0;
  return 1;
}

