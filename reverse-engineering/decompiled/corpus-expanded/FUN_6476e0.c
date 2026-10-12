/* Ghidra pseudocode, not original source.
 * ev_4cb705c119a92d6224ed1b3e942cece0f3f9eff485159b2837ae2ccadb058a2e
 * Entry: 0x6476e0; label: FUN_006476e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006476e0(undefined4 param_1,int param_2)

{
  if (DAT_02920970 != 0) {
    if ((*(byte *)(param_2 + 0x11) & 1) != 0) {
      *(uint *)(DAT_02920970 + 0x114) = *(uint *)(DAT_02920970 + 0x114) | *(uint *)(param_2 + 0xc);
      return;
    }
    *(uint *)(DAT_02920970 + 0x114) = *(uint *)(DAT_02920970 + 0x114) & ~*(uint *)(param_2 + 0xc);
  }
  return;
}

