/* Ghidra pseudocode, not original source.
 * ev_0e84ad542db3be7599677a500db2c2fcd5f6f463504cd13a52c31f7d7facbfa7
 * Entry: 0x63deb0; label: FUN_0063deb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_0063deb0(float param_1)

{
  int *piVar1;
  
  piVar1 = (int *)((int)param_1 + 0xc);
  param_1 = 0.01;
  if (*(float *)(*piVar1 + 0x1c) - *(float *)(*piVar1 + 0x18) < 5.0) {
    param_1 = 0.001;
  }
  return (float10)param_1;
}

