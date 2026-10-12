/* Ghidra pseudocode, not original source.
 * ev_df72e9ec6d097d98265581ff35a2e461cddfe69d3931fceba3802c9eedcc8d52
 * Entry: 0x63eee0; label: FUN_0063eee0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0063eee0(void)

{
  int iVar1;
  int *in_ECX;
  int iStack_4;
  
  if (in_ECX[2] != 0) {
    DAT_0291389c = in_ECX[2];
    iVar1 = (**(code **)(*in_ECX + 0xc))();
    if (0 < iVar1) {
      iVar1 = in_ECX[2];
      iStack_4 = iVar1 + 0x4f84;
      if (*(int *)(iVar1 + 0x4f84) == 0) {
        FUN_00635b10(iVar1,&iStack_4,iVar1 + 0x6fac);
      }
      return in_ECX[2];
    }
  }
  return 0;
}

