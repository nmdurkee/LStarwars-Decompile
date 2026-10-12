/* Ghidra pseudocode, not original source.
 * ev_184291d84d57a0e0f71d3c8a05fa8a71135e786a990f62c870cdb26b01607f61
 * Entry: 0x60f310; label: FUN_0060f310
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060f310(void)

{
  int in_ECX;
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0x1ff;
  puVar1 = (undefined4 *)(in_ECX + 0x4b0);
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 0x12d;
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  return;
}

