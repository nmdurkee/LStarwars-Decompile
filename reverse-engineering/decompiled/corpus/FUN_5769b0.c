/* Ghidra analysis pseudocode, not original source.
 * ev_d93daca17d105ef5f57eb8b76e4a8c3d960b6599f63d34fdaa382c813fb01a39
 * Entry: 0x5769b0; label: FUN_005769b0
 */

void FUN_005769b0(int param_1)

{
  if ((param_1 != 0) && (*(char *)(param_1 + 0x14) == '\0')) {
    *(undefined1 *)(param_1 + 0x14) = 1;
    FUN_005766e0();
    return;
  }
  return;
}

