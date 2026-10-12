/* Ghidra pseudocode, not original source.
 * ev_ba497556ae4cb5529d0570e30fa122537b7c12099b06aeea7aeb0dc1b59874db
 * Entry: 0x5b1220; label: FUN_005b1220
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005b1220(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *in_ECX;
  
  iVar1 = *param_1;
  if ((iVar1 != -1) && (in_ECX[iVar1 + 5] != 0)) {
    in_ECX[9] = iVar1;
    *in_ECX = param_2;
    return 1;
  }
  in_ECX[9] = 0xffffffff;
  return 0;
}

