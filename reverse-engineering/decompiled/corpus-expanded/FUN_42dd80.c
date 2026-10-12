/* Ghidra pseudocode, not original source.
 * ev_e7751f4f01b1073429001044a4e8501ad85e4023b91c3e954e91fa81cbba79ed
 * Entry: 0x42dd80; label: FUN_0042dd80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0042dd80(void)

{
  undefined4 uVar1;
  
  if (DAT_0087b0f8 == *(int *)(PTR_DAT_00802c54 + 0x128)) {
    uVar1 = FUN_00412aa0();
    return uVar1;
  }
  return 0;
}

