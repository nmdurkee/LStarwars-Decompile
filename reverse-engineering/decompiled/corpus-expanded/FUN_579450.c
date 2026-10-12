/* Ghidra pseudocode, not original source.
 * ev_70aa57168a76f6a14ecedad416987a4c285e0af1098fb5505be14bfd88103624
 * Entry: 0x579450; label: FUN_00579450
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00579450(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_007622ac);
    if (iVar1 == 0) {
      *(uint *)(DAT_00951b74 + 100) = *(uint *)(DAT_00951b74 + 100) & 0xff7fffff;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00758e24);
    if (iVar1 == 0) {
      *(uint *)(DAT_00951b74 + 100) = *(uint *)(DAT_00951b74 + 100) | 0x800000;
    }
  }
  return;
}

