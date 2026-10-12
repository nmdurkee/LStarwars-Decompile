/* Ghidra pseudocode, not original source.
 * ev_e0447f8e73d2150c5385a8aa294440164da99c01f5f62ba5bd70b4e5b4546b39
 * Entry: 0x74af30; label: FUN_0074af30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_0074af30(char param_1,char param_2,char param_3)

{
  return -(uint)(param_1 != '\0') & 0x4000 | -(uint)(param_2 != '\0') & 0x2000 |
         -(uint)(param_3 != '\0') & 0x1000 | 0x20;
}

