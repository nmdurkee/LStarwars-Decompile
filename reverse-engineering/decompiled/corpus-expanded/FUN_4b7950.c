/* Ghidra pseudocode, not original source.
 * ev_994c8ab95260a4a020e9117574c628d5ef7b33cde61134a1d0677698b3534ab7
 * Entry: 0x4b7950; label: FUN_004b7950
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004b7950(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined4 *in_EDX;
  
  uVar1 = DAT_007fc344;
  if (DAT_009213e4 == 0) {
    uVar1 = DAT_007fc338;
  }
  *in_EDX = uVar1;
  uVar1 = DAT_007fc348;
  if (DAT_009213e4 == 0) {
    uVar1 = DAT_007fc33c;
  }
  *param_1 = uVar1;
  uVar1 = DAT_007fc34c;
  if (DAT_009213e4 == 0) {
    uVar1 = DAT_007fc340;
  }
  *in_ECX = uVar1;
  return;
}

