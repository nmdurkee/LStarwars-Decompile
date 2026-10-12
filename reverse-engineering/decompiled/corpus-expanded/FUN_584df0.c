/* Ghidra pseudocode, not original source.
 * ev_f4a8ff6582840101146b6beddb128c7f08992de8be10658b05520190150ad97a
 * Entry: 0x584df0; label: FUN_00584df0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00584df0(int param_1)

{
  ushort in_AX;
  int iVar1;
  int unaff_ESI;
  
  *(ushort *)(unaff_ESI + 0x48) = *(ushort *)(unaff_ESI + 0x48) | in_AX;
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00758e24);
    if (iVar1 == 0) {
      *(ushort *)(unaff_ESI + 0x48) = *(ushort *)(unaff_ESI + 0x48) & ~in_AX;
    }
  }
  return;
}

