/* Ghidra pseudocode, not original source.
 * ev_70aa57168a76f6a14ecedad416987a4c285e0af1098fb5505be14bfd88103624
 * Entry: 0x578fe0; label: FUN_00578fe0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00578fe0(undefined4 param_1)

{
  undefined1 uVar1;
  
  uVar1 = FUN_004f9e70(param_1);
  *(undefined1 *)(DAT_00951b74 + 0x8f) = uVar1;
  *(undefined1 *)(DAT_00951b74 + 0x8e) = *(undefined1 *)(DAT_00951b74 + 0x8f);
  return;
}

