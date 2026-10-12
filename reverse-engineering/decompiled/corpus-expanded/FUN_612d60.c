/* Ghidra pseudocode, not original source.
 * ev_d4530897d537ad66196ce8be54ac8764fec809d1ef324fd4741f37f5a52d36bb
 * Entry: 0x612d60; label: FUN_00612d60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00612d60(int param_1)

{
  int iVar1;
  int in_ECX;
  
  if (((param_1 != 0) && (*(int *)(in_ECX + 0x3c + param_1 * 0x18) != 0)) &&
     (iVar1 = in_ECX + (param_1 * 3 + 6) * 8, iVar1 != 0)) {
    return *(undefined4 *)(iVar1 + 8);
  }
  return 0;
}

