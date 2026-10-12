/* Ghidra pseudocode, not original source.
 * ev_70aa57168a76f6a14ecedad416987a4c285e0af1098fb5505be14bfd88103624
 * Entry: 0x5791b0; label: FUN_005791b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005791b0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f9e70(param_1);
  if (iVar1 < 10) {
    iVar1 = 10;
  }
  else if (20000 < iVar1) {
    *(undefined2 *)(DAT_00951b74 + 0x8c) = 20000;
    return;
  }
  *(short *)(DAT_00951b74 + 0x8c) = (short)iVar1;
  return;
}

