/* Ghidra pseudocode, not original source.
 * ev_6ea325c01e2f5d3a14c4ac5085e7df4745032b0fec5c1eb605a31240a38307be
 * Entry: 0x540000; label: FUN_00540000
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00540000(int param_1)

{
  uint *puVar1;
  int iVar2;
  
  iVar2 = FUN_004f7fb0(param_1);
  while (iVar2 != 0) {
    iVar2 = FUN_004f29a0(*(undefined4 *)(param_1 + 0x510));
    puVar1 = (uint *)(DAT_029838fc + 0xdc + ((int)(iVar2 + (iVar2 >> 0x1f & 0x1fU)) >> 5) * 4);
    *puVar1 = *puVar1 | 1 << ((byte)iVar2 & 0x1f);
    iVar2 = FUN_004f7fb0(param_1);
  }
  return;
}

