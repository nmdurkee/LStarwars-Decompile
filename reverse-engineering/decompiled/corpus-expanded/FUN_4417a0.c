/* Ghidra pseudocode, not original source.
 * ev_52b1dbacad98807a86fda1d7285f00f4b35f02131457f245004edfced337e57f
 * Entry: 0x4417a0; label: FUN_004417a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_004417a0(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                    int param_5)

{
  if (((param_5 != 0) || ((param_3 != 0 && (param_5 = *(int *)(param_3 + 0xd0), param_5 != 0)))) &&
     (*(char *)(param_5 + 0x288) != '\0')) {
    return (float10)1;
  }
  return (float10)0;
}

