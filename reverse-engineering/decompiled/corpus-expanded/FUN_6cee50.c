/* Ghidra pseudocode, not original source.
 * ev_b393d28c9e9a0ec683edd3b274f1828e861e17aa87a3660c9a4e9e0f17cff856
 * Entry: 0x6cee50; label: FUN_006cee50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006cee50(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *extraout_ECX;
  
  for (puVar3 = DAT_0081fa94; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {
    if (puVar3[2] == DAT_0081fdf4) {
      iVar1 = puVar3[3];
      iVar2 = *(int *)(iVar1 + 0x2c);
      while (iVar2 != 0) {
        FUN_006ce2b0();
        iVar2 = *extraout_ECX;
      }
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

