/* Ghidra pseudocode, not original source.
 * ev_70aa57168a76f6a14ecedad416987a4c285e0af1098fb5505be14bfd88103624
 * Entry: 0x579320; label: FUN_00579320
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00579320(void)

{
  uint in_EAX;
  int iVar1;
  int unaff_EDI;
  
  *(uint *)(DAT_00951b74 + 100) = *(uint *)(DAT_00951b74 + 100) | in_EAX;
  iVar1 = FUN_004f7fb0();
  if (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(unaff_EDI + 0x510),&DAT_00758e24);
    if (iVar1 == 0) {
      *(uint *)(DAT_00951b74 + 100) = *(uint *)(DAT_00951b74 + 100) & ~in_EAX;
    }
  }
  return;
}

