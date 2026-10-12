/* Ghidra pseudocode, not original source.
 * ev_b393d28c9e9a0ec683edd3b274f1828e861e17aa87a3660c9a4e9e0f17cff856
 * Entry: 0x6cedf0; label: FUN_006cedf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006cedf0(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  for (puVar2 = DAT_0081fa94; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
    if (puVar2[2] == DAT_0081fdf4) {
      iVar1 = puVar2[3];
      FUN_006c7580();
      if (DAT_0081fe04 != 0) {
        if (_DAT_0081fa00 <= *(float *)(iVar1 + 0x48)) {
          FUN_006c7730();
        }
        else {
          FUN_006c7660();
        }
      }
    }
  }
  return;
}

