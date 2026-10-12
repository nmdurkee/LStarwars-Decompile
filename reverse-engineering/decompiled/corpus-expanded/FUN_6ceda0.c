/* Ghidra pseudocode, not original source.
 * ev_b393d28c9e9a0ec683edd3b274f1828e861e17aa87a3660c9a4e9e0f17cff856
 * Entry: 0x6ceda0; label: FUN_006ceda0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006ceda0(void)

{
  undefined4 *puVar1;
  
  for (puVar1 = DAT_0081fa94; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
    if (puVar1[2] == DAT_0081fdf4) {
      if (_DAT_0081fa00 <= *(float *)(puVar1[3] + 0x48)) {
        FUN_006c7730();
      }
      else {
        FUN_006c7660();
      }
    }
  }
  return;
}

