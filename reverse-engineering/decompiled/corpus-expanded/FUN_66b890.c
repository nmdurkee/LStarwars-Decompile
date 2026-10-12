/* Ghidra pseudocode, not original source.
 * ev_c3511c7e9be8c9ea3f86dbf498dc77cf8080442af45acd9c68d26e3bdf8b902d
 * Entry: 0x66b890; label: FUN_0066b890
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0066b890(int *param_1)

{
  if (((*param_1 == -0x400000) || (param_1[1] == -0x400000)) || (param_1[2] == -0x400000)) {
    *param_1 = 0;
    param_1[1] = 0x3f800000;
    param_1[2] = 0;
  }
  return;
}

