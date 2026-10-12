/* Ghidra pseudocode, not original source.
 * ev_0e84ad542db3be7599677a500db2c2fcd5f6f463504cd13a52c31f7d7facbfa7
 * Entry: 0x63de00; label: FUN_0063de00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0063de00(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 8) + 4))
            (*(undefined4 *)(in_ECX + 0xc),*(undefined4 *)(in_ECX + 0x10),param_1,0);
  return;
}

