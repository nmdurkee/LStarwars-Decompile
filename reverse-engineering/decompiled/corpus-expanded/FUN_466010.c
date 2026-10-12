/* Ghidra pseudocode, not original source.
 * ev_8b33ce688355ba097f8d2f702831fda396d81ac3370e92e38da24fe76235d9ff
 * Entry: 0x466010; label: FUN_00466010
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00466010(int param_1)

{
  int iVar1;
  int unaff_ESI;
  
  *(ushort *)(unaff_ESI + 0x2a) = *(ushort *)(unaff_ESI + 0x2a) | 3;
  if (*(int *)(unaff_ESI + 0x1c) != 0) {
    FUN_005a0670(*(int *)(unaff_ESI + 0x1c));
  }
  iVar1 = *(int *)(unaff_ESI + 0x24);
  if ((((iVar1 != 0) && ((*(byte *)(param_1 + 0xc) & 2) != 0)) &&
      ((*(uint *)(iVar1 + 0x1fc) & 1) != 0)) && ((*(uint *)(iVar1 + 0x1fc) & 0x1000) != 0)) {
    FUN_004364e0(iVar1,4,0);
  }
  *(undefined4 *)(unaff_ESI + 0x24) = 0;
  return;
}

