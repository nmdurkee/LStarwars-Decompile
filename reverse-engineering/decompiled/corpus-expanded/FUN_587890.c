/* Ghidra pseudocode, not original source.
 * ev_aa81935a86a90d95efe1cd13896fafaf1f7525855a34f109f6da8479aa997be3
 * Entry: 0x587890; label: FUN_00587890
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00587890(void)

{
  uint in_EAX;
  int iVar1;
  int unaff_EDI;
  
  *(uint *)(DAT_00954400 + 4) = *(uint *)(DAT_00954400 + 4) | in_EAX;
  iVar1 = FUN_004f7fb0();
  if (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(unaff_EDI + 0x510),&DAT_00758e24);
    if (iVar1 == 0) {
      *(uint *)(DAT_00954400 + 4) = *(uint *)(DAT_00954400 + 4) & ~in_EAX;
    }
  }
  return;
}

