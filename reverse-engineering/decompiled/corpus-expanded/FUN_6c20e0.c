/* Ghidra pseudocode, not original source.
 * ev_8705922c1b0f5911d8582e9aa5172c8d40ef9c41de03e321ff79e08d51867777
 * Entry: 0x6c20e0; label: FUN_006c20e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c20e0(undefined4 *param_1)

{
  int *piVar1;
  int *in_ECX;
  
  piVar1 = (int *)*in_ECX;
  if (piVar1 != (int *)0x0) {
    do {
      if ((int)param_1[0x1d] < piVar1[0x1d]) {
        FUN_006c1570(param_1,piVar1);
        return;
      }
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)0x0);
  }
  *param_1 = 0;
  param_1[1] = in_ECX[1];
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    *(undefined4 *)in_ECX[1] = param_1;
  }
  in_ECX[1] = (int)param_1;
  if (*in_ECX == 0) {
    *in_ECX = (int)param_1;
  }
  in_ECX[2] = in_ECX[2] + 1;
  return;
}

