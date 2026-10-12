/* Ghidra pseudocode, not original source.
 * ev_7628bb02d4360686842aba648e3e8351ab050d06c55da9366e8a0a89d745bc47
 * Entry: 0x6a3ae0; label: FUN_006a3ae0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_006a3ae0(int *param_1)

{
  if (param_1[4] <= *param_1) {
    return 0xffffffff;
  }
  return *(byte *)param_1[3] >> (7U - (char)param_1[1] & 0x1f) & 1;
}

