/* Ghidra pseudocode, not original source.
 * ev_32a2dc35cb5c8cf62ae1975b64ffeaf00e4ae9610f4a026957bdc8e6e6aa33b0
 * Entry: 0x69a1e0; label: FUN_0069a1e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_0069a1e0(char *param_1)

{
  return (((int)param_1[3] << 8 | (int)param_1[2]) << 8 | (int)param_1[1]) << 8 | (int)*param_1;
}

