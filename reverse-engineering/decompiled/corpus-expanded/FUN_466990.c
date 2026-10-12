/* Ghidra pseudocode, not original source.
 * ev_8b33ce688355ba097f8d2f702831fda396d81ac3370e92e38da24fe76235d9ff
 * Entry: 0x466990; label: FUN_00466990
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00466990(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  
  if (((DAT_00877ad8 != 0) && (iVar2 = FUN_004f7fb0(param_1), iVar2 != 0)) &&
     (*(short *)(DAT_00877ad8 + 0x86) == -1)) {
    uVar1 = FUN_00650dc0(*(undefined4 *)(param_1 + 0x510));
    *(undefined2 *)(DAT_00877ad8 + 0x86) = uVar1;
  }
  return;
}

