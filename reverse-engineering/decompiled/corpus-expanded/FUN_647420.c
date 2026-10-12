/* Ghidra pseudocode, not original source.
 * ev_4cb705c119a92d6224ed1b3e942cece0f3f9eff485159b2837ae2ccadb058a2e
 * Entry: 0x647420; label: FUN_00647420
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00647420(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (DAT_02920970 != 0) {
    iVar1 = *(int *)(param_2 + 0xc);
    if (iVar1 == 0) {
      *(undefined4 *)(DAT_02920970 + 0xd4) = *(undefined4 *)(param_2 + 0x54);
      return;
    }
    if (iVar1 == 1) {
      *(undefined4 *)(DAT_02920970 + 0xd8) = *(undefined4 *)(param_2 + 0x54);
      return;
    }
    if (iVar1 == 2) {
      *(undefined4 *)(DAT_02920970 + 0xdc) = *(undefined4 *)(param_2 + 0x54);
    }
  }
  return;
}

