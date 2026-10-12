/* Ghidra analysis pseudocode, not original source.
 * ev_4ddc17d0b5ae2dc444590ce1384da883f11f3d0f2dd8037fed9dcc825d4bbeec
 * Entry: 0x634dd0; label: FUN_00634dd0
 */

void FUN_00634dd0(void)

{
  int in_ECX;
  
  DAT_0291389c = FUN_005958a0();
  if (DAT_0291389c == 0) {
    DAT_0291389c = *(int *)(in_ECX + 8);
  }
  *(undefined4 *)(DAT_0291389c + 0x4f84) = 0;
  return;
}

