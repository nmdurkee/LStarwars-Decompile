/* Ghidra pseudocode, not original source.
 * ev_fbd0714d29abf1967b7a59c1140afabe8eda1c53d580ba604e59c833adf58051
 * Entry: 0x6193e0; label: FUN_006193e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006193e0(undefined4 *param_1,undefined4 *param_2)

{
  byte bVar1;
  
  if (param_2[6] != 0) {
    for (param_1 = (undefined4 *)*param_1; param_1 != (undefined4 *)0x0;
        param_1 = (undefined4 *)*param_1) {
      if (param_1 == param_2) {
        if (param_1[2] == 3) {
          bVar1 = *(byte *)((int)param_1 + 0x11);
          *(byte *)((int)param_1 + 0x11) = (-bVar1 - 1 ^ bVar1) & 1 ^ bVar1;
        }
        else {
          *(byte *)((int)param_1 + 0x11) = *(byte *)((int)param_1 + 0x11) | 1;
        }
      }
      else if (param_1[6] == param_2[6]) {
        *(byte *)((int)param_1 + 0x11) = *(byte *)((int)param_1 + 0x11) & 0xfe;
      }
    }
  }
  return;
}

