/* Ghidra pseudocode, not original source.
 * ev_f4a8ff6582840101146b6beddb128c7f08992de8be10658b05520190150ad97a
 * Entry: 0x584db0; label: FUN_00584db0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00584db0(int param_1)

{
  uint in_EAX;
  int iVar1;
  int unaff_ESI;
  
  *(uint *)(unaff_ESI + 4) = *(uint *)(unaff_ESI + 4) | in_EAX;
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00758e24);
    if (iVar1 == 0) {
      *(uint *)(unaff_ESI + 4) = *(uint *)(unaff_ESI + 4) & ~in_EAX;
    }
  }
  return;
}

