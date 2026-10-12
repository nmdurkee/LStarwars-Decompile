/* Ghidra pseudocode, not original source.
 * ev_26d1fac8fd457d7aa06190d117e50b4f3cb6f2e0dd1b5e3302fd798cb5ca6742
 * Entry: 0x43d410; label: FUN_0043d410
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_0043d410(int param_1,int param_2)

{
  if (param_1 != 0) {
    if ((*(uint *)(param_1 + 0xef4) & 0x2000) == 0) {
      return true;
    }
    if (*(byte *)(param_1 + 0x1084) != 0xff) {
      return (&DAT_0093d7f0)[*(byte *)(param_1 + 0x1084)] == param_2;
    }
  }
  return false;
}

