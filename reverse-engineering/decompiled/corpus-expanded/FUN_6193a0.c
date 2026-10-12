/* Ghidra pseudocode, not original source.
 * ev_fbd0714d29abf1967b7a59c1140afabe8eda1c53d580ba604e59c833adf58051
 * Entry: 0x6193a0; label: FUN_006193a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006193a0(int *param_1,byte param_2)

{
  int *piVar1;
  
  do {
    piVar1 = (int *)*param_1;
    if (piVar1 != (int *)0x0) {
      do {
        *(byte *)((int)piVar1 + 0x11) =
             *(byte *)((int)piVar1 + 0x11) & 0xfd | (param_2 & 1) * '\x02';
        piVar1 = (int *)*piVar1;
      } while (piVar1 != (int *)0x0);
    }
    param_1 = (int *)param_1[0xf];
  } while (param_1 != (int *)0x0);
  return;
}

