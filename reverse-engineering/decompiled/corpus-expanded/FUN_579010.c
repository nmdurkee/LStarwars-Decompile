/* Ghidra pseudocode, not original source.
 * ev_70aa57168a76f6a14ecedad416987a4c285e0af1098fb5505be14bfd88103624
 * Entry: 0x579010; label: FUN_00579010
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00579010(undefined4 param_1)

{
  undefined1 uVar1;
  
  uVar1 = FUN_004f9e70(param_1);
  *(undefined1 *)(DAT_00951b74 + 0x91) = uVar1;
  *(undefined1 *)(DAT_00951b74 + 0x90) = *(undefined1 *)(DAT_00951b74 + 0x91);
  return;
}

