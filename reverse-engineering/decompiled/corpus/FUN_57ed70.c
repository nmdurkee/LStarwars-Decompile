/* Ghidra analysis pseudocode, not original source.
 * ev_726a28db9a436487e0129f186879c1991782c0ddc180f98bd984abea004253e2
 * Entry: 0x57ed70; label: FUN_0057ed70
 */

void FUN_0057ed70(void)

{
  int iVar1;
  
  iVar1 = 0;
  if (DAT_00951c7c < 1) {
    DAT_00951c7c = 0;
    return;
  }
  do {
    FUN_0057eb00((&DAT_00951c0c)[iVar1]);
    iVar1 = iVar1 + 1;
  } while (iVar1 < DAT_00951c7c);
  DAT_00951c7c = 0;
  return;
}

