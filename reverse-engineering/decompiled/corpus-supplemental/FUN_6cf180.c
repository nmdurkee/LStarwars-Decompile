/* Ghidra pseudocode, not original source.
 * ev_659eea1dc00a859f9d32b97d98369d0a367714cfb07a93b4448bfffc51247c8f
 * Entry: 0x6cf180; label: FUN_006cf180
 * Boundary hypotheses: reports/native-supplemental-entry-inspection.json.
 */

void FUN_006cf180(int param_1)

{
  int *piVar1;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (DAT_0081fa94 != (int *)0x0) {
    piVar1 = DAT_0081fa94;
    do {
      if (piVar1[3] == *(int *)(param_1 + 0x40)) {
        return;
      }
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)0x0);
  }
  local_8 = *(undefined4 *)(param_1 + 0x40);
  local_4 = 0;
  local_c = DAT_0081fdf4;
  FUN_006c9bf0(&local_c,1);
  return;
}

